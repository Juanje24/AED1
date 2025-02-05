#ifndef __ARBOLTRIE_H__
#define __ARBOLTRIE_H__
#include <list>
#include <string>

using namespace std;
class NodoTrie;
class ArbolTrie
{
private:
    class NodoTrie
    {
        friend class ArbolTrie;

    private:
        char car;
        NodoTrie *siguiente;
        NodoTrie *puntero;

    public:
        NodoTrie();
        NodoTrie(char c, NodoTrie *sig, NodoTrie *ptr);
        ~NodoTrie();
        void insertar(char caracter);
        NodoTrie *consultar(char caracter);
        void PonMarca();
        void QuitaMarca();
        bool HayMarca();
    };

    NodoTrie *raiz;
    int nElem;
    string buscarPalabraMasLarga(NodoTrie *nodo, const string &palabraActual);
    int longitud(const string &palabra); // calcula la longitud, sin contar caracteres de más de un byte

public:
    ArbolTrie();
    ~ArbolTrie();
    void insertar(const string &palabra);
    void vaciar();
    bool consultar(const string &palabra);
    int numElem(void);
    string alargapalabras(const string &prefijo);
};

#endif