#include "Sistema.h"

//Cadastrar usuario no sistema
int cadastrar_usuario(Lista *l){
    CelulaL *c = criar_celulaL();

    char nome[MAX_SIZE_STRING];
    char email[MAX_SIZE_STRING];

    if(inserir_celula(l, c)){
       printf("\e[1;1H\e[2J");

        printf("Nome: ");
        fflush(stdin);
        gets(nome);
        strcpy(c->info.info_usuarios.nome, nome);

        printf("E-mail: ");
        fflush(stdin);
        gets(email);
        strcpy(c->info.info_usuarios.email, email);

        //gerar id
        c->ID = gerar_id(l);

        //iniciar a quantiade de livros
        c->info.info_usuarios.qtdeLivros = 0;
        c->info.info_usuarios.qtdeLivrosEsperando = 0;

        //realizar o insertion sort toda vez que um novo usuário é adicionado ao sistema
        exportar_lista(c, 1);
        insertionsort(l);
        return 1;
    }

    return 0;
}

//atualizar o cadastro de cada usuário
int atualizar_cadastro_usuario(Lista *l){
    CelulaL *c = (pesquisar(l));

    char nome[MAX_SIZE_STRING];
    char email[MAX_SIZE_STRING];

    if(c != NULL){
        printf("\e[1;1H\e[2J");

        printf("Nome: ");
        fflush(stdin);
        gets(nome);
        strcpy(c->info.info_usuarios.nome, nome);

        printf("E-mail: ");
        fflush(stdin);
        gets(email);
        strcpy(c->info.info_usuarios.email, email);

        //realizar o insertion sort toda vez que o registro do usuário é atualizado
        insertionsort(l);
        return 1;
    }

    return 0;
}

//Mostrar informações do usuario
void mostrar_info_usuario(Lista *l){
    CelulaL *aux = l->inicio;
    char opcao;

    //verificar se a lista esta vazia
    if(lista_vazia(l)){
        printf("\e[1;1H\e[2J");
        printf("Nao ha usuarios cadastrados\n\n");
        system("pause");
    } else {
        do{
            printf("\e[1;1H\e[2J");

            printf("========================================================================================================================\n\n");
            printf("  ID: %d\n", aux->ID);
            printf("  Nome: %s", aux->info.info_usuarios.nome);
            printf("  E-mail: %s\n", aux->info.info_usuarios.email);
            printf("  Quantidade de livros emprestados: %d\n\n", aux->info.info_usuarios.qtdeLivros);

            if(aux->info.info_usuarios.qtdeLivrosEsperando){
                printf("  OBS: %d livros esperando para fazer emprestimo\n\n", aux->info.info_usuarios.qtdeLivrosEsperando);
            }
            printf("========================================================================================================================\n");

            printf("\nPressione L avancar\n");
            printf("Pressione J retroceder\n");
            printf("Pressione K para sair\n");
            fflush(stdin);
            opcao = getch();

            //menu interativo para mostrar os usuarios em sequencia
            switch(opcao){
                case 'J':
                case 'j':
                {
                    //Andar para frente na lista
                    aux = aux->anterior;
                    break;
                }
                case 'L':
                case 'l':
                {
                    //Andar para trás na lista
                    aux = aux->proximo;
                    break;
                }
            }
        } while(opcao != 'K' && opcao != 'k');
    }
}
