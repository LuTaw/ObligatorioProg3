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
    printf("Seleccione la opcion deseada: \n\n");
    for(int i = 0; i < SEGUNDO_MENU_SIZE; i++) {
        std::cout << SEGUNDO_MENU_ITEMS[i] << ". " << SEGUNDO_MENU_NAMES[i] << "\n";
    }
}

void desplegarJugadoresRegistrados(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void desplegarJugador(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void registrarEncuentro(Torneo &torneo, Participantes &participantes)
{
    printf("Proximamente a implementar....");
}

void desplegarTodasPartidasAscendente(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void cantParticipantesSegunFecha(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void determinarMismaSubDivision(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void obtenerGanador(Torneo torneo)
{
    printf("Proximamente a implementar....");
}

void procesarValorSegundoMenu(int opcionIngresada, Torneo &torneo, Participantes &participantes)
{
    switch (opcionIngresada) {
        case 1:
            desplegarJugadoresRegistrados(torneo);
            break;
        case 2:
            desplegarJugador(torneo);
            break;
        case 3:
            registrarEncuentro(torneo, participantes);
            break;
        case 4:
            desplegarTodasPartidasAscendente(torneo);
            break;
        case 5:
            cantParticipantesSegunFecha(torneo);
            break;
        case 6:
            determinarMismaSubDivision(torneo);
            break;
        case 7:
            obtenerGanador(torneo);
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

    while(!salirSegundoMenu) {
        desplegarSegundoMenu();
        scanf("%d", &opcionIngresada);
        procesarValorSegundoMenu(opcionIngresada, torneo, participantes);

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
