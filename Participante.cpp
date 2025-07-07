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

string DarNombre(Participante participante)
{
    string nombre;
    strcrear(nombre);
    strcop(nombre, participante.nombre);

    return nombre;
}

string DarApellido(Participante participante)
{
    string apellido;
    strcrear(apellido);
    strcop(apellido, participante.apellido);

    return apellido;
}

int DarCantPartidasJugadas(Participante participante)
{
    return participante.cantPartidasJugadas;
}

int DarCantPartidasGanadas(Participante participante)
{
    return participante.cantPartidasGanadas;
}

string DarDeptoProcedencia(Participante participante)
{
    string depto;
    strcrear(depto);
    strcop(depto, participante.deptoProcedencia);

    return depto;
}


void crearParticipante(Participante &participante){
    printf("\n Ingrese su numero de cedula: ");
    scanf("%d", &participante.cedula);
    printf("\n Ingrese su fecha de nacimiento: ");
    crearFecha(participante.fechaNacimiento);
    //nro de jug
    strcrear(participante.nombre);
    printf("\n Ingrese el nombre: ");
    scan(participante.nombre);
    printf("\n Ingrese el apellido: ");
    strcrear(participante.apellido);
    scan(participante.apellido);
    printf("\n Ingrese departamento de procedencia: ");
    strcrear(participante.deptoProcedencia);
    scan(participante.deptoProcedencia);
    //cant partidas

}

void desplegarParticipante(Participante participante){
    printf("\n Cedula: %ld ", DarCedula(participante));
    printf("\n Fecha de Nacimiento: ");
    desplegarFecha(DarFechaNacimiento(participante));
    printf("\n Numero de jugador: "); /// ver
    printf("\n Nombre: ");
    print(DarNombre(participante));
    printf("\n Apellido: ");
    print(DarApellido(participante));
    printf("\n Departamento: ");
    print(DarDeptoProcedencia(participante));
    printf("\n Partidas Jugadas: %d", DarCantPartidasJugadas(participante));
    printf("\n Partidas Ganadas: %d", DarCantPartidasGanadas(participante));
}

