#ifndef ENCUENTRO_H_INCLUDED
#define ENCUENTRO_H_INCLUDED

#include "boolean.h"

typedef struct { int nroEncuentro;
                 int cedulaParticipante1;
                 int cedulaParticipante2;
                 int cedulaGanador;
               } Encuentro;

///crea un encuentro
Encuentro crearEncuentro(int nuevoIdEncuentro, int cedulaParticipante1, int cedulaParticipante2);

///despliega por pantalla los datos del encuentro
void desplegarEncuentro(Encuentro encuentro);

///da el numero de encuentro
int DarNroEncuentro(Encuentro encuentro);

//obtener cedula participante 1
int DarCedulaParticipante1(Encuentro encuentro);

//obtener cedula participante 1
int DarCedulaParticipante2(Encuentro encuentro);

//obtener cedula participante ganador
int DarCedulaGanador(Encuentro encuentro);

#endif // ENCUENTRO_H_INCLUDED
