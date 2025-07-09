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
    strcrear(nombre);
    return strcop(nombre, participante.nombre);
}

void DarApellido(Participante participante,string &apellido){
    strcrear(apellido);
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
    strcrear(depto);
    return strcop(depto, participante.deptoProcedencia);
}

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

void desplegarParticipante(Participante participante){
    printf("\n Participante con numero de jugador: %d", DarNroJugador(participante));
    printf("\n Cedula: %d ", DarCedula(participante));
    printf("\n Fecha de Nacimiento: ");
    desplegarFecha(DarFechaNacimiento(participante));
    printf("\n Nombre: ");
    DarNombre(participante, participante.nombre);
    print(participante.nombre);
    printf("\n Apellido: ");
    DarApellido(participante, participante.apellido);
    print(participante.apellido);
    printf("\n Departamento: ");
    DarDeptoProcedencia(participante, participante.deptoProcedencia);
    print(participante.deptoProcedencia);
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

