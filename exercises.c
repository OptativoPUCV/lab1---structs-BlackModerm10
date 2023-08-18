#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
             max = arr[i];
        }
    }
    return max; 
}
/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
    int izq = 0;            
    int der = size - 1;    

    while (izq < der) {
        int temp = arr[izq];
        arr[izq] = arr[der];
        arr[der] = temp;

        izq++;
        der--;
    }
}
/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int* filterEvenNumbers(const int arr[], int size, int *newSize) 
{
    int evenCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        }
    }
    
    int* evenArray = (int*)malloc(evenCount * sizeof(int));
    
    if (evenArray == NULL) {
        *newSize = 0;
        return NULL;
    }
    
    int temp = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evenArray[temp] = arr[i];
            temp++;
        }
    }
    
    *newSize = evenCount;
    return evenArray;
}
/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,
                       int result[]) 
{
    int temp1 = 0;  
    int temp2 = 0;  
    int mergeTemp = 0;  
    
    while (temp1 < size1 && temp2 < size2) {
        if (arr1[temp1] <= arr2[temp2]) {
            result[mergeTemp] = arr1[temp1];
            temp1++;
        } else {
            result[mergeTemp] = arr2[temp2];
            temp2++;
        }
        mergeTemp++;
    }
    
    while (temp1 < size1) {
        result[mergeTemp] = arr1[temp1];
        temp1++;
        mergeTemp++;
    }

    while (temp2 < size2) {
        result[mergeTemp] = arr2[temp2];
        temp2++;
        mergeTemp++;
    }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{ 
  int ascendente = 1;
  int descendente = 1;
  
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      ascendente = 0;
    }
    if (arr[i] > arr[i - 1]) {
      descendente = 0;
    }
  }

  if (ascendente) {
    return 1;
  } else if (descendente) {
    return -1;
  } else {
    return 0;
  }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) 
{
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion =  anioPublicacion;
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) {
    Nodo *primero = NULL; // Puntero al primer nodo de la lista
    Nodo *actual = NULL;  // Puntero al nodo actual

    for (int i = 0; i < size; i++) {
        Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo)); // Crear un nuevo nodo

        if (nuevoNodo == NULL) {
            // Manejo de error si la asignación de memoria falla
            return NULL;
        }

        nuevoNodo->numero = arr[i];
        nuevoNodo->siguiente = NULL;

        if (actual == NULL) {
            // Si es el primer nodo, actual y primero apuntan al nuevo nodo
            actual = nuevoNodo;
            primero = nuevoNodo;
        } else {
            // Enlazar el nodo actual al nuevo nodo
            actual->siguiente = nuevoNodo;
            actual = nuevoNodo; // Mover actual al nuevo nodo
        }
    }

    return primero; // Devolver un puntero al primer nodo de la lista
}
