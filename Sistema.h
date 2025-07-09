#ifndef SISTEMA_H_INCLUDED
#define SISTEMA_H_INCLUDED

#include "Torneo.h"

void registrarJugador(Torneo &torneo, Participantes &participantes);
void desplegarJugadoresRegistrados(Participantes participantes);
void desplegarJugador(Participantes participantes);
void registrarEncuentro(Torneo &torneo, Participantes &participantes, Encuentros &encuentros);
void desplegarTodasPartidasAscendente(Encuentros encuentros);
void cantParticipantesDadoFecha(Participantes participantes);
void determinarMismaSubDivision(Torneo torneo, Participantes participantes);
void obtenerGanador(Torneo torneo, Participantes participantes, Encuentros encuentros);

#endif // SISTEMA_H_INCLUDED
