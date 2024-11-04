#include "Sistema.h"

//gerar id aleatorio
int gerar_id(Lista *l){
    srand(time(NULL));
    int id;
    CelulaL *aux = l->inicio;

    do{
        id = rand() % 101;

        if(id == aux->ID){
            aux = l->inicio;
        }

        aux = aux->proximo;
    }while(aux != l->inicio->anterior);

    return id;
}

//trocar apenas a info de cada celula
static void trocar(CelulaL *a, CelulaL *b){
    CelulaL *aux = criar_celulaL();

    aux->info = a->info;
    aux->ID = a->ID;

    a->info = b->info;
    a->ID = b->ID;

    b->info = aux->info;
    b->ID = aux->ID;
}

//algoritmo de insertion sort
void insertionsort(Lista *l){
    CelulaL *aux1 = l->inicio;
    CelulaL *aux2;

    while(aux1 != l->inicio->anterior){
        aux2 = aux1->proximo;

        while(aux2->anterior->ID > aux2->ID && aux2 != l->inicio){
            trocar(aux2, aux2->anterior);
            aux2 = aux2->anterior;
        }
        aux1 = aux1->proximo;
    }
}

//algoritmo de ordenacao de strings por selection sort
void selectsort(Lista *l){
    CelulaL *maior, *inicio, *fim, *aux;
    inicio = l->inicio;
    fim = l->inicio->anterior;

    //printf(".");
    while(inicio != fim){
        aux = inicio;
        maior = inicio;

        do{
            if(strcmp(aux->info.info_livros.genero, maior->info.info_livros.genero) > 0){
                maior = aux;
            }

            aux = aux->proximo;
        }while(aux->anterior != fim);

        trocar(maior, fim);
        fim = fim->anterior;
    }
}

//contar a quantidade de itens em uma lista
int quantidade_itens(Lista *l){
    CelulaL *aux = l->inicio;
    int qtde = 1;

    if(lista_vazia(l)){
        return 0;
    }

    while(aux->proximo != l->inicio){
        aux = aux->proximo;
        qtde++;
    }

    return qtde;
}

//tela de login
void login(){
    char usuario[10];
    char senha[10];

    do{
        printf("\e[1;1H\e[2J");
        printf(" ____                         _           _          __     ____  _ _     _ _       _\n");
        printf("|  _ \\                       (_)         | |         \\_\\   |  _ \\(_) |   | (_)     | |\n");
        printf("| |_) | ___ _ __ ___   __   ___ _ __   __| | ___     __ _  | |_) |_| |__ | |_  ___ | |_ ___  ___ __ _ \n");
        printf("|  _ < / _ \\ '_ ` _ \\  \\ \\ / / | '_ \\ / _` |/ _ \\   / _` | |  _ <| | '_ \\| | |/ _ \\| __/ _ \\/ __/ _` |\n");
        printf("| |_) |  __/ | | | | |  \\ V /| | | | | (_| | (_) | | (_| | | |_) | | |_) | | | (_) | ||  __/ (_| (_| |\n");
        printf("|____/ \\___|_| |_| |_|   \\_/ |_|_| |_|\\__,_|\\___/   \\__,_| |____/|_|_.__/|_|_|\\___/ \\__\\___|\\___\\__,_|\n\n");

        printf("\n\t\t\t\t\t\tUsuario: ");
        fflush(stdin);
        gets(usuario);

        printf("\n\t\t\t\t\t\tSenha: ");
        fflush(stdin);
        gets(senha);

        //Comparar duas strings para validar o acesso
        if(strcmp("admin", usuario) != 0 || strcmp("admin", senha) != 0){
            printf("\nUsuario ou senha incorreto(s)\n\n");
            system("pause");
        }

    } while(strcmp("admin", usuario) != 0 || strcmp("admin", senha) != 0);
}

