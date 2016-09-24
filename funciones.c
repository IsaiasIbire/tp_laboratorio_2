#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int menu(char msj[],int min,int max,char msjError[],int cantError){
    /**seleccion (Entra por teclado usser) / contFueraRango (Se compara con la cantidad de error permitido)*/
    int seleccion,contFueraRango=0,resp=0,verificaNro=1;
    char seleccionCadena[128];
    do{
        printf("%s",msj);
        scanf("%s",seleccionCadena);
        verificaNro=validar(seleccionCadena,1);
        if(verificaNro==0){
            printf("\t\t\t%s\n\n",msjError);
            system("pause");
            system("cls");
        }
        else{
            seleccion=atoi(seleccionCadena);
        /** SE VALIDA EL RANGO CON LOS PARAMETROS PASADOS*/
            if(contFueraRango!=cantError&&(seleccion<min||seleccion>max)){
                system("cls");
                printf("\t\t\t%s\n\n",msjError);
                contFueraRango++;
            }
        /** PREGUNTA SI QUIERE CONTINUAR SI IGUALO LA CANTIDAD DE ERRORES PERMITIDOS */
            if(contFueraRango==cantError){
                do{
                    printf("FUERA DE RANGO VARIAS VECES - %cQUERES CONTINUAR?\n",168);
                    printf("\n0 --> CONTINUAR\n"
                            "1 --> SALIR\n");
                    scanf("%d",&resp);
        /** -1 SI QUIERE SALIR */
                    if(resp==1){
                        seleccion=-1;
                        break;
                    }
                    else{
                        system("cls");
                        contFueraRango=0;
                    }
                }while(resp<0||resp>1);
            }
        }
    }while(resp==0&&(seleccion<min||seleccion>max));
    system("cls");
    /** SE RETORNA LO QUE SELECCIONO EL USUARIO DEL MENU */
    return seleccion;
}

int validar(char cadena[],int tipoVal){
    /** resp=1 - ES VERDADERA HASTA QUE SE DIGA LO CONTRARIO */
    int resp=1,i,cant,nroNegativo=0;
    /** ASIGNO LA CANTIDAD DE CARACTERES DE LA CADENA */
    cant=strlen(cadena);
    switch (tipoVal){
        /** VALIDA NROS. */
        case 1:
            if(cadena[0]){
                nroNegativo=strchr(cadena,'-');
            }
            for(i=0;i<cant;i++){
                if(nroNegativo!=0){
                    i++;
                }
                /** MIENTRAS SEA UN NUMERO SIGUE */
                if(isdigit(cadena[i])==0){
                    resp=0;
                    break;
                }
            }
            break;
        /** VALIDA LETRAS */
        case 2:
            for(i=0;i<cant;i++){
                /** MIENTRAS SEA UNA LETRA SIGUE */
                if(isalpha(cadena[i])==0){
                    resp=0;
                    break;
                }
            }
            break;
    }
    return resp;
}

