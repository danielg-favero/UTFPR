#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_STRING 101

typedef struct CelulaL CelulaL;
typedef struct CelulaF CelulaF;
typedef struct Usuarios Usuarios;
typedef struct Livros Livros;
typedef union Info Info;

typedef struct{
    CelulaL *inicio;
}Lista;


typedef struct{
    CelulaF *inicio;
    CelulaF *fim;
}Fila;

struct Usuarios{
    char nome[MAX_SIZE_STRING];
    char email[MAX_SIZE_STRING];
    int qtdeLivros;
    int qtdeLivrosEsperando;

    Lista *livrosE;
};

struct CelulaF{
    int ID;
    Usuarios info;
    CelulaF *proximo;
};

struct Livros{
    char nome[51];
    char autor[31];
    char genero[11];
    char editora[21];
    int ano;
    int emprestado;

    Fila *espera;
};

union Info{
    Livros info_livros;
    Usuarios info_usuarios;
};

struct CelulaL{
    int ID;
    Info info;
    CelulaL *anterior;
    CelulaL *proximo;
};

