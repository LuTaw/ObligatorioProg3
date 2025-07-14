#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "Sistema.h"

//desplegar menu principal
void desplegarMenuPrincipal();

//procesa opcion elegida en el menu princiapl
void procesarValorMenuPrincipal(int num);

//desplegar menu secundario
void desplegarSegundoMenu();

//procesa opcion elegida en el menu secundario
void procesarValorSegundoMenu(int opcionIngresada, Torneo &torneo, Participantes &participantes, Encuentros &encuentros);

//maneja segundo menu
void segundoMenu(Torneo &torneo, Participantes &participantes);


#endif // MENU_H_INCLUDED
