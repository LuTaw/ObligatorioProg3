#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include "Torneo.h"

// este metodo solo se puede ejecutar al comienzo del torneo.
// los numeros de jugador iran siendo asignados por orden de registro, iniciando en 0.
// la cedula no debe existir previamente en el sistema.
void registrarJugador(Torneo &torneo, Participantes &participantes);

// Listar por pantalla los datos de todos los jugadores registrados en el torneo.
// No se pide ningún orden en particular para este listado.
void desplegarJugadoresRegistrados(Participantes participantes);

// se debe pedir una cedula por pantalla
// luego a partir de esa cedula, que se debe verificar que exista previamente se listan los datos del jugador incluyendo las partidas jugadas hasta el momento.
// Las partidas deberán listarse ordenadas en forma ascendente por número de partida.
void desplegarJugador(Participantes participantes);

// obtener el idDelUltimoEncuentroRegistrado (que va a ser el tope), utilizar ese ID + 1 para ingresar el siguiente encuentro
// IMPORTANTE: solo puedo registrar un encuentro si el torneo no termino.
// solicitar que se ingrese una CI por consola, debe corresponder a un participante
// solicitar que se ingrese otra CI valida por consola, verificar que no exista ya un encuentro entre ambos
// solicitar indique cual es la ganadora, debe corresponder a alguna de las dos CIs previamente ingresadas
// Luego InsertarArista, crearEncuentro, insertarEncuentroFinal, incrementar partidas jugadas para ambos, y partidas ganadas para el ganador
// por ultimo actualizar los datos de los participantes
void registrarEncuentro(Torneo &torneo, Participantes &participantes, Encuentros &encuentros);

// despliega en pantalla todas los encuentros del torneo registrados hasta el momento en el sistema de forma ascendente.
void desplegarTodasPartidasAscendente(Encuentros encuentros);

// se pide se ingrese una fecha por consola, se verifica que es fecha valida
// se obtienen las cantidades correspondientes de acuerdo a la fecha ingresada y se despliegan las cantidades en pantalla.
void cantParticipantesSegunFecha(Participantes participantes);

// solicitar que se ingrese una CI por consola, debe corresponder a un participante
// solicitar que se ingrese otra CI valida por consola, obtener los numeros de jugador para cada uno
// luego determinar si existe un camino entre esos dos vertices
// si existe camino, entonces pertenecen a la misma sub-división, en caso contrario no, desplegar el resultado en pantalla.
void determinarMismaSubDivision(Torneo torneo, Participantes participantes);

// Primero determina si ya termino el partido, para ello verificamos que el tope del arreglo sea igual al CantMaximaPartidas
// Si no termino: imprimo mensaje que no termino y termina la ejecucion
// Si termino: obtenego el/los ganador/es y los listo en pantalla con la cantidad de partidos ganados (esto ultimo solo para verificar que el algoritmo esta funcionando correctamente)
void obtenerGanador(Torneo torneo, Participantes participantes, Encuentros encuentros);

#endif // SISTEMA_H_INCLUDED
