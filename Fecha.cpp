#include "Fecha.h"

int DarDia(Fecha fecha){
    return fecha.dia;
}

int DarMes(Fecha fecha){
    return fecha.mes;
}

int DarAnio(Fecha fecha){
    return fecha.anio;
}

void crearFecha(Fecha &fecha){
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

boolean esValida(Fecha fecha){
    if (f.mes < 1 || f.mes > 12)
        return FALSE;
    if (f.dia < 1 || f.dia > 31)
        return FALSE;
}

void desplegarFecha(Fecha fecha){
    printf("\n %d %d %d", f.dia,f.mes,f.anio);
}

boolean sonIguales(Fecha fecha1, Fecha fecha2){
    if(darDia(fecha1) == darDia(fecha2)  && darMes(fecha1) == darMes(fecha2) && darAnio(fecha1) == darAnio(fecha2))
        return TRUE;
    else
        return FALSE;
}

boolean esPosterior(Fecha fecha1, Fecha fecha2){
    if (darAnio(fecha1) >= darAnio(s2))
        return TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2) && darMes(fecha1) >= darMes(fecha2))
        return TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2) && darMes(fecha1) == darMes(fecha2) && darDia(fecha1) >= darDia(fecha2))
        return TRUE;
    else
        return FALSE;
}

boolean esAnterior(Fecha fecha1, Fecha fecha2){
    if (darAnio(fecha1) <= darAnio(fecha2))
        return TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2) && darMes(fecha1) <= darMes(fecha2))
        return TRUE;
    else if (darAnio(fecha1) == darAnio(fecha2) && darMes(fecha1) == darMes(fecha2) && darDia(fecha1) <= darDia(fecha2))
        return TRUE;
    else
        return FALSE;
}


