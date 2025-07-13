#include "Torneo.h"

// Crear:   Grafo
// Crea un grafo vacío
void CrearTorneo(Torneo &torneo)
{
    for(int i = 0; i < CantParticipantes; i++) {
        for(int j = 0; j < CantParticipantes; j++) {
            torneo[i][j] = 0;
        }
    }
}

// PerteneceArista : Grafo x A  Boolean
// Determina si en el grafo existe la arista especificada.
boolean PerteneceArista(Torneo torneo, int v, int u)
{
    boolean pertence = FALSE;
    if (torneo[v][u] == 1 || torneo[u][v] == 1)
        pertence = TRUE;

    return pertence;
}

// InsertarArista : Grafo x A  Grafo
// Inserta la nueva arista al grafo.
// Precondición: la arista no pertenece al grafo.
void InsertarArista(Torneo &torneo, int u, int v)
{
    torneo[u][v] = 1;
    torneo[v][u] = 1;
}

// GradoVertice : Grafo x V  Entero
// Devuelve el grado del vértice especificado.
// Precondición: el vértice pertenece al grafo.
int GradoVertice(Torneo torneo, int u)
{
    int grado = 0;
    for(int i = 0; i < CantParticipantes; i++) {
        if (torneo[u][i] == 1)
            grado++;
    }

    return grado;
}

void dfsMismaSubDivision(Torneo torneo, int actual, boolean visitado[CantParticipantes], int nroJugador2)
{
    visitado[actual] = TRUE;
    int i = 0;
    while(!visitado[nroJugador2] && i < CantParticipantes) {
        if(torneo[actual][i] == 1) {
            if(!visitado[i])
                dfsMismaSubDivision(torneo, i, visitado, nroJugador2);
        }
        i++;
    }
}

// determina si pertenecen a la misma subDivision, es decir si existe al menos un camino entre nroJugador1 y nroJugador2
boolean pertencenMismaSubDivision(Torneo torneo, int nroJugador1, int nroJugador2)
{
    boolean pertenecen = FALSE;
    if (PerteneceArista(torneo, nroJugador1, nroJugador2))
        pertenecen = TRUE;
    else {
        boolean visitado[CantParticipantes];
        for(int i = 0; i < CantParticipantes; i++) {
            visitado[i] = FALSE;
        }
        dfsMismaSubDivision(torneo, nroJugador1, visitado, nroJugador2);

        if (visitado[nroJugador1] && visitado[nroJugador2])
            pertenecen = TRUE;
    }

    return pertenecen;
}
