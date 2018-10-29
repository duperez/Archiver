/*
---------------
IMPORTANTE
Padrão de inserção:
|NOME.TAG|CORPO|
onde, '|' representa o elemento 0 da tabela ascii
o indice TEM a posição do CORPO e NÃO do NOME no archive
As posições dos arquivos são pegos por logica na hora da leitura e inserção
O arquivo CRIA o indice cada vez que é chamado
---------------
*/

#include "arquivo.cpp"
#include "index.cpp"
#include <vector>
#include <iostream>
#include <string.h> 
using namespace std;
class Archiver : Arquivo{
private:
    vector<Index*> indice;
    char FLAG = 0;
public:
    //construtor do archiver
    //se o archiver existir, coloca na ram os nomes
    //se não, coloca o sinalizador de inserção
    Archiver(char* nome) : Arquivo(nome){
        if(!verificaArquivoExiste()){
            //coloca um flag inicial no arquivo caso ele não exista
            escreveNoArquivo(FLAG);
        }else{
            //se o arquivo existir o programa só pega os nomes e posições dos arquivos e coloca na ram
            pegaNomes();
        }
    }
    //metodo que escreve um arquivo em um archiver
    void escreveArquivo(Arquivo arq){
        //verifica se o arquivo ja foi inserido no arquivo
        if(!verificaArquivoInserido(arq.getNome())){
            //se não foi, insere o arquivo, seu corpo e as flags de separação
            escreveNoArquivo(arq.getNome());
            int posiIni = escreveNoArquivo(FLAG);
            insereCorpo(arq);
            escreveNoArquivo(FLAG);
            //cria uma nova posição no indice contendo o no arquivo
            indice.insert(indice.end(), new Index(arq.getNome(), posiIni));
        }else{
            //caso o arquivo ja tenha sido inserido previamente, avisa o usuario que o arquivo ja existe
            printf("ARQUIVO JA INSERIDO\n");
        }
    }
    //metodo que insere o corpo de um arquivo no archiver
    //fica em um while escrevendo caractere por caractere
    void insereCorpo(Arquivo arq){
        if(arq.verificaArquivoExiste()){
            char caractere = ' ';
            while(caractere != '\0'){
                caractere = arq.leArquivo();
                if(caractere != '\0'){
                escreveNoArquivo(caractere);
                }

            }
        }else{
            //se o arquivo não existir ou não possuir nada escrito, o sistema coloca um espaço ' '
           escreveNoArquivo(' '); 
        }
    }
    //pega os nomes dos arquivos e coloca no indice da ram
    void pegaNomes(){
        bool a = true;
        int count = 0;
        char caractere = ' ';
        int aux = 0;
        int posi;
        char* arch = new char[100];
        //coloca o ponteiro do aquivo na posição 1
        setPonteiro(1);
        while(a != 0){
            caractere = leArquivo(a);
            posi = getPonteiro();
            //se for uma flag, coloca +1 no contador
            //se o contador for par quer dizer que esta em um nome
            //se for impar, esta no corpo
            if(caractere == FLAG){
                count++;
                if(aux > 0){
                    //uma vez q pegou o nome e saiu da area do nome, coloca os dados no indice da ram
                    indice.insert(indice.end(), new Index(arch, posi));
                    arch = new char[100];
                    aux = 0;
                }
            }//quando encontra um nome, coloca caractere a caractere no vetor
            if(count % 2 == 0 && caractere != FLAG){
                arch[aux++] = caractere;
                arch[aux] = '\0';
            }
        }
    }
    //printa o nome de todos os arquivos
    //faz isso varrendo o indice da ram
    void getNomeArquivos(){
        vector<Index*>::iterator varre;
        varre = indice.begin();
        while(varre != indice.end()){
            if((*varre)->getExistencia() == true){
                printf("%s\n", (*varre)->getNome());
            }
            varre++;
        }
    }
    //retorna verdadeiro ou falso dependendo se o arquivo existir no archive
    //verdadeiro se existir
    //falso se não existir
    //essa verificação é feita pelo indice na ram
    bool verificaArquivoInserido(char* nomeArq){
        vector<Index*>::iterator varre;
        varre = indice.begin();
        while(varre != indice.end()){
            if(strcmp((*varre)->getNome(), nomeArq) == 0){
                    return 1;
            }
            varre++;
        }
        return 0;
    }
    //cris um arquivo auxliar e renomeia ele
    //usado para deletar arquivos dentro do archive
    void CopiaArquivo(int posi, char* nome){
        //esse bloco é feito apenas para não gerar warning com o nome do arquivo
        //"aux.cpy" é o arquivo de copia do archive
        string nomeArquivoAux = "aux.cpy";
        char* nomeAux = new char[100];
        strcpy(nomeAux, nomeArquivoAux.c_str());
        //esse bloco é feito apenas para não gerar warning com o nome do arquivo
        //coloca o ponteiro do leitor na posição indicada
        setPonteiro(posi);
        bool fim;
        char caractere = ' ';
        //cria um novo archive
        Archiver arq(nomeAux);
        //escreve nome, copor e flags no padrão do sistema
        arq.escreveNoArquivo(nome);
        arq.escreveNoArquivo(FLAG);
        while(caractere != FLAG){
            caractere = leArquivo(fim);
            if(caractere != FLAG){
                arq.escreveNoArquivo(caractere);
            }
        }
        arq.escreveNoArquivo(FLAG);
    }
    //cria um arquivo independente do archive
    void CriaArquivo(char* nome){
        vector<Index*>::iterator varre;
        varre = indice.begin();
        while(varre != indice.end()){
            //veririca posição do arquivo no archive
            if(strcmp((*varre)->getNome(), nome) == 0){
                    setPonteiro((*varre)->getPosi());
                    printf("%d", getPonteiro());
            }
            varre++;
        }
        bool fim;
        char caractere = ' ';
        //insere dados do arquivo que estavam no archive para um arquivo proprio
        Archiver arq(nome);
        arq.criaArquivo();
        while(caractere != FLAG){
            caractere = leArquivo(fim);
            if(caractere != FLAG){
                arq.escreveNoArquivo(caractere);
            }
        }
        //retira o arquivo do archive
        deletaArquivo(nome);
        CopiaTodosOsArquivos();
    }
    //faz a copia do archive
    void CopiaTodosOsArquivos(){
        //esse bloco só existe para não gerar warning com o nome
        string nomeArquivoAux = "aux.cpy";
        char* nome = new char[100];
        strcpy(nome, nomeArquivoAux.c_str());
        //esse bloco só existe para não gerar warning com o nome
        //copia os arquivos com parametro ["existe" = true] para o novo archive
        vector<Index*>::iterator varre;
        varre = indice.begin();
        while(varre != indice.end()){
            if((*varre)->getExistencia() == true){
                    CopiaArquivo((*varre)->getPosi(), (*varre)->getNome());
            }
            varre++;
        }
        if(Arquivo(nome).verificaArquivoExiste()){
            substituiArquivo(nome);
        }else{//essa verificação valida se o arquivo foi efetivamente criado. Se não fio, cria o arquivo com uma flag
            Arquivo(nome).escreveNoArquivo(FLAG);
            substituiArquivo(nome);
        }
        //faz um novo indice
        indice.clear();
        pegaNomes();
    }
    //metodo que troca o nome do arquivo auxiliar
    //usa o systema
    //a string gerada pelos strcat é: [mv novoNome nome] sendo, novoNome o nome do arquivo auxiliar e
    // nome o nome do archive
    void substituiArquivo(char* novoNome){
        char* aux = new char[100];
        aux[0] = '\0';
        strcat(aux, "mv ");;
        strcat(aux, novoNome);
        strcat(aux, " ");
        strcat(aux, this->getNome());
        strcat(aux, "\0");
        system(aux);
    }
    //procura o archive com o mesmo nome dado por parametro e coloca a parametro existe = false
    //a busca é feita pelo indice na ram
    void deletaArquivo(char* nomeArq){
        if(verificaArquivoInserido(nomeArq)){
            vector<Index*>::iterator varre;
            varre = indice.begin();
            while(varre != indice.end()){
                if(strcmp((*varre)->getNome(), nomeArq) == 0){
                    (*varre)->setExistencia(false);
                }
                varre++;
            }
        }
    }
};