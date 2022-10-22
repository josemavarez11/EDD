/* PRÁCTICA No.1 LISTAS CIRCULARES.
Crear, insertar y eliminar nodos. Además de poder recorrer la lista.
José Mavárez. C.I. V-29.932.288
Laboratorio de E.D.D sección "A"
URU 2022-C */

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
void buscarNodo(); //Creando la función para buscar un nodo de la lista.
void borrarNodo(); //Creando la función para borrar un nodo de la lista.

int main(){ //Función principal.
	int menu=0;
	do{
		printf("\n *LISTA CIRCULARES para numeros enteros* \n");
		printf("\n -------------------------------------- \n");
		printf("\n 1. Insertar Nodo.          4. Recorrer Lista. \n");
		printf("\n 2. Buscar Nodo.            5. Salir. \n");
		printf("\n 3. Eliminar Nodo.                    \n");
		printf("\n --------------------------------------- \n");
		printf("\n Ingrese una opcion: \n");
		printf("\n --------------------------------------- \n");
		scanf("%d",&menu);
		switch(menu){
			case 1:
				system("cls");
				printf("\n *INSERTANDO UN NUEVO NODO EN LA LISTA* \n");
				printf("\n --------------------------------------- \n");
				insertarNodo();
				break;
			case 2:
				system("cls");
				printf("\n *BUSCANDO UN NODO EN LA LISTA* \n");
				printf("\n --------------------------------------- \n");
				buscarNodo();
				break;
			case 3:
				system("cls");
				printf("\n *ELIMINANDO UN NODO EN LA LISTA* \n");
				printf("\n --------------------------------------- \n");
				borrarNodo();
				break;
			case 4:
				system("cls");
				printf("\n LA LISTA INGRESADA ES: \n");
				printf("\n -------------------------------------- \n");
				recorrerLista();
				printf("\n -------------------------------------- \n");
				break;
			case 5:
				printf("\n El programa ha sido finalizado exitosamente! \n");
				break;
			default:
				system("cls");
				printf("\n Opcion no valida! Intente de nuevo: \n");
		}
	}while(menu!=5);	
	return 0;
}

void insertarNodo(){
	nodo*nuevo=(nodo*)malloc(sizeof(nodo)); //Para insertar un nodo, debemos crearlo primero.
	printf("\n Introduce un dato para el nuevo nodo: \n"); //Aquí pedimos que se ingrese el dato declarado en la estructura para introducirlo al nodo.
	scanf("%d",&nuevo->dato);
	system("cls");
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

void buscarNodo(){
	nodo*actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	int buscado=0, encontrado=0;
	printf("\n Ingrese el valor del nodo a buscar: \n");
	scanf("%d",&buscado);
	system("cls");
	if(primero!=NULL){
		do{
			if(actual->dato==buscado){
				printf("\n Nodo con el dato (%d) encontrado! \n", buscado);
				encontrado=1;
			}
			actual=actual->siguiente;
		}while(actual!=primero&&encontrado!=1);
		if(encontrado==0){
			printf("\n El nodo ingresado no fue encontrado! \n");
			}
		}else{
		printf("\n La lista se encuentra vacia! \n");	
	}
}

void borrarNodo(){
	nodo*actual=(nodo*)malloc(sizeof(nodo));
	actual=primero;
	nodo*anterior=(nodo*)malloc(sizeof(nodo));
	anterior=NULL;
	int buscado=0, encontrado=0;
	printf("\n Ingrese el valor del nodo a eliminar: \n");
	scanf("%d",&buscado);
	system("cls");
	if(primero!=NULL){
		while(actual!=NULL&&encontrado!=1){
			if(actual->dato==buscado){
				if(actual==primero){
					primero=primero->siguiente;
				}else if(actual==ultimo){
					anterior->siguiente=NULL;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
				}
				printf("\n El nodo ha sido eliminado exitosamente \n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->siguiente;
		}
		if(encontrado==0){
			printf("\n El nodo ingresado no fue encontrado! \n");
		}else{
			free (anterior);
		}
	}else{
		printf("\n La lista se encuentra vacia! \n");
	}
}

