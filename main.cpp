#include "archiver.cpp"
#include <stdio.h>
int main(){
    Arquivo arq("arq.txt");
    Archiver arch("archiver.txt");
    arch.escreveArquivo(arq);
    return 0;
}