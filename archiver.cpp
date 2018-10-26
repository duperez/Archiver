#include "arquivo.cpp"
class Archiver : Arquivo{
private:
    int numArq;
public:
    Archiver(char* nome) : Arquivo(nome){
        if(verificaArquivoExiste()){
            this->numArq = leArquivoInt();
        }else{
            this->numArq = 0;
            escreveNoArquivo(0);
            escreveNoArquivo('*', 1);
            escreveNoArquivo('*', 2);
            escreveNoArquivo('|', 3);
        }
    }

    void atualizaNumArqHD(){
        escreveNoArquivo(++this->numArq, 0);
    }

    void atualizaNumRAM(){
        this->numArq = leArquivoInt();
    }

    void escreveArquivo(Arquivo arq){
        escreveNoArquivo(arq.getNome());
        escreveNoArquivo('|');
        atualizaNumArqHD();

    }

    int getNumArq(){
        return this->numArq;
    }
};