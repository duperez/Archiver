#include <iostream>
#include <stdio.h>
#define USED_TABS
using namespace std;
class Archive{
private:
    string nome;
    char* index[200];
    char* conteudo;
public:
    Archive(string nome){
        FILE* aux;
        aux = fopen(nome.c_str(), "w");
        fclose(aux);
        this->nome = nome;
        criaIndex();
    };

    int insereArchive(string conteudo){
        FILE* aux = fopen(this->nome.c_str(), "a");
        fprintf(aux, "%s|",conteudo.c_str());
        return 0;
    };
    void criaIndex(){
        FILE* aux = fopen(this->nome.c_str(), "a");
        for(int num = 0; num < 200; num++){
            fprintf(aux, "%c", '*');
        }
        fprintf(aux, "%c", '\n');
    }
    void PegaConteudo(){
         FILE* aux = fopen(nome.c_str(), "r");
         fscanf(aux, "%s", *this->index);
         printf("%s", *this->index);
    }
    char* getConteudo(){
        return this->conteudo;
    }

};
