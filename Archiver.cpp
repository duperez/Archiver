#include "Archive.cpp"
#include <iostream>
#include <vector>
#include "Linha.cpp"
#define NUM_COMANDOS 5

using namespace std;
class Archiver{
private:
    string comandos[NUM_COMANDOS];
    Archive* basic;
    vector<Archive>conteudo;
public:
    Archiver(){};
    
    void InsereNovoArquivo(char* nome, char* corpo){
        Archive* arq = new Archive(nome);
        bool fim;
        char* linha;
        while(strlen(corpo) > 10){
           arq->insereArchive(Linha::trataNome(nome, 10), Linha::trataCorpo(corpo, 10, fim), 'V');
           if(fim = true){
               corpo = Linha::tratamentoDecomposicao(corpo, 10, strlen(corpo));
           }
        }
        arq->insereArchive(Linha::trataNome(nome, 10), Linha::trataCorpo(corpo, 10, fim), 'V');
    };

};
