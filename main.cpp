#include <iostream>
#include <string>
#include "diccionario.h"
using namespace std;

string normalizar(const string &cadena)
{
    string salida;
    for (unsigned i = 0; i < cadena.length(); i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            salida += cadena[i] - 32;
        }
        else if (cadena[i] == (char)0xC3)
        {
            if (cadena[i + 1] == (char)0xBC)
            {
                salida += cadena[i];
                i++;
                salida += (char)0x9C;
            }
            else if (cadena[i + 1] == (char)0xB1)
            {
                salida += cadena[i];
                i++;
                salida += (char)0x91;
            }
            else if (cadena[i + 1] == (char)0xA1 || cadena[i + 1] == (char)0x81)
            {
                salida += 'A';
                i++;
            }
            else if (cadena[i + 1] == (char)0xA9 || cadena[i + 1] == (char)0x89)
            {
                salida += 'E';
                i++;
            }
            else if (cadena[i + 1] == (char)0xAD || cadena[i + 1] == (char)0x8D)
            {
                salida += 'I';
                i++;
            }
            else if (cadena[i + 1] == (char)0xB3 || cadena[i + 1] == (char)0x93)
            {
                salida += 'O';
                i++;
            }
            else if (cadena[i + 1] == (char)0xBA || cadena[i + 1] == (char)0x9A)
            {
                salida += 'U';
                i++;
            }
            else
            {
                salida += cadena[i];
            }
        }
        else
        {
            salida += cadena[i];
        }
    }
    return salida;
}

Diccionario d;
void INSERTAR()
{
    int insertadas = 0;
    string palabra;
    cin >> palabra;

    while (palabra != "</insertar>")
    {
        palabra = normalizar(palabra);
        d.insertar(palabra);
        insertadas++;
        cin >> palabra;
    }
    cout << "Insertando: " << insertadas << " palabras" << endl;
    cout << "Total diccionario: " << d.numElem() << " palabras" << endl;
}

void VACIAR()
{
    d.vaciar();
    cout << "Vaciando" << endl;
    cout << "Total diccionario: " << d.numElem() << " palabras" << endl;
}
void BUSCAR()
{
    string palabra;
    cin >> palabra;
    palabra = normalizar(palabra);
    if (d.consultar(palabra) == true)
    {
        cout << "Buscando: " << palabra << " -> Encontrada" << endl;
    }
    else
    {
        cout << "Buscando: " << palabra << " -> No encontrada" << endl;
    }
}
void PARTIDAS()
{
    string palabra;
    cout << "Partidas: ";
    cin >> palabra;
    bool primero = true;
    while (palabra != "</partidas>")
    {
        if (!primero)
        {
            cout << " ";
        }
        cout << normalizar(palabra);
        cin >> palabra;
        primero = false;
    }
    cout << endl
         << "No implementado" << endl;
}
void ALOCADO()
{
    string palabra;
    cout << "Alocado: ";
    cin >> palabra;
    cout << normalizar(palabra) << endl;

    cout << "No implementado" << endl;
}
void CESAR()
{
    string palabra;
    cout << "César: ";
    cin >> palabra;
    string normalizada = normalizar(palabra);
    cout << normalizada << " ->" << d.cesar(normalizada) << endl;
}
void JUANAGRAMA()
{
    string palabra;
    cout << "Juanagrama: ";
    cin >> palabra;
    string normalizada = normalizar(palabra);
    cout << normalizada << endl
         << "No implementado" << endl;
}
void SACO()
{
    string palabra;
    string palabra2;
    cout << "Saco: ";
    cin >> palabra >> palabra2;
    cout << normalizar(palabra) << " " << normalizar(palabra2);
    cout << endl
         << "No implementado" << endl;
}
void CONSOME()
{
    string palabra;
    cout << "Consomé: ";
    cin >> palabra;
    cout << normalizar(palabra);
    cout << endl
         << "No implementado" << endl;
}
void ALARGA()
{
    string palabra;
    cout << "Alarga: ";
    cin >> palabra;
    cout << normalizar(palabra) << " ->" << d.alargapalabras(normalizar(palabra)) << endl;
}
void SALIR()
{
    cout << "Saliendo..." << endl;
    exit(0);
}

void Interprete(const string &comando)
{
    if (comando == "<insertar>")
    {
        INSERTAR();
    }
    else if (comando == "<vaciar>")
    {
        VACIAR();
    }
    else if (comando == "<buscar>")
    {
        BUSCAR();
    }
    else if (comando == "<partidas>")
    {
        PARTIDAS();
    }
    else if (comando == "<alocado>")
    {
        ALOCADO();
    }
    else if (comando == "<césar>" || comando == "<cÉsar>")
    {
        CESAR();
    }
    else if (comando == "<juanagra>")
    {
        JUANAGRAMA();
    }
    else if (comando == "<saco>")
    {
        SACO();
    }
    else if (comando == "<consomé>" || comando == "<consomÉ>")
    {
        CONSOME();
    }
    else if (comando == "<alarga>")
    {
        ALARGA();
    }
    else if (comando == "<exit>")
    {
        SALIR();
    }
}

int main()
{

    string comando;
    while (cin >> comando)
    {
        Interprete(comando);
    }

    return 0;
}
