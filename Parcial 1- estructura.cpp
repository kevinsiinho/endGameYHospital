#include "iostream"
#include "malloc.h"
#include"conio.h"
#include"stdlib.h"
#include"string.h"

//Andrades Mondragon Kevin Arley
using namespace std;

struct nodo{
	char nombre[15],apellido[15];
	char barrio[15];
	char kr[5],cl[15],numcasa[10]; //carrera, calle y numero de la casa
	char  tel[10];
	double vcancelar;// Valor a cancelar 
	int menu;
	nodo *sig;	
};
nodo *cab, *aux, *aux2; 

struct nodo2{
 char nombre2[15],apellido2[15];
 char repartidor[15];
 char dr[50];
 double pago;
 char cel[10];
 int menu2;	
 char recivido_si[20]=" ", recivido_no[20]=" ";
 nodo2 *sig; 	
};
nodo2 *cab2, *ayu, *ayu2;

struct nodo3{
	char repartidor2[20];
	char name2[20],lastname2[20];
	double pago2;
	int menu3;	
	nodo3 *sig;
};
nodo3 *msn_cab, *msn_aux, *msn_aux2;

struct nodo4{
char name[20];
int num_msn;
	nodo4 *sig;	
};

nodo4 *msn_cab2, *msn_aux3, *msn_aux4;
int n;
int cont=0;
int op2,op3;
double valor=0;
int ord=0;
int rs=0,rn=0;
int m1=0,m2=0,m3=0,m4=0,m5=0,m6=0,m7=0,m8=0;
int contador=0,a;
int cant=0;
double cobrados_si=0,no_cobrados=0;	
char temp[20];

int enviar_msn();
int enviar_msn_copia();                                                          
int recividos_si(double co){
	cobrados_si=cobrados_si+co;
	rs++;
	return 0;
}

int recividos_no(double co2){
	no_cobrados=no_cobrados+co2;
	rn++;
	return 0;
}

int cont_menu(int bb2){
	int bb=bb2;	
	if(1==bb){
		m1++;
	}
	if(2==bb){
		m2++;
	}
	if(3==bb){
		m3++;
	}
	if(4==bb){
		m4++;
	}
	if(5==bb){
		m5++;
	}
	if(6==bb){
		m6++;
	}
	if(7==bb){
		m7++;
	}
	if(8==bb){
		m8++;
	}
	cant++; 
		return 0;
}

int menu(){
	int sel;
	do{
		cout<<" \t *** Opciones ***"<<endl;
		cout<<"1. Arroz chino"<<endl;
		cout<<"2. Sancocho"<<endl;
		cout<<"3. Pollo Azado"<<endl;
		cout<<"4. Carne"<<endl;
		cout<<"5. Ensalada"<<endl;
		cout<<"6. Pescado frito"<<endl;
		cout<<"7. Sopa de pescasdo"<<endl;
		cout<<"8. Arroz con pollo "<<endl;
		cout<<" Selecione un menu: ";
		cin>>op2;
		switch(op2){
		
		case 1: cout<<" Menu 1 ($ 10000) \n";
				valor=10000;
				sel=1;break;
		case 2: cout<<" Menu 2 ($ 15000) \n";
				valor=15000;
				sel=2;break;
		case 3: cout<<" Menu 3 ($ 9000) \n";
				valor=9000;
				sel=3;break;
		case 4:  cout<<" Menu 4 ($ 20000) \n";
				valor=20000;
				sel=4;
				break;
		case 5: cout<<" Menu 5 ($ 21000) \n";
				valor=21000;
				sel=5;
				break;
		case 6: cout<<" Menu 6 ($ 16000) \n";
				valor=16000;
				sel=6;
				break;
		case 7:  cout<<" Menu 7 ($ 17000) \n";
				valor=17000;
				sel=7;
				break;
		case 8: cout<<" Menu 8 ($ 8000) \n";
				valor=8000;
				sel=8;
				break;
		default: cout<<"Opcion invalida, precione el numero 2:("<<endl;
		}
		cout<<" Confirmar seleccion del menu (1.Si/2.No) "<<endl;
		cin>>op3;
	}while(op3==2);
				if(ord==1){//si es la cabeza
	 				cab->menu=sel;
	 				cab->vcancelar=valor;
					cout<<"Factura : Menu "<<cab->menu<<"- Valor a pagar $ "<<cab->vcancelar<<endl;
				 }else{
				 	aux->menu=sel;
				 	aux->vcancelar=valor;
					cout<<"Factura:  Menu "<<aux->menu<<"- Valor a pagar $ "<<aux->vcancelar<<endl;
				 }
	return 0;
}
                                                                             
