/*-------------------------
 | Arbol.c
 | Alumno: Ivan Bravo
-------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"

#define CANT_ARBOLES 100
#define CADENA_DATOS 50

/*-----------------
 |    Axiomas     |
-----------------*/

struct ArbolE{
    char especie[30];
    int edad;
    float altura;
};

/*-----------------
 | Constructores  |
-----------------*/

ArbolP crearArbol(char especie[], int edad, float altura){

    ArbolP arbol = malloc(sizeof(struct ArbolE));

    strcpy(arbol->especie, especie);
    arbol->edad = edad;
    arbol->altura = altura;

    return arbol;
}

ArbolP crearArbolPorTeclado(){

    char nombre[25];
    int edad;
    float altura;

    printf("\nIngrese nombre del arbol: ");
    fflush(stdin);
    gets(nombre);

    printf("\nIngrese la edad de \"%s\": ", nombre);
    scanf("%d", &edad);

    printf("\nIngrese la altura para \"%s\": ", nombre);
    scanf("%f", &altura);

    return crearArbol(nombre, edad, altura);
}

/*-----------------
 |  Destructores  |
-----------------*/

void destruirArbol(ArbolP arbol){
    free(arbol);
}

/*------------------------------
 | Procedimientos individuales |
------------------------------*/

int buscarPosicionLibre(ArbolP arboles[]){

    int posicionLibre = -1;

    for(int i = 0; i < CANT_ARBOLES; i++){

        if(arboles[i]->edad == -1){

            posicionLibre = i;
            i = CANT_ARBOLES;
        }
    }
    return posicionLibre;
}

void mostrarArbol(ArbolP arbol){

    // Si el Arbol esta cargado
    if(arbol->edad != -1){

        printf("\n------ ARBOL ------\n");
        printf("Nombre: %s\n", arbol->especie);
        printf("Edad: %d\n", arbol->edad);
        printf("Altura: %.2f\n", arbol->altura);
    }
}

void agregarArbol(ArbolP arboles[]){

    int posicionLibre = buscarPosicionLibre(arboles);

    if(posicionLibre != -1){

        arboles[posicionLibre] = crearArbolPorTeclado();
    }
}

void modificarArbol(ArbolP arboles[], char nombreArbol[]){

    int encontrado = -1;

    for(int i = 0; i < CANT_ARBOLES; i++){

        if(strcmp(arboles[i]->especie, nombreArbol) == 0){

            encontrado = 1;

            printf("\nIngrese nueva edad para \"%s\" (actual: %d): ", arboles[i]->especie, arboles[i]->edad);
            scanf("%d", &arboles[i]->edad);

            printf("\nIngrese nueva altura para \"%s\" (actual: %.2f): ", arboles[i]->especie, arboles[i]->altura);
            scanf("%f", &arboles[i]->altura);

            printf("\nModificado con exito!\n");
        }
    }

    if(encontrado == -1){

        printf("\nNo se encontro arbol con nombre \"%s\", pruebe con otro nombre", nombreArbol);
    }
}

void eliminarArbol(ArbolP arboles[], char nombreArbol[]){

    for(int i = 0; i < CANT_ARBOLES; i++){

        if(strcmp(arboles[i]->especie, nombreArbol) == 0){

            // Lo seteamos como vacio
            strcpy(arboles[i]->especie, "");
            arboles[i]->edad = -1;
            arboles[i]->altura = -1.00;
        }
    }
}

/*-----------------------------
 | Procedimientos de arreglo  |
-----------------------------*/

void inicializarArboles(ArbolP arboles[]){

    for(int i = 0; i < CANT_ARBOLES; i++){

        // Arboles vacios
        arboles[i] = crearArbol("", -1, -1.00);
    }
}

void agregarArboles(ArbolP arboles[], int cantidadAgregar){

    for(int i = 0; i < cantidadAgregar; i++){

        agregarArbol(arboles);
    }
}

void mostrarArboles(ArbolP arboles[]){

    for(int i = 0; i < CANT_ARBOLES; i++){

        mostrarArbol(arboles[i]);
    }
}

