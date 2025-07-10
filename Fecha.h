#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"

typedef struct { int dia;
                 int mes;
                 int anio;
               } Fecha;

int darDia(Fecha fecha);

int darMes(Fecha fecha);

int darAnio(Fecha fecha);

void crearFecha(Fecha &fecha);

boolean validarFecha(Fecha fecha);

void desplegarFecha(Fecha fecha);

boolean sonIguales(Fecha fecha1, Fecha f2);

boolean esPosterior(Fecha fecha1, Fecha fecha2);

boolean esAnterior(Fecha fecha1, Fecha fecha2);



#endif // FECHA_H_INCLUDED
