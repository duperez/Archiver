class Index{
private:
    char* nome;
    int posi;
    bool existe;
public:
    //construtor do index, recebe o nome e a posição do arquivo no archive
    Index(char* nome, int posi){
        this->nome = nome;
        this->posi = posi;
        existe = true;
    }
    //deleta o index (para o usuario)
    void DeletaIndex(){
        this->posi = -1;
        this->existe = false;
    }
    //coloca uma nova posição 
    void setPosi(int posi){
        this->posi = posi;
    }
    //retorna o nome
    char* getNome(){
        return this->nome;
    }
    //retorna a posição
    int getPosi(){
        return this->posi;
    }
    //retorna se ele existe ou não
    bool getExistencia(){
        return existe;
    }
    //muda a existencia da posição
    bool setExistencia(bool existe){
        this->existe = existe;
    }
};