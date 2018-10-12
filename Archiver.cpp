#include "Archive.cpp"
#include <iostream>
#include <vector>
#define NUM_COMANDOS 5

using namespace std;
class Archiver{
private:
    string comandos[NUM_COMANDOS];
    Archive* basic;
    vector<Archive>conteudo;
public:
    Archiver(){
        this->basic = new Archive("BASIC.txt");
    }
    void NovoArchive(string nome, string corpo){
        conteudo.insert(conteudo.end(), Archive(nome));
        basic->insereArchive(nome, corpo);
    }

};
