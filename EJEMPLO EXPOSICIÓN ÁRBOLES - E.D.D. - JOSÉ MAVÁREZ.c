#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char*postorden;
char*inorden="IABEGLDCFMKHJ";
char*preorden="GEAIBMCLDFKJH"

void post(char*pre,char*in,char*posto, int n){
	int longizq;
	if(n!=0){
		Posto[n-1]=pre[0];
		Longizq=strchr(in,pre[0])-in;
		Post(pre+1,in,posto,longizq);
		Post(pre+1+longizq, in+1+longizq,posto+longizq, n-1-longiz1);
	}
}

int main(int arg, char*argv[]){
	int aux;
	aux=strlen(preorden);
	postorden=(char*)malloc(aux*sizeof(char));
	if(postorden){
		printf("El recorrido en preorden es: %s \n", preorden);
		printf("El recorrido en inorden es: %s \n", inorden);
		Post(preorden, inorden, postorden, aux);
		Postorden[aux]='\0';
		printf ("El recorrido en postorden es: %s \n", postorden);
		free(postorden);
	}else{
		fprintf(stderr, "Error. No hay memoria \n");
		return 1;
	}
	return 0;
}
