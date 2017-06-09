#include<stdio.h>
#include<stdlib.h>
#include<math.h>


void imprimirBin(int numero){
	int contador = pow(2,15);
	for (contador;contador>0;contador>>=1){
		if(contador&numero){
			printf("1");
		}else{
			printf("0");
		}
	} 
}

void insertar(int *conjunto,int n){
	if((*conjunto>>n)%2){
		printf("\nElemento %i ya ingresado",n);
	}else{
		*conjunto = *conjunto|(1<<1);
		printf("\nElemento %i ingresado",n);
	}
}

int main(){
	//A = {4,5,2,8,7};
	int A;
	A = (1<<4)|(1<<5)|(1<<2)|(1<<8)|(1<<7);
	int B;
	//B = {0,1,3,4,5}
	B = (1<<0)|(1<<1)|(1<<3)|(1<<4)|(1<<5);
	
	printf("\nA  :  ");
	imprimirBin(A);
	printf("\nB  :  ");
	imprimirBin(B);
	printf("\n");
	printf("\nA and B : ");
	imprimirBin(A&B);
	printf("\n");
	printf("\nA or B  : ");
	imprimirBin(A|B);
	printf("\n");
	printf("\n(A - B) U (B + A)  :  ");
	//B+A = se toma como la interseccion
	int C = (A&(~B))|(B&A);
	imprimirBin(C);
	printf("\n\nInsertar 1 y 2 en A  :  ");
	printf("\n");
	insertar(&A,2);
	insertar(&A,1);
	printf("\n\n A : ");
	imprimirBin(A);
	printf("\n");
	printf("\nInsertar 5 y 4 en B  :  ");
	printf("\n");
	insertar(&B,5);
	insertar(&B,4);
	printf("\n\n B : ");
	imprimirBin(B);
	//Con los nuevo conjuntos conjuntos de A y B
	printf("\n\nInterseccion  A y B : ");imprimirBin(A&B);
	printf("\n\nUnion  A y B : ");imprimirBin(A|B);
	return 0;
}
