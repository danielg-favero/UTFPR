#include "Sistema.h"

int main()
{
    //criar uma lista de livros
    system("color 70");
    Lista *livros = importar_livro(livros);
    Lista *usuarios = importar_usuario(usuarios);
    //login();
    menu_geral(livros, usuarios);
}
