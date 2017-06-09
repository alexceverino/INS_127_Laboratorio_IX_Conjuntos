#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct nodo{
	int dato;
	struct nodo *sgte;
}Nodo;

typedef struct conjunto{
	int tam;
	Nodo *ini;
	Nodo *fin;
}Conjunto;

Conjunto *crearConjunto(){
	//Funcion que inicializa una variable tipo lista
	Conjunto *L;
	L = (Conjunto*)malloc(sizeof(Conjunto)); // un espacio de memoria
	L->ini = NULL;
	L->fin = NULL;
	L->tam = 0;
	return L;
}

void insertarElemento(Conjunto *L,int valor){
	Nodo *nodonuevo; 
	if	(nodonuevo = (Nodo*)malloc(sizeof(Nodo))){
		nodonuevo->dato = valor;
		nodonuevo->sgte = NULL;
		if (L->tam == 0){
			L->ini = nodonuevo;
			L->fin = nodonuevo;
		}else{
			nodonuevo->sgte = L->ini;
			L->ini = nodonuevo;
		}
		L->tam = L->tam +1;
	}else{
		printf("ERROR: MEMORIA NO ASIGNADA");
	}

}

void imprimirConjunto(Conjunto *L){
	int i;
	Nodo *aux = L->ini;
	for (i=0;i<L->tam;i++){
		printf(" %i ",aux->dato);
		aux = aux->sgte;
	}
}


