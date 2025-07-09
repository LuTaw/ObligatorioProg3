#include "Encuentros.h"

// Crear:   Secuencia
// Crea una secuencia vac�a.
void CrearEncuentros(Encuentros &encuentros)
{
    encuentros.tope = 0;
}

// EsVac�a : Secuencia -> Boolean
// Determina si la secuencia est� vac�a o no.
boolean EsVacia(Encuentros encuentros)
{
    boolean es = FALSE;
    if (encuentros.tope == 0)
        es = TRUE;

    return es;
}

// Largo: Secuencia -> N
// Devuelve la cantidad de elementos de la secuencia.
int Largo(Encuentros encuentros)
{
    return encuentros.tope;
}

// K-�simo: Secuencia x N -> T
// Devuelve el elemento que ocupa la posici�n K de la secuencia.
// Precondici�n: El largo de la secuencia es mayor o igual a K.
Encuentro Kesimo(Encuentros encuentros, int pos)
{
    return encuentros.encuentro[pos];
}

//inserta el encuentro dentro del arreglo Encuentros
void insertarEncuentroFinal(Encuentros &encuentros, Encuentro enc)
{
    if(encuentros.tope < CantMaximaPartidas) {
        encuentros.encuentro[encuentros.tope] = enc;
        encuentros.tope++;
    } else {
        printf("Ocurrio un error, el arreglo esta lleno.");
    }
}

// despliega por pantalla todos los encuentros
void desplegarEncuentros(Encuentros encuentros)
{
    int i = 0;
    while(i < Largo(encuentros)) {
        desplegarEncuentro(encuentros.encuentro[i]);
        i++;
    }
}

//determina si el torneo ha finalizado
boolean torneoTerminado(Encuentros encuentros)
{
    boolean termino = FALSE;
    if (encuentros.tope == CantMaximaPartidas)
        termino = TRUE;

    return termino;
}
