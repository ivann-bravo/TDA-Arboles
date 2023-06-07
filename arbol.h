/*-------------------------
 | Arbol.h
 | Alumno: Ivan Bravo
-------------------------*/

#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

/*-----------------
 |    Axiomas     |
-----------------*/

// especie: Menos de 30 caracteres
// edad: Entero mayor a 0
// altura: Flotante mayor a 0
struct ArbolE;

typedef struct ArbolE * ArbolP;

/*-----------------
 | Constructores  |
-----------------*/

// PRE: -
// POST: Devuelve un Arbol
ArbolP crearArbol(char especie[], int edad, float altura);

// PRE: Se ingresa por teclado
// POST: Devuelve un Arbol
ArbolP crearArbolPorTeclado();

/*-----------------
 |  Destructores  |
-----------------*/

// PRE: Debe existir arbol
// POST: Libera la memoria ocupada por arbol
void destruirArbol(ArbolP arbol);

/*------------------------------
 | Procedimientos individuales |
------------------------------*/

// PRE: Debe existir el array
// POST: Devuelve un entero que sera usado en otras funciones
// RETURN: -1 si no hay mas espacio, [-1 < n < 100] si lo hay
int buscarPosicionLibre(ArbolP arboles[]);

// PRE: El arbol debe estar correctamente cargado. -> Edad != -1
// POST: Muestra todos los datos del Arbol por pantalla
void mostrarArbol(ArbolP arbol);

// PRE: Debe existir el array y tambien debe haber espacio. -> buscarPosicionLibre()
// POST: Agrega un Arbol en alguna posicion libre, por teclado
void agregarArbol(ArbolP arboles[]);

// PRE: Debe existir el Arbol a modificar
// POST: Modifica la edad y altura del Arbol
void modificarArbol(ArbolP arboles[], char nombreArbol[]);

// PRE: Debe existir el Arbol a eliminar
// POST: Setea la posicion que ocupaba el Arbol como 'vacio'. -> Edad = -1
void eliminarArbol(ArbolP arboles[], char nombreArbol[]);

/*-----------------------------
 | Procedimientos de arreglo  |
-----------------------------*/

// PRE: Debe existir el array
// POST: Setea las edades y las alturas en -1
void inicializarArboles(ArbolP arboles[]);

// PRE: Debe existir el array y cantidadAgregar > 0
// POST: Agrega una cantidad especifica de arboles en las posiciones libres
void agregarArboles(ArbolP arboles[], int cantidadAgregar);

// PRE: Debe existir el array y los Arboles deben estar correctamente cargador. -> Edad != -1
// POST: Muestra todos los datos de los Arboles
void mostrarArboles(ArbolP arboles[]);

/*-----------------------------
 | Procedimientos de archivo  |
-----------------------------*/

// PRE: Debe existir 'arboles.txt' y el array pasado por parametro
// POST:  Agrega 'arboles.txt' con todos los datos del array
void agregarArbolesArchivo(ArbolP arboles[]);

// PRE: Debe existir 'arboles.txt' y el array pasado por parametro
// POST:  Sobreescribe 'arboles.txt' con todos los datos del array
void sobreescribirArboles(ArbolP arboles[]);

// PRE: Recibe una cadena de texto con el formato '%s+%d+%.2f\n'. Menos de 50 caracteres
// POST: Devuelve un ArbolP con los datos cargados ---> crearArbol()
ArbolP TransformarTextoAArboles(char datos[50]);

// PRE: Debe existir 'arboles.txt' y el array pasado por parametro
// POST: Carga los datos en cada posicion del array
void cargarArboles(ArbolP arboles[]);

#endif // ARBOL_H_INCLUDED
