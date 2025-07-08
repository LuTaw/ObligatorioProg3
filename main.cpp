#include <iostream>
#include "Torneo.h"

using namespace std;

const int MENU_ITEMS[] = {1, 2};
const char* MENU_NAMES[] = {
    "Cargar Jugadores.",
    "Salir"
    };
const int MENU_SIZE = sizeof(MENU_ITEMS) / sizeof(MENU_ITEMS[0]);

const int SEGUNDO_MENU_ITEMS[] = {1, 2, 3, 4, 5, 6, 7, 8};
const char* SEGUNDO_MENU_NAMES[] = {
    "Desplegar jugadores registrados.",
    "Desplegar un jugador.",
    "Registrar encuentro para dos jugadores.",
    "Desplegar todas las partidas de forma ascendente.",
    "Dada una fecha, determinar cuantos jugadores nacieron en esa fecha, antes o despues.",
    "Determinar si dos jugadores pertenecen a la misma subdivision.",
    "Obtener ganador/es.",
    "Volver"
    };
const int SEGUNDO_MENU_SIZE = sizeof(SEGUNDO_MENU_ITEMS) / sizeof(SEGUNDO_MENU_ITEMS[0]);

void desplegarMenuPrincipal()
{
    printf("Escoja la opcion deseada: \n\n");
    for(int i = 0; i < MENU_SIZE; i++) {
        std::cout << MENU_ITEMS[i] << ". " << MENU_NAMES[i] << "\n";
    }
}

void desplegarSegundoMenu()
{
    printf("\n\n Seleccione la opcion deseada: \n\n");
    for(int i = 0; i < SEGUNDO_MENU_SIZE; i++) {
        std::cout << SEGUNDO_MENU_ITEMS[i] << ". " << SEGUNDO_MENU_NAMES[i] << "\n";
    }
}

void desplegarJugadoresRegistrados(Participantes participantes)
{
    desplegarParticipantes(participantes);
}

void desplegarJugador(Participantes participantes)
{
    printf("Proximamente a implementar....");
}

void registrarEncuentro(Torneo &torneo, Participantes &participantes, Encuentros &encuentros)
{
    if (!torneoTerminado(encuentros)) {
        boolean selecciono  = FALSE;
        while(!selecciono) {
            Participante participante1 = Find(participantes, seleccionarParticipante(participantes));
            Participante participante2 = Find(participantes, seleccionarParticipante(participantes));
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
    } else {
        printf("El torneo ha finalizado, por lo que no se pueden ingresar mas encuentros. \n\n\n");
    }
}

void desplegarTodasPartidasAscendente(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void cantParticipantesSegunFecha(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void determinarMismaSubDivision(Torneo torneo, Participantes participantes)
{
    boolean selecciono  = FALSE;
    while(!selecciono) {
        Participante participante1 = Find(participantes, seleccionarParticipante(participantes));
        Participante participante2 = Find(participantes, seleccionarParticipante(participantes));
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

void obtenerGanador(Torneo torneo, Participantes participantes, Encuentros encuentros)
{
    if (torneoTerminado(encuentros)) {
        desplegarJugadoresGanadores(participantes);
    } else {
        printf("El torneo aun no ha finalizado por lo que no se pueden determinar aun los ganadores del torneo. \n\n\n");
    }
}

void procesarValorSegundoMenu(int opcionIngresada, Torneo &torneo, Participantes &participantes, Encuentros &encuentros)
{
    switch (opcionIngresada) {
        case 1:
            desplegarJugadoresRegistrados(participantes);
            break;
        case 2:
            desplegarJugador(participantes);
            break;
        case 3:
            registrarEncuentro(torneo, participantes, encuentros);
            break;
        case 4:
            desplegarTodasPartidasAscendente(torneo);
            break;
        case 5:
            cantParticipantesSegunFecha(torneo);
            break;
        case 6:
            determinarMismaSubDivision(torneo, participantes);
            break;
        case 7:
            obtenerGanador(torneo, participantes, encuentros);
            break;
        case 8:
            break;
        default:
            std::cout << "Opción no válida\n\n\n";
            break;
    }
}

void segundoMenu(Torneo &torneo, Participantes &participantes)
{
    int opcionIngresada;
    boolean salirSegundoMenu = FALSE;
    Encuentros encuentros;
    CrearEncuentros(encuentros);

    while(!salirSegundoMenu) {
        desplegarSegundoMenu();
        scanf("%d", &opcionIngresada);
        procesarValorSegundoMenu(opcionIngresada, torneo, participantes, encuentros);

        if (opcionIngresada == 8)
            salirSegundoMenu = TRUE;
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


void procesarValorMenuPrincipal(int opcionMenuPrincipal)
{
    Torneo torneo;
    Participantes participantes;
    CrearTorneo(torneo);
    Make(participantes);
    printf("\n\n");
    switch (opcionMenuPrincipal) {
        case 1: {
            registrarJugador(torneo, participantes);
            segundoMenu(torneo, participantes);
            break;
        }
        case 2:
            break;
        default:
            std::cout << "Opción no válida\n\n\n";
            break;
    }
}

int main()
{
   int num;
   boolean salir = FALSE;

    while(!salir) {
        desplegarMenuPrincipal();
        scanf("%d", &num);
        procesarValorMenuPrincipal(num);

        if (num == 2)
            salir = TRUE;
    }

    return 0;
}
