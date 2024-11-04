#include "Sistema.h"

//Cadastrar o livro
int cadastrar_livro(Lista *l){
    CelulaL *c = criar_celulaL();

    char nome[MAX_SIZE_STRING];
    char autor[MAX_SIZE_STRING];
    char genero[MAX_SIZE_STRING];
    char editora[MAX_SIZE_STRING];
    int ano;

    //Verificar se o livro conseguiu ser inserido na lista
    if(inserir_celula(l, c)){
        printf("\e[1;1H\e[2J");

        //cadastrar dados
        printf("Nome: ");
        fflush(stdin);
        gets(nome);
        strcpy(c->info.info_livros.nome, nome);
        strcat(c->info.info_livros.nome, "\n");

        printf("Autor: ");
        fflush(stdin);
        gets(autor);
        strcpy(c->info.info_livros.autor, autor);
        strcat(c->info.info_livros.autor, "\n");

        printf("Editora: ");
        fflush(stdin);
        gets(editora);
        strcpy(c->info.info_livros.editora, editora);
        strcat(c->info.info_livros.editora, "\n");

        printf("Genero: ");
        fflush(stdin);
        gets(genero);
        strcpy(c->info.info_livros.genero, genero);
        strcat(c->info.info_livros.genero, "\n");

        printf("Ano: ");
        scanf("%d", &ano);
        c->info.info_livros.ano = ano;

        //atribuir um id
        c->ID = gerar_id(l);

        //criar uma fila de espera para o livro
        c->info.info_livros.espera = criar_fila();

        //Livro nao esta emprestado
        c->info.info_livros.emprestado = 0;

        //realizar o insertion sort toda vez que um novo livro é adicionado ao sistema
        exportar_lista(c, 2);
        insertionsort(l);

        return 1;
    }

    return 0;
}

//atualizar cadastro de um livro
int atualizar_cadastro_livro(Lista *l){
    CelulaL *c = pesquisar(l);

    char nome[20];
    char autor[20];
    char genero[10];
    char editora[20];
    int ano;
    int ID;

    if(c != NULL){

        printf("\e[1;1H\e[2J");

        printf("Nome: ");
        fflush(stdin);
        gets(nome);
        strcpy(c->info.info_livros.nome, nome);

        printf("Autor: ");
        fflush(stdin);
        gets(autor);
        strcpy(c->info.info_livros.autor, autor);

        printf("Editora: ");
        fflush(stdin);
        gets(editora);
        strcpy(c->info.info_livros.editora, editora);

        printf("Genero: ");
        fflush(stdin);
        gets(genero);
        strcpy(c->info.info_livros.genero, genero);

        printf("Ano: ");
        scanf("%d", &ano);
        c->info.info_livros.ano = ano;

        //realizar o insertion sort toda vez que o registro de um livro for atualizado
        exportar_lista(c, 2);
        insertionsort(l);
        return 1;
    }

    return 0;
}

//Mostrar todos os livros
void mostrar_livros(Lista *l){
    CelulaL *aux = l->inicio;
    char opcao;

    //verificar se a lista esta vazia
    if(lista_vazia(l)){
        printf("\e[1;1H\e[2J");
        printf("Nao ha livros cadastrados\n\n");
        system("pause");
    } else {
        do{
            printf("\e[1;1H\e[2J");

            //Mostrar as informacoes do livro atual logo abaixo das opcoes
            printf("========================================================================================================================\n\n");
            printf("  ID: %d\n", aux->ID);
            printf("  Nome: %s", aux->info.info_livros.nome);
            printf("  Autor: %s", aux->info.info_livros.autor);
            printf("  Genero: %s", aux->info.info_livros.genero);
            printf("  Editora: %s", aux->info.info_livros.editora);
            printf("  Ano: %d\n\n", aux->info.info_livros.ano);

            if(aux->info.info_livros.emprestado){
                printf("  OBS: Emprestado\n\n");
            }
            printf("========================================================================================================================\n");

            printf("\nPressione L avancar\n");
            printf("Pressione J retroceder\n");
            printf("Pressione K para sair\n");
            fflush(stdin);
            opcao = getch();

            //menu interativo para mostrar as informações dos livros em sequência
            switch(opcao){
                case 'J':
                case 'j':
                {
                    //Andar para tras na lista
                    aux = aux->anterior;
                    break;
                }
                case 'L':
                case 'l':
                {
                    //Andar para frente na lista
                    aux = aux->proximo;
                    break;
                }
            }
        } while(opcao != 'K' && opcao != 'k');
    }
}

void mostrar_genero(Lista *l){
    printf("\e[1;1H\e[2J");

    if(lista_vazia(l)){
        printf("\e[1;1H\e[2J");
        printf("Nao ha livros cadastrados\n\n");
    } else {
        //ordenar a lista por genero
        selectsort(l);
        CelulaL *aux = l->inicio;

        printf(">> %s", aux->info.info_livros.genero);
        do{

            if(strcmp(aux->info.info_livros.genero, aux->anterior->info.info_livros.genero) > 0){
                printf("\n");
                printf(">> %s", aux->info.info_livros.genero);
            }
            printf("ID: %d - Nome: %s", aux->ID, aux->info.info_livros.nome);

            aux = aux->proximo;

        }while(aux != l->inicio);

        //ordenar a lista novamente por id
        insertionsort(l);
    }

    printf("\n");
    system("pause");
}

void mostrar_livros_disponiveis(Lista *l){
    CelulaL *aux = l->inicio;
    char opcao;

    //verificar se a lista esta vazia
    if(lista_vazia(l)){
        printf("\e[1;1H\e[2J");
        printf("Nao ha livros cadastrados\n\n");
        system("pause");
    } else {
        do{
            printf("\e[1;1H\e[2J");

            //Mostrar as informacoes do livro atual logo abaixo das opcoes
            printf("========================================================================================================================\n\n");
            printf("  ID: %d\n", aux->ID);
            printf("  Nome: %s", aux->info.info_livros.nome);
            printf("  Autor: %s", aux->info.info_livros.autor);
            printf("  Genero: %s", aux->info.info_livros.genero);
            printf("  Editora: %s", aux->info.info_livros.editora);
            printf("  Ano: %d\n\n", aux->info.info_livros.ano);

            if(aux->info.info_livros.emprestado >0){
                printf("  OBS: Emprestado\n\n");
            }
            printf("========================================================================================================================\n");

            printf("\nPressione L avancar\n");
            printf("Pressione J retroceder\n");
            printf("Pressione K para sair\n");
            fflush(stdin);
            opcao = getch();

            //menu interativo para mostrar as informações dos livros em sequência
            switch(opcao){
                case 'J':
                case 'j':
                {
                    //Andar para tras na lista
                    while(aux->info.info_livros.emprestado != 0){
                        aux = aux->anterior;
                    }
                    break;
                }
                case 'L':
                case 'l':
                {
                    //Andar para frente na lista
                    while(aux->info.info_livros.emprestado != 0){
                        aux = aux->proximo;
                    }
                    break;
                }
            }
        } while(opcao != 'K' && opcao != 'k');
    }
}
