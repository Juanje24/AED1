#ifndef __TABLAHASH_H__
#define __TABLAHASH_H__
#include <list>
#include <string>
#define TAM 9839 // 1187

using namespace std;

class TablaHash
{
private:
    list<string> T[TAM];

    unsigned long nElem;
    string quitar_dieresis(string palabra);
    bool tiene_dieresis(string palabra);
    list<string> consulta_dieresis(string palabra);
    bool tiene_u(string palabra);

public:
    int hashfunction(string palabra);
    TablaHash();
    void vaciar();
    void insertar(string palabra);
    bool consultar(string palabra);
    unsigned long numElem(void);
    string cesar(string palabra);
};

#endif