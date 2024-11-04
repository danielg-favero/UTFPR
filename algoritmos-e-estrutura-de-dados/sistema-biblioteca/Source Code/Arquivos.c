#include "Sistema.h"

char *gerar_nome_arquivo(CelulaL *c){
    char *diretorio  = malloc(sizeof(char));
    strcpy(diretorio, "Lista de livros emprestados\\");
    strcat(diretorio, c->info.info_usuarios.nome);
    strtok(diretorio, "\n"); //função para remover o \n do final do nome para completar o nome do arquivo
    strcat(diretorio, ".txt");

    return diretorio;
}

void exportar_lista(CelulaL *c, int tipo){
    FILE *fptr;

    if(tipo == 1){
        fptr = fopen("usuarios.txt", "a");

        fprintf(fptr, "%d", c->ID);
        fprintf(fptr, "\n"); //pular linha toda vez que um numero inteiro e adicionado
        strcat(c->info.info_usuarios.nome, "\n");
        fprintf(fptr, c->info.info_usuarios.nome);
        strcat(c->info.info_usuarios.email, "\n");
        fprintf(fptr, c->info.info_usuarios.email);
        fprintf(fptr, "%d", c->info.info_usuarios.qtdeLivros);
        fprintf(fptr, "\n");
        fprintf(fptr, "%d", c->info.info_usuarios.qtdeLivrosEsperando);
        fprintf(fptr, "\n\n");
    } else if(tipo == 2){
        fptr = fopen("livros.txt", "a");

        fprintf(fptr, "%d", c->ID);
        fprintf(fptr, "\n"); //pular linha toda vez que um numero inteiro e adicionado
        fprintf(fptr, c->info.info_livros.nome);
        fprintf(fptr, c->info.info_livros.autor);
        fprintf(fptr, c->info.info_livros.editora);
        fprintf(fptr, c->info.info_livros.genero);
        fprintf(fptr, "%d", c->info.info_livros.ano);
        fprintf(fptr, "\n");
        fprintf(fptr, "%d", c->info.info_livros.emprestado);
        fprintf(fptr, "\n\n");
    }
    fclose(fptr);
}

void exportar_lista_emprestados(CelulaL *c, char *arquivo){
    FILE *fptr = fopen(arquivo, "a");

    fprintf(fptr, "%d", c->ID);
    fprintf(fptr, "\n");
    fprintf(fptr, c->info.info_livros.nome);
    fprintf(fptr, c->info.info_livros.autor);
    fprintf(fptr, c->info.info_livros.editora);
    fprintf(fptr, c->info.info_livros.genero);
    fprintf(fptr, "%d", c->info.info_livros.ano);
    fprintf(fptr, "\n");
    fprintf(fptr, "%d", c->info.info_livros.emprestado);
    fprintf(fptr, "\n\n");

    fclose(fptr);
}

int contar_linhas(FILE *f, const char *nome){
    f = fopen(nome, "r");

    char c, fim = '\n';
    int qtde = 0;

    while(fread(&c, sizeof(char), 1, f)){
        if(c == fim){
            qtde++;
        }
    }

    fclose(f);
    return qtde;
}

Lista *importar_livro_emprestado(const char *arquivo, Lista *l){
    FILE *fptr;
    CelulaL *c;
    char ignorar[MAX_SIZE_STRING];
    char nome[MAX_SIZE_STRING];
    char autor[MAX_SIZE_STRING];
    char editora[MAX_SIZE_STRING];
    char genero[MAX_SIZE_STRING];
    int ano;
    int id;

    int linhas = 0;
    int total_linhas = contar_linhas(fptr, arquivo);

    fptr = fopen(arquivo, "r");

    if(lista_vazia(l) && fptr != NULL){
        while(linhas < total_linhas ){
            //Inserir dados do arquivo na lista
            fscanf(fptr, "%d", &id);
            fgets(ignorar, sizeof(int), fptr); //inserir um \n toda vez que ler um numero inteiro

            fgets(nome, MAX_SIZE_STRING, fptr);

            fgets(autor, MAX_SIZE_STRING, fptr);

            fgets(editora, MAX_SIZE_STRING, fptr);

            fgets(genero, MAX_SIZE_STRING, fptr);

            fscanf(fptr, "%d", &ano);
            fgets(ignorar, sizeof(int), fptr);

            fgets(ignorar, MAX_SIZE_STRING, fptr);
            linhas += 8;

            c = criar_celulaL();
            c->ID = id;
            strcpy(c->info.info_livros.nome, nome);
            strcpy(c->info.info_livros.autor, autor);
            strcpy(c->info.info_livros.editora, editora);
            strcpy(c->info.info_livros.genero, genero);
            c->info.info_livros.ano = ano;
            inserir_celula(l, c);


        }
        fclose(fptr);
        insertionsort(l);
        return l;
    }
    return NULL;
}

