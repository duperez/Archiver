#include <iostream>
#include "Archiver.cpp"
using namespace std;

int main()
{
    Archiver* aux = new Archiver();
    aux->NovoArchive("abcdefghijk.txt", "abcedfghijklmnop");
    return 0;
}