//menu para gerenciamento dos livros
void menu_livros(Lista *ll, Lista *lu){
    int opcao;

    do{
       printf("\e[1;1H\e[2J");

       printf("1) Listar todos os livros\n");
       printf("2) Listar livro por genero\n");
       printf("3) Cadastrar livro\n");
       printf("4) Atualizar cadastro de um livro\n");
       printf("5) Remover livro\n");
       printf("6) Mostrar fila de espera para livro\n");
       printf("9) Sair\n");
       fflush(stdin);
       opcao = getch() - 48;

       switch(opcao){
            case 1:
            {
                //mostrar todos os livros
                mostrar_livros(ll);
                break;
            }

            case 2:
            {
                mostrar_genero(ll);
                break;
            }

            case 3:
            {
                //cadastrar um novo livro
                if(cadastrar_livro(ll)){
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }

            case 4:
            {
                //atualizar o cadastro de um livro
                if(atualizar_cadastro_livro(ll)){
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }

            case 5:
            {
                //remover livro
                CelulaL *l = pesquisar(ll);

                if(l != NULL){
                    if(remover(ll, l)){
                        printf("\nOperacao bem sucedida\n\n");
                    } else {
                        printf("\nNao foi possivel realizar a operacao\n\n");
                    }
                } else {
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }
                system("pause");
                break;
            }

            case 6:
            {
                printf("\e[1;1H\e[2J");
                CelulaL *aux = pesquisar(ll);

                printf("\e[1;1H\e[2J");
                if(aux != NULL){
                    mostrar_fila(aux);
                } else {
                    printf("\nLivro nao encontrado\n\n");
                }

                system("pause");
            }
       }
    } while(opcao != 9);
}

//menu para gerenciamento dos usuarios
void menu_usuarios(Lista *l){
    int opcao;

    do{
       printf("\e[1;1H\e[2J");

       printf("1) Listar todos os usuarios\n");
       printf("2) Cadastrar usuario\n");
       printf("3) Atualizar cadastro do usuario\n");
       printf("4) Mostrar lista de livros de um usuario\n");
       printf("9) Sair\n");
       fflush(stdin);
       opcao = getch() - 48;

       switch(opcao){
            case 1:
            {
                //mostrar todos os usuarios
                mostrar_info_usuario(l);
                break;
            }

            case 2:
            {
                //cadastrar um novo usuario
                if(cadastrar_usuario(l)){
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }

            case 3:
            {
                //atualizar cadastro de um usuario
                if(atualizar_cadastro_usuario(l)){
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }

            case 4:
            {
                //mostrar a lista de livros emprestados por um usuario
                printf("\e[1;1H\e[2J");
                CelulaL *u = pesquisar(l);
                if(u != NULL){
                   mostrar_livros(u->info.info_usuarios.livrosE);
                } else {
                    printf("Usuario nao encontrado\n\n");
                    system("pause");
                }
            }
       }
    } while(opcao != 9);
}

/** menu geral do sistema **/
void menu_geral(Lista *ll, Lista *lu){
    int opcao;

    do{
        printf("\e[1;1H\e[2J");
        printf("========================================================================================================================\n\n");
        printf("  1) Gerenciar livros\n");
        printf("  2) Gerenciar Usuarios\n");
        printf("  3) Realizar emprestimo\n");
        printf("  4) Realizar devolucao\n");
        printf("  9) Sair do sistema\n\n");
        printf("========================================================================================================================\n\n");
        printf("  Opcao: ");
        fflush(stdin);
        opcao = getch() - 48;

        switch(opcao){
            case 1:
            {
                //Abrir menu dos livros
                menu_livros(ll, lu);
                break;
            }

            case 2:
            {
                //Abrir menu dos usuarios
                menu_usuarios(lu);
                break;
            }

            case 3:
            {
                //realizar a operacao de emprestimo
                if(emprestar(ll, lu)){
                    printf("\e[1;1H\e[2J");
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\e[1;1H\e[2J");
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }
            case 4:
            {
                if(devolver(ll, lu)){
                    printf("\e[1;1H\e[2J");
                    printf("\nOperacao bem sucedida\n\n");
                } else {
                    printf("\e[1;1H\e[2J");
                    printf("\nNao foi possivel realizar a operacao\n\n");
                }

                system("pause");
                break;
            }
            default:
            {
                printf("Opcao invalida!\n");
            }
        }
    } while(opcao != 9);
}

//função para emprestar um livro
int emprestar(Lista *ll, Lista *lu){
    char opcao;
    char nome[MAX_SIZE_STRING];
    int id;

    CelulaL *aux;
    Info info_aux;
    Fila *f;

    do{
        printf("\e[1;1H\e[2J");
        printf("\t\t\t\t\t\t\tLIVRO\n");
        printf("========================================================================================================================\n\n");
        id = informar_id();
        CelulaL *l = pesquisar(ll, id);
        f = l->info.info_livros.espera;

        printf("\e[1;1H\e[2J");
        printf("\t\t\t\t\t\t\tUSUARIO\n");
        printf("========================================================================================================================\n\n");
        id = informar_id();
        CelulaL *u = pesquisar(lu, id);
        if(!existe_livro(u->info.info_usuarios.livrosE, l->ID)){
            //verificar se o livro e/ou usuario foram encontrados
            if(u == NULL || l == NULL){
                printf("\e[1;1H\e[2J");

                printf("Nao foi possivel encontrar o livro e/ou usuario\n");
                printf("Pressione qualquer tecla para tentar novamente\n");
                printf("Pressione s/S para sair\n");
                fflush(stdin);
                scanf("%c", &opcao);

            } else if(l->info.info_livros.emprestado){
                if(!fila_vazia(f) && u->ID == f->inicio->ID){
                    desenfileirar(f);

                    aux = criar_celulaL();
                    info_aux = l->info;
                    aux->ID = l->ID;
                    aux->info = info_aux;

                    if(inserir_celula(u->info.info_usuarios.livrosE, aux)){
                        u->info.info_usuarios.qtdeLivros++;

                        if(u->info.info_usuarios.qtdeLivrosEsperando > 0){
                            u->info.info_usuarios.qtdeLivrosEsperando--;
                        }
                        return 1;
                    } else{
                        return 0;
                    }
                }

                printf("\nO livro em questao esta emprestado, deseja adicionar o usuario a lista de espera?(s/S)\n");
                fflush(stdin);
                scanf("%c", &opcao);

                if(opcao == 's' || opcao == 'S'){
                    enfileirar(l->info.info_livros.espera, u);
                    return 1;
                }
            }else {
                //celula auxiliar para receber uma copia das informacoes do livro emprestado
                aux = criar_celulaL();
                info_aux = l->info;
                aux->ID = l->ID;
                aux->info = info_aux;

                if(inserir_celula(u->info.info_usuarios.livrosE, aux)){                    u->info.info_usuarios.qtdeLivros++;
                    l->info.info_livros.emprestado = 1;

                    //exportar_lista_emprestados(aux, gerar_nome_arquivo(u));
                    return 1;
                }
            }
        } else {
            printf("\e[1;1H\e[2J");
            printf("Este livro ja foi emprestado a esse usuario\n\n");
            system("pause");
            return 0;
        }
    } while((opcao != 's' && opcao != 'S'));

    return 0;
}

int devolver(Lista *ll, Lista *lu){
    int opcao;
    int id;
    CelulaL *u, *removido, *temp;
    Fila *f;

    printf("\e[1;1H\e[2J");
    printf("\t\t\t\t\t\t\tUSUARIO\n");
    printf("========================================================================================================================\n\n");
    id = informar_id();
    u = pesquisar(lu, id);
    if(u != NULL){
        if(lista_vazia(u->info.info_usuarios.livrosE)){
            printf("\e[1;1H\e[2J");
            printf("Nao ha livros cadastrados\n\n");
        } else {
            printf("\e[1;1H\e[2J");
            printf("\t\t\t\t\t\t\tLIVRO\n");
            printf("========================================================================================================================\n\n");
            id = informar_id();
            removido = pesquisar(ll, id);
            f = removido->info.info_livros.espera;
        }
    } else {
        printf("\e[1;1H\e[2J");
        printf("Usuario nao encontrado\n\n");
        return 0;
    }

    if(removido != NULL && !fila_vazia(f)){
        do{
            printf("\e[1;1H\e[2J");
            printf("Ha usuarios na fila de espera para esse livro, o que deseja fazer?\n");
            printf("1) Emprestar livro ao proximo usuario\n");
            printf("2) Avisar o proximo usuario\n");
            printf("Opcao: ");
            scanf("%d", &opcao);

            switch(opcao){
                case 1:
                {
                    temp = pesquisar(lu, f->inicio->ID);
                    desenfileirar(f);
                    break;
                }

                case 2:
                {
                    temp = pesquisar(lu, f->inicio->ID);
                    temp->info.info_usuarios.qtdeLivrosEsperando++;
                    break;
                }
            }
        }while(opcao != 1 && opcao != 2);
        u->info.info_usuarios.qtdeLivros--;
        return 1;
    } else {
        removido->info.info_livros.emprestado = 0;
        temp = remover(u->info.info_usuarios.livrosE, removido);

        if(temp != NULL){
            return 1;
        }else {
            return 0;
        }
    }

    return 0;
}
