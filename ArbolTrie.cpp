#include "ArbolTrie.h"
#include <list>
// Nodo:
ArbolTrie::NodoTrie::NodoTrie()
{
    car = '?';
    siguiente = nullptr;
    puntero = nullptr;
}
ArbolTrie::NodoTrie::NodoTrie(char c, NodoTrie *sig, NodoTrie *ptr)
{
    car = c;
    siguiente = sig;
    puntero = ptr;
}

ArbolTrie::NodoTrie::~NodoTrie()
{
    delete this->puntero;
    delete this->siguiente;
}

void ArbolTrie::NodoTrie::insertar(char caracter)
{

    NodoTrie *tmp = this;
    while (tmp->siguiente != nullptr && tmp->siguiente->car < caracter)
    {
        tmp = tmp->siguiente;
    }
    if (tmp->siguiente == nullptr || tmp->siguiente->car != caracter)
    {

        tmp->siguiente = new NodoTrie(caracter, tmp->siguiente, new NodoTrie);
    }
}
ArbolTrie::NodoTrie *ArbolTrie::NodoTrie::consultar(char caracter)
{
    NodoTrie *tmp = this->siguiente;
    while (tmp != nullptr && tmp->car < caracter)
    {
        tmp = tmp->siguiente;
    }
    if (tmp != nullptr && tmp->car == caracter)
    {
        return tmp->puntero;
    }
    else
    {
        return nullptr;
    }
}

void ArbolTrie::NodoTrie::PonMarca()
{
    car = '$';
}

void ArbolTrie::NodoTrie::QuitaMarca()
{
    car = '?';
}

bool ArbolTrie::NodoTrie::HayMarca()
{
    return car == '$';
}

// Arbol:
ArbolTrie::ArbolTrie()
{
    nElem = 0;
    raiz = new NodoTrie;
}

ArbolTrie::~ArbolTrie()
{
    delete raiz;
}
void ArbolTrie::insertar(const string &cadena)
{
    NodoTrie *pos;
    int i = 0;
    pos = raiz;
    if (!consultar(cadena))
    {
        while (cadena[i] != '\0')
        {

            if (pos->consultar(cadena[i]) == nullptr)
            {

                pos->insertar(cadena[i]);
            }
            pos = pos->consultar(cadena[i]);
            i++;
        }
        pos->PonMarca();
        nElem++;
    }
}
bool ArbolTrie::consultar(const string &cadena)
{
    NodoTrie *pos;
    int i = 0;
    pos = raiz;
    while (cadena[i] != '\0' && pos != nullptr)
    {

        pos = pos->consultar(cadena[i]);
        i++;
    }
    if (pos != nullptr && pos->HayMarca() && cadena[i] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}
void ArbolTrie::vaciar()
{
    delete raiz;
    raiz = new NodoTrie;
    nElem = 0;
}
int ArbolTrie::numElem()
{
    return nElem;
}
int ArbolTrie::longitud(const string &palabra)
{
    int longitud = 0;
    for (int i = 0; i < palabra.length(); i++)
    {
        if (palabra[i] != (char)0xC3)
        {
            longitud++;
        }
    }
    return longitud;
}
string ArbolTrie::alargapalabras(const string &prefijo)
{
    NodoTrie *actual = raiz;

    for (int i = 0; i < prefijo.length(); i++)
    {

        actual = actual->consultar(prefijo[i]);
        if (actual == nullptr)
        {
            return "";
        }
    }
    string texto = buscarPalabraMasLarga(actual, prefijo);
    string resultado = "";
    if (texto.length() > 0)
    {
        resultado += " ";
        resultado += texto;
    }
    return resultado;
}

string ArbolTrie::buscarPalabraMasLarga(NodoTrie *nodo, const string &palabraActual)
{
    list<string> palabras;
    int longmax;
    if (nodo == nullptr)
    {
        return palabraActual;
    }

    string palabraLarga = "";
    if (nodo->HayMarca() && nodo->siguiente == nullptr)
    {
        return palabraActual;
    }

    NodoTrie *tmp = nodo->siguiente; // Evitar la cabecera
    while (tmp != nullptr)
    {
        string palabraEncontrada = buscarPalabraMasLarga(tmp->puntero, palabraActual + tmp->car);

        if (longitud(palabraEncontrada) >= longitud(palabraLarga)) // palabraEncontrada.length() > palabraLarga.length())
        {
            longmax = longitud(palabraEncontrada);
            palabraLarga = palabraEncontrada;
            palabras.push_back(palabraLarga);
        }

        tmp = tmp->siguiente;
    }
    palabras.sort();
    string solucion;
    list<string>::iterator itLista;
    itLista = palabras.begin();
    while (longitud(*itLista) != longmax && itLista != palabras.end())
    {
        itLista++;
    }
    solucion = *itLista;
    return solucion;
}
