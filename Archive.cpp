#include <iostream>
#include <string.h>
#include <stdio.h>
#define NUM_CORPO 10
#define NUM_NOME 10

using namespace std;
class Archive{
private:
    char index[200];
    char conteudo[2000];
public:
    Archive(char* nome){
        FILE* aux;
        aux = fopen(nome, "w");
        fclose(aux);
    };

    char* insereArchive(char* nome, char* conteudo, char continua){
        FILE* aux = fopen(nome, "a");
        printf("%s/%s/%c/%c|\n", nome, conteudo, continua, 'S');
        fclose(aux);
        return conteudo;
    };
    

    FILE* procuraPosicao(char* nome, int posi){
        FILE* aux = fopen (nome, "rb" );
        fseek(aux, posi, SEEK_SET);
        return aux;
    };

    char* leNomes(int tam){

    }
};
