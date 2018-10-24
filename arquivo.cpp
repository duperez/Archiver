#include <stdio.h>
class Arquivo{
private:
    //nome do arqivo
    char* nome;
    //posicao do ponteiro no arquivo
    int posi;
public:
    //construtor do arquivo
    //recebe o nome por parametro
    //a posicao é colocada como 0
    Arquivo(char* nome){
        this->nome = nome;
        this->posi = 0;
    };
    //metodo que verifica se o arquivo existe
    int verificaArquivoExiste(){
        FILE* file = fopen(this->nome, "r");
        if(file){
            fclose(file);
            return 1;
        }else{
            fclose(file);
            return 0;
        }
    }
    //metodo para criar o arquivo
    void criaArquivo(){
        FILE* file = fopen(this->nome, "w");
        fclose(file);
    } 
};