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
        printf("Ingrese la cedula del ganador de este encuentro: \n\n");
        scanf("%d", &cedulaGanadorEncuentro);
        if (cedulaGanadorEncuentro == cedulaParticipante1 || cedulaGanadorEncuentro == cedulaParticipante2) {
            determinarGanador = TRUE;
            encuentro.cedulaGanador = cedulaGanadorEncuentro;
        } else {
            printf("La cedula del ganador debe coincidir con alguno de los dos participantes de este encuentro. \n\n");
        }
    }

    return encuentro;
}

void desplegarEncuentro(Encuentro encuentro)
{
    printf("\n\n Es el encuentro numero: %d \n", DarNroEncuentro(encuentro));\
    printf("\n Los participantes fueron: %d y %d \n", DarCedulaParticipante1(encuentro), DarCedulaParticipante2(encuentro));
    printf("\n El ganador del encuentro fue: %d \n\n", DarCedulaGanador(encuentro));
}

int DarNroEncuentro(Encuentro encuentro)
{
    return encuentro.nroEncuentro;
}

int DarCedulaParticipante1(Encuentro encuentro)
{
    return encuentro.cedulaParticipante1;
}

int DarCedulaParticipante2(Encuentro encuentro)
{
    return encuentro.cedulaParticipante2;
}

int DarCedulaGanador(Encuentro encuentro)
{
    return encuentro.cedulaGanador;
}
