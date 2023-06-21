#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;
struct C
{
	double documento,telefono;
	int cama_asig,cama_trans,ocupado;
	int piso_asig,piso_trans;
	int fila,columna;
	int nivel,eps2,seguro,dia;
	char tratamientos[20],medicamentos[20];
    double valor,porcentaje;
    char enfermedad[50];
    char nombre1[20],nombre2[20],apellido1[20],apellido2[20];
	char direccion[50],tipo_doc[30],fecha[20];
    char regimen[20],estado[20],eps[20],entidad[50];
    string verificar;
};
string enfer;
int op,op1,op2,cont,temp=1;
int x,y,i=1,w,z,c,d;
double cc,tvalor;
char aux[20];
string s="salida";
string e="Ingresado";
string t="tralado a otra entidad";
//pisos
C urgencias[3][3];
C consulgen[3][3];
C recuperaciones[3][3];
C intencivos[3][3];
C salidas[3][3];
C history[3][3];
//funciones
void urgencia();
void cgenerales();
void recuperacion();
void criticos();
void critico_recuperado();
void recuperado_critico();
void disponibilidad();
void salida();
void traslado();
void lista();
void consultas();
void tratamientos();
void medicamentos();
void atender();
void pagar();
void historial();

int main(){
	do
	{
		cout<<"\t\t ******| Hospital Hells pass |******"<<endl;
		cout<<"1.Urgencias"<<endl;
		cout<<"2.Consultas Generales"<<endl;
		cout<<"3.Consultas Pacientes"<<endl;
		cout<<"4.Historia clinica"<<endl;
		cout<<"5.Pagar"<<endl;
		cout<<"6.Salidas"<<endl;
		cout<<"7.Atender Paciente"<<endl;
		cout<<"8.Tralados de piso"<<endl;
		cout<<"9.Tralados de entidad"<<endl;
		cout<<"10.Mostrar disponibilidad"<<endl;
		cout<<"11.Mostrar Lista"<<endl;
		cout<<"12.Salir"<<endl;
		cout<<"Escoja una opcion: ";
		cin>>op;
		switch(op)
		{
			case 1: urgencia(); break;
			case 2: cgenerales(); break;
			case 3: consultas(); break;
			case 4: historial(); break;
			case 5: pagar(); break;
			case 6: salida(); break;
			case 7: atender(); break;
			case 8: cout<<"A que piso lo va trasladar"<<endl;
					cout<<"1.De Urgencias a Recuperacion"<<endl;
					cout<<"2.De urgencias a cuidados intencivos"<<endl;
					cout<<"3.De Recuperacion a cuidados intencivos"<<endl;
					cout<<"4.De Cuidados intencivos a recuperacion"<<endl;
					cout<<"Escoja una opcion:";
					cin>>op;
					switch (op)
					{
					case 1: recuperacion(); break;
					case 2: criticos(); break;
					case 3: recuperado_critico(); break;
					case 4: critico_recuperado(); break;
					default:cout<<"Error de opcion\n";
					break;
					}
			break;
			case 9:  traslado();break;
			case 10: disponibilidad(); break;
			case 11: lista(); break;
				default:cout<<"Error de opcion\n";
		}
		cout<<"\n Desea volver al menu principal(1.si/2.no):";
		cin>>op;
	system("cls");
	}while(op==1);
	return 0;
}

