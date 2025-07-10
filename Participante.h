#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include "Fecha.h"
#include "string.h"

typedef struct { int cedula;
                Fecha fechaNacimiento;
                int nroJugador;
                string nombre;
                string apellido;
                string deptoProcedencia;
                int cantPartidasJugadas;
                int cantPartidasGanadas;
              } Participante;

int darCedula(Participante participante);

Fecha darFechaNacimiento(Participante participante);

int darNroJugador(Participante participante);

void darNombre(Participante participante,string &nombre);

void darApellido(Participante participante,string &apellido);

void darDeptoProcedencia(Participante participante,string &depto);

int darCantPartidasJugadas(Participante participante);

int darCantPartidasGanadas(Participante participante);

void crearParticipante(Participante &participante, int nroJugador);

void desplegarParticipante(Participante participante);

// incrementa en uno la cantidad de partidas ganadas para un participante.
void incrementarCantPartidasGanadas(Participante &participante);

// incrementa en uno la cantidad de partidas jugadas para un participante.
void incrementarCantPartidasJugadas(Participante &participante);

#endif // PARTICIPANTE_H_INCLUDED
