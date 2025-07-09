#include "Sistema.h"

void registrarEncuentro(Torneo &torneo, Participantes &participantes, Encuentros &encuentros)
{
    if (!torneoTerminado(encuentros)) {
        boolean selecciono  = FALSE;
        boolean deseaContinuar = TRUE;
        while(!selecciono && deseaContinuar) {
            int cedulaParticipante1, cedulaParticipante2;
            seleccionarParticipante(participantes, cedulaParticipante1, deseaContinuar);
            if (deseaContinuar) {
                Participante participante1 = Find(participantes, cedulaParticipante1);
                seleccionarParticipante(participantes, cedulaParticipante2, deseaContinuar);
                if (deseaContinuar) {
                    Participante participante2 = Find(participantes, cedulaParticipante2);
                    if (DarCedula(participante1) != DarCedula(participante2)) {
                        int nroJugador1 = DarNroJugador(participante1);
                        int nroJugador2 = DarNroJugador(participante2);
                        if(!PerteneceArista(torneo, nroJugador1, nroJugador2)) {
                            selecciono = TRUE;
                            InsertarArista(torneo, nroJugador1, nroJugador2);
                            int nuevoIdEncuentro = Largo(encuentros) + 1;
                            Encuentro encuentro = crearEncuentro(nuevoIdEncuentro, DarCedula(participante1), DarCedula(participante2));
                            insertarEncuentroFinal(encuentros, encuentro);
                            int cedulaGanador = DarCedulaGanador(encuentro);
                            if (cedulaGanador == DarCedula(participante1)) {
                                IncrementarCantPartidasGanadas(participante1);
                            } else {
                                IncrementarCantPartidasGanadas(participante2);
                            }
                            IncrementarCantPartidasJugadas(participante1);
                            IncrementarCantPartidasJugadas(participante2);
                            Modify(participantes, participante1);
                            Modify(participantes, participante2);
                        } else {
                            printf("Los jugadores seleccionados ya jugaron una partida entre ellos, deben ser jugadores que no hayan jugado una partida aun. \n\n\n");
                        }
                    }
                    else
                        printf("Debe seleccionar participantes diferentes. \n\n\n");
                }
            }
        }
    } else {
        printf("El torneo ha finalizado, por lo que no se pueden ingresar mas encuentros. \n\n\n");
    }
}

void determinarMismaSubDivision(Torneo torneo, Participantes participantes)
{
    boolean selecciono  = FALSE;
    boolean deseaContinuar = TRUE;
    while(!selecciono && deseaContinuar) {
        int cedulaParticipante1, cedulaParticipante2;
        seleccionarParticipante(participantes, cedulaParticipante1, deseaContinuar);
        if (deseaContinuar) {
            Participante participante1 = Find(participantes, cedulaParticipante1);
            seleccionarParticipante(participantes, cedulaParticipante2, deseaContinuar);
            if (deseaContinuar) {
                Participante participante2 = Find(participantes, cedulaParticipante2);
                if (DarCedula(participante1) != DarCedula(participante2)) {
                    selecciono = TRUE;
                    boolean pertenecen = pertencenMismaSubDivision(torneo, DarNroJugador(participante1), DarNroJugador(participante2));
                    if(pertenecen)
                        printf("Los jugadores seleccionadas pertenecen a la misma subdivision. \n\n\n");
                    else
                        printf("Los jugadores seleccionadas NO pertenecen a la misma subdivision. \n\n\n");
                } else {
                    printf("Debe seleccionar participantes diferentes. \n\n");
                }
            }
        }
    }
}

void obtenerGanador(Torneo torneo, Participantes participantes, Encuentros encuentros)
{
    if (torneoTerminado(encuentros)) {
        desplegarJugadoresGanadores(participantes);
    } else {
        printf("El torneo aun no ha finalizado por lo que no se pueden determinar aun los ganadores del torneo. \n\n\n");
    }
}

// 	1. Registrar los datos de los N jugadores que participan del torneo. Esta operación se ejecutará
//	solamente una vez, al comienzo del torneo. Los números de jugador irán siendo asignados por
//	orden de registro (el primer jugador tendrá el número 0, el siguiente el 1 y así sucesivamente).
//	Se debe verificar que cada cédula ingresada efectivamente sea única dentro del sistema.
void registrarJugador(Torneo &torneo, Participantes &participantes)
{
    int cantJugadoresActual = 0;
    while (cantJugadoresActual < CantParticipantes) {
        boolean participanteValido = FALSE;
        while(!participanteValido) {
            Participante participante;
            crearParticipante(participante, cantJugadoresActual);
            if (!Member(participantes, DarCedula(participante))) {
                Insert(participantes, participante);
                cantJugadoresActual++;
                participanteValido = TRUE;
                printf("\n\n Participante ingresado correctamente!! \n\n");
                printf("Restan %d participantes por ingresar... \n\n", CantParticipantes - cantJugadoresActual);
            } else {
                printf("\n\n Participante no valido, ya existe uno con la misma CI, ingrese los datos nuevamente \n\n");
            }
        }
    }
}

void desplegarJugadoresRegistrados(Participantes participantes)
{
    desplegarParticipantes(participantes);
}

void desplegarJugador(Participantes participantes)
{
    boolean existe = FALSE;
    while(!existe){
        int ced;
        printf(" Ingrese la cedula del jugador: ");
        scanf("%d", &ced);
        if(Member(participantes,ced)){
            Participante p = Find(participantes, ced);
            desplegarParticipante(p);
            existe = TRUE;
        } else {
            printf("No existe participante con esa cedula. ");
        }
    }
}

void desplegarTodasPartidasAscendente(Encuentros encuentros)
{
    if(!EsVacia(encuentros))
        desplegarEncuentros(encuentros);
    else
        printf("\n\n Aun no hay ningun encuentro registrado en el sistema.");
}

/*
void cantParticipantesSegunFecha(Participantes participantes)
{
    boolean ok = FALSE;
    while(!ok){
        Fecha fecha;
        printf(" Ingrese una fecha valida: ");
        crearFecha(fecha);
        if(validarFecha(fecha)){


        }
    }
}
}
*/
