#include <iostream>
#include "menu.h"


int main()
{
   int num;
   boolean salir = FALSE;

    while(!salir) {
        desplegarMenuPrincipal();
        scanf("%d", &num);
        procesarValorMenuPrincipal(num);

        if (num == 2)
            salir = TRUE;
    }

    return 0;
}
