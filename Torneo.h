#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED
#include "Encuentros.h"

const int CantParticipantes = 10;
typedef int Torneo[CantParticipantes][CantParticipantes];

// Crear:   Grafo
// Crea un grafo vacío
void CrearTorneo(Torneo &torneo);

// PerteneceVertice : Grafo x V  Boolean
// Determina si en el grafo existe el vértice especificado.
boolean PerteneceVertice(Torneo torneo, int v);

// PerteneceArista : Grafo x A  Boolean
// Determina si en el grafo existe la arista especificada.
boolean PerteneceArista(Torneo torneo, int v, int u);

// InsertarArista : Grafo x A  Grafo
// Inserta la nueva arista al grafo.
// Precondición: la arista no pertenece al grafo.
void InsertarArista(Torneo &torneo, int u, int v);

// GradoVertice : Grafo x V  Entero
// Devuelve el grado del vértice especificado.
// Precondición: el vértice pertenece al grafo.
int GradoVertice(Torneo torneo, int u);

///determina si pertenecen
boolean pertencenMismaSubDivision(Torneo torneo, int ced1, int ced2);

#endif // TORNEO_H_INCLUDED
