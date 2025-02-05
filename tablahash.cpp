#include "tablahash.h"
#include <string>
#include <list>

using namespace std;

int TablaHash::hashfunction(string palabra)
{
    palabra = quitar_dieresis(palabra);
    unsigned long long indice = 0;
    int i = 0;
    while (i < palabra.size() - 1)
    {

        indice += 5381 * (int)palabra[i] * 1217 * (int)palabra[i + 1];
        i += 2;
    }
    if (i < palabra.size())
    {
        indice += 5381 * (int)palabra[i];
    }
    return (indice % TAM);
}

TablaHash::TablaHash(void)
{

    nElem = 0;
}
void TablaHash::vaciar()
{
    for (int i = 0; i < TAM; i++)
    {
        T[i].clear();
    }
    nElem = 0;
}
string TablaHash::quitar_dieresis(string palabra)
{
    string cesar = "";
    for (int i = 0; i < palabra.length(); i++)
    {

        if (palabra[i] == (char)0xC3 && palabra[i + 1] == (char)0x9C) // quitar dieresis
        {
            cesar += 'U';
            i++;
        }
        else
        {
            cesar += palabra[i];
        }
    }
    return cesar;
}
bool TablaHash::tiene_dieresis(string palabra)
{
    for (int i = 0; i < palabra.length(); i++)
    {

        if (palabra[i] == (char)0xC3 && palabra[i + 1] == (char)0x9C)
        {
            return true;
        }
    }
    return false;
}
void TablaHash::insertar(string palabra)
{
    int indice;
    string copia = palabra;
    if (tiene_dieresis(palabra))
    {
        indice = hashfunction(quitar_dieresis(copia));
    }
    else
    {
        indice = hashfunction(palabra);
    }

    list<string>::iterator itLista;
    itLista = T[indice].begin();
    while (itLista != T[indice].end() && *itLista < palabra)
    {
        itLista++;
    }
    if (itLista == T[indice].end() || *itLista != palabra)
    {
        T[indice].insert(itLista, palabra);
        nElem++;
    }
}

bool TablaHash::consultar(string palabra)
{
    int indice = hashfunction(palabra);
    list<string>::iterator itLista;
    itLista = T[indice].begin();
    while (itLista != T[indice].end())
    {
        if (*itLista == palabra)
        {
            return true;
        }
        itLista++;
    }
    return false;
}

list<string> TablaHash::consulta_dieresis(string palabra)
{
    int indice = hashfunction(quitar_dieresis(palabra));
    list<string> lista;
    list<string>::iterator it = T[indice].begin();
    string copia = "";
    while (it != T[indice].end())
    {
        copia = *it;
        if (quitar_dieresis(copia) == palabra)
        {
            lista.push_back(*it);
        }
        it++;
    }
    return lista;
}

bool TablaHash::tiene_u(string palabra)
{
    for (int i = 0; i < palabra.length(); i++)
    {
        if (palabra[i] == 'U')
        {
            return true;
        }
    }
    return false;
}

string TablaHash::cesar(string palabra)
{
    string cesar = quitar_dieresis(palabra);

    list<string> soluciones;
    string nueva = cesar; // LLEVA CADA CESAR
    string copia;         // DONDE SE GUARDA EL CESAR NUEVO
    for (int i = 0; i < 27; i++)
    {
        copia = "";
        for (int j = 0; j < nueva.length(); j++)
        {
            if (nueva[j] == 'N')
            {
                copia += (char)0xC3;
                copia += (char)0x91;
            }
            else if (nueva[j] == (char)0xC3 && nueva[j + 1] == (char)0x91)
            {
                copia += 'O';
                j++;
            }
            else if (nueva[j] == 'Z')
            {
                copia += 'A';
            }

            else
            {
                copia += nueva[j] + 1;
            }
        }
        if (tiene_u(copia))
        {

            list<string> lista = consulta_dieresis(copia);
            lista.sort();
            if (lista.size() > 0)
            {
                list<string>::iterator it2 = lista.begin();
                while (it2 != lista.end())
                {

                    soluciones.push_back(*it2);
                    it2++;
                }
            }
        }
        else if (consultar(copia))
        {
            soluciones.push_back(copia);
        }

        nueva = copia;
    }

    soluciones.sort();
    string texto;
    list<string>::iterator it2;
    list<string>::iterator itLista = soluciones.begin();
    if (soluciones.size() == 0)
    {
        return "";
    }
    else
    {
        texto += " "; // Espacio de detrás de la flecha
    }
    while (itLista != soluciones.end())
    {
        texto += *itLista;
        it2 = itLista++;
        if (it2 != soluciones.end())
        {
            texto += " ";
        }
    }
    if (texto[texto.length() - 1] == ' ')
    {
        texto.erase(texto.length() - 1);
    }
    return texto;
}
unsigned long TablaHash::numElem(void)
{
    return nElem;
}