#include "Participante.h"

int DarCedula(Participante participante)
{
    return participante.cedula;
}

Fecha DarFechaNacimiento(Participante participante)
{
    return participante.fechaNacimiento;
}

int DarNroJugador(Participante participante)
{
    return participante.nroJugador;
}

void DarNombre(Participante participante,string &nombre){
    return strcop(nombre, participante.nombre);
}

void DarApellido(Participante participante,string &apellido){
    return strcop(apellido, participante.apellido);
}

int DarCantPartidasJugadas(Participante participante)
{
    return participante.cantPartidasJugadas;
}

int DarCantPartidasGanadas(Participante participante)
{
    return participante.cantPartidasGanadas;
}

void DarDeptoProcedencia(Participante participante,string &depto){
    return strcop(depto, participante.deptoProcedencia);
}

void crearParticipante(Participante &participante, int nroJugador){
    printf("\n Ingrese su numero de cedula: ");
    scanf("%d", &participante.cedula);
    printf("\n Ingrese su fecha de nacimiento: ");
    crearFecha(participante.fechaNacimiento);
    strcrear(participante.nombre);
    printf("\n Ingrese el nombre: ");
    scan(participante.nombre);
    printf("\n Ingrese el apellido: ");
    strcrear(participante.apellido);
    scan(participante.apellido);
    printf("\n Ingrese departamento de procedencia: ");
    strcrear(participante.deptoProcedencia);
    scan(participante.deptoProcedencia);
    participante.cantPartidasGanadas = 0;
    participante.cantPartidasJugadas = 0;
    participante.nroJugador = nroJugador;
}

void desplegarParticipante(Participante participante){
    printf("\n Participante con numero de jugador: %d", DarNroJugador(participante));
    printf("\n Cedula: %d ", DarCedula(participante));
    printf("\n Fecha de Nacimiento: ");
    desplegarFecha(DarFechaNacimiento(participante));
    printf("\n Nombre: ");
    print(DarNombre(participante));
    printf("\n Apellido: ");
    print(DarApellido(participante));
    printf("\n Departamento: ");
    print(DarDeptoProcedencia(participante));
    printf("\n Partidas Jugadas: %d", DarCantPartidasJugadas(participante));
    printf("\n Partidas Ganadas: %d \n\n", DarCantPartidasGanadas(participante));
}

// incrementa en uno la cantidad de partidas ganadas para un participante.
void IncrementarCantPartidasGanadas(Participante &participante)
{
    participante.cantPartidasGanadas++;
}

// incrementa en uno la cantidad de partidas jugadas para un participante.
void IncrementarCantPartidasJugadas(Participante &participante)
{
    participante.cantPartidasJugadas++;
}

