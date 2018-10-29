#include "archiver.cpp"
#include <stdio.h>
int main(int argc, char *argv[]){
    //cria um objeto archiver
    Archiver arch(argv[2]);
    //condição para caso o usuario queira criar o archiver e inserir um arquivo ou só inserir um arquivo
    if(strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-i") == 0){
        //roda todas as posições de argv[] que contem os nomes dos arquivos
        for(int x = 3; x < argc; x++){
            //escreve os arquivos no archive
            arch.escreveArquivo(Arquivo(argv[x]));
        }
    }
    //condição para caso o ususario queira ver os arquivos presentes no archive
    if(strcmp(argv[1], "-l") == 0){
        //metodo que printa os nomes dos arquivos
        arch.getNomeArquivos();
    }
    //condição para caso o usuario queira desempacotar um arquivo
    if(strcmp(argv[1], "-e") == 0){
        //metodo de desempacotamento
        arch.CriaArquivo(argv[3]);
    }
    //comdição para caso o usuario queira deletar um arquivo do archive
    if(strcmp(argv[1], "-r") == 0){
        //deleta o arquivo do indice da ram
        arch.deletaArquivo(argv[3]);
        //recria o archive sem o arquivo escolhido
        arch.CopiaTodosOsArquivos();
    }
    return 0;
}