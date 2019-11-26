#include "Camiones.h"

int Camiones :: dispersion(String mat)
{
    String aux;
    int num = aux.SumaAscii(mat);
    return (num % B);
}

void Camiones :: crearLista(Nodo * &L)
{
    L = NULL;
}

void Camiones :: destruirLista (Nodo * &L)
{
    Nodo * aux = L;
    while (aux != NULL)
    {
        L = aux->sig;
        delete(aux);
        aux = L;
    }
    L = aux;
}

bool Camiones :: perteneceLista (Nodo * L, String mat)
{
    bool existe = false;
    while (!existe && L != NULL)
    {
        if (L->info->getMatricula() == mat)
            existe = true;
        else
            L = L->sig;
    }
    return existe;
}

void Camiones :: insFrontEnLista (Nodo * &L, Camion * c)
{
    Nodo * aux = new Nodo;
    aux->info = c;
    aux->sig = L;
    L = aux;
}

Camion * Camiones :: obtenerEnLista(Nodo * L, String mat)
{
    while(L->info->getMatricula() != mat)
        L = L->sig;
    return (L->info);
}

Camiones :: Camiones()
{
    for (int i=0; i < B; i++)
        crearLista(Hash[i]);
}

Camiones :: ~Camiones()
{
    for(int i=0; i < B; i++)
        destruirLista(Hash[i]);
}

bool Camiones :: Member(String mat)
{
    int cubeta = dispersion(mat);
    return perteneceLista(Hash[cubeta], mat);
}

void Camiones :: Insert(Camion * c)
{
    String mat = c->getMatricula();
    int cubeta = dispersion(mat);
    insFrontEnLista(Hash[cubeta],c);
}

Camion * Camiones :: Find(String mat)
{
    int cubeta = dispersion(mat);
    return obtenerEnLista(Hash[cubeta], mat);
}