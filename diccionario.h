#ifndef __DICCIONARIO_H__
#define __DICCIONARIO_H__
#include <string>
#include <list>
#include "tablahash.h"
#include "ArbolTrie.h"
using namespace std;

class Diccionario
{
private:
    TablaHash tabla;
    ArbolTrie arbol;

public:
    Diccionario();
    void vaciar();
    void insertar(const string &palabra);
    bool consultar(const string &palabra);
    int numElem(void);
    string cesar(const string &palabra);
    string alargapalabras(const string &prefijo);
};

#endif
