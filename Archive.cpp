#include <iostream>
#include <string.h>
#include <stdio.h>
#define USED_TABS
using namespace std;
class Archive{
private:
    string nome;
    char index[200];
    char conteudo[2000];
public:
    Archive(string nome){
        FILE* aux;
        aux = fopen(nome.c_str(), "w");
        fclose(aux);
        this->nome = nome;
    };

    int insereArchive(string nome, string conteudo){
        FILE* aux = fopen(this->nome.c_str(), "a");
        printf("Nome:%s/%s/%d/%c|", trataString(nome, 10), trataString(conteudo, 50), -1, 'S');
        fclose(aux);
        return 0;
    };

    int insereArchive(string nome, string conteudo, int continuacao){
        FILE* aux = fopen(this->nome.c_str(), "a");
        printf("%s/%s/%d/%c|", trataString(nome, 10), trataString(conteudo, 50), continuacao, 'S');
        fclose(aux);
        return 0;
    };

    char* trataString(string conteudo, int tam){
        char* aux = new char[conteudo.length()];
        strcpy(aux, conteudo.c_str());
        if(conteudo.length() < tam){
            return strcat(aux, criaString(tam-conteudo.length()));
        }else{
            return aux; 
        }
    };

    char* criaString(int tam){
        char* str = new char[tam];
        for(int i=0;i<tam;i++){
            str[i] = '*';
        }
        return str;
    };

    FILE* procuraPosicao(int posi){
        FILE* aux = fopen ( this->nome.c_str() , "rb" );
        fseek(aux, posi, SEEK_SET);
        return aux;
    };

    char* getIndex(){
        return this->index;
    };
};
