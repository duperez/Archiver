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
        arq->insereArchive(Linha::trataNome(nome, 10), Linha::trataCorpo(corpo, 100, fim), 'N');

    }

};
