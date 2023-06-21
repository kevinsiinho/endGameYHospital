#include <malloc.h>
#include <iostream>
#include <string.h>

using namespace std;

struct nodo{
    char placa[8];
    nodo *sig;
};

nodo *cab, *aux, *cab2,*aux2;
char placa2[8];
int registrar();
int consultar();
int eliminar();

int main(){
    int op;
    do{
        cout<<"1.Registrar Vehiculo"<<endl;
        cout<<"2.Retirar Vehiculo"<<endl;
        cout<<"3.Consultar Vehiculo"<<endl;
        cout<<"4.Salir "<<endl;
        cout<<"Escoja una opcion: ";
        cin>>op;
        switch(op){
        case 1: registrar (); break;
        case 2: eliminar (); break;
        case 3: consultar (); break;
        defaul: cout<<"Error de opcion"<<endl;
    }
    }while(op!=4);
    return 0;
}

int registrar(){
    aux=(struct nodo*)malloc(sizeof(struct nodo));
    cout<<"Ingrese placa: ";
    cin>>aux->placa;
    if(cab==NULL){
        cab=aux;
        cab->sig=NULL;
    }else{
        aux->sig=cab;
        cab=aux;
    }
    aux=NULL;
    free(aux);
    return 0;
}

int eliminar(){
   
	if(cab!=NULL){
		 cout<<"Ingrese la placa:";
    	 cin>>placa2;
         for(aux=cab; aux!=NULL;aux=aux->sig){
            if(strcmp(aux->placa,placa2)==0){
                cab=cab->sig;
                cout<<"Carro retirado exitosamente"<<endl;
				break;
            } else{
            	aux2=(struct nodo*)malloc(sizeof(struct nodo));
                strcpy(aux2->placa,aux->placa);
				if(cab2==NULL){
            		 cab2=aux2;
                    cab2->sig=NULL;
					cab=cab->sig;
                }else{
                	aux2->sig=cab2;
                    cab2=aux2;
					cab=cab->sig;
                }
            }
	}
	//Regresandolos
	for(aux2=cab2; aux2!=NULL;aux2=aux2->sig)
	{
		aux=(struct nodo*)malloc(sizeof(struct nodo));
		strcpy(aux->placa,aux2->placa);	
		if (cab==NULL)
		{
	        cab=aux;
	        cab->sig=NULL;
		}else{
		        aux->sig=cab;
		        cab=aux;
		    }
 }
    }else{
        cout<<"NO hay placas"<<endl;
    }
    aux=NULL;
    aux2=NULL;
    cab2=NULL;
    free(aux);
    free(aux2);
    free(cab2);
    return 0;
}
int consultar(){
	int cont=0;
	for(aux=cab; aux!=NULL; aux = aux->sig){
		cont++;
	 cout<<"La placa "<<cont<<" es : "<<aux->placa<<endl;
    }
    return 0;
}
