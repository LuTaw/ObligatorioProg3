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

// devuelve la cedula de un participante dado.
int darCedula(Participante participante);

// devuelve la fecha de nacimiento del participante dado.
Fecha darFechaNacimiento(Participante participante);

// devuelve el numero de jugador asignado al participante en el momento de la inscripcion al torneo.
int darNroJugador(Participante participante);

// obtiene el nombre del participante dado y lo almacena en la variable nombre pasada por referencia.
void darNombre(Participante participante, string &nombre);

// obtiene el apellido del participante dado y lo almacena en la variable apellido pasada por referencia.
void darApellido(Participante participante, string &apellido);

// obtiene el departamento de procedencia del participante dado y lo almacena en la variable depto pasada por referencia.
void darDeptoProcedencia(Participante participante, string &depto);

// devuelve la cantidad de partidas jugadas de un participante dado.
int darCantPartidasJugadas(Participante participante);

// devuelve la cantidad de partidas ganadas de un participante dado.
int darCantPartidasGanadas(Participante participante);

// interactua con el usuario mediante la consola para crear el participante
void crearParticipante(Participante &participante, int nroJugador);

// despliega el participante en pantalla.
void desplegarParticipante(Participante participante);

// incrementa en uno la cantidad de partidas ganadas para un participante.
void incrementarCantPartidasGanadas(Participante &participante);

// incrementa en uno la cantidad de partidas jugadas para un participante.
void incrementarCantPartidasJugadas(Participante &participante);

#endif // PARTICIPANTE_H_INCLUDED
