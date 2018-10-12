#include <iostream>
#include "Archiver.cpp"
using namespace std;

int main()
{
    Archiver* aux = new Archiver();
    aux->NovoArchive("ana.txt", "aaa");
    return 0;
}