int registrar(){
	cout<<" \t REGISTRO CLIENTE "<<endl;
	cout<<"si va ingresar espacio precione (-)\n";
	if(cab==NULL){
		cab = (struct nodo *) malloc(sizeof(nodo));			
		cout<<"Nombre: ";
		cin>>cab->nombre;
		cout<<"Apellido: ";
		cin>>cab->apellido;
		cout<<"Dirreccion "<<endl;
		cout<<"Barrio: ";
		cin>>cab->barrio;
		cout<<"Carrera: ";
		cin>>cab->kr;
		cout<<"Calle: ";
		cin>>cab->cl;
		cout<<"Numero de la casa: ";
		cin>>cab->numcasa;
		cout<<"Telefono: ";
		cin>>cab->tel;
		ord=1;
		menu();
		cab->sig = NULL;		
	}else{
		aux = (nodo *) malloc(sizeof(nodo));
		cout<<"Nombre: ";
		cin>>aux->nombre;
		cout<<"Apellido: ";
		cin>>aux->apellido;
		cout<<"Dirreccion:\n ";
		cout<<"Barrio: ";
		cin>>cab->barrio;
		cout<<"Carrera: ";
		cin>>aux->kr;
		cout<<"Calle: ";
		cin>>aux->cl;
		cout<<"Numero de la casa: ";
		cin>>aux->numcasa;
		cout<<"Telefono: ";
		cin>>aux->tel;
		ord=2;
		menu();
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

int consultar(){
	contador=0;
	if(cab==NULL){
		cout<<"Lista vacida"<<endl;
	}
	for(aux=cab;aux!=NULL;aux=aux->sig){
		contador++;
		cout<<"Turno: "<<contador<<endl;
		cout<<"Nombre: "<<aux->nombre<<" "<<aux->apellido<<endl;
		cout<<"Dirrecion: "<<"Barrio "<<aux->barrio<<" Kr "<<aux->kr<<" Cl "<<aux->cl<<" # "<<aux->numcasa<<endl;
		cout<<"Telefono: "<<aux->tel<<endl;
		cout<<"Menu: "<<aux->menu<<endl;
		cout<<"Valor a cancelar: "<<aux->vcancelar<<endl;
		cout<<"---------------------------------------------\n";
	}
	free(aux);
}

int mensajero(){
	cout<<" \t REGISTRO MENSAJERO "<<endl;
	cont++;
	if(msn_cab2==NULL){
		msn_cab2 = (struct nodo4 *) malloc(sizeof(nodo4));			
		cout<<"Nombre: ";
		cin>>msn_cab2->name;
		msn_cab2->num_msn=cont;
		cout<<"su numeor es "<<msn_cab2->num_msn<<endl;
		msn_cab2->sig = NULL;		
	}
	else{
		msn_aux3 = (struct nodo4 *) malloc(sizeof(nodo4));
		cout<<"Nombre: ";
		cin>>msn_aux3->name;
		msn_aux3->num_msn=cont;
		cout<<"su numeor es "<<msn_aux3->num_msn<<endl;
		msn_aux3->sig = NULL;
		msn_aux4=msn_cab2; 
		
		while(msn_aux4->sig!=NULL){
			msn_aux4=msn_aux4->sig;
		}
		msn_aux4->sig = msn_aux3;
		msn_aux4=msn_aux3 = NULL;
		free(msn_aux3);
		free(msn_aux4);	
	}
	return 0;
}

int entrega(){
	if(msn_cab==NULL){
		cout<<"Lista vacida\n";
	}else{
		cout<<" \t *** Entrega Mensajero ***"<<endl;
		cout<<"Mensajero: "<<msn_cab->repartidor2<<endl;	
		cout<<"Nombre: "<<msn_cab->name2<<" "<<msn_cab->lastname2<<endl;
		cout<<"Menu: "<<msn_cab->menu3<<endl;
		cout<<"Valor a cancelar: "<<msn_cab->pago2<<endl;
    	cout<<"(1.)Recividos - (2.)Rechazado: ";
		cin>>a;
		for(ayu=cab2;ayu!=NULL;ayu=ayu->sig){
		  if(strcmp(ayu->nombre2,msn_cab->name2)){                             //buscando el nobmre del nodo3 para compararlo con el nodo2
		   
		   if(1==a){
			recividos_si(ayu->pago);	
			strcpy(ayu->recivido_si,"si");
			}                                                      //mandando datos a los nodo2
		   else if(a==2){
			recividos_no(ayu->pago);
			strcpy(ayu->recivido_no,"no");
			}		
		}
	}
		}
		msn_cab=msn_cab->sig;
		free(ayu);
		return 0;				
}

int despachar(){
	int aa,rep;
do{
	aa=0;
	if(cab==NULL){
		cout<<"No hay despachos"<<endl;
	}else{
		if(msn_cab2==NULL){
			cout<<"No hay repartidores, registre uno"<<endl; //sino existe 
			mensajero();
			aa=1;
		}else{
		
		do{
		cout<<" Mensajeros:"<<endl;	
		for(msn_aux3=msn_cab2;msn_aux3!=NULL;msn_aux3=msn_aux3->sig){   //muestra los mensajeros registrados
			cout<<msn_aux3->num_msn<<"."<<msn_aux3->name<<endl;
		}	
		cout<<"Selecione un mensajero: ";
		cin>>rep;
		if(rep>cont){
			cout<<"Error de opcion"<<endl;
		}
		}while(rep>cont);
		
		for(msn_aux3=msn_cab2;msn_aux3!=NULL;msn_aux3=msn_aux3->sig){
		if(rep==msn_aux3->num_msn){
			strcpy(temp," ");
			strcpy(temp,msn_aux3->name);
		}
		}
		
		cout<<"Cliente \n"<<cab->nombre<<" "<<cab->apellido<<endl;
		cout<<"Dirrecion: "<<"Barrio "<<cab->barrio<<" Kr "<<cab->kr<<" Cl "<<cab->cl<<" # "<<cab->numcasa<<endl;
		cout<<"Telefono: "<<cab->tel<<endl;
		cout<<"Menu: "<<cab->menu<<endl;
		cout<<"Valor a cancelar: "<<cab->vcancelar<<endl;
		cout<<"Mensajero : "<<temp<<endl;
		cout<<" Despachado :) "<<endl;
		cont_menu(cab->menu);				
		enviar_msn();
		enviar_msn_copia();
		cab=cab->sig;
		}                           
}
	
}while(aa==1);	
	return 0;
}

int enviar_msn_copia(){
	if(msn_cab==NULL){	
		msn_cab = (struct nodo3 *) malloc(sizeof(nodo3));
		strcpy(msn_cab->name2,cab->nombre);
		strcpy(msn_cab->repartidor2,temp);				
		strcpy(msn_cab->lastname2,cab->apellido);
		msn_cab->pago2=cab->vcancelar;
		msn_cab->menu3=cab->menu;
		msn_cab->sig = NULL;
				
	}
	else{
		msn_aux = (struct nodo3 *) malloc(sizeof(nodo3));
		strcpy(msn_aux->name2,cab->nombre);
		strcpy(msn_aux->repartidor2,temp);
		strcpy(msn_aux->lastname2,cab->apellido);
		msn_aux->pago2=cab->vcancelar;
		msn_aux->menu3=cab->menu;
		msn_aux->sig = NULL;

		msn_aux2=msn_cab; 
		
		while(msn_aux2->sig!=NULL){
			msn_aux2=msn_aux2->sig;
		}
		msn_aux2->sig = msn_aux;
		msn_aux2=msn_aux2 = NULL;
		free(msn_aux);
		free(msn_aux2);	
		free(ayu);
		free(ayu2);	
	}
	return 0;
}

int enviar_msn(){
	
	if(cab2==NULL){
		cab2 = (struct nodo2 *) malloc(sizeof(nodo2));
		strcpy(cab2->recivido_si," ");
		strcpy(cab2->recivido_no," ");   //inicializando de nuevos las variables 
		strcpy(cab2->repartidor,temp);			
		strcpy(cab2->nombre2,cab->nombre);
		strcpy(cab2->apellido2,cab->apellido);
		strcpy(cab2->dr,cab->barrio);
		strcpy(cab2->cel,cab->tel);
		cab2->pago=cab->vcancelar;
		cab2->menu2=cab->menu;
		cab2->sig = NULL;
				
	}
	else{
		ayu = (struct nodo2 *) malloc(sizeof(nodo2));
		strcpy(ayu->recivido_si," ");
		strcpy(ayu->recivido_no," ");   //inicializando de nuevos las variables 
		strcpy(ayu->repartidor,temp);			
		strcpy(ayu->nombre2,cab->nombre);
		strcpy(ayu->apellido2,cab->apellido);
		strcpy(ayu->dr,cab->barrio);
		strcpy(ayu->cel,cab->tel);
		ayu->pago=cab->vcancelar;
		ayu->menu2=cab->menu;
		ayu->sig = NULL;		

		ayu2=cab2; 
		
		while(ayu2->sig!=NULL){
			ayu2=ayu2->sig;
		}
		ayu2->sig = ayu;
		ayu2=ayu = NULL;
		
	}
	return 0;
}

int control(){
	cout<<" \t *** Control de Venta ***"<<endl;
	cout<<"  Ventas de cada menu"<<endl;
	cout<<"| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |"<<endl;
	cout<<"  "<<m1<<"   "<<m2<<"   "<<m3<<"   "<<m4<<"   "<<m5<<"   "<<m6<<"   "<<m7<<"   "<<m8<<endl;
	cout<<"|  Datos cliente   |   Menu  |  Repartidor |"<<endl;
	for(ayu=cab2;ayu!=NULL;ayu = ayu->sig){
		cout<<"   "<<ayu->nombre2<<" "<<ayu->apellido2<<"\t "<<ayu->menu2 <<" \t "<<ayu->repartidor<<endl; 
	cout<<"   "<<ayu->dr<<endl;
		cout<<"   "<<ayu->pago<<"-------\t"<<ayu->recivido_si<<ayu->recivido_no <<endl;
		cout<<"   "<<ayu->cel<<endl;
		cout<<"---------------------------------------------------------"<<endl;
	    }		
		return 0;
		free(ayu);
}

int cierre(){
	cout<<" \t\t *** Cierre ***"<<endl;
	cout<<"|  Despachados  |   Entregados  |  Rechazados  |   Dinero cobrado  |   Perdida  |    Ganancia Neta   |"<<endl;
	cout<<" \t"<<cant<<"\t\t"<<rs<<"\t\t"<<rn<<"\t\t"<<cobrados_si<<"\t\t"<<no_cobrados<<"\t\t"<<cobrados_si-no_cobrados<<endl;
	m1=m2=m3=m4=m5=m6=m7=m8=0;
	no_cobrados=cobrados_si=cant=contador=ord=valor=0;
	rn=0;
	rs=0;
	cant=0;
	free(cab);
	free(aux);
	free(aux2);
	free(cab2);
	free(ayu);
	free(ayu2);
	free(msn_cab);
	free(msn_cab2);
	free(msn_aux);
	free(msn_aux2);
	free(msn_aux3);
	free(msn_aux4);
}

int main(){
		int op;  
		do{                
		cout<<" \t *** El congreso ***"<<endl;
		cout<<"1. Registrar Pedido"<<endl;
		cout<<"2. Consultar"<<endl;
		cout<<"3. Despachar"<<endl;
		cout<<"4. Entrega mensajero"<<endl;
		cout<<"5. Control de venta"<<endl;
		cout<<"6. Registro Mensajero"<<endl;
		cout<<"7. Cierre"<<endl;
		cout<<"8. Salir"<<endl;
		cin>>op;
		switch(op){
		case 1:registrar(); break;
		case 2:consultar(); break;
		case 3:despachar(); break;
		case 4:entrega(); break;
		case 5:control(); break;
		case 6:mensajero(); break; 
		case 7:cierre(); break; 
		default: cout<<"Opcion invalida..."<<endl;
		}
		system("pause");
		system("cls");
		
	}while(op!=8);
}

    
