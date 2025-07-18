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
                    if (darCedula(participante1) != darCedula(participante2)) {
                        int nroJugador1 = darNroJugador(participante1);
                        int nroJugador2 = darNroJugador(participante2);
                        if(!PerteneceArista(torneo, nroJugador1, nroJugador2)) {
                            selecciono = TRUE;
                            InsertarArista(torneo, nroJugador1, nroJugador2);
                            int nuevoIdEncuentro = Largo(encuentros) + 1;
                            Encuentro encuentro = crearEncuentro(nuevoIdEncuentro, darCedula(participante1), darCedula(participante2));
                            insertarEncuentroFinal(encuentros, encuentro);
                            int cedulaGanador = darCedulaGanador(encuentro);
                            if (cedulaGanador == darCedula(participante1)) {
                                incrementarCantPartidasGanadas(participante1);
                            } else {
                                incrementarCantPartidasGanadas(participante2);
                            }
                            incrementarCantPartidasJugadas(participante1);
                            incrementarCantPartidasJugadas(participante2);
                            Modify(participantes, participante1);
                            Modify(participantes, participante2);
                        } else {
                            printf(" Los jugadores seleccionados ya jugaron una partida entre ellos, deben ser jugadores que no hayan jugado una partida aun. \n\n\n");
                        }
                    } else {
                        printf(" Debe seleccionar participantes diferentes. \n\n\n");
                    }
                }
            }
        }
    } else {
        printf(" El torneo ha finalizado, por lo que no se pueden ingresar mas encuentros. \n\n\n");
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
                if (darCedula(participante1) != darCedula(participante2)) {
                    selecciono = TRUE;
                    boolean pertenecen = pertencenMismaSubDivision(torneo, darNroJugador(participante1), darNroJugador(participante2));
                    if(pertenecen)
                        printf(" Los jugadores seleccionadas pertenecen a la misma subdivision. \n\n\n");
                    else
                        printf(" Los jugadores seleccionadas NO pertenecen a la misma subdivision. \n\n\n");
                } else {
                    printf(" Debe seleccionar participantes diferentes. \n\n");
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
        printf(" El torneo aun no ha finalizado por lo que no se pueden determinar aun los ganadores del torneo. \n\n\n");
    }
}

void registrarJugador(Torneo &torneo, Participantes &participantes)
{
    int cantJugadoresActual = 0;
    while (cantJugadoresActual < CantParticipantes) {
        boolean participanteValido = FALSE;
        while(!participanteValido) {
            Participante participante;
            crearParticipante(participante, cantJugadoresActual);
            if (!Member(participantes, darCedula(participante))) {
                Insert(participantes, participante);
                cantJugadoresActual++;
                participanteValido = TRUE;
                printf("\n\n Participante ingresado correctamente!! \n\n");
                printf(" Restan %d participantes por ingresar... \n\n", CantParticipantes - cantJugadoresActual);
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

void desplegarEncuentrosJugadorSeleccionado(Encuentros encuentros, int cedulaParicipante)
{
    Encuentro encuentro;
    int total = 0;
    for(int i = 0; i < encuentros.tope; i++) {
        encuentro = Kesimo(encuentros, i);
        if(darCedulaParticipante1(encuentro) == cedulaParicipante || darCedulaParticipante2(encuentro) == cedulaParicipante) {
            desplegarEncuentro(encuentro);
            total++;
        }
    }
    printf("\n Total de encuentros jugados por el participante: %d \n", total);
}

void desplegarJugador(Torneo torneo, Participantes participantes, Encuentros encuentros)
{
    int cedula;
	boolean encontro = TRUE;

	seleccionarParticipante(participantes, cedula, encontro);
	if(encontro) {
		Participante p = Find(participantes, cedula);
		desplegarParticipante(p);
		if (GradoVertice(torneo, darNroJugador(p)) > 0) {
            desplegarEncuentrosJugadorSeleccionado(encuentros, darCedula(p));
		} else {
            printf(" El jugador seleccionado aun no ha participado de ningun encuentro. \n\n");
		}
	} else {
		printf(" Debe seleccionar un participante valido \n\n");
	}
}

void desplegarTodasPartidasAscendente(Encuentros encuentros)
{
    if(!EsVacia(encuentros))
        desplegarEncuentros(encuentros);
    else
        printf("\n\n Aun no hay ningun encuentro registrado en el sistema. \n");
}

void cantParticipantesSegunFecha(Participantes participantes)
{
    boolean ok = FALSE;
    while(!ok){
        Fecha fecha;
        printf("\n\n Ingrese una fecha valida: ");
        crearFecha(fecha);
        if(validarFecha(fecha)){
            ok = TRUE;
            int cantIgual, cantMenor, cantMayor;
            cantParticipantesSegunFecha(participantes,fecha,cantIgual,cantMenor,cantMayor);
            printf("\n\n Participantes nacidos en la fecha indicada: %d",cantIgual);
            printf("\n Participantes nacidos antes de la fecha indicada: %d",cantMenor);
            printf("\n Participantes nacidos despues de la fecha indicada: %d",cantMayor);
        } else {
            printf("\n\n Ingrese una fecha valida. ");
        }
    }
}
