#include "Participante.h"

// devuelve la cedula de un participante dado.
int darCedula(Participante participante)
{
    return participante.cedula;
}

// devuelve la fecha de nacimiento del participante dado.
Fecha darFechaNacimiento(Participante participante)
{
    return participante.fechaNacimiento;
}

// devuelve el numero de jugador asignado al participante en el momento de la inscripcion al torneo.
int darNroJugador(Participante participante)
{
    return participante.nroJugador;
}

// obtiene el nombre del participante dado y lo almacena en la variable nombre pasada por referencia.
void darNombre(Participante participante,string &nombre){
    strcrear(nombre);
    return strcop(nombre, participante.nombre);
}

// obtiene el apellido del participante dado y lo almacena en la variable apellido pasada por referencia.
void darApellido(Participante participante,string &apellido){
    strcrear(apellido);
    return strcop(apellido, participante.apellido);
}

// obtiene el departamento de procedencia del participante dado y lo almacena en la variable depto pasada por referencia.
int darCantPartidasJugadas(Participante participante)
{
    return participante.cantPartidasJugadas;
}

// devuelve la cantidad de partidas jugadas de un participante dado.
int darCantPartidasGanadas(Participante participante)
{
    return participante.cantPartidasGanadas;
}

// devuelve la cantidad de partidas ganadas de un participante dado.
void darDeptoProcedencia(Participante participante,string &depto){
    strcrear(depto);
    return strcop(depto, participante.deptoProcedencia);
}

// interactua con el usuario mediante la consola para crear el participante
void crearParticipante(Participante &participante, int nroJugador){
    printf(" Ingrese su numero de cedula: ");
    scanf("%d", &participante.cedula);
    printf(" Ingrese su fecha de nacimiento: ");
    crearFecha(participante.fechaNacimiento);
    printf(" Ingrese el nombre: ");
    strcrear(participante.nombre);
    scan(participante.nombre);
    printf(" Ingrese el apellido: ");
    strcrear(participante.apellido);
    scan(participante.apellido);
    printf(" Ingrese departamento de procedencia: ");
    strcrear(participante.deptoProcedencia);
    scan(participante.deptoProcedencia);
    participante.cantPartidasGanadas = 0;
    participante.cantPartidasJugadas = 0;
    participante.nroJugador = nroJugador;
}

// despliega el participante en pantalla.
void desplegarParticipante(Participante participante){
    printf("\n Participante con numero de jugador: %d", darNroJugador(participante));
    printf("\n Cedula: %d ", darCedula(participante));
    printf("\n Fecha de Nacimiento: ");
    desplegarFecha(darFechaNacimiento(participante));
    printf("\n Nombre: ");
    darNombre(participante, participante.nombre);
    print(participante.nombre);
    printf("\n Apellido: ");
    darApellido(participante, participante.apellido);
    print(participante.apellido);
    printf("\n Departamento: ");
    darDeptoProcedencia(participante, participante.deptoProcedencia);
    print(participante.deptoProcedencia);
    printf("\n Partidas Jugadas: %d", darCantPartidasJugadas(participante));
    printf("\n Partidas Ganadas: %d \n\n", darCantPartidasGanadas(participante));
}

// incrementa en uno la cantidad de partidas ganadas para un participante.
void incrementarCantPartidasGanadas(Participante &participante)
{
    participante.cantPartidasGanadas++;
}

// incrementa en uno la cantidad de partidas jugadas para un participante.
void incrementarCantPartidasJugadas(Participante &participante)
{
    participante.cantPartidasJugadas++;
}
