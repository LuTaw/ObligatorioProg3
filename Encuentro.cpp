#include "Encuentro.h"

// crea un encuentro
// Precondicion:
//      - Las cédulas de ambos participantes deben corresponder a jugadores registrados en el torneo.
//      - Las cédulas de los jugadores deben ser distintas.
//      - No debe existir ya un encuentro registrado entre esos dos jugadores.
Encuentro crearEncuentro(int nuevoIdEncuentro, int cedulaParticipante1, int cedulaParticipante2)
{
    Encuentro encuentro;
    encuentro.cedulaParticipante1 = cedulaParticipante1;
    encuentro.cedulaParticipante2 = cedulaParticipante2;
    encuentro.nroEncuentro = nuevoIdEncuentro;

    boolean determinarGanador = FALSE;
    int cedulaGanadorEncuentro;
    while(!determinarGanador) {
        printf(" Ingrese la cedula del ganador de este encuentro: \n\n");
        scanf("%d", &cedulaGanadorEncuentro);
        if (cedulaGanadorEncuentro == cedulaParticipante1 || cedulaGanadorEncuentro == cedulaParticipante2) {
            determinarGanador = TRUE;
            encuentro.cedulaGanador = cedulaGanadorEncuentro;
        } else {
            printf(" La cedula del ganador debe coincidir con alguno de los dos participantes de este encuentro. \n\n");
        }
    }

    return encuentro;
}

// despliega por pantalla los datos del encuentro
void desplegarEncuentro(Encuentro encuentro)
{
    printf("\n\n Es el encuentro numero: %d \n", darNroEncuentro(encuentro));
    printf("\n Los participantes fueron: %d y %d \n", darCedulaParticipante1(encuentro), darCedulaParticipante2(encuentro));
    printf("\n El ganador del encuentro fue: %d \n\n", darCedulaGanador(encuentro));
}

// da el numero de encuentro
int darNroEncuentro(Encuentro encuentro)
{
    return encuentro.nroEncuentro;
}

// obtener cedula participante 1
int darCedulaParticipante1(Encuentro encuentro)
{
    return encuentro.cedulaParticipante1;
}

// obtener cedula participante 2
int darCedulaParticipante2(Encuentro encuentro)
{
    return encuentro.cedulaParticipante2;
}

// obtener cedula participante ganador
int darCedulaGanador(Encuentro encuentro)
{
    return encuentro.cedulaGanador;
}
