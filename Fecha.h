#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"

typedef struct { int dia;
                 int mes;
                 int anio;
               } Fecha;

int DarDia(Fecha fecha);

int DarMes(Fecha fecha);

int DarAnio(Fecha fecha);

void crearFecha(Fecha &fecha);

bool esValida(Fecha fecha);

void desplegarFecha(Fecha fecha);

boolean sonIguales(Fecha fecha1, Fecha f2);

boolean esPosterior(Fecha fecha1, Fecha fecha2);

boolean esAnterior(Fecha fecha1, Fecha fecha2);



#endif // FECHA_H_INCLUDED
