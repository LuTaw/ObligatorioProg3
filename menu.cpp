#include "menu.h"

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
        printf("%d. %s \n", MENU_ITEMS[i], MENU_NAMES[i]);
    }
}

void desplegarSegundoMenu()
{
    printf("\n\n Seleccione la opcion deseada: \n\n");
    for(int i = 0; i < SEGUNDO_MENU_SIZE; i++) {
        printf("%d. %s \n", SEGUNDO_MENU_ITEMS[i], SEGUNDO_MENU_NAMES[i]);
    }
}

void procesarValorSegundoMenu(int opcionIngresada, Torneo &torneo, Participantes &participantes, Encuentros &encuentros)
{
    switch (opcionIngresada) {
        case 1:
            desplegarJugadoresRegistrados(participantes);
            break;
        case 2:
            desplegarJugador(torneo, participantes, encuentros);
            break;
        case 3:
            registrarEncuentro(torneo, participantes, encuentros);
            break;
        case 4:
            desplegarTodasPartidasAscendente(encuentros);
            break;
        case 5:
            cantParticipantesSegunFecha(participantes);
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
            printf("Opción no válida\n\n\n");
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
            printf("Opción no válida\n\n\n");
            break;
    }
}

