#include <iostream>
#include <string>
#include <string.h>
#include "Archiver.cpp"
using namespace std;

int main()
{
    Archiver* aux = new Archiver();
    FILE* f = fopen("ARQUIVOS.txt", "r");
    char* nome = new char[10];
    char* corpo = new char[10];
    for(int x = 0; x < 3; x++){
        fscanf(f, "%s", nome);
        fscanf(f, "%s", corpo);
        aux->InsereNovoArquivo(nome, corpo);
    }
    fclose(f);
    return 0;
}
