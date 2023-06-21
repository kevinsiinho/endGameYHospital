#include "iostream"
#include "malloc.h"
#include"conio.h"
#include"stdlib.h"

//Andrades Mondragon Kevin Arley
using namespace std;

struct nodo{
	int val;
	nodo *sig;
};
nodo *cab, *aux, *aux2;

int registrar(){
	if(cab==NULL){
		cab = (struct nodo *) malloc(sizeof(nodo));			
		cout<<"Ingrese el turno del cliente: ";
		cin>>cab->val;
		cab->sig = NULL;
	}
	else {
		aux = (nodo *) malloc(sizeof(nodo));				
		cout<<"Ingrese el turno del cliente: ";
		cin>>aux->val;
		aux->sig = NULL;
		aux2=cab; 
		while(aux2->sig!=NULL){
			aux2=aux2->sig;
		}
		aux2->sig = aux;
		aux2=aux = NULL;
		free(aux);
		free(aux2);	
	}	
	return 0;
}
int mostrar(){
	for(aux=cab; aux!=NULL; aux = aux->sig)
		cout<<"Cliente: "<<aux->val<<endl;
	return 0;
}

int atender(){
	if(cab==NULL){
		cout<<"Lista Vacida"<<endl;
	}else{
		cout<<"Cliente "<<cab->val<<" Atendido Exitosamente"<<endl;
		cab=cab->sig;
		}	
		return 0;
}


int main(){
	int opc;
	do{
		cout<<"1. Registrar turno"<<endl;
		cout<<"2. Mostrar turno"<<endl;
		cout<<"3. Atender turno"<<endl;
		cout<<"4. Salir"<<endl;
		cin>>opc;
		switch(opc){
			case 1: registrar(); break;
			case 2: mostrar(); break;
			case 3: atender(); break;
			default: cout<<"Opcion invalida..."<<endl;
		}
		system("pause");
		system("cls");
		
	}while(opc!=4);
}



