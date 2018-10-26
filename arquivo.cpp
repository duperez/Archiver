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
    //se o arquivo não existir retorna 0
    //se o arquivo existir retorna 1
    int verificaArquivoExiste(){
        FILE* file = fopen(this->nome, "r");
        if(file == NULL){
            return 0;
        }
        else{
            return 1;
        }
    };
    //metodo para criar o arquivo
    void criaArquivo(){
        FILE* file = fopen(this->nome, "w");
        fclose(file);
    };
    //metodo para ler caractere do arquivo na posicao posi
    char leArquivo(bool& fim){
        char caractere;
        FILE* file = fopen(this->nome, "r");
        fseek(file, this->posi++, SEEK_SET);
        fscanf(file, "%c", &caractere);
        if(file){
            fim = 1;
            fclose(file);
            return caractere;
        }else{
            fim = 0;
            fclose(file);
            return ' ';
        }
    };

    char leArquivo(){
        char caractere;
        FILE* file = fopen(this->nome, "r");
        fseek(file, this->posi++, SEEK_SET);
        fscanf(file, "%c", &caractere);
        if(file){
            fclose(file);
            return caractere;
        }else{
            fclose(file);
            return ' ';
        }
    };

    int leArquivoInt(){
        int num;
        FILE* file = fopen(this->nome, "r");
        fseek(file, this->posi++, SEEK_SET);
        fscanf(file, "%d", &num);
        if(file){
            fclose(file);
            return num;
        }else{
            fclose(file);
            return ' ';
        }
    };

    //metodo que retorna o nome
    char* getNome(){
        return this->nome;
    };

    //metodo que retorna a posicao do ponteiro
    int getPosicao(){
        return this->posi;
    };

    //metodo que manda o ponteiro do arquivo para uma posicao especifica
    void setPonteiro(int posi){
        this->posi = posi;
    };

    //escreve um caractere no final do arquivo
    void escreveNoArquivo(char caractere){
        FILE* file = fopen(this->nome, "a");
        fprintf(file, "%c",caractere);
        fclose(file);
    };

    //escreve um caractere na posicao indicada
    void escreveNoArquivo(char caractere, int posi){
        FILE* file = fopen(this->nome, "r+");
        fseek(file, posi, SEEK_SET);
        fprintf(file, "%c",caractere);
        fclose(file);
    };

    void escreveNoArquivo(int num, int posi){
        FILE* file = fopen(this->nome, "r+");
        fseek(file, posi, SEEK_SET);
        fprintf(file, "%d",num);
        fclose(file);
    };

    void escreveNoArquivo(int num){
        FILE* file = fopen(this->nome, "a");
        fprintf(file, "%d",num);
        fclose(file);
    };

    //escreve uma string no arquivo
    void escreveNoArquivo(char* palavra){
        FILE* file = fopen(this->nome, "a");
        fseek(file, posi, SEEK_SET);
        fprintf(file, "%s", palavra);
        fclose(file);
    }
};