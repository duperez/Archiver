#include <iostream>
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
        criaIndex();
        fclose(aux);
    };

    int insereArchive(string conteudo){
        FILE* aux = fopen(this->nome.c_str(), "a");
        fprintf(aux, "%s|",conteudo.c_str());
        fclose(aux);
        return 0;
    };
    void criaIndex(){
        FILE* aux = fopen(this->nome.c_str(), "a");
        for(int num = 0; num < 200; num++){
            fprintf(aux, "%c", '*');
        }
        fprintf(aux, "%c", '\n');
        fclose(aux);
    }
    void PegaConteudo(){
         pegaIndex();

    }
    void pegaIndex(){
        FILE* aux = fopen(this->nome.c_str(), "r");
         fscanf(aux, "%s", this->index);
         fclose(aux);
    }

    void pegaCorpo(){
        FILE* aux = procuraPosicao(201);
        fscanf(aux, "%s", this->conteudo);
        cout<<this->conteudo;
        fclose(aux);

    }
    FILE* procuraPosicao(int posi){
        FILE* aux = fopen ( this->nome.c_str() , "rb" );
        fseek(aux, posi, SEEK_SET);
        return aux;
    }
    char* getIndex(){
        return this->index;
    }

};
