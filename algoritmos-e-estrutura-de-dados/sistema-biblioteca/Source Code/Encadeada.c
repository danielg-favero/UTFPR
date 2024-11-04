#include "Sistema.h"

/** funções para lista circular duplamente encadeada **/
//criar uma lista
Lista *criar_lista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;

    return l;
}

//criar celula de uma lista
CelulaL *criar_celulaL()
{
    CelulaL *c = (CelulaL*)malloc(sizeof(CelulaL));
    c->proximo = NULL;
    c->anterior = NULL;

    return c;
}

//criar as informações de uma lista
Info *criar_info()
{
    Info *i = (Info*)malloc(sizeof(Info));
    return i;
}

//verificar se a lista esta vazia
int lista_vazia(Lista *l)
{
    return l == NULL || l->inicio == NULL;
}

//inserir uma nova celula na lista
int inserir_celula(Lista *l, CelulaL *c)
{
    CelulaL *aux = l->inicio;

    if(lista_vazia(l))
    {
        l->inicio = c;
        l->inicio->proximo = l->inicio;
        l->inicio->anterior = l->inicio;

        return 1;
    }
    else
    {
        while(aux->proximo != l->inicio)
        {
            aux = aux->proximo;
        }

        l->inicio->anterior = c;
        aux->proximo = c;
        c->proximo = l->inicio;
        c->anterior = aux;

        return 1;
    }

    return 0;
}

int informar_id(){
    int id;

    printf("ID: ");
    scanf("%d", &id);

    return id;
}

//pesquisar uma celula através de seu id
CelulaL* pesquisar(Lista *l, int id)
{
    CelulaL *aux = l->inicio;

    //verificar se é possível/viável realiar a busca na lista
    if(lista_vazia(l) || id < aux->ID || id > aux->anterior->ID)
    {
        return NULL;
    }
    else
    {
        do
        {
            if(aux->ID == id)
            {
                return aux;
            }

            aux = aux->proximo;
        }
        while(aux != l->inicio);
    }

    //retornar nulo se não encontrar o id
    return NULL;
}

//função para verificar a existencia de um livro
int existe_livro(Lista *l, int ID){
    CelulaL *aux;

    if(!lista_vazia(l)){
        aux = l->inicio;

        do{
            if(aux->ID == ID){
                return 1;
            }
        } while(aux != NULL);
    }

    return 0;
}

//remover item da lista
CelulaL *remover(Lista *l, CelulaL *p)
{
    CelulaL *temp = p;
    CelulaL *aux;

    //verificar se a celula pesquisada não é nula
    if(p != NULL)
    {
        //verificar se a lista tem apenas um item
        if(p == l->inicio && p->anterior == l->inicio || p->ID == l->inicio->ID && p->ID == l->inicio->anterior->ID)
        {
            l->inicio = NULL;
            system("pause");
            free(l->inicio);
        }
        else if(p == l->inicio || p->ID == l->inicio->ID) //verificar se o item escolhido é o inicio da lista
        {
            aux = l->inicio;
            l->inicio = l->inicio->proximo;
            l->inicio->anterior = aux->anterior;
            aux->anterior->proximo = l->inicio;

            free(aux);
        }
        else //excluir um item da lista que não seja a cabeça
        {
            aux = p->anterior;
            aux->proximo = p->proximo;
            p->proximo->anterior = aux;

            free(p);
        }

        return temp;
    }

    return NULL;
}

/** funções para fila encadeada **/
//criar uma fila
Fila *criar_fila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

//criar uma celula para fila
CelulaF *criar_celulaF()
{
    CelulaF *c = (CelulaF*)malloc(sizeof(CelulaF));
    c->proximo = NULL;

    return c;
}

//verificar se uma fila esta vazia
int fila_vazia(Fila *f)
{
    return f == NULL || f->inicio == NULL;
}

//enfileirar celulas em uma fila
int enfileirar(Fila *f, CelulaL *u)
{
    CelulaF *c = criar_celulaF();
    c->info = u->info.info_usuarios;
    c->ID = u->ID;

    if(fila_vazia(f))
    {
        f->inicio = c;
        f->fim = c;
        return 1;
    }
    else
    {
        f->fim->proximo = c;
        f->fim = f->fim->proximo;
        return 1;
    }

    return 0;
}

//remover itens de uma fila
int desenfileirar(Fila *f)
{
    CelulaF *aux;

    if(!fila_vazia(f))
    {
        aux = f->inicio;
        f->inicio = aux->proximo;
        free(aux);
        return 1;
    }
    return 0;
}

void mostrar_fila(CelulaL *l){
    Fila *f = l->info.info_livros.espera;
    CelulaF *aux = f->inicio;

    printf("\e[1;1H\e[2J");
    if(fila_vazia(f)){
       printf("Nao ha fila de espera para este livro\n\n");
    } else {
        while(aux != NULL){
            printf("  ID: %d\n", aux->ID);
            printf("  Nome: %s", aux->info.nome);
            printf("  E-mail: %s\n\n", aux->info.email);

            aux = aux->proximo;
        }
    }
}
