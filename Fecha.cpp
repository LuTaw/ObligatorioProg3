#include "Fecha.h"

int darDia(Fecha fecha)
{
    return fecha.dia;
}

int darMes(Fecha fecha)
{
    return fecha.mes;
}

int darAnio(Fecha fecha)
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
    if (darMes(fecha) < 1 || darMes(fecha) > 12)
        valida = FALSE;
    if (darDia(fecha) < 1 || darDia(fecha) > 31)
        valida = FALSE;
    if (darAnio(fecha) > 2010 || darAnio(fecha) < 1930)
        valida = FALSE;

    return valida;
}

void desplegarFecha(Fecha fecha)
{
    printf(" %d/%d/%d", darDia(fecha), darMes(fecha), darAnio(fecha));
}

boolean sonIguales(Fecha fecha1, Fecha fecha2)
{
    if(darDia(fecha1) == darDia(fecha2)
       && darMes(fecha1) == darMes(fecha2)
       && darAnio(fecha1) == darAnio(fecha2))
        return TRUE;
    else
        return FALSE;
}

boolean esPosterior(Fecha fecha1, Fecha fecha2){
    boolean es = FALSE;
    if (darAnio(fecha1) >= darAnio(fecha2))
        es = TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2)) {
        if (darMes(fecha1) >= darMes(fecha2))
            es = TRUE;
        else if (darMes(fecha1) == darMes(fecha2) && darDia(fecha1) >= darDia(fecha2))
            es = TRUE;
    }

    return es;
}

boolean esAnterior(Fecha fecha1, Fecha fecha2){
    boolean es = FALSE;
    if (darAnio(fecha1) <= darAnio(fecha2))
        es = TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2)) {
        if (darMes(fecha1) <= darMes(fecha2))
            es = TRUE;
        else if (darMes(fecha1) == darMes(fecha2) && darDia(fecha1) <= darDia(fecha2))
            es = TRUE;
    }

    return es;
}