/*-----------------------------
 | Procedimientos de archivo  |
-----------------------------*/

void agregarArbolesArchivo(ArbolP arboles[]){

    FILE * archivoArboles = fopen("arboles.txt", "a");      // Abro el archivo

    if(archivoArboles != NULL){

        for(int i = 0; i < CANT_ARBOLES; i++){

            if(arboles[i]->edad != -1){     // Si el arbol fue cargado correctamente

                // Lo guardo en el archivo -> especie+edad+altura
                fprintf(archivoArboles, "%s+%d+%.2f\n", arboles[i]->especie, arboles[i]->edad, arboles[i]->altura);
            }
        }
    }

    fclose(archivoArboles);     // Cierro el archivo
}

void sobreescribirArboles(ArbolP arboles[]){

    FILE * archivoArboles = fopen("arboles.txt", "w");      // Abro el archivo

    if(archivoArboles != NULL){

        for(int i = 0; i < CANT_ARBOLES; i++){

            if(arboles[i]->edad != -1){     // Si el arbol fue cargado correctamente

                // Lo guardo en el archivo -> especie+edad+altura
                fprintf(archivoArboles, "%s+%d+%.2f\n", arboles[i]->especie, arboles[i]->edad, arboles[i]->altura);
            }
        }
    }

    fclose(archivoArboles);     // Cierro el archivo
}

ArbolP TransformarTextoAArboles(char datos[50]){

    int posPrimerDelimitador = -1;
    int posSegundoDelimitador = -1;

    char especieArbol[30] = "";
    char edadArbol[5] = "";
    char alturaArbol[5] = "";

    // Buscamos primer delimitador
    for(int i = 0; i < CADENA_DATOS; i++){      // Arranco de 0

        if(datos[i] == '+'){                    // Corto si encuentro delimitador

            posPrimerDelimitador = i;           // Guardo la pos
            i = CADENA_DATOS;                   // Salgo del for
        }
    }

    // Buscamos segundo delimitador
    for(int i = posPrimerDelimitador + 1; i < CADENA_DATOS; i++){       // Arranco despues del primer delimitador

        if(datos[i] == '+'){                                            // Corto si encuentro delimitador

            posSegundoDelimitador = i;                                  // Guardo la pos
            i = CADENA_DATOS;                                           // Salgo del for
        }
    }

    // Separamos los datos: nombre
    for(int i = 0; i < posPrimerDelimitador; i++){      // Recorro desde el principio hasta el primer delimitador

        especieArbol[i] = datos[i];                      // Voy guardando el nombre caracter por caracter
    }
    especieArbol[strlen(especieArbol)] = '\0';            // Marco el final de la cadena

    // Separamos los datos: edad
    for(int i = posPrimerDelimitador + 1; i < posSegundoDelimitador; i++){      // Recorro desde el primer hasta el segundo delimitador

        edadArbol[i - posPrimerDelimitador - 1] = datos[i];                     // Voy guardando el nombre caracter por caracter
    }
    edadArbol[strlen(edadArbol)] = '\0';                                        // Marco el final de la cadena

    // Separamos los datos: altura
    for(int i = posSegundoDelimitador + 1; i < strlen(datos); i++){       // Recorro desde el segundo delimitador hasta el final

        alturaArbol[i - posSegundoDelimitador - 1] = datos[i];            // Voy guardando el nombre caracter por caracter
    }
    alturaArbol[strlen(alturaArbol)]= '\0';                               // Marco el final de la cadena
    return crearArbol(especieArbol, atoi(edadArbol), atof(alturaArbol));   // Creo el arbol casteando los datos
}

void cargarArboles(ArbolP arboles[]){

    FILE * archivoArboles = fopen("arboles.txt", "r");      // Abro 'arboles.txt'

    char datos[CADENA_DATOS] = "";

    int i = 0;

    while((fgets(datos, CADENA_DATOS, archivoArboles)) && (i < CANT_ARBOLES)){      // Voy leyendo el archivo

        arboles[i] = TransformarTextoAArboles(datos);       // Guardo los datos en el array del tipo Arbol
        i++;
    }

    fclose(archivoArboles);
}
