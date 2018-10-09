#include <iostream>
#include "Archiver.cpp"
using namespace std;

int main()
{
    Archiver* aux = new Archiver();
    aux->NovoArchive("banana.txt");
    return 0;
}
