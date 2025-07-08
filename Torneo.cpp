#include "Torneo.h"
#include "Encuentros.h"

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

// PerteneceVertice : Grafo x V  Boolean
// Determina si en el grafo existe el vértice especificado.
boolean PerteneceVertice(Torneo torneo, int v)
{
    boolean encontro = FALSE;
    int i = 0;
    while(!encontro && i < CantParticipantes) {
        if (i == v)
            encontro = TRUE;
        else
            i++;
    }

    return encontro;
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

void DFSMismaSubDivision(Torneo torneo, int actual, boolean visitado[CantParticipantes], int nroJugador2)
{
    visitado[actual] = TRUE;
    int i = 0;
    while(!visitado[nroJugador2] && i < CantParticipantes) {
        if(torneo[actual][i] == 1) {
            if(!visitado[i])
                DFSMismaSubDivision(torneo, i, visitado, nroJugador2);
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
        DFSMismaSubDivision(torneo, nroJugador1, visitado, nroJugador2);

        if (visitado[nroJugador1] && visitado[nroJugador2])
            pertenecen = TRUE;
    }

    return pertenecen;
}

void registrarEncuentro(Torneo &torneo, Participantes &participantes, Encuentros &encuentros)
{
    if (!torneoTerminado(encuentros)) {
        boolean selecciono  = FALSE;
        while(!selecciono) {
            Participante participante1 = Find(participantes, seleccionarParticipante(participantes));
            Participante participante2 = Find(participantes, seleccionarParticipante(participantes));
            if (DarCedula(participante1) != DarCedula(participante2)) {
                int nroJugador1 = DarNroJugador(participante1);
                int nroJugador2 = DarNroJugador(participante2);
                if(!PerteneceArista(torneo, nroJugador1, nroJugador2)) {
                    selecciono = TRUE;
                    InsertarArista(torneo, nroJugador1, nroJugador2);
                    int nuevoIdEncuentro = Largo(encuentros) + 1;
                    Encuentro encuentro = crearEncuentro(nuevoIdEncuentro, DarCedula(participante1), DarCedula(participante2));
                    insertarEncuentroFinal(encuentros, encuentro);
                    int cedulaGanador = DarCedulaGanador(encuentro);
                    if (cedulaGanador == DarCedula(participante1)) {
                        IncrementarCantPartidasGanadas(participante1);
                    } else {
                        IncrementarCantPartidasGanadas(participante2);
                    }
                    IncrementarCantPartidasJugadas(participante1);
                    IncrementarCantPartidasJugadas(participante2);
                    Modify(participantes, participante1);
                    Modify(participantes, participante2);
                } else {
                    printf("Los jugadores seleccionados ya jugaron una partida entre ellos, deben ser jugadores que no hayan jugado una partida aun. \n\n\n");
                }
            }
            else
                printf("Debe seleccionar participantes diferentes. \n\n\n");
        }
    } else {
        printf("El torneo ha finalizado, por lo que no se pueden ingresar mas encuentros. \n\n\n");
    }
}

void determinarMismaSubDivision(Torneo torneo, Participantes participantes)
{
    boolean selecciono  = FALSE;
    while(!selecciono) {
        Participante participante1 = Find(participantes, seleccionarParticipante(participantes));
        Participante participante2 = Find(participantes, seleccionarParticipante(participantes));
        if (DarCedula(participante1) != DarCedula(participante2)) {
            selecciono = TRUE;
            boolean pertenecen = pertencenMismaSubDivision(torneo, DarNroJugador(participante1), DarNroJugador(participante2));
            if(pertenecen)
                printf("Los jugadores seleccionadas pertenecen a la misma subdivision. \n\n\n");
            else
                printf("Los jugadores seleccionadas NO pertenecen a la misma subdivision. \n\n\n");
        } else {
            printf("Debe seleccionar participantes diferentes. \n\n");
        }
    }
}

void obtenerGanador(Torneo torneo, Participantes participantes, Encuentros encuentros)
{
    if (torneoTerminado(encuentros)) {
        desplegarJugadoresGanadores(participantes);
    } else {
        printf("El torneo aun no ha finalizado por lo que no se pueden determinar aun los ganadores del torneo. \n\n\n");
    }
}

// 	1. Registrar los datos de los N jugadores que participan del torneo. Esta operación se ejecutará
//	solamente una vez, al comienzo del torneo. Los números de jugador irán siendo asignados por
//	orden de registro (el primer jugador tendrá el número 0, el siguiente el 1 y así sucesivamente).
//	Se debe verificar que cada cédula ingresada efectivamente sea única dentro del sistema.
void registrarJugador(Torneo &torneo, Participantes &participantes)
{
    int cantJugadoresActual = 0;
    while (cantJugadoresActual < CantParticipantes) {
        boolean participanteValido = FALSE;
        while(!participanteValido) {
            Participante participante;
            crearParticipante(participante, cantJugadoresActual);
            if (!Member(participantes, DarCedula(participante))) {
                Insert(participantes, participante);
                cantJugadoresActual++;
                participanteValido = TRUE;
                printf("\n\n Participante ingresado correctamente!! \n\n");
                printf("Restan %d participantes por ingresar... \n\n", CantParticipantes - cantJugadoresActual);
            } else {
                printf("\n\n Participante no valido, ya existe uno con la misma CI, ingrese los datos nuevamente \n\n");
            }
        }
    }
}

void desplegarTodasPartidasAscendente(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void cantParticipantesSegunFecha(Torneo torneo)
{
    printf("Proximamente a implementar....");
}


