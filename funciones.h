#define VACIO 0
#define CARGADO 1
#define BAJA_LOGICA -1
typedef struct{
    char nombre[30];
    int edad;
    int flag;
    long int dni;
}persona;

/**
* /brief muestra un menu por pantalla
* /param msj - muestra menu
* /param min - minimo disponible a ingresar
* /param max - maximo disponible a ingresar
* /param msjError - mensaje de error
* /param cantError - cantidad de errores permitidos
* /return devuelve la seleccion del usuario
*
* IMPORTANTE: Si se cumple la cantidad de error y no quiere continuar retorna -1 */
int menu(char msj[],int min,int max,char msjError[],int cantError);

/**
* /brief valida una cadena ingresada
* /param cadena - cadena de caracteres a validar
* /param tipoVal - 1 numeros - 2 letras
* /return devuelve 0 si es correcto -1 si es incorrecto
*/
int validar(char cadena[],int tipoVal);

/**
* /brief genera el alta y baja en un sistema
* /param estructura para el ABM
* /param maximos de altas que puede tener
* /param 1==ALTA 2==BAJA
*/
int ABM(persona pers[],int MAX,int tipoABM);

/**
* /brief busca un numero en un vector
* /param nro a buscar
* /param estructura donde se encuentra el array con los numeros donde buscar
* /param maximo del vector
*/
int busqueda(double dniBaja,persona pers[],int MAX);

/**
* /brief ordena un vector por dos criterios
* /param estructura a ordenar alfabetica o numericamente
* /param maximo del vector
*/
int ordenarDosCriterios(persona pers[],int MAX);
