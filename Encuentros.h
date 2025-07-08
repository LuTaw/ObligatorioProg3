#ifndef ENCUENTROS_H_INCLUDED
#define ENCUENTROS_H_INCLUDED

#include "Encuentro.h"
#include "Participantes.h"

const int CantMaximaPartidas = CantParticipantes * (CantParticipantes  - 1) / 2;
typedef struct { Encuentro encuentro[CantMaximaPartidas];
                 int tope;
               } Encuentros;

// Crear:   Secuencia
// Crea una secuencia vac�a.
void CrearEncuentros(Encuentros &encuentros);


// EsVac�a : Secuencia -> Boolean
// Determina si la secuencia est� vac�a o no.
boolean EsVacia(Encuentros encuentros);

// Largo: Secuencia -> N
// Devuelve la cantidad de elementos de la secuencia.
int Largo(Encuentros encuentros);

// K-�simo: Secuencia x N -> T
// Devuelve el elemento que ocupa la posici�n K de la secuencia.
// Precondici�n: El largo de la secuencia es mayor o igual a K.
Encuentro Kesimo(Encuentros encuentros, int pos);

//inserta el encuentro dentro del arreglo Encuentros
void insertarEncuentroFinal(Encuentros &encuentros, Encuentro enc);

//despliega por pantalla todos los encuentros
void desplegarEncuentros(Encuentros encuentros);

//determina si el torneo ha finalizado
boolean torneoTerminado(Encuentros encuentros);

#endif // ENCUENTROS_H_INCLUDED
