#include <stdio.h>
class Arquivo{
private:
    //nome do arqivo
    char* nome;
    //posicao do ponteiro no arquivo
    //é usado como uma variavel para que, mesmo com o arquivo efetivamente fechado, a posição não seja perdida
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
        int fn = fscanf(file, "%c", &caractere);
        if(fn != EOF){
            fim = 1;
            fclose(file);
            return caractere;
        }else{
            fim = 0;
            fclose(file);
            return '\0';
        }
    };
    //le um arquivo retornando um \0 caso o arquivo esteja no fim
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
            return '\0';
        }
    };

    //le um caractere do arquivo na posição fornecida
    char leArquivo(int position){
        char caractere;
        FILE* file = fopen(this->nome, "r");
        fseek(file, position, SEEK_SET);
        fscanf(file, "%c", &caractere);
        if(file){
            fclose(file);
            return caractere;
        }else{
            fclose(file);
            return '\0';
        }
    };

    //metodo que retorna o nome
    char* getNome(){
        return this->nome;
    };

    //metodo que retorna a posicao do ponteiro
    int getPonteiro(){
        return this->posi;
    };
    //metodo que manda o ponteiro do arquivo para uma posicao especifica
    void setPonteiro(int posi){
        this->posi = posi;
    };

    //escreve um caractere no final do arquivo
    int escreveNoArquivo(char caractere){
        FILE* file = fopen(this->nome, "a");
        fprintf(file, "%c",caractere);
        int posi = ftell(file);
        fclose(file);
        return posi;
    };

    //escreve uma string no arquivo
    void escreveNoArquivo(char* palavra){
        FILE* file = fopen(this->nome, "a");
        fprintf(file, "%s", palavra);
        fclose(file);
    }
    //posiciona o ponteiro do leitor em uma posição especifica
    void posicionaPonteiro(int position){
        this->posi = position;
    }
};