int ABM(persona pers[],int MAX,int tipoABM){
    int i,validarDato;
    double dniBaja;
    char validarCadena[128],res[2];
    switch (tipoABM){
        /** ALTA */
        case 1:
            for(i=0;i<MAX;i++){
                if(pers[i].flag==0){
                    printf("INGRESE:\n\n");
                    do{
                        printf("Nombre: ");
                        fflush(stdin);
                        gets(pers[i].nombre);
                        validarDato=validar(pers[i].nombre,2);
                        if(validarDato==0){
                            system("cls");
                            printf("\t\t\tINGRESE SOLO LETRAS\n\n");
                            system("pause\n");
                            system("cls");
                        }
                    }while(validarDato==0);
                    strupr(pers[i].nombre);
                    do{
                        printf("Edad: ");
                        gets(validarCadena);
                        validarDato=validar(validarCadena,1);
                        if(validarDato==0){
                            system("cls");
                            printf("\t\t\tINGRESE SOLO  NUMEROS\n\n");
                            system("pause\n");
                            system("cls");
                        }
                        else{
                            pers[i].edad=atoi(validarCadena);
                        }
                        if(pers[i].edad<0){
                            system("cls");
                            printf("\t\t\tLA EDAD NO PUEDE SER MENOR A 0\n\n");
                            system("pause\n");
                            system("cls");
                        }
                        if(pers[i].edad>125&&validarDato!=0){
                            system("cls");
                            printf("\t\t\tLA EDAD NO PUEDE SER MAYOR A 125 A%cOS\n\n",165);
                            system("pause\n");
                            system("cls");
                        }
                    }while(validarDato==0||pers[i].edad<0||pers[i].edad>125);
                    do{
                        printf("DNI: ");
                        gets(validarCadena);
                        validarDato=validar(validarCadena,1);
                        if(validarDato==0){
                            system("cls");
                            printf("\t\t\tINGRESE SOLO  NUMEROS\n\n");
                            system("pause\n");
                            system("cls");
                        }
                        else{
                            pers[i].dni=atol(validarCadena);
                        }
                        if(pers[i].dni<0){
                            system("cls");
                            printf("\t\t\tEL DNI NO PUEDE SER MENOR A 0\n\n");
                            system("pause\n");
                            system("cls");
                        }
                    }while(validarDato==0||pers[i].dni<0);
                    pers[i].flag=CARGADO;
                    break;
                }
                if(pers[i].flag!=0&&i==MAX-1){
                    printf("\t\t\tMEMORIA LLENA\n\n");
                    system("pause\n");
                    system("cls");
                }
            }
            system("cls");
            break;
        /** BAJA */
        case 2:
            do{
                printf("INGRESE EL DNI: ");
                fflush(stdin);
                gets(validarCadena);
                validarDato=validar(validarCadena,1);
                if(validarDato==0){
                    system("cls");
                    printf("\t\t\tINGRESE SOLO  NUMEROS\n\n");
                    system("pause\n");
                    system("cls");
                }
                else{
                    dniBaja=atof(validarCadena);
                }
                if(dniBaja<0){
                    system("cls");
                    printf("\t\t\tEL DNI NO PUEDE SER MENOR A 0\n\n");
                    system("pause\n");
                    system("cls");
                }
            }while(validarDato==0||dniBaja<0);
            validarDato=busqueda(dniBaja,pers,MAX);
            if((validarDato!=0||validarDato!=-1)&&pers[validarDato].flag==1){
                system("cls");
                printf("%cQUIERE ELIMINAR LOS SIGUIENTES DATOS?\n\n",168);
                printf("Nombre: %s\n",pers[validarDato].nombre);
                printf("Edad: %d A%cOS\n",pers[validarDato].edad,165);
                printf("DNI: %ld\n\n",pers[validarDato].dni);
                printf("[SI/NO] : ");
                fflush(stdin);
                gets(res);
                if(strcmp(res,"SI")==0||strcmp(res,"si")==0){
                    pers[validarDato].flag=BAJA_LOGICA;
                    system("pause");
                }
            }
            if(validarDato==-1){
                    system("cls");
                    printf("\t\t\tDNI INEXISTENTE\n\n");
                    system("pause");
            }
            system("cls");
            break;
    }
    return 0;
}

int busqueda(double dniBaja,persona pers[],int MAX){
    int i,respuesta;
    for(i=0;i<MAX;i++){
        if(pers[i].flag==CARGADO&&pers[i].dni==dniBaja){
            respuesta=i;
            break;
        }
        else{
            respuesta=-1;
        }
    }
    return respuesta;
}


int ordenarDosCriterios(persona pers[],int MAX){
    int i,j;
    persona persAUX;
    for(i=0;i<MAX-1;i++){
        for(j=i+1;j<MAX;j++){
            if(strcmp(pers[i].nombre,pers[j].nombre)>0&&pers[i].flag==CARGADO){

                persAUX=pers[j];
                pers[j]=pers[i];
                pers[i]=persAUX;
            }
            else if(strcmp(pers[i].nombre,pers[j].nombre)==0&&pers[i].flag==CARGADO){
                    persAUX=pers[j];
                    pers[j]=pers[i];
                    pers[i]=persAUX;
            }
        }
    }
    system("cls");
    for(i=0;i<MAX;i++){
        if(pers[i].flag==CARGADO){
            printf("%s\t\t%d A%cOS\t\t%ld\n",pers[i].nombre,pers[i].edad,165,pers[i].dni);
        }
    }
    printf("\n\n");
    system("pause");
    system("cls");
    return 0;
}
