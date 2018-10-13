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

    int insereArchive(char* nome, char* conteudo, char continua){
        FILE* aux = fopen(nome, "w");
        fprintf(aux, "%s/%s/%c/%c|", nome, conteudo, continua, 'S');
        //cout<<"aqui";
        fclose(aux);
        return 0;
    };
    

    FILE* procuraPosicao(char* nome, int posi){
        FILE* aux = fopen (nome, "rb" );
        fseek(aux, posi, SEEK_SET);
        return aux;
    };

};
