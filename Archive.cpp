#include <iostream>
#include <string.h>
#include <stdio.h>
#define NUM_CORPO 10
#define NUM_NOME 10
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
        bool fim = true;
        char continua = 'N';
        if(conteudo.length() > NUM_CORPO){
            continua = 'S';
        }
        printf("%s/%s/%c/%c|\n", trataNome(nome, NUM_NOME), trataCorpo(conteudo, NUM_CORPO, fim), continua, 'S');
        fclose(aux);
        if(fim == false){
            char* prox = new char[conteudo.length()];
            strcpy(prox, conteudo.c_str());

            insereArchive(nome, tratamentoDecomposicao(prox, NUM_CORPO, conteudo.length()));
        }
        return 0;
    };

    char* trataCorpo(string conteudo, int tam, bool& fim){
        char* aux = new char[conteudo.length()];
        strcpy(aux, conteudo.c_str());
        if(conteudo.length() < tam){
            return strcat(aux, criaString(tam-conteudo.length()));
        }
        if(conteudo.length() == tam){
            return aux; 
        }
        if(conteudo.length() > tam){
            char* retorno = new char[tam];
            for(int i =0; i < tam;i++){
                retorno[i] = aux[i];
            }
            fim = false; 
            return retorno;
        }
    };

    char* trataNome(string conteudo, int tam){
        char* aux = new char[conteudo.length()];
        char* retorno = new char[tam];
        strcpy(aux, conteudo.c_str());
        if(conteudo.length() > tam){
            for(int i =0; i < tam-4;i++){
                retorno[i] = aux[i];
            }
            return strcat(retorno, ".txt");
        }
        if(conteudo.length() == tam){
            return aux;
        }
        if(conteudo.length() < tam){
            return strcat(aux, criaString(tam-conteudo.length()));
        }

    }
    char* criaString(int tam){
        char* str = new char[tam];
        for(int i=0;i<tam;i++){
            str[i] = '*';
        }
        return str;
    };

    char* tratamentoDecomposicao(char* conteudo, int inicio, int fim){
        char* novaString = new char[fim - inicio];
        for(int i = 0; i < fim - inicio; i++){
            novaString[i] = conteudo[i+inicio];
        }
        return novaString;
    };

    FILE* procuraPosicao(int posi){
        FILE* aux = fopen ( this->nome.c_str() , "rb" );
        fseek(aux, posi, SEEK_SET);
        return aux;
    };

};
