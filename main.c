/*-------------------------
 | main.c
 | Alumno: Ivan Bravo
-------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

#define CANT_ARBOLES 100
#define ARBOLES_A_AGREGAR 3

int main(){

    ArbolP arboles[CANT_ARBOLES];

    printf("Cargando los datos guardados en arboles.txt . . .\n");
    inicializarArboles(arboles);
    printf("\nCargados con exito!\n");

    printf("\nAhora, agregue %d arboles\n", ARBOLES_A_AGREGAR);
    agregarArboles(arboles, ARBOLES_A_AGREGAR);

    printf("\nCargando los nuevos arboles en arboles.txt . . .\n");
    agregarArbolesArchivo(arboles);
    printf("\nCargados con exito!\n");

    cargarArboles(arboles);

    printf("\nEstos son los arboles cargados en arboles.txt . . .\n");
    mostrarArboles(arboles);

    printf("\n");
    system("pause");

    printf("\nAhora, vamos a modificar a 'Laurel' . . .\n");
    modificarArbol(arboles, "Laurel");

    printf("\nEstos son los arboles a dejar en arboles.txt . . .\n");
    mostrarArboles(arboles);

    printf("\n");
    system("pause");

    printf("\nEliminando 'Cocotero' de los arboles . . .\n");
    eliminarArbol(arboles, "Cocotero");
    printf("\nEliminado con exito!\n");

    printf("\nEliminando 'Falsa Acacia' de los arboles . . .\n");
    eliminarArbol(arboles, "Falsa Acacia");
    printf("\nEliminado con exito!\n");

    printf("\nEstos son los arboles a dejar en arboles.txt . . .\n");
    mostrarArboles(arboles);

    printf("\nSobreescribiendo los datos guardados en arboles.txt . . .\n");
    sobreescribirArboles(arboles);
    printf("\nProceso finalizado con exito!\n");

    printf("\nEsperemos que haya disfrutado la experiencia. Nos vemos pronto! ;)\n");
    printf("\nLiberando la memoria . . .\n");
    destruirArbol(arboles);

    return 0;
}
