#include "Fecha.h"

int DarDia(Fecha fecha)
{
    return fecha.dia;
}

int DarMes(Fecha fecha)
{
    return fecha.mes;
}

int DarAnio(Fecha fecha)
{
    return fecha.anio;
}

void crearFecha(Fecha &fecha)
{
    boolean esValida = FALSE;
    do{
        printf("\n Ingrese dia/mes/anio: ");
        scanf("%d/%d/%d",&fecha.dia,&fecha.mes,&fecha.anio);
        if(!validarFecha(fecha))
            printf("\n Fecha incorrecta. Ingrese una nueva");
        else
            esValida = TRUE;
    } while (!esValida);
}

boolean validarFecha(Fecha fecha)
{
    boolean valida = TRUE;
    if (DarMes(fecha) < 1 || DarMes(fecha) > 12)
        valida = FALSE;
    if (DarDia(fecha) < 1 || DarDia(fecha) > 31)
        valida = FALSE;
    if (DarAnio(fecha) > 2010 || DarAnio(fecha) < 1930)
        valida = FALSE;

    return valida;
}

void desplegarFecha(Fecha fecha)
{
    printf("\n %d/%d/%d", DarDia(fecha),DarMes(fecha),DarAnio(fecha));
}

boolean sonIguales(Fecha fecha1, Fecha fecha2)
{
    if(DarDia(fecha1) == DarDia(fecha2)
       && DarMes(fecha1) == DarMes(fecha2)
       && DarAnio(fecha1) == DarAnio(fecha2))
        return TRUE;
    else
        return FALSE;
}

boolean esPosterior(Fecha fecha1, Fecha fecha2){
    boolean es = FALSE;
    if (DarAnio(fecha1) >= DarAnio(fecha2))
        es = TRUE;
    else if (DarAnio(fecha1) == DarAnio(fecha2)) {
        if (DarMes(fecha1) >= DarMes(fecha2))
            es = TRUE;
        else if (DarMes(fecha1) == DarMes(fecha2) && DarDia(fecha1) >= DarDia(fecha2))
            es = TRUE;
    }

    return es;
}

boolean esAnterior(Fecha fecha1, Fecha fecha2){
    boolean es = FALSE;
    if (DarAnio(fecha1) <= DarAnio(fecha2))
        es = TRUE;
    else if (DarAnio(fecha1) == DarAnio(fecha2)) {
        if (DarMes(fecha1) <= DarMes(fecha2))
            es = TRUE;
        else if (DarMes(fecha1) == DarMes(fecha2) && DarDia(fecha1) <= DarDia(fecha2))
            es = TRUE;
    }

    return es;
}
