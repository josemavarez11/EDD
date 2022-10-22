#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct nodo{  //Declaración de estructura.
	int dato;
	struct nodo*siguiente;
}nodo;

nodo*primero=NULL; //Nodo apuntando al primero.
nodo*ultimo=NULL; //Nodo apuntando al ultimo.

void insertarNodo(); //Creando la función para insertar el nodo.
void recorrerLista(); //Creando la función para recorrer la lista.

int main(){ //Función principal.
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	insertarNodo();
	printf("\n La lista ingresada es: \n");
	recorrerLista();
	
	return 0;
}

void insertarNodo(){
	nodo*nuevo=(nodo*)malloc(sizeof(nodo)); //Para insertar un nodo, debemos crearlo primero.
	printf("\n Introduce un dato para el nuevo nodo: \n"); //Aquí pedimos que se ingrese el dato declarado en la estructura para introducirlo al nodo.
	scanf("%d",&nuevo->dato);
	
	if(primero==NULL){
		primero=nuevo;
		primero->siguiente=primero;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=primero;
		ultimo=nuevo;
	}
	printf("\nEl nodo se ha ingresado exitosamente! \n");
}

void recorrerLista(){
	nodo*actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	if(primero!=NULL){
		do{
			printf("\n %d",actual->dato);
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		printf("\n La lista se encuentra vacia! \n");
	}
}
