#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"

typedef struct { int dia;
                 int mes;
                 int anio;
               } Fecha;

// devuelve el dia de la fecha dada.
int darDia(Fecha fecha);

// devuelve el mes de la fecha dada.
int darMes(Fecha fecha);

// devuelve el anio de la fecha dada.
int darAnio(Fecha fecha);

// interactua con el usuario mediante la consola para crear la fecha.
void crearFecha(Fecha &fecha);

// verifica que la fecha es valida, esto es:
// el dia entre 1 y 31
// el mes entre 1 y 12
// el anio entre 1930 y 2010
boolean validarFecha(Fecha fecha);

// depliega en consola la fecha dada.
void desplegarFecha(Fecha fecha);

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es igual a fecha2.
boolean sonIguales(Fecha fecha1, Fecha f2);

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es posterior a fecha2.
boolean esPosterior(Fecha fecha1, Fecha fecha2);

// dadas dos fechas: fecha1 y fecha2 determina si fecha1 es anterior a fecha2.
boolean esAnterior(Fecha fecha1, Fecha fecha2);

#endif // FECHA_H_INCLUDED
