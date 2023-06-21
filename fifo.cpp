#include "iostream"
//Andrades Mondragon Kevin 
using namespace std;

struct nodo{
	int val;
	nodo *sig;
};
nodo *cab, *aux, *aux2;

int registrar(){
	if(cab==NULL){
		cab = (struct nodo *) malloc(sizeof(nodo));		
		cout<<cab<<endl;		
		cout<<"Ingrese el valor del nodo";
		cin>>cab->val;
		cab->sig = NULL;
	}
	else {
		aux = (nodo *) malloc(sizeof(nodo));		
		cout<<aux<<endl;		
		cout<<"Ingrese el valor del nodo";
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
		cout<<aux->val<<" ";
	return 0;
}

int main(){
	int opc;
	do{
		cout<<"1. Registrar Nodo"<<endl;
		cout<<"2. Mostrar Nodos"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>opc;
		switch(opc){
			case 1: registrar(); break;
			case 2: mostrar(); break;
			default: cout<<"Opcion invalida..."<<endl;
		}
	}while(opc!=3);
}



