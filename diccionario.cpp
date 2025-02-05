#include "diccionario.h"

using namespace std;

Diccionario::Diccionario(void)
{
}
TablaHash tabla;
ArbolTrie arbol;
void Diccionario::vaciar()
{
    tabla.vaciar();
    arbol.vaciar();
}
void Diccionario::insertar(const string &palabra)
{
    tabla.insertar(palabra);
    arbol.insertar(palabra);
}
bool Diccionario::consultar(const string &palabra)
{
    if (arbol.consultar(palabra))
    {

        return true;
    }
    return false;
}

int Diccionario::numElem()
{
    return arbol.numElem();
}
string Diccionario::cesar(const string &palabra)
{
    return tabla.cesar(palabra);
}
string Diccionario::alargapalabras(const string &prefijo)
{
    return arbol.alargapalabras(prefijo);
}
