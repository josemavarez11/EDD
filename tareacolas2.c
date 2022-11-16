#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct producto{ //Declaramos la estructura para los productos.
	char nombre[15];
	int cantidad;
	float precio;
}Producto; 

typedef struct nodo{ //Declaramos la estructura para los nodos.
	Producto *dato;
	struct nodo*siguiente;
}Nodo;

typedef struct cola{ //Declaramos la estructura para la cola.
	struct nodo*primero, *ultimo;
	int total; //Contador para saber cuántos elementos hay en la cola.
}Cola;

Producto*crearProducto(char nombre[15], int cantidad, float precio){ //función para crear el producto.
	Producto*aux=(Producto*)malloc(sizeof(Producto));
	strcpy(aux->nombre, nombre);
	aux->cantidad=cantidad;
	aux->precio=precio;
	return aux;
}

Nodo*crearNodo(Producto*producto){ //función para crear el nodo.
	Nodo*aux=(Nodo*)malloc(sizeof(Nodo));
	aux->dato=producto;
	aux->siguiente=NULL;
}

Cola*crearCola(){ //función para crear la cola.
	Cola*aux=(Cola*)malloc(sizeof(Cola));
	aux->primero=aux->ultimo=NULL;
	aux->total=0;
	return aux;
}

int estaVacia(Cola*cola){ //funcion para verificar si la cola esta vacia.
	if(cola->total==0){
		return 1;
	}else{
		return 0;
	}
}

void insertar(Cola*cola, Nodo*aux){
	struct nodo*nuevo=crearNodo(Producto *producto);
	if(estaVacia(cola)){
		(cola)->primero=(cola)->ultimo=nuevo;
		return;
	};
	(cola)->ultimo->siguiente=nuevo;
	(cola)->ultimo=nuevo;
}

Producto  borrar( struct cola ** aux){
     if( (*aux )->primero==NULL  )  return INT_MIN;

     //que ocurrre si la cola no esta vacia
     struct nodo *eliminado = (*aux)->primero ;
     Producto producto = eliminado->producto;

      //eliminamos el nodo de la cola
      (*aux) ->primero = eliminado->siguiente;

      if((*aux)->primero==NULL){
        (*aux)->ultimo = NULL;
      }

      free(eliminado);

      return producto;
}

void mostrar ( struct cola ** aux){
    if ( (*aux )->primero==NULL) return ;

    //si no esta vacia
    printf("Primero %d \n  Ultimo : %d \n", (*aux )->primero->producto, (*aux )->ultimo->producto );


    struct nodo* actual  = (*aux )->primero;

    while(actual){
        printf ("%d,  ", actual->producto);
        actual = actual ->siguiente;
    }

    printf ("\n----------\n ");
}

int main(){
	struct cola  * c = crearCola();
    insertar("pasta",2, 25, &c);
    insertar("sopa", 1, 15, &c);
    insertar("hamburguesa", 3, 12, &c);
    insertar("pollo", 2, 15 , &c);

    mostrar( &c);

    for( int i = 0; i < 5 ; i++){
        printf("Eliminado %d \n", borrar(&c));
        mostrar(&c);
    };
	return 0;
}



