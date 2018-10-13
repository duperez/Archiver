#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
using namespace std;
class Linha{
public:
    //construtor do objeto linh 
    Linha(){};
    //classe que trata o corpo do arquivo
    static char* trataCorpo(char* conteudo, int tam, bool& fim){
        if(strlen(conteudo) < tam){
            return strcat(conteudo, criaString(tam-strlen(conteudo)));
        }
        if(strlen(conteudo) == tam){
            return conteudo; 
        }
        if(strlen(conteudo) > tam){
            char* retorno = new char[tam];
            retorno = tratamentoDecomposicao(conteudo, 0, tam);
            fim = false; 
            return retorno;
        }
    };
    //trata o nome do arquivo
    static char* trataNome(char* conteudo, int tam){
        char* retorno = new char[tam];
        if(strlen(conteudo)> tam){
            retorno = tratamentoDecomposicao(conteudo, 0, tam-4);
            strcat(retorno, ".txt");
            return retorno;
        }
        if(strlen(conteudo) == tam){
            return conteudo;
        }
        if(strlen(conteudo) < tam){
            strcat(conteudo, criaString(tam-strlen(conteudo)));
            return conteudo;
        }

    };
    //criar um vetor de char que possui "*" em todas as opiçoes
    static char* criaString(int tam){
        char* str = new char[tam];
        for(int i=0;i<tam;i++){
            str[i] = '*';
        }
        return str;
    };
    //retorna uma parte de um vetor
    static char* tratamentoDecomposicao(char* conteudo, int inicio, int fim){
        char* novaString = new char[fim - inicio];
        for(int i = 0; i < fim - inicio; i++){
            novaString[i] = conteudo[i+inicio];
        }
        return novaString;
    };
};