Lista* importar_livro(){
    Lista *l = criar_lista();
    FILE *fptr;
    CelulaL *c;

    char ignorar[MAX_SIZE_STRING];
    char nome[MAX_SIZE_STRING];
    char autor[MAX_SIZE_STRING];
    char editora[MAX_SIZE_STRING];
    char genero[MAX_SIZE_STRING];
    int ano;
    int id;

    int linhas = 0;
    int total_linhas = contar_linhas(fptr, "livros.txt");

    fptr = fopen("livros.txt", "r");

    if(lista_vazia(l) && fptr != NULL){
        while(linhas < total_linhas ){
            //Inserir dados do arquivo na lista
            fscanf(fptr, "%d", &id);
            fgets(ignorar, sizeof(int), fptr); //inserir um \n toda vez que ler um numero inteiro

            fgets(nome, MAX_SIZE_STRING, fptr);

            fgets(autor, MAX_SIZE_STRING, fptr);

            fgets(editora, MAX_SIZE_STRING, fptr);

            fgets(genero, MAX_SIZE_STRING, fptr);

            fscanf(fptr, "%d", &ano);
            fgets(ignorar, sizeof(int), fptr);

            fgets(ignorar, MAX_SIZE_STRING, fptr);
            linhas += 8;

            c = criar_celulaL();
            c->ID = id;
            strcpy(c->info.info_livros.nome, nome);
            strcpy(c->info.info_livros.autor, autor);
            strcpy(c->info.info_livros.editora, editora);
            strcpy(c->info.info_livros.genero, genero);
            c->info.info_livros.ano = ano;
            c->info.info_livros.espera = criar_fila();
            inserir_celula(l, c);
        }
        fclose(fptr);
        insertionsort(l);
    }

    return l;
}

Lista* importar_usuario(){
    Lista *l = criar_lista();
    FILE *fptr;
    CelulaL *c;

    char ignorar[MAX_SIZE_STRING];
    char nome[MAX_SIZE_STRING];
    char email[MAX_SIZE_STRING];
    double cpf;
    int qtdeLivros;
    int id;
    int qtdeLivrosEsperando;

    char *arquivo = malloc(sizeof(char));
    char *diretorio = malloc(sizeof(char));

    int linhas = 0;
    int total_linhas = contar_linhas(fptr, "usuarios.txt");

    fptr = fopen("usuarios.txt", "r");

    if(lista_vazia(l) && fptr != NULL){
        while(linhas < total_linhas - 1){
            //Inserir dados do arquivo na lista
            fscanf(fptr, "%d", &id);
            fgets(ignorar, sizeof(int), fptr); //inserir um \n toda vez que ler um numero inteiro

            fgets(nome, MAX_SIZE_STRING, fptr);

            fgets(email, MAX_SIZE_STRING, fptr);

            fscanf(fptr, "%d", &qtdeLivros);
            fgets(ignorar, sizeof(int), fptr);

            fscanf(fptr, "%d", &qtdeLivrosEsperando);
            fgets(ignorar, sizeof(int), fptr);

            fgets(ignorar, MAX_SIZE_STRING, fptr);
            linhas += 6;


            c = criar_celulaL();
            c->ID = id;
            strcpy(c->info.info_usuarios.nome, nome);
            strcpy(c->info.info_usuarios.email, email);
            c->info.info_usuarios.qtdeLivros = qtdeLivros;
            c->info.info_usuarios.qtdeLivros = qtdeLivrosEsperando;

//            strcpy(diretorio, gerar_nome_arquivo(c));
            c->info.info_usuarios.livrosE = criar_lista();
//            c->info.info_usuarios.livrosE = importar_livro_emprestado(diretorio, c->info.info_usuarios.livrosE);
            inserir_celula(l, c);

        }
        fclose(fptr);
        insertionsort(l);
    }

    return l;
}
