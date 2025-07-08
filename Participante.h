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

int DarCedula(Participante participante);

Fecha DarFechaNacimiento(Participante participante);

int DarNroJugador(Participante participante);

string DarNombre(Participante participante);

string DarApellido(Participante participante);

string DarDeptoProcedencia(Participante participante);

int DarCantPartidasJugadas(Participante participante);

int DarCantPartidasGanadas(Participante participante);

void crearParticipante(Participante &participante, int nroJugador);

void desplegarParticipante(Participante participante);

void IncrementarCantPartidasGanadas(Participante &participante);

void IncrementarCantPartidasJugadas(Participante &participante);

#endif // PARTICIPANTE_H_INCLUDED
