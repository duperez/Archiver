#include <iostream>
#include <string>
#include <string.h>
#include "Archiver.cpp"
using namespace std;

int main()
{
    Archiver* aux = new Archiver();
    string nome = "abcdef.txt";
    string conteudo = "abcedfghijklmnop";
    char* novoNome = new char[nome.length()];
    strcpy(novoNome, nome.c_str());
    char* novoConteudo = new char[conteudo.length()];
    strcpy(novoConteudo, conteudo.c_str());
    aux->InsereNovoArquivo(novoNome, novoConteudo);
    return 0;
}
