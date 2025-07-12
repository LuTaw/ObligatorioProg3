#include "Encuentro.h"

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

void desplegarEncuentro(Encuentro encuentro)
{
    printf("\n\n Es el encuentro numero: %d \n", darNroEncuentro(encuentro));
    printf("\n Los participantes fueron: %d y %d \n", darCedulaParticipante1(encuentro), darCedulaParticipante2(encuentro));
    printf("\n El ganador del encuentro fue: %d \n\n", darCedulaGanador(encuentro));
}

int darNroEncuentro(Encuentro encuentro)
{
    return encuentro.nroEncuentro;
}

int darCedulaParticipante1(Encuentro encuentro)
{
    return encuentro.cedulaParticipante1;
}

int darCedulaParticipante2(Encuentro encuentro)
{
    return encuentro.cedulaParticipante2;
}

int darCedulaGanador(Encuentro encuentro)
{
    return encuentro.cedulaGanador;
}
