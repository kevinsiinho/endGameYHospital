#include <malloc.h>
#include <iostream>

using namespace std;

struct jugador{
	char nombre[10];
	int gol;
	jugador *izq;
	jugador *der;
};

jugador *raiz, *aux, *aux2;

 int posicionar(){
	if(aux->gol < aux2->gol){
		if(aux2->izq!=NULL){
			aux2=aux2->izq;
			posicionar();
		}
		else{
		aux2->izq=aux;
		}
	}
	else{
	
	if(aux->gol > aux2->gol){
		if(aux2->der!=NULL){
			aux2=aux2->der;
			posicionar();
		}
		else{
			aux2->der= aux;
		}
	}
	}
	
	return 0;	
}

int registrar(){
	aux=(struct jugador*) malloc(sizeof(struct jugador));
	cout<<"Ingrese nombre: ";
	cin>>aux->nombre;
	cout<<"Ingrese goles: ";
	cin>>aux->gol;
	aux->izq=aux->der=NULL;
	
	if(raiz==NULL){
		raiz=aux;
		aux=NULL;
		free(aux);
	}
	else{
		aux2=raiz;
		posicionar();
	}
	
	return 0;
}

int preorden( jugador *recursive){
	cout<<"Nombre: "<<recursive->nombre <<endl;
	cout<<"Goles: "<<recursive->gol <<endl;
	if(recursive->izq !=NULL){
		preorden(recursive->izq);
	}
	if(recursive->der!=NULL){
		preorden(recursive->der);
	}
	return 0;
}

int recorrer(){
 aux=raiz;
 if(aux!=NULL){
 	preorden(aux);
 }	
 
 return 0;
}

int main(){
	int op;
	do{
	cout<<"1.Registrar"<<endl;
	cout<<"2.Recorer"<<endl;
	cout<<"3.Salir"<<endl;
	cout<<"Selecione una opcion: ";
	cin>>op;
	switch(op){
		case 1: registrar(); break;
		case 2: recorrer(); break;
		default: cout<<"Error de opcion"<<endl;
	}
	 }while(op!=3);
	return 0;
}
