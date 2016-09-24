#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAX 20


int main()
{
    persona pers[MAX];
    char menu_printf[]=("1--> Agregar persona\n"
                 "2--> Borrar persona\n"
                 "3--> Imprimir lista ordenada por nombre\n"
                 "4--> Imprimir grafico de edades\n"
                 "5--> Salir\n\n");
    int seleccion,i,sigue=1;
    for(i=0;i<MAX;i++){
        pers[i].flag=VACIO;
    }
    do
    {
        seleccion=menu(menu_printf,1,5,"ERROR / NO VALIDO",3);
        switch(seleccion)
        {
            case 1:
                ABM(pers,MAX,1);
                break;
            case 2:
                ABM(pers,MAX,2);
                break;
            case 3:
                ordenarDosCriterios(pers,MAX);
                break;
            case 4:
                break;
            case -1:
                sigue=0;
                break;
        }
    }while(sigue==1&&seleccion!=5);


    return 0;
}
