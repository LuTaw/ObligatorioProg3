#include "Fecha.h"

// devuelve el dia de la fecha dada.
int darDia(Fecha fecha)
{
    return fecha.dia;
}

// devuelve el mes de la fecha dada.
int darMes(Fecha fecha)
{
    return fecha.mes;
}

// devuelve el anio de la fecha dada.
int darAnio(Fecha fecha)
{
    return fecha.anio;
}

// interactua con el usuario mediante la consola para crear la fecha.
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

// verifica que la fecha es valida, esto es:
// el dia entre 1 y 31
// el mes entre 1 y 12
// el anio entre 1930 y 2010
boolean validarFecha(Fecha fecha)
{
    boolean valida = TRUE;
    if (darMes(fecha) < 1 || darMes(fecha) > 12)
        valida = FALSE;
    if (darDia(fecha) < 1 || darDia(fecha) > 31)
        valida = FALSE;
    if (darAnio(fecha) > 2025 || darAnio(fecha) < 1930)
        valida = FALSE;

    return valida;
}

// depliega en consola la fecha dada.
void desplegarFecha(Fecha fecha)
{
    printf(" %d/%d/%d", darDia(fecha), darMes(fecha), darAnio(fecha));
}

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es igual a fecha2.
boolean sonIguales(Fecha fecha1, Fecha fecha2)
{
    if(darDia(fecha1) == darDia(fecha2)
       && darMes(fecha1) == darMes(fecha2)
       && darAnio(fecha1) == darAnio(fecha2))
        return TRUE;
    else
        return FALSE;
}

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es posterior a fecha2.
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

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es anterior a fecha2.
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
