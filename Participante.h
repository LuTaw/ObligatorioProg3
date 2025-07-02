#ifndef PARTICIPANTE_H_INCLUDED
#define PARTICIPANTE_H_INCLUDED
#include "Fecha.h"
#include "string.h"

typdef struct { int cedula;
                Fecha fechaNacimiento;
                int nroJugador;
                string nombre;
                string apellido;
                string deptoProcedencia;
                int cantPartidasJugadas;
                intCantPartidasGanadas;
              } Participante;

int DarCedula(Participante participante);
Fecha DarFechaNacimiento(Participante participante);
int DarNroJugador(Participante participante);
string DarNombre(Participante participante);
string DarApellido(Participante participante);
string DarDeptoProcedencia(Participante participante);
int DarCantPartidasJugadas(Participante participante);
int DarCantPartidasGanadas(Participante participante);
void crearParticipante(Participante &participante);
void desplegarParticipante(Participante participante);



#endif // PARTICIPANTE_H_INCLUDED
