#include <stdio.h>
#include <stdlib.h>

//Definimos la estructura de un nodo
typedef struct nodo
{
    int num;
    struct nodo *siguiente;
    int cont;
} nodo;


void push(int num, nodo **tope ){

    //Creacion de un nuevo nodo
    nodo *nodoNuevo = malloc(sizeof(nodo));

    if(nodoNuevo ==  NULL){
        printf("La memoria no pudo ser asignada correctamente");
        return;
    }

    nodoNuevo->num = num;
    nodoNuevo-> siguiente = *tope;

    if (*tope == NULL) {
        nodoNuevo->cont = 1;  // Si la pila esta vacia, el contador comienza en 0
    } else {
        nodoNuevo->cont = (*tope)->cont + 1;  // Si no, se incrementa el contador del nodo superior
    }

    *tope = nodoNuevo;


}


int pop(nodo **tope){

    if(*tope == NULL){
        printf("La lista esta vacia")   ;
        return 0;
    }

    nodo *nodoTemp = *tope;


    int eliminado = nodoTemp->num;


    *tope = nodoTemp->siguiente;

    if (*tope != NULL) {
        (*tope)->cont = (*tope)->cont - 1;
    }

    free(nodoTemp);

    return eliminado;


}


void imprimirPila(nodo *tope){

    while(tope != NULL){
            printf("%i ->", tope->num);
            tope = tope->siguiente;
    }
}


int size(nodo *tope){
    if(tope == NULL){
        return 0;
    }

    int n = tope->cont;
    return n;
}

int isEmpty(nodo **tope){
    int n = 0;
    if(*tope != NULL){
        n = 1;
    }
    return n;
}


int main(){

    //Creacion de una pila aplicando la solución del error 2: paso por referencia y no por valor
    nodo *pila = NULL;

    push(10, &pila);
    push(20, &pila);
    push(30, &pila);

    imprimirPila(pila);

    printf("\nTope de la pila:%i\n", pila->num);
    printf("Tamanio de la pila:%i\n", size(pila));

    printf("Desapilando pila: \n");
    while(isEmpty(&pila) != 0){

        printf("%i ->", pop(&pila));
    }
    return 0;
}