void urgencia(){
	
	do{
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<urgencias[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
	 //mostrando disponibilidad de urgencias
	 cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
	cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(urgencias[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Registrando Paciente"<<endl;
			      cout<<"Tipo de documento:"<<endl;
			   do{
			      cout<<"1. Cedula\n 2. Tarjeta de identidad\n 3. Registro Civil:"<<endl;
			      cin>>op;
			      switch(op){
			     	case 1: op=1; strcpy(urgencias[x][y].tipo_doc,"Cedula"); break;
			    	case 2: op=1; strcpy(urgencias[x][y].tipo_doc,"Tarjeta de identidad"); break;
			    	case 3: op=1; strcpy(urgencias[x][y].tipo_doc,"Registro civil"); break;
			    	default:cout<<"Error de opcion";
			        }
			     }while(op!=1);
			    
			       cout<<"Ingrese Numero del documento: ";
			      cin>>urgencias[x][y].documento;
			    
			  	  cout<<"Ingrese primer nombres: "; 
				  cin>>urgencias[x][y].nombre1;
				 
				  cout<<"Ingrese segundo nombres, si no tiene(-): "; 
			      cin>>urgencias[x][y].nombre2;
				 
				 cout<<"Ingrese primer apellido: "; 
				 cin>>urgencias[x][y].apellido1;
				 
    			 cout<<"Ingrese Segundo apellido, si no tiene(-): "; 
				 cin>>urgencias[x][y].apellido2;
				 
				  cout<<"Ingrese fecha de nacimiento (dia/mes/ano)): ";
    			  cin>>urgencias[x][y].fecha;
    			  
    			  cout<<"Ingrese Direccion: ";
    			  cin>>urgencias[x][y].direccion;
    			  
    			  cout<<"Ingrese Telefono: ";
    			  cin>>urgencias[x][y].telefono;
				  do{
    			  cout<<"Tiene: \n 1.EPS \n 2.Seguro \n 3. Ninguna: ";
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>urgencias[x][y].eps;
						       urgencias[x][y].eps2=1;
							   urgencias[x][y].porcentaje=0;
					  break;
				 case 2: urgencias[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(urgencias[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									urgencias[x][y].nivel=op;
									cin>>op;
									switch (op)
									{
									case 1: urgencias[x][y].porcentaje=25; break;
									case 2: urgencias[x][y].porcentaje=40; break;
									case 3: urgencias[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(urgencias[x][y].regimen,"Subsidiado"); 
							   			urgencias[x][y].porcentaje=5; break;
						   	default:cout<<"Error de opcion"; break;
				    	   } 
				case 3: cout<<"paga todo "<<endl;	break;	   
				  default: cout<<"error opcion"<<endl;
					  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
    			 		 
			  		 cout<<"Nivel de urgencia:"<<endl;
					   do{
					     cout<<"1. Leve\n 2. Grave\n 3. Critico:"<<endl;
			  			 cin>>op;
			   			 switch(op){
						   	case 1: op=1; strcpy(urgencias[x][y].estado,"Leve"); break;
						   	case 2: op=1; strcpy(urgencias[x][y].estado," Grave"); break;
						   	case 3: op=1; strcpy(urgencias[x][y].estado,"Critico"); break;
						   	default:cout<<"Error de opcion";
					       }
					    }while(op!=1);
			    
						    cout<<"\ncondicion clinica (enfermedad o dolencia): ";
			    			cin>>urgencias[x][y].enfermedad;
			    			cout<<"Piso asignado 1"<<endl;
			    		    urgencias[x][y].piso_asig=1;
			    		    urgencias[x][y].ocupado=1;
			 				urgencias[x][y].fila=x;
							urgencias[x][y].columna=y;
							//asignando numero de la cama
							for(w=0;w<3;w++)
							{
								for(z=0;z<3;z++)
								{
									cont++;
								if(x==w && y==z){
									cout<<"cama asignada: "<<cont<<endl;
									urgencias[x][y].cama_asig=cont;
								}
								}
								}			
			  				}else if(urgencias[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
	
		cout<<"\n Va a registrar de nuevo(1.si/2.no):";
		cin>>op1;
	 }while(op1==1);
}

//registrando en consultas generales
void cgenerales(){
	cout<<"\t Consultas generales"<<endl;
	do{
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<consulgen[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
	 //mostrando disponibilidad de urgencias
	 cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
	cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(consulgen[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Registrando Paciente"<<endl;
			      cout<<"Tipo de documento:"<<endl;
			   do{
			      cout<<"1. Cedula\n 2. Tarjeta de identidad\n 3. Registro Civil:"<<endl;
			      cin>>op;
			      switch(op){
			     	case 1: op=1; strcpy(consulgen[x][y].tipo_doc,"Cedula"); break;
			    	case 2: op=1; strcpy(consulgen[x][y].tipo_doc,"Tarjeta de identidad"); break;
			    	case 3: op=1; strcpy(consulgen[x][y].tipo_doc,"Registro civil"); break;
			    	default:cout<<"Error de opcion";
			        }
			     }while(op!=1);
			    
			       cout<<"Ingrese Numero del documento: ";
			      cin>>consulgen[x][y].documento;
			    
			  	  cout<<"Ingrese primer nombres: "; 
				  cin>>consulgen[x][y].nombre1;
				 
				  cout<<"Ingrese segundo nombres, si no tiene(-): "; 
			      cin>>consulgen[x][y].nombre2;
				 
				 cout<<"Ingrese primer apellido: "; 
				 cin>>consulgen[x][y].apellido1;
				 
    			 cout<<"Ingrese Segundo apellido, si no tiene(-): "; 
				 cin>>consulgen[x][y].apellido2;
				 
				  cout<<"Ingrese fecha de nacimiento (dia/mes/ano)): ";
    			  cin>>consulgen[x][y].fecha;
    			  
    			  cout<<"Ingrese Direccion: ";
    			  cin>>consulgen[x][y].direccion;
    			  
    			  cout<<"Ingrese Telefono: ";
    			  cin>>consulgen[x][y].telefono;
				  do{
    			  cout<<"selecione: \n 1.EPS \n 2.Seguro \n 3. Ninguna: ";
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>consulgen[x][y].eps;
						       consulgen[x][y].eps2=1;
							   consulgen[x][y].porcentaje=0;
					  break;
				 case 2: consulgen[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(consulgen[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									consulgen[x][y].nivel=op;
									cin>>op;
									switch (op)
									{
									case 1: consulgen[x][y].porcentaje=25; break;
									case 2: consulgen[x][y].porcentaje=40; break;
									case 3: consulgen[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(consulgen[x][y].regimen,"Subsidiado"); 
							   			consulgen[x][y].porcentaje=5; break;
						   	default:cout<<"Error de opcion"; break;
				    	   } 
				case 3: cout<<"paga todo "<<endl;	break;	   
				  default: cout<<"error opcion"<<endl;
					  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
    			 		 
			  		 cout<<"Nivel de urgencia:"<<endl;
					   do{
					     cout<<"1. Leve\n 2. Grave\n 3. Critico:"<<endl;
			  			 cin>>op;
			   			 switch(op){
						   	case 1: op=1; strcpy(consulgen[x][y].estado,"Leve"); break;
						   	case 2: op=1; strcpy(consulgen[x][y].estado," Grave"); break;
						   	case 3: op=1; strcpy(consulgen[x][y].estado,"Critico"); break;
						   	default:cout<<"Error de opcion";
					       }
					    }while(op!=1);
			    
						    cout<<"\ncondicion clinica (enfermedad o dolencia): ";
			    			cin>>consulgen[x][y].enfermedad;
			    			cout<<"Piso asignado 2"<<endl;
			    		    consulgen[x][y].piso_asig=2;
			    		    consulgen[x][y].ocupado=1;
			 				consulgen[x][y].fila=x;
							consulgen[x][y].columna=y;
			  				}
							else if(consulgen[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
	
		cout<<"\n Va a registrar de nuevo(1.si/2.no):";
		cin>>op1;
	 }while(op1==1);
	
}

//tranladando de urgencias a recuperacion
void recuperacion(){
	
	do{
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<recuperaciones[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Ingrese documento: ";
		cin>>cc;
			for(z=0;z<3;z++)
		{
			for(w=0;w<3;w++)
			{
				if(cc==urgencias[z][w].documento){
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(recuperaciones[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Traslando Paciente a Recuperacion"<<endl;
			
			   	    strcpy(recuperaciones[x][y].tipo_doc,urgencias[z][w].tipo_doc);
			     	recuperaciones[x][y].documento=urgencias[z][w].documento;
			        strcpy(recuperaciones[x][y].nombre1,urgencias[z][w].nombre1);
				 	strcpy(recuperaciones[x][y].nombre2,urgencias[z][w].nombre2);
				 	strcpy(recuperaciones[x][y].apellido1,urgencias[z][w].apellido1);
				 	strcpy(recuperaciones[x][y].apellido2,urgencias[z][w].apellido2);
				 	strcpy(recuperaciones[x][y].fecha,urgencias[z][w].fecha);
    			  	strcpy(recuperaciones[x][y].direccion,urgencias[z][w].direccion);
    			  	recuperaciones[x][y].telefono=urgencias[z][w].telefono;
    			  	strcpy(recuperaciones[x][y].eps,urgencias[z][w].eps);
					recuperaciones[x][y].eps2=urgencias[z][w].eps2;
					recuperaciones[x][y].seguro=urgencias[z][w].seguro;
					recuperaciones[x][y].nivel=urgencias[z][w].nivel;
					recuperaciones[x][y].porcentaje=urgencias[z][w].porcentaje;
	    			strcpy(recuperaciones[x][y].regimen,urgencias[z][w].regimen); 
			 		strcpy(recuperaciones[x][y].estado,urgencias[z][w].estado);
					strcpy(recuperaciones[x][y].enfermedad,urgencias[z][w].enfermedad);
			    	recuperaciones[x][y].piso_trans=3;
			    	recuperaciones[x][y].piso_asig=1;
			        recuperaciones[x][y].cama_asig=urgencias[x][y].cama_asig;
			      	recuperaciones[x][y].ocupado=1;
			 		recuperaciones[x][y].fila=x;
					recuperaciones[x][y].columna=y;
					//asignando numero de la cama
							for(w=0;w<3;w++)
							{
								for(z=0;z<3;z++)
								{
									cont++;
								if(x==w && y==z){
									cout<<"cama asignada: "<<cont<<endl;
									recuperaciones[x][y].cama_trans=cont;
								}
								}
								}		
					cout<<"Traslado exitosamente";
					i=0;
			  				}
							else if(recuperaciones[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
					
				}
			}
		
		}
		if(i==1){
			cout<<"Documento no encontrado";
		}
	 	cout<<"\n Desea volver(1.si/2.no):";
		cin>>op1;
			system("cls");
	}while(op1==1);
}

//tranladando de urgencias a cuidados intencivos
void criticos(){
	
	do{
	
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<intencivos[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Ingrese documento: ";
		cin>>cc;
			for(z=0;z<3;z++)
		{
			for(w=0;w<3;w++)
			{
				if(cc==urgencias[z][w].documento){
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(intencivos[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Traslando Paciente a Unidad Intencivo"<<endl;
			
			   	    strcpy(intencivos[x][y].tipo_doc,urgencias[z][w].tipo_doc);
			     	intencivos[x][y].documento=urgencias[z][w].documento;
			        strcpy(intencivos[x][y].nombre1,urgencias[z][w].nombre1);
				 	strcpy(intencivos[x][y].nombre2,urgencias[z][w].nombre2);
				 	strcpy(intencivos[x][y].apellido1,urgencias[z][w].apellido1);
				 	strcpy(intencivos[x][y].apellido2,urgencias[z][w].apellido2);
				 	strcpy(intencivos[x][y].fecha,urgencias[z][w].fecha);
    			  	strcpy(intencivos[x][y].direccion,urgencias[z][w].direccion);
    			  	intencivos[x][y].telefono=urgencias[z][w].telefono;
					intencivos[x][y].eps2=urgencias[z][w].eps2;
					intencivos[x][y].seguro=urgencias[z][w].seguro;
					intencivos[x][y].nivel=urgencias[z][w].nivel;
					intencivos[x][y].porcentaje=urgencias[z][w].porcentaje;
    			  	strcpy(intencivos[x][y].eps,urgencias[z][w].eps);
	    			strcpy(intencivos[x][y].regimen,urgencias[z][w].regimen); 
			 		strcpy(intencivos[x][y].estado,urgencias[z][w].estado);
					strcpy(intencivos[x][y].enfermedad,urgencias[z][w].enfermedad);
			    	intencivos[x][y].piso_asig=1;
			    	intencivos[x][y].piso_trans=4;
			        intencivos[x][y].cama_trans=urgencias[x][y].cama_asig;
					intencivos[x][y].ocupado=1;
			 		urgencias[z][w].ocupado=0;
					 intencivos[x][y].fila=x;
					intencivos[x][y].columna=y;
					//asignando numero de la cama
							for(w=0;w<3;w++)
							{
								for(z=0;z<3;z++)
								{
									cont++;
								if(x==w && y==z){
									cout<<"cama asignada: "<<cont<<endl;
									intencivos[x][y].cama_trans=cont;
								}
								}
								}		

					cout<<"Traslado exitosamente";
					i=0;
			  				}
							else if(intencivos[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
					
				}
			}
		
		}
		if(i==1){
			cout<<"Documento no encontrado";
		}
	 	cout<<"\n Desea volver(1.si/2.no):";
		cin>>op1;
			system("cls");
	 }while(op1==1);
}

//tranladando de recuperaciones a cuidados intencivos
void recuperado_critico(){
	
	do{
	
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<intencivos[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Ingrese documento: ";
		cin>>cc;
			for(z=0;z<3;z++)
		{
			for(w=0;w<3;w++)
			{
				if(cc==recuperaciones[z][w].documento){
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(intencivos[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Traslando Paciente a Unidad Intencivo"<<endl;
			
			   	    strcpy(intencivos[x][y].tipo_doc,recuperaciones[z][w].tipo_doc);
			     	intencivos[x][y].documento=recuperaciones[z][w].documento;
			        strcpy(intencivos[x][y].nombre1,recuperaciones[z][w].nombre1);
				 	strcpy(intencivos[x][y].nombre2,recuperaciones[z][w].nombre2);
				 	strcpy(intencivos[x][y].apellido1,recuperaciones[z][w].apellido1);
				 	strcpy(intencivos[x][y].apellido2,recuperaciones[z][w].apellido2);
				 	strcpy(intencivos[x][y].fecha,recuperaciones[z][w].fecha);
    			  	strcpy(intencivos[x][y].direccion,recuperaciones[z][w].direccion);
    			  	intencivos[x][y].telefono=recuperaciones[z][w].telefono;
					intencivos[x][y].eps2=recuperaciones[z][w].eps2;
					intencivos[x][y].porcentaje=recuperaciones[z][w].porcentaje;
					intencivos[x][y].seguro=recuperaciones[z][w].seguro;
					intencivos[x][y].nivel=recuperaciones[z][w].nivel;  
    			  	strcpy(intencivos[x][y].eps,recuperaciones[z][w].eps);
	    			strcpy(intencivos[x][y].regimen,recuperaciones[z][w].regimen); 
			 		strcpy(intencivos[x][y].estado,recuperaciones[z][w].estado);
					strcpy(intencivos[x][y].enfermedad,recuperaciones[z][w].enfermedad);
			    	intencivos[x][y].piso_asig=3;
			    	intencivos[x][y].piso_trans=4;
			        intencivos[x][y].cama_asig=recuperaciones[x][y].cama_asig;
					intencivos[x][y].ocupado=1;
			 		recuperaciones[z][w].ocupado=0;
					 intencivos[x][y].fila=x;
					intencivos[x][y].columna=y;
					//asignando numero de la cama
							for(w=0;w<3;w++)
							{
								for(z=0;z<3;z++)
								{
									cont++;
								if(x==w && y==z){
									cout<<"cama asignada: "<<cont<<endl;
									intencivos[x][y].cama_trans=cont;
								}
								}
								}	
					cout<<"Traslado exitosamente";
					i=0;
			  				}
							else if(intencivos[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
					
				}
			}
		
		}
		if(i==1){
			cout<<"Documento no encontrado";
		}
	 	cout<<"\n Desea volver(1.si/2.no):";
		cin>>op1;
			system("cls");
	 }while(op1==1);
}

//tranladando  cuidados intencivos a recuperacion
void critico_recuperado(){
	
	do{
	
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<recuperaciones[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Ingrese documento: ";
		cin>>cc;
			for(z=0;z<3;z++)
		{
			for(w=0;w<3;w++)
			{
				if(cc==intencivos[z][w].documento){
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			  		cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
		if(x>=0 && x<3)
		{
			if(y>=0 &&y<3)
				{
				if(intencivos[x][y].ocupado==0)
			 	{
			 			cout<<"\n Cama desocupada"<<endl;
			      cout<<"\n Traslando Paciente a Recuperacion"<<endl;
			
			   	    strcpy(recuperaciones[x][y].tipo_doc,intencivos[z][w].tipo_doc);
			     	recuperaciones[x][y].documento=intencivos[z][w].documento;
			        strcpy(recuperaciones[x][y].nombre1,intencivos[z][w].nombre1);
				 	strcpy(recuperaciones[x][y].nombre2,intencivos[z][w].nombre2);
				 	strcpy(recuperaciones[x][y].apellido1,intencivos[z][w].apellido1);
				 	strcpy(recuperaciones[x][y].apellido2,intencivos[z][w].apellido2);
				 	strcpy(recuperaciones[x][y].fecha,intencivos[z][w].fecha);
    			  	strcpy(recuperaciones[x][y].direccion,intencivos[z][w].direccion);
    			  	recuperaciones[x][y].telefono=intencivos[z][w].telefono;
					recuperaciones[x][y].eps2=intencivos[z][w].eps2;
					recuperaciones[x][y].seguro=intencivos[z][w].seguro;
					recuperaciones[x][y].nivel=intencivos[z][w].nivel;
    			  	recuperaciones[x][y].porcentaje=intencivos[z][w].porcentaje;
					strcpy(recuperaciones[x][y].eps,intencivos[z][w].eps);
	    			strcpy(recuperaciones[x][y].regimen,intencivos[z][w].regimen); 
			 		strcpy(recuperaciones[x][y].estado,intencivos[z][w].estado);
					strcpy(recuperaciones[x][y].enfermedad,intencivos[z][w].enfermedad);
			    	recuperaciones[x][y].piso_asig=4;
			    	recuperaciones[x][y].piso_trans=3;
			        recuperaciones[x][y].cama_asig=intencivos[x][y].cama_asig;
					recuperaciones[x][y].ocupado=1;
			 		intencivos[z][w].ocupado=0;
					 recuperaciones[x][y].fila=x;
					recuperaciones[x][y].columna=y;
					//asignando numero de la cama
							for(w=0;w<3;w++)
							{
								for(z=0;z<3;z++)
								{
									cont++;
								if(x==w && y==z){
									cout<<"cama asignada: "<<cont<<endl;
									recuperaciones[x][y].cama_trans=cont;
								}
								}
								}	
					cout<<"Traslado exitosamente";
					i=0;
			  				}
							else if(recuperaciones[x][y].ocupado==1){
								cout<<"Esta ocupado"<<endl;
					}				
				}
				else
				{
				cout<<"\n columna no existe"<<endl;
			  }

			}
			else
			{
			cout<<"\n Fila no existe"<<endl;
		 }
					
				}
			}
		
		}
		if(i==1){
			cout<<"Documento no encontrado";
		}
	 	cout<<"\n Desea volver(1.si/2.no):";
		cin>>op1;
			system("cls");
	 }while(op1==1);
}

//Mostrando las disponibilidades
void disponibilidad(){
	cout<<"Urgencias"<<endl;
	for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<urgencias[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"\t Consultas generales"<<endl;
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<consulgen[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Recuperacion"<<endl;
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<recuperaciones[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
		cout<<"Unidad intenciva"<<endl;
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
			cout<<intencivos[x][y].ocupado<<"\t";
			}
			cout<<endl;
		}
}

void salida(){

	do{
  double cc1;
	cout<<"Salidas"<<endl;
	cout<<"Ingrese cedula: ";
	cin>>cc1;
	for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				if(cc1==urgencias[x][y].documento){
					if(urgencias[x][y].valor==0){
					strcpy(salidas[x][y].tipo_doc,urgencias[x][y].tipo_doc);
			     	salidas[x][y].documento=urgencias[x][y].documento;
			        strcpy(salidas[x][y].nombre1,urgencias[x][y].nombre1);
				 	strcpy(salidas[x][y].nombre2,urgencias[x][y].nombre2);
				 	strcpy(salidas[x][y].apellido1,urgencias[x][y].apellido1);
				 	strcpy(salidas[x][y].apellido2,urgencias[x][y].apellido2);
				 	strcpy(salidas[x][y].fecha,urgencias[x][y].fecha);
    			  	strcpy(salidas[x][y].direccion,urgencias[x][y].direccion);
    			  	salidas[x][y].telefono=urgencias[x][y].telefono;
					salidas[x][y].eps2=urgencias[z][w].eps2;
					salidas[x][y].seguro=urgencias[z][w].seguro;
					salidas[x][y].nivel=urgencias[z][w].nivel;
					salidas[x][y].porcentaje=urgencias[z][w].porcentaje;
    			  	strcpy(salidas[x][y].eps,urgencias[x][y].eps);
	    			strcpy(salidas[x][y].regimen,urgencias[x][y].regimen); 
			 		strcpy(salidas[x][y].estado,urgencias[x][y].estado);
					strcpy(salidas[x][y].enfermedad,urgencias[x][y].enfermedad);
			    	//urgencias[x][y].cama_asig=cont;
					urgencias[x][y].ocupado=0;
					salidas[x][y].verificar=s;
			 		cout<<"Salida exitosa ";
					i=0;
					}else{cout<<" No ha pagado"<<endl;}	
				}else if(cc1==recuperaciones[x][y].documento){
					if(recuperaciones[x][y].valor==0){
					strcpy(salidas[x][y].tipo_doc,recuperaciones[x][y].tipo_doc);
			     	salidas[x][y].documento=recuperaciones[x][y].documento;
			        strcpy(salidas[x][y].nombre1,recuperaciones[x][y].nombre1);
				 	strcpy(salidas[x][y].nombre2,recuperaciones[x][y].nombre2);
				 	strcpy(salidas[x][y].apellido1,recuperaciones[x][y].apellido1);
				 	strcpy(salidas[x][y].apellido2,recuperaciones[x][y].apellido2);
				 	strcpy(salidas[x][y].fecha,recuperaciones[x][y].fecha);
    			  	strcpy(salidas[x][y].direccion,recuperaciones[x][y].direccion);
    			  	salidas[x][y].telefono=recuperaciones[x][y].telefono;
					salidas[x][y].eps2=recuperaciones[z][w].eps2;
					salidas[x][y].porcentaje=recuperaciones[z][w].porcentaje;
					salidas[x][y].seguro=recuperaciones[z][w].seguro;
					salidas[x][y].nivel=recuperaciones[z][w].nivel;   
    			  	strcpy(salidas[x][y].eps,recuperaciones[x][y].eps);
	    			strcpy(salidas[x][y].regimen,recuperaciones[x][y].regimen); 
			 		strcpy(salidas[x][y].estado,recuperaciones[x][y].estado);
					strcpy(salidas[x][y].enfermedad,urgencias[x][y].enfermedad);
					recuperaciones[x][y].ocupado=0;
					salidas[x][y].verificar=s;
			 		cout<<"Salida exitosa ";
					 i=0;
					 }else{cout<<" No ha pagado"<<endl;}	
				}else if(cc1==consulgen[x][y].documento){
					if(consulgen[x][y].valor==0){
					strcpy(salidas[x][y].tipo_doc,consulgen[x][y].tipo_doc);
			     	salidas[x][y].documento=consulgen[x][y].documento;
			        strcpy(salidas[x][y].nombre1,consulgen[x][y].nombre1);
				 	strcpy(salidas[x][y].nombre2,consulgen[x][y].nombre2);
				 	strcpy(salidas[x][y].apellido1,consulgen[x][y].apellido1);
				 	strcpy(salidas[x][y].apellido2,consulgen[x][y].apellido2);
				 	strcpy(salidas[x][y].fecha,consulgen[x][y].fecha);
    			  	strcpy(salidas[x][y].direccion,consulgen[x][y].direccion);
    			  	salidas[x][y].telefono=consulgen[x][y].telefono;
					salidas[x][y].eps2=consulgen[z][w].eps2;
					salidas[x][y].porcentaje=consulgen[z][w].porcentaje;
					salidas[x][y].seguro=consulgen[z][w].seguro;
					salidas[x][y].nivel=consulgen[z][w].nivel;  
    			  	strcpy(salidas[x][y].eps,consulgen[x][y].eps);
	    			strcpy(salidas[x][y].regimen,consulgen[x][y].regimen); 
			 		strcpy(salidas[x][y].estado,consulgen[x][y].estado);
					strcpy(salidas[x][y].enfermedad,consulgen[x][y].enfermedad);
					consulgen[x][y].ocupado=0;
					salidas[x][y].verificar=s;
			 		cout<<"Salida exitosa ";
					 i=0;
					 }else{cout<<" No ha pagado"<<endl;}
					
				}else if(cc1==intencivos[x][y].documento){
					if(intencivos[x][y].valor==0){
					strcpy(salidas[x][y].tipo_doc,intencivos[x][y].tipo_doc);
			     	salidas[x][y].documento=intencivos[x][y].documento;
			        strcpy(salidas[x][y].nombre1,intencivos[x][y].nombre1);
				 	strcpy(salidas[x][y].nombre2,intencivos[x][y].nombre2);
				 	strcpy(salidas[x][y].apellido1,intencivos[x][y].apellido1);
				 	strcpy(salidas[x][y].apellido2,intencivos[x][y].apellido2);
				 	strcpy(salidas[x][y].fecha,intencivos[x][y].fecha);
    			  	strcpy(salidas[x][y].direccion,intencivos[x][y].direccion);
    			  	salidas[x][y].telefono=intencivos[x][y].telefono;
					salidas[x][y].eps2=intencivos[z][w].eps2;
					salidas[x][y].seguro=intencivos[z][w].seguro;
					salidas[x][y].nivel=intencivos[z][w].nivel;
    			  	salidas[x][y].porcentaje=intencivos[z][w].porcentaje;  
    			  	strcpy(salidas[x][y].eps,intencivos[x][y].eps);
	    			strcpy(salidas[x][y].regimen,intencivos[x][y].regimen); 
			 		strcpy(salidas[x][y].estado,intencivos[x][y].estado);
					strcpy(salidas[x][y].enfermedad,intencivos[x][y].enfermedad);
					intencivos[x][y].ocupado=0;
					salidas[x][y].verificar=s;
			 		cout<<"Salida exitosa ";
					 i=0;
					}else{cout<<" No ha pagado"<<endl;}
				}
				
			}
		 }
		if(i==1){
					cout<<"No esta registrado"<<endl;
				}
	
		cout<<"Desea volver(1.si/2.no):";
		cin>>op;
			system("cls");

	  }while(op==1);
}

void traslado(){
	do{
	
	double cc1;
	
	cout<<"Traslados a otra entidad"<<endl;
	cout<<"Ingrese cedula: ";
	cin>>cc1;
	for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				if(cc1==urgencias[x][y].documento){
					 do{ i=0;
    			  cout<<"1.EPS - 2.Seguro - 3. Ninguna: ";
    			  cout<<"Escoja una opcion: "<<endl;
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>urgencias[x][y].eps;
						       urgencias[x][y].eps2=1;
							   urgencias[x][y].porcentaje=0;
							   strcpy(urgencias[x][y].regimen," ");
							   urgencias[x][y].nivel=0;
					  break;
				 case 2: urgencias[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(urgencias[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									cin>>op;
									urgencias[x][y].nivel=op;
									switch (op)
									{
									case 1: urgencias[x][y].porcentaje=25; break;
									case 2: urgencias[x][y].porcentaje=40; break;
									case 3: urgencias[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(urgencias[x][y].regimen,"Subsidiado"); 
							   			urgencias[x][y].porcentaje=95; break;
				    	   } 
				case 3: cout<<"paga todo"<<endl; break; 		   
				  default: cout<<"error opcion"<<endl;
				  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
				  if(op==1){
					  cout<<urgencias[x][y].nombre1<<" "<<"traslado exitoso "<<endl;
				  }
			 	}
				 /////////////////////////////////
				 if(cc1==consulgen[x][y].documento){
					 do{ i=0;
    			  cout<<"1.EPS - 2.Seguro - 3. Ninguna: ";
    			  cout<<"Escoja una opcion: "<<endl;
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>consulgen[x][y].eps;
						       consulgen[x][y].eps2=1;
							   consulgen[x][y].porcentaje=0;
							   strcpy(consulgen[x][y].regimen," ");
							   consulgen[x][y].nivel=0;
					  break;
				 case 2: consulgen[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(consulgen[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									cin>>op;
									consulgen[x][y].nivel=op;
									switch (op)
									{
									case 1: consulgen[x][y].porcentaje=25; break;
									case 2: consulgen[x][y].porcentaje=40; break;
									case 3: consulgen[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(consulgen[x][y].regimen,"Subsidiado"); 
							   			consulgen[x][y].porcentaje=95; break;
				    	   } 
				case 3: cout<<"paga todo"<<endl; break; 		   
				  default: cout<<"error opcion"<<endl;
				  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
				  if(op==1){
					  cout<<consulgen[x][y].nombre1<<" "<<"traslado exitoso "<<endl;
				  }
			 	}
				 /////////////////////////////////
				 if(cc1==recuperaciones[x][y].documento){
					 do{ i=0;
    			  cout<<"1.EPS - 2.Seguro - 3. Ninguna: ";
    			  cout<<"Escoja una opcion: "<<endl;
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>recuperaciones[x][y].eps;
						       recuperaciones[x][y].eps2=1;
							   recuperaciones[x][y].porcentaje=0;
							   strcpy(recuperaciones[x][y].regimen," ");
							   recuperaciones[x][y].nivel=0;
					  break;
				 case 2: recuperaciones[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(recuperaciones[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									recuperaciones[x][y].nivel=op;
									cin>>op;
									switch (op)
									{
									case 1: recuperaciones[x][y].porcentaje=25; break;
									case 2: recuperaciones[x][y].porcentaje=40; break;
									case 3: recuperaciones[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(recuperaciones[x][y].regimen,"Subsidiado"); 
							   			recuperaciones[x][y].porcentaje=95; break;
				    	   } 
				case 3: cout<<"paga todo"<<endl; break; 		   
				  default: cout<<"error opcion"<<endl;
				  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
				  if(op==1){
					  cout<<recuperaciones[x][y].nombre1<<" "<<"traslado exitoso "<<endl;
				  }
			 	}
				 /////////////////////////////////
				 if(cc1==intencivos[x][y].documento){
					 do{ i=0;
    			  cout<<"1.EPS - 2.Seguro - 3. Ninguna: ";
    			  cout<<"Escoja una opcion: "<<endl;
				  cin>>op;
				  switch (op)
				  {
				  case 1: cout<<"Ingrese EPS: ";
    			  		  cin>>intencivos[x][y].eps;
						       intencivos[x][y].eps2=1;
							   intencivos[x][y].porcentaje=0;
							   strcpy(intencivos[x][y].regimen," ");
							   intencivos[x][y].nivel=0;
					  break;
				 case 2: intencivos[x][y].seguro=2; cout<<"Regimen:"<<endl;
    					  cout<<"1. Contributivo \n 2. Subsidiado: ";
			 		      cin>>op;
			 			    switch(op){
			 			  	case 1: strcpy(intencivos[x][y].regimen,"Contributivo");
							        cout<<"Nivel: 1-2-3:";
									intencivos[x][y].nivel=op;
									cin>>op;
									switch (op)
									{
									case 1: intencivos[x][y].porcentaje=25; break;
									case 2: intencivos[x][y].porcentaje=40; break;
									case 3: intencivos[x][y].porcentaje=55; break;
									default: cout<<"Error opcion"<<endl;
										break;
									}
							    break;
			 			  	case 2: strcpy(intencivos[x][y].regimen,"Subsidiado"); 
							   			intencivos[x][y].porcentaje=95; break;
				    	   } 
				case 3: cout<<"paga todo"<<endl; break; 		   
				  default: cout<<"error opcion"<<endl;
				  break;
				  }
				  cout<<"Seguro (1.si/ 2.no): ";
				  cin>>op;
				  }while(op==2); 
				  if(op==1){
					  cout<<intencivos[x][y].nombre1<<" "<<"traslado exitoso "<<endl;
				  }
			 	}
			}
		}
		cout<<"Desea volver(1.si/2.no):";
		cin>>op;
			system("cls");
	  }while(op==1);
}

void lista(){
	cout<<"\n \tLista del Hospial"<<endl;
	
	cout<<"\n \t Urgencias "<<endl;
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if ( strcmp( urgencias[x][y].nombre1, urgencias[c][d].nombre1)<=0)
			{
			
				strcpy(aux,urgencias[x][y].nombre1);
				strcpy(urgencias[x][y].nombre1,urgencias[x][y].nombre1);
				strcpy(urgencias[x][y].nombre1,aux);
			
		}
}
}
	                        
	for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(urgencias[x][y].ocupado==1)
				{
				cout<<"Nombre: "<<urgencias[x][y].nombre1<<" "<<urgencias[x][y].nombre2
				<<" "<<urgencias[x][y].apellido1<<" "<<urgencias[x][y].apellido2<<endl
				<<"Documento:"<<urgencias[x][y].documento<<"  "<<urgencias[x][y].verificar<<endl;
				cout<<"Cama: "<<urgencias[x][y].cama_asig<<"\n";
				cout<<"Piso: "<<urgencias[x][y].piso_asig<<"\n";
				}
			}
			}
			
			cout<<"\n \t Consultas generales ";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( consulgen[x][y].nombre1, consulgen[c][d].nombre1)<=0)
			{
				strcpy(aux,consulgen[x][y].nombre1);
				strcpy(consulgen[x][y].nombre1,consulgen[c][d].nombre1);
				strcpy(consulgen[c][d].nombre1,aux);
			}
}
}

	for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(consulgen[x][y].ocupado==1)
				{
				cout<<"Nombre: "<<consulgen[x][y].nombre1<<" "<<consulgen[x][y].nombre2
				<<" "<<consulgen[x][y].apellido1<<" "<<consulgen[x][y].apellido2<<endl
				<<"Documento:"<<consulgen[x][y].documento<<"  "<<consulgen[x][y].verificar<<endl;
				cout<<"Cama: "<<consulgen[x][y].cama_asig<<"\n";
				cout<<"Piso: "<<consulgen[x][y].piso_asig<<"\n";
				}
			}
			}
			
			cout<<"\n \t Recuperaciones ";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( recuperaciones[x][y].nombre1, recuperaciones[c][d].nombre1)<=0)
			{
				strcpy(aux,recuperaciones[x][y].nombre1);
				strcpy(recuperaciones[x][y].nombre1,recuperaciones[c][d].nombre1);
				strcpy(recuperaciones[c][d].nombre1,aux);
			}
}
}

	for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(recuperaciones[x][y].ocupado==1)
				{
				cout<<"Nombre: "<<recuperaciones[x][y].nombre1<<" "<<recuperaciones[x][y].nombre2
				<<" "<<recuperaciones[x][y].apellido1<<" "<<recuperaciones[x][y].apellido2<<endl
				<<"Documento:"<<recuperaciones[x][y].documento<<"  "<<recuperaciones[x][y].verificar<<endl;
				cout<<"Cama: "<<recuperaciones[x][y].cama_asig<<"\n";
				cout<<"Piso: "<<recuperaciones[x][y].piso_asig<<"\n";
				}
			}
			}
			
						
			cout<<"\n \t Cuidados intencivos ";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( intencivos[x][y].nombre1, intencivos[c][d].nombre1)<=0)
			{
				strcpy(aux,intencivos[x][y].nombre1);
				strcpy(intencivos[x][y].nombre1,intencivos[c][d].nombre1);
				strcpy(intencivos[c][d].nombre1,aux);
			}
}
}

	for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(intencivos[x][y].ocupado==1)
				{
				cout<<"Nombre: "<<intencivos[x][y].nombre1<<" "<<intencivos[x][y].nombre2
				<<" "<<intencivos[x][y].apellido1<<" "<<intencivos[x][y].apellido2<<endl
				<<"Documento:"<<intencivos[x][y].documento<<"  "<<intencivos[x][y].verificar<<endl;
				cout<<"Cama: "<<intencivos[x][y].cama_asig<<"\n";
				cout<<"Piso: "<<intencivos[x][y].piso_asig<<"\n";
				}
			}
			}	
			
						
			cout<<"\n \t Salidas";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( salidas[x][y].nombre1, salidas[c][d].nombre1)<=0)
			{
				strcpy(aux,salidas[x][y].nombre1);
				strcpy(salidas[x][y].nombre1,salidas[c][d].nombre1);
				strcpy(salidas[c][d].nombre1,aux);
			}
}
}

	for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(salidas[x][y].documento)
				{
				cout<<"Nombre: "<<salidas[x][y].nombre1<<" "<<salidas[x][y].nombre2
				<<" "<<salidas[x][y].apellido1<<" "<<salidas[x][y].apellido2<<endl
				<<"Documento:"<<salidas[x][y].documento<<"  "<<salidas[x][y].verificar<<endl;
				cout<<"Cama: "<<salidas[x][y].cama_asig<<"\n";
				cout<<"Piso: "<<salidas[x][y].piso_asig<<"\n";
				
				}
			}
			}							
}

void consultas(){
	do{
	cout<<"Ingrese cedula: ";
	cin>>cc;
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(urgencias[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<urgencias[x][y].nombre1<<" "<<urgencias[x][y].nombre2
				<<" "<<urgencias[x][y].apellido1<<" "<<urgencias[x][y].apellido2<<endl;
				cout<<"Tipo de documento: "<<urgencias[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<urgencias[x][y].documento<<endl;
				cout<<"Tel: "<<urgencias[x][y].telefono<<"\n";
				cout<<"fecha de nacimiento: "<<urgencias[x][y].fecha<<"\n";
				cout<<"Direcion: "<<urgencias[x][y].direccion<<"\n";
				cout<<"Piso Asignando: "<<urgencias[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<urgencias[x][y].piso_trans<<"\n";
				tvalor=urgencias[x][y].valor-(urgencias[x][y].valor*urgencias[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"Cama Asignada: "<<urgencias[x][y].cama_asig<<"\n";
				cout<<"Cama traslado: "<<urgencias[x][y].cama_trans<<"\n";
				cout<<"Piso Asignado: "<<urgencias[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<urgencias[x][y].piso_trans<<"\n";
				cout<<"EPS: "<<urgencias[x][y].eps<<"\n";
				cout<<"Regimen: "<<urgencias[x][y].regimen<<"\n";
				cout<<"Nivel: "<<urgencias[x][y].nivel<<"\n";
				cout<<"Estado: "<<urgencias[x][y].estado<<"\n";
				cout<<"Enfermedad: "<<urgencias[x][y].enfermedad<<"\n";
				cout<<urgencias[x][y].verificar<<endl;
				i=0;
				}else if(consulgen[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<consulgen[x][y].nombre1<<" "<<consulgen[x][y].nombre2
				<<" "<<consulgen[x][y].apellido1<<" "<<consulgen[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<consulgen[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<consulgen[x][y].documento<<endl;
				cout<<"Tel: "<<consulgen[x][y].telefono<<"\n";
				cout<<"fecha de nacimiento: "<<urgencias[x][y].fecha<<"\n";
				cout<<"Direcion: "<<consulgen[x][y].direccion<<"\n";
				cout<<"Piso Asignando: "<<consulgen[x][y].piso_asig<<"\n";
				tvalor=consulgen[x][y].valor-(urgencias[x][y].valor*consulgen[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"EPS: "<<consulgen[x][y].eps<<"\n";
				cout<<"Regimen: "<<consulgen[x][y].regimen<<"\n";
				cout<<"Nivel: "<<consulgen[x][y].nivel<<"\n";
				cout<<"Estado: "<<consulgen[x][y].estado<<"\n";
				cout<<"Enfermedad: "<<consulgen[x][y].enfermedad<<"\n";
				cout<<consulgen[x][y].verificar<<endl;
				i=0;
				}else if(recuperaciones[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<recuperaciones[x][y].nombre1<<" "<<recuperaciones[x][y].nombre2
				<<" "<<recuperaciones[x][y].apellido1<<" "<<recuperaciones[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<recuperaciones[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<recuperaciones[x][y].documento<<endl;
				cout<<"Tel: "<<recuperaciones[x][y].telefono<<"\n";
				cout<<"fecha de nacimiento: "<<recuperaciones[x][y].fecha<<"\n";
				cout<<"Direcion: "<<recuperaciones[x][y].direccion<<"\n";
				cout<<"Piso Asignando: "<<recuperaciones[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<recuperaciones[x][y].piso_trans<<"\n";
				tvalor=recuperaciones[x][y].valor-(urgencias[x][y].valor*recuperaciones[x][y].porcentaje)/100;
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"Cama Asignada: "<<recuperaciones[x][y].cama_asig<<"\n";
				cout<<"Cama traslado: "<<recuperaciones[x][y].cama_trans<<"\n";
				cout<<"Piso Asignado: "<<recuperaciones[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<recuperaciones[x][y].piso_trans<<"\n";
				cout<<"EPS: "<<recuperaciones[x][y].eps<<"\n";
				cout<<"Regimen: "<<recuperaciones[x][y].regimen<<"\n";
				cout<<"Nivel: "<<recuperaciones[x][y].nivel<<"\n";
				cout<<"Estado: "<<recuperaciones[x][y].estado<<"\n";
				cout<<"Enfermedad: "<<recuperaciones[x][y].enfermedad<<"\n";
				cout<<recuperaciones[x][y].verificar<<endl;
				i=0;
				}else if(intencivos[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<intencivos[x][y].nombre1<<" "<<intencivos[x][y].nombre2
				<<" "<<intencivos[x][y].apellido1<<" "<<intencivos[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<intencivos[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<intencivos[x][y].documento<<endl;
				cout<<"Tel: "<<intencivos[x][y].telefono<<"\n";
				cout<<"fecha de nacimiento: "<<intencivos[x][y].fecha<<"\n";
				cout<<"Direcion: "<<intencivos[x][y].direccion<<"\n";
				cout<<"Piso Asignando: "<<intencivos[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<intencivos[x][y].piso_trans<<"\n";
				tvalor=intencivos[x][y].valor-(urgencias[x][y].valor*intencivos[x][y].porcentaje)/100;
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"Cama Asignada: "<<intencivos[x][y].cama_asig<<"\n";
				cout<<"Cama traslado: "<<intencivos[x][y].cama_trans<<"\n";
				cout<<"Piso Asignado: "<<intencivos[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<intencivos[x][y].piso_trans<<"\n";
				cout<<"EPS: "<<intencivos[x][y].eps<<"\n";
				cout<<"Regimen: "<<intencivos[x][y].regimen<<"\n";
				cout<<"Nivel: "<<intencivos[x][y].nivel<<"\n";
				cout<<"Estado: "<<intencivos[x][y].estado<<"\n";
				cout<<"Enfermedad: "<<intencivos[x][y].enfermedad<<"\n";
				cout<<intencivos[x][y].verificar<<endl;
				i=0;
				}
			}
			}
	for(x=0;x<9;x++){
			for(y=0;y<9;y++){
			 if(salidas[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<salidas[x][y].nombre1<<" "<<salidas[x][y].nombre2
				<<" "<<salidas[x][y].apellido1<<" "<<salidas[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<salidas[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<salidas[x][y].documento<<endl;
				cout<<"Tel: "<<salidas[x][y].telefono<<"\n";
				cout<<"fecha de nacimiento: "<<salidas[x][y].fecha<<"\n";
				cout<<"Direcion: "<<salidas[x][y].direccion<<"\n";
				cout<<"Piso Asignando: "<<salidas[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<salidas[x][y].piso_trans<<"\n";
				cout<<"Cama Asignada: "<<salidas[x][y].cama_asig<<"\n";
				cout<<"Cama traslado: "<<salidas[x][y].cama_trans<<"\n";
				cout<<"Piso Asignado: "<<salidas[x][y].piso_asig<<"\n";
				cout<<"Piso traslado: "<<salidas[x][y].piso_trans<<"\n";
				cout<<"EPS: "<<salidas[x][y].eps<<"\n";
				cout<<"Regimen: "<<salidas[x][y].regimen<<"\n";
				cout<<"Nivel: "<<salidas[x][y].nivel<<"\n";
				cout<<"Estado: "<<salidas[x][y].estado<<"\n";
				cout<<"Enfermedad: "<<salidas[x][y].enfermedad<<"\n";
				cout<<salidas[x][y].verificar<<endl;
				i=0;
				} 
			}
			}
			if(i==1){
				cout<<"No encontrado"<<endl;
			}			
			
	cout<<"Desea volver a consultar(1.si/2.no): ";
	cin>>op;
		system("cls");
	}while(op==1);
}

void tratamientos(){
	cout<<"Tratamientos"<<endl;
	cout<<"1. Tratamiento uno $40000\n 2. Tratamiento dos $50000\n 3.Tratamiento tres$60000"<<endl;
}

void medicamentos(){
	cout<<"Medicamentos"<<endl;
	cout<<"1. Medicamentos uno $10000 \n 2. Medicamentos dos $20000 \n 3. Medicamentos tres $30000"<<endl;
}

void atender(){
	do{
	cout<<"Ingrese cedula: ";
	cin>>cc;
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(urgencias[x][y].documento==cc)
				{
					history[x][y].documento=urgencias[x][y].documento;
					strcpy(history[x][y].nombre1,urgencias[x][y].nombre1);
					strcpy(history[x][y].apellido1,urgencias[x][y].apellido1);
					i=0;
				cout<<"\nNombre: "<<urgencias[x][y].nombre1<<" "<<urgencias[x][y].nombre2
				<<" "<<urgencias[x][y].apellido1<<" "<<urgencias[x][y].apellido2<<endl;
				cout<<"Tipo de documento: "<<urgencias[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<urgencias[x][y].documento<<endl;
				do{
				cout<<"1.Tratar / 2. medicar"<<endl;
				cin>>op;
				switch (op)
				{
				case 1: tratamientos();
						cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].tratamientos," 1");
						urgencias[x][y].valor=urgencias[x][y].valor+40000;
						break;
						case 2:strcat(history[x][y].tratamientos," 2");
						urgencias[x][y].valor=urgencias[x][y].valor+50000;
						break;
						case 3: strcat(history[x][y].tratamientos," 3");
						urgencias[x][y].valor=urgencias[x][y].valor+60000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
					break;
				case 2: medicamentos();
				cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].medicamentos," 1");
						urgencias[x][y].valor=urgencias[x][y].valor+10000;
						break;
						case 2: strcat(history[x][y].medicamentos," 2");
						urgencias[x][y].valor=urgencias[x][y].valor+20000;
						break;
						case 3: strcat(history[x][y].medicamentos," 3");
						urgencias[x][y].valor=urgencias[x][y].valor+30000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
				    break;
				default:  cout<<"Error de opcion"<<endl;
					break;
				}
				cout<<"Seguro 1.si/2.no"<<endl;
				cin>>op1;
				}while(op1==2);

				}else if(consulgen[x][y].documento==cc)
				{i=0;
				history[x][y].documento=consulgen[x][y].documento;
				strcpy(history[x][y].nombre1,consulgen[x][y].nombre1);
					strcpy(history[x][y].apellido1,consulgen[x][y].apellido1);
				cout<<"\nNombre: "<<consulgen[x][y].nombre1<<" "<<consulgen[x][y].nombre2
				<<" "<<consulgen[x][y].apellido1<<" "<<consulgen[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<consulgen[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<consulgen[x][y].documento<<endl;
				do{
				cout<<"1.Tratar / 2. medicar"<<endl;
				cin>>op;
				switch (op)
				{
				case 1: tratamientos();
						cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].tratamientos," 1");
						consulgen[x][y].valor=consulgen[x][y].valor+40000;
						break;
						case 2: strcat(history[x][y].tratamientos," 2");
						consulgen[x][y].valor=consulgen[x][y].valor+50000;
						break;
						case 3: strcat(history[x][y].tratamientos," 3");
						consulgen[x][y].valor=consulgen[x][y].valor+60000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
					break;
				case 2: medicamentos();
				cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].medicamentos," 1");
						consulgen[x][y].valor=consulgen[x][y].valor+10000;
						break;
						case 2: strcat(history[x][y].medicamentos," 2");
						consulgen[x][y].valor=consulgen[x][y].valor+20000;
						break;
						case 3: strcat(history[x][y].medicamentos," 3");
						consulgen[x][y].valor=consulgen[x][y].valor+30000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
				    break;
				default: cout<<"Error de opcion"<<endl;
					break;
				}
				cout<<"Seguro 1.si/2.no"<<endl;
				cin>>op1;
				}while(op1==2);
				
				}else if(recuperaciones[x][y].documento==cc)
				{i=0;
				history[x][y].documento=recuperaciones[x][y].documento;
				strcpy(history[x][y].nombre1,recuperaciones[x][y].nombre1);
					strcpy(history[x][y].apellido1,recuperaciones[x][y].apellido1);
				cout<<"\nNombre: "<<recuperaciones[x][y].nombre1<<" "<<recuperaciones[x][y].nombre2
				<<" "<<recuperaciones[x][y].apellido1<<" "<<recuperaciones[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<recuperaciones[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<recuperaciones[x][y].documento<<endl;
				do{
				cout<<"1.Tratar / 2. medicar"<<endl;
				cin>>op;
				switch (op)
				{
				case 1: tratamientos();
						cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].tratamientos," 1");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+40000;
						break;
						case 2: strcat(history[x][y].tratamientos," 2");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+50000;
						break;
						case 3: strcat(history[x][y].tratamientos," 3");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+60000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
					break;
				case 2: medicamentos();
				cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].medicamentos," 1");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+10000;
						break;
						case 2: strcat(history[x][y].medicamentos," 2");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+20000;
						break;
						case 3: strcat(history[x][y].medicamentos," 3");
						recuperaciones[x][y].valor=recuperaciones[x][y].valor+30000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
				    break;
				default:  cout<<"Error de opcion"<<endl;
					break;
				}
				cout<<"Seguro 1.si/2.no"<<endl;
				cin>>op1;
				}while(op1==2);
				
				}else if(intencivos[x][y].documento==cc)
				{i=0;
				history[x][y].documento=intencivos[x][y].documento;
				strcpy(history[x][y].nombre1,intencivos[x][y].nombre1);
					strcpy(history[x][y].apellido1,intencivos[x][y].apellido1);
				cout<<"\nNombre: "<<intencivos[x][y].nombre1<<" "<<intencivos[x][y].nombre2
				<<" "<<intencivos[x][y].apellido1<<" "<<intencivos[x][y].apellido2<<endl;
				cout<<"Tipo de documento"<<intencivos[x][y].tipo_doc<<endl;
				cout<<"Documento:"<<intencivos[x][y].documento<<endl;
				do{
				cout<<"1.Tratar / 2. medicar"<<endl;
				cin>>op;
				switch (op)
				{
				case 1: tratamientos();
						cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].tratamientos," 1");
						intencivos[x][y].valor=intencivos[x][y].valor+40000;
						break;
						case 2: strcat(history[x][y].tratamientos," 2");
						intencivos[x][y].valor=intencivos[x][y].valor+50000;
						break;
						case 3: strcat(history[x][y].tratamientos," 3");
						intencivos[x][y].valor=intencivos[x][y].valor+60000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
					break;
				case 2: medicamentos();
				cin>>op;
						switch (op)
						{
						case 1: strcat(history[x][y].medicamentos," 1");
						intencivos[x][y].valor=intencivos[x][y].valor+10000;
						break;
						case 2: strcat(history[x][y].medicamentos," 2");
						intencivos[x][y].valor=intencivos[x][y].valor+20000;
						break;
						case 3: strcat(history[x][y].medicamentos," 3");
						intencivos[x][y].valor=intencivos[x][y].valor+30000;
						break;
						default: cout<<"Error de opcion"<<endl;
							break;
						}
				    break;
				default: op1=1; cout<<"Error de opcion"<<endl;
					break;
				}
				cout<<"Seguro 1.si/2.no"<<endl;
				cin>>op1;
				}while(op1==2);
				}
			}
			}		
			if(i==1){
				cout<<"no encontado"<<endl;
			}	
	cout<<"Desea volver atender(1.si/2.no): ";
	cin>>op;
		system("cls");
	}while(op==1);
}

void pagar(){
	do{
	cout<<"Ingrese cedula: ";
	cin>>cc;
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(urgencias[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<urgencias[x][y].nombre1<<" "<<urgencias[x][y].nombre2
				<<" "<<urgencias[x][y].apellido1<<" "<<urgencias[x][y].apellido2<<endl;
				cout<<"Numero de dias que estuvo en el hospital: ";
				cin>>op2;
				urgencias[x][y].dia=op2;
				urgencias[x][y].valor=urgencias[x][y].valor+urgencias[x][y].dia;
				tvalor=urgencias[x][y].valor-(urgencias[x][y].valor*urgencias[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"va a pagar (1.si/2.no): ";
				cin>>op2;
				if(op2){
					urgencias[x][y].valor=0;
				}
				
				i=0;
				}else if(consulgen[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<consulgen[x][y].nombre1<<" "<<consulgen[x][y].nombre2
				<<" "<<consulgen[x][y].apellido1<<" "<<consulgen[x][y].apellido2<<endl;
				cout<<"Numero de dias que estuvo en el hospital: ";
				cin>>op2;
				consulgen[x][y].dia=op2;
				consulgen[x][y].valor=consulgen[x][y].valor+consulgen[x][y].dia;
				tvalor=consulgen[x][y].valor-(consulgen[x][y].valor*consulgen[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"va a pagar (1.si/2.no): ";
				cin>>op2;
				if(op2){
					consulgen[x][y].valor=0;
				}
				i=0;

				}else if(recuperaciones[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<recuperaciones[x][y].nombre1<<" "<<recuperaciones[x][y].nombre2
				<<" "<<recuperaciones[x][y].apellido1<<" "<<recuperaciones[x][y].apellido2<<endl;
				cout<<"Numero de dias que estuvo en el hospital: ";
				cin>>op2;
				recuperaciones[x][y].dia=op2;
				recuperaciones[x][y].valor=recuperaciones[x][y].valor+recuperaciones[x][y].dia;
				tvalor=recuperaciones[x][y].valor-(recuperaciones[x][y].valor*recuperaciones[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"va a pagar (1.si/2.no): ";
				cin>>op2;
				if(op2){
					recuperaciones[x][y].valor=0;
				}
				i=0;
				}else if(intencivos[x][y].documento==cc)
				{
				cout<<"\nNombre: "<<intencivos[x][y].nombre1<<" "<<intencivos[x][y].nombre2
				<<" "<<intencivos[x][y].apellido1<<" "<<intencivos[x][y].apellido2<<endl;
				cout<<"Numero de dias que estuvo en el hospital: ";
				cin>>op2;
				intencivos[x][y].dia=op2;
				intencivos[x][y].valor=intencivos[x][y].valor+intencivos[x][y].dia;
				tvalor=intencivos[x][y].valor-(intencivos[x][y].valor*intencivos[x][y].porcentaje/100);
				cout<<"Valor a pagar: "<<tvalor<<"\n"; 
				cout<<"va a pagar (1.si/2.no): ";
				cin>>op2;
				if(op2){
					intencivos[x][y].valor=0;
				}
				i=0;
				}
			}
			}
			if(i==1){
				cout<<"No encontrado"<<endl;
			}			
			
	cout<<"Desea volver a contultar(1.si/2.no): ";
	cin>>op;
		system("cls");
	}while(op==1);
}	

void historial(){
	do{
	cout<<"Ingrese cedula: ";
	cin>>cc;
		for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(history[x][y].documento==cc)
				{
				cout<<"Nombre: "<<history[x][y].nombre1<<" "<<history[x][y].apellido1<<endl;	
				cout<<"Tratamientos: "<<history[x][y].tratamientos<<endl;
				cout<<"Medicamentos: "<<history[x][y].medicamentos<<endl;
				i=0;
				}
			}
			}
			if(i==1){
				cout<<"No encontrado"<<endl;
			}			
			
	cout<<"Desea volver a consultar el historial(1.si/2.no): ";
	cin>>op;
		system("cls");
	}while(op==1);
}
