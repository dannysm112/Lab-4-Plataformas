#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;

void agregarNodoAlFinal(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void agregarNodoAlInicio(Nodo** cabeza, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

void eliminarNodoPorValor(Nodo** cabeza, int valor) {
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == valor) {
            if (anterior == NULL) {
                *cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            free(actual);
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }
}

void buscarNodoPorValor(Nodo* cabeza, int valor) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        if (actual->dato == valor) {
            printf("El valor %d existe en la lista.\n", valor);
            return;
        }
        actual = actual->siguiente;
    }
    printf("El valor %d no existe en la lista.\n", valor);
}

void obtenerElementoEnesimo(Nodo* cabeza, int indice) {
    int contador = 0;
    Nodo* actual = cabeza;

    while (actual != NULL) {
        if (contador == indice) {
            printf("Elemento en el índice %d: %d\n", indice, actual->dato);
            return;
        }
        contador++;
        actual = actual->siguiente;
    }
    printf("No existe un elemento en el índice %d.\n", indice);
}

void imprimirLista(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void liberarMemoria(Nodo* cabeza) {
    Nodo* actual = cabeza;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
}

int main() {
    Nodo* lista = NULL;

    agregarNodoAlFinal(&lista, 1);
    agregarNodoAlFinal(&lista, 2);
    agregarNodoAlFinal(&lista, 3);
    agregarNodoAlInicio(&lista, 0);
    agregarNodoAlFinal(&lista, 4);

    printf("Lista inicial: ");
    imprimirLista(lista);

    buscarNodoPorValor(lista, 2);

    eliminarNodoPorValor(&lista, 2);

    printf("Lista después de eliminar el valor 2: ");
    imprimirLista(lista);

    obtenerElementoEnesimo(lista, 2);

    liberarMemoria(lista); //Esto es para liberar antes de salir

    return 0;
}
