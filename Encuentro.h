#ifndef ENCUENTRO_H_INCLUDED
#define ENCUENTRO_H_INCLUDED

#include "boolean.h"

typedef struct { int nroEncuentro;
                 int cedulaParticipante1;
                 int cedulaParticipante2;
                 int cedulaGanador;
               } Encuentro;

// crea un encuentro
// Precondicion:
//      - Las cédulas de ambos participantes deben corresponder a jugadores registrados en el torneo.
//      - Las cédulas de los jugadores deben ser distintas.
//      - No debe existir ya un encuentro registrado entre esos dos jugadores.
Encuentro crearEncuentro(int nuevoIdEncuentro, int cedulaParticipante1, int cedulaParticipante2);

// despliega por pantalla los datos del encuentro
void desplegarEncuentro(Encuentro encuentro);

// da el numero de encuentro
int darNroEncuentro(Encuentro encuentro);

// obtener cedula participante 1
int darCedulaParticipante1(Encuentro encuentro);

// obtener cedula participante 2
int darCedulaParticipante2(Encuentro encuentro);

// obtener cedula participante ganador
int darCedulaGanador(Encuentro encuentro);

#endif // ENCUENTRO_H_INCLUDED
