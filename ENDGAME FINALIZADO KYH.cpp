//kevin Andrades y Horracio lopez

//estructura general
#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<fstream>


using namespace std;
struct C
{
	int documento,telefono,silla,cant;
	int codigo,fila,columna,puesto;
	float valorboleta;
    string area,piso;
    char nombre[20],apellido[20];
};

int op1,op2,op3,op4,op5,op6,op7,op8,op9,op10,op11,op12,op13,op14,ara,ara1; //nueva: ara,ara1,
int doc,t=0,a=0,cod=0,cc;
int x=0,y=0,c,d,k,l;
float valorB=0,valorC=0;
char Nomevent[20],tipo[20];
char aux[20];

//variables archivo
string AD,AC;

string sur="Sur",norte="Norte",occidente="Occidente",oriente="oriente",platino="platino",vip="VIP";
string p1="uno",p2="dos",p3="tres";

//areas del norte
C CNP1[3][3];
C CNP2[3][3];
C CNP3[3][3];
// areas del sur
C CSP1[3][3];
C CSP2[3][3];
C CSP3[3][3];
// areas del oriente
C CORP1[3][3];
C CORP2[3][3];
C CORP3[3][3];
// areas del occidente
C COCP1[3][3];
C COCP2[3][3];
C COCP3[3][3];
//PLATINO
C CPLAT[2][2];
//VIP
C CVIP[2][2];
//FUNCIONES
void ConsulD();
void ConsulC();
void Cancel();
void CancelC();
void CancelE();
void ListaD();
void ListaC();
void RegD();
void RegC();
void Norte();
void Sur();
void Occidente();
void Oriente();
void Platino();
void VIP();
void Npiso1();
void Npiso2();
void Npiso3();
void Spiso1();
void Spiso2();
void Spiso3();
void OCpiso1();
void OCpiso2();
void OCpiso3();
void ORpiso1();
void ORpiso2();
void ORpiso3();
void deportivo();
void concierto();
//funcion principal

//Funciones Archivo Concierto y Deportivo
void ArC();
void ArD();


ofstream entrada;
ifstream salida;

int main()
{
	do
	{
		cout<<"\n\n\n\n\t\t\t ****COLISEO ENDGAME**** \n\n\n";
		cout<<"\t\t ******| A QUE EVENTO VA HA ASISTIR |******\n", Sleep(150);
		cout<<"\t\t ******|**********|H|*|K|***********|******\n", Sleep(150);
		cout<<"\t---------------------------------------------------------\n",Sleep(150);
		cout<<"\n\t\t [1]-|| Deportivo",Sleep(150);
		cout<<"\n\t\t [2]-|| Concierto \n\n", Sleep(150);
		cout<<"\n ----->> Escoja el evento: ", Sleep(150);
		cin>>op1;
		system("cls");
		switch(op1)
		{
				case 1:
				deportivo();
				break;

				case 2:
				concierto();
				break;

				default:cout<<"Error de opcion";
		}
		cout<<"\n Desea volver al menu principal(1.si/2.no):";
		cin>>op6;
	}while(op6==1);

	return 0;
}

//funcion deportiva
void deportivo()
{
			cout<<"\n\n\n\t----> INGRESE EL TIPO DE EVENTO:";
			cin>>tipo;
			cout<<"\n\n\n\t----> INGRESE NOMBRE DEL EVENTO:";
			cin>>Nomevent;
			system("cls");
			cout<<"\n\n\n\t----> EVENTO: "<<tipo<<" "<< Nomevent;
            cout<<"\n\n\n\t----> INGRESE VALOR BASE: ";
            cin>>valorB;
            system("cls");

	do
	{
		cout<<"\n Que desea hacer\n";
		cout<<"\n [1]. Registro";
		cout<<"\n [2]. Consulta";
		cout<<"\n [3]. Cancelar";
		cout<<"\n [4]. Lista de clientes";
		cout<<"\n [5]. Mostrar Archivo\n";
		cout<<"\n Elija una Opcion: ";
		cin>>op7;
		system("cls");
		switch(op7)
		{
			case 1:
			RegD();
			break;

			case 2:
			ConsulD();
			break;

			case 3:
			Cancel();
			break;

			case 4:
			ListaD();
			break ;

			case 5:
            ArD();
            break;

			default: cout<<"\n Error de opcion";
		}
		cout<<"\n Desea volver al menu deportivo(1.si/2.no):";
		cin>>op8;
		system("cls");
	}while(op8==1);
}

//funcion de cancelar

void Cancel()
{
	cout<<"\t Canlelar";
	cout<<"\nQue desea cancelar\n";
	cout<<"\n[1]. Compra";
	cout<<"\n[2]. Evento\n";
	cout<<"\nElija una Opcion: ";
	cin>>op1;
	system("cls");
	switch(op1)
	{
		case 1:
		CancelC();
		break;

		case 2:
		CancelE();
		break;

		default: cout<<"\n*****Error de opcion*****";
	}
}

//funcion de Registro deportivo
void RegD()
{
	cout<<"\t Inicio de registro";
	do
	{
		cout<<"\n Elija Area\n";
		cout<<"\n [1].Norte";
		cout<<"\n [2].Sur";
		cout<<"\n [3].Occidente";
		cout<<"\n [4].Oriente\n";
		cout<<"\n A cual area va a ir?: ";
		cin>>op9;
		system("cls");
		switch(op9)
		{
			case 1:
				Norte();
			break;

			case 2:
			  Sur();
			break;

			case 3:
			  Occidente();
			break;

			case 4:
			   Oriente();
			 break;

		default:cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir area(1.si/2.no):";
		cin>>op10;
	}while(op10==1);


}

// area del Sur

void Sur()
{
	do
	{
		cout<<"\t Area del Sur";
		cout<<"\n 1. Primero";
		cout<<"\n 2. Segundo";
		cout<<"\n 3. Tercero";
		cout<<"\n Elija el piso:";
		cin>>op11;
		switch(op11)
		{
			case 1:
			Spiso1();
			break;

			case 2:
			Spiso2();
			break;

			case 3:
			Spiso3();
			break;

			default: cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir el piso(1.si/2.no):";
		cin>>op12;
	}while(op12==1);
}

//primer piso del area del sur

void Spiso1()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CSP1[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CSP1[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CSP1[x][y].fila=x;
								CSP1[x][y].columna=y;
								CSP1[x][y].documento=cc;
								CSP1[x][y].codigo=x+y+1;;
								CSP1[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CSP1[x][y].area=sur;
				CSP1[x][y].piso=p1;
				CSP1[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CSP1[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CSP1[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CSP1[x][y].telefono;
				valorC=valorB+(valorB*10/100);
				valorC=valorC*t;
				CSP1[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CSP1[x][y].puesto << endl;
                entrada<< "--| Documento: " << CSP1[x][y].documento << endl;
                entrada<< "--| Nombre: " << CSP1[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CSP1[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CSP1[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CSP1[x][y].codigo << endl;
                entrada<< "--| Area: " << CSP1[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();
			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//segundo piso del area del sur

void Spiso2()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CSP2[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CSP2[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CSP2[x][y].fila=x;
								CSP2[x][y].columna=y;
								CSP2[x][y].documento=cc;
								CSP2[x][y].codigo=x+y+15;
								CSP2[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CSP2[x][y].area=sur;
				CSP2[x][y].piso=p2;
				CSP2[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CSP2[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CSP2[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CSP2[x][y].telefono;
				valorC=valorB+(valorB*5/100);
				valorC=valorC*t;
				CSP2[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CSP2[x][y].puesto << endl;
                entrada<< "--| Documento: " << CSP2[x][y].documento << endl;
                entrada<< "--| Nombre: " << CSP2[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CSP2[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CSP2[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CSP2[x][y].codigo << endl;
                entrada<< "--| Area: " << CSP2[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}
// Tercer piso del area del sur

void Spiso3()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CSP3[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CSP3[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CSP3[x][y].fila=x;
								CSP3[x][y].columna=y;
								CSP3[x][y].documento=cc;
								CSP3[x][y].codigo=x+y+30;
								CSP3[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CSP3[x][y].area=sur;
				CSP3[x][y].piso=p3;
				CSP3[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CSP3[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CSP3[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CSP3[x][y].telefono;
				valorC=valorB;
				valorC=valorC*t;
				CSP3[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CSP3[x][y].puesto << endl;
                entrada<< "--| Documento: " << CSP3[x][y].documento << endl;
                entrada<< "--| Nombre: " << CSP3[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CSP3[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CSP3[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CSP3[x][y].codigo << endl;
                entrada<< "--| Area: " << CSP3[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();
			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

// area del occidente

void Occidente()
{
	do
	{
		cout<<"\t Area del Occidente";
		cout<<"\n 1. Primero";
		cout<<"\n 2. Segundo";
		cout<<"\n 3. Tercero";
		cout<<"\n Elija el piso:";
		cin>>op11;
		switch(op11)
		{
			case 1:
			OCpiso1();
			break;

			case 2:
			OCpiso2();
			break;

			case 3:
			OCpiso3();
			break;

			default: cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir el piso(1.si/2.no):";
		cin>>op12;
	}while(op12==1);
}


//primer piso del area de Occidente

void OCpiso1()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<COCP1[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(COCP1[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								COCP1[x][y].fila=x;
								COCP1[x][y].columna=y;
								COCP1[x][y].documento=cc;
								COCP1[x][y].codigo=x+y+45;
								COCP1[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				COCP1[x][y].area=occidente;
				COCP1[x][y].piso=p1;
				COCP1[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>COCP1[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>COCP1[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>COCP1[x][y].telefono;
				valorC=valorB+(valorB*60/100);
				valorC=valorC*t;
				COCP1[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << COCP1[x][y].puesto << endl;
                entrada<< "--| Documento: " << COCP1[x][y].documento << endl;
                entrada<< "--| Nombre: " << COCP1[x][y].nombre << endl;
                entrada<< "--| Apellido: " << COCP1[x][y].apellido << endl;
                entrada<< "--| Telefono: " << COCP1[x][y].telefono << endl;
                entrada<< "--| Codigo: " << COCP1[x][y].codigo << endl;
                entrada<< "--| Area: " << COCP1[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}


//segundo piso del area de Occidente

void OCpiso2()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<COCP2[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(COCP2[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								COCP2[x][y].fila=x;
								COCP2[x][y].columna=y;
								COCP2[x][y].documento=cc;
								COCP2[x][y].codigo=x+y+60;
								COCP2[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				COCP2[x][y].area=occidente;
				COCP2[x][y].piso=p2;
				COCP2[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>COCP2[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>COCP2[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>COCP2[x][y].telefono;
				valorC=valorB+(valorB*55/100);
				valorC=valorC*t;
				COCP2[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

                entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << COCP2[x][y].puesto << endl;
                entrada<< "--| Documento: " << COCP2[x][y].documento << endl;
                entrada<< "--| Nombre: " << COCP2[x][y].nombre << endl;
                entrada<< "--| Apellido: " << COCP2[x][y].apellido << endl;
                entrada<< "--| Telefono: " << COCP2[x][y].telefono << endl;
                entrada<< "--| Codigo: " << COCP2[x][y].codigo << endl;
                entrada<< "--| Area: " << COCP2[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}
// Tercer piso del area de OCCIDENTE

void OCpiso3()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<COCP3[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(COCP3[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								COCP3[x][y].fila=x;
								COCP3[x][y].columna=y;
								COCP3[x][y].documento=cc;
								COCP3[x][y].codigo=x+y+75;
								COCP3[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				COCP3[x][y].area=occidente;
				COCP3[x][y].piso=p3;
				COCP3[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>COCP3[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>COCP3[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>COCP3[x][y].telefono;
				valorC=valorB+(valorB*50/100);
				valorC=valorC*t;
				COCP3[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << COCP3[x][y].puesto << endl;
                entrada<< "--| Documento: " << COCP3[x][y].documento << endl;
                entrada<< "--| Nombre: " << COCP3[x][y].nombre << endl;
                entrada<< "--| Apellido: " << COCP3[x][y].apellido << endl;
                entrada<< "--| Telefono: " << COCP3[x][y].telefono << endl;
                entrada<< "--| Codigo: " << COCP3[x][y].codigo << endl;
                entrada<< "--| Area: " << COCP3[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//area del norte
void Norte()
{
	do
	{
		cout<<"\t Area del Norte";
		cout<<"\n 1. Primero";
		cout<<"\n 2. Segundo";
		cout<<"\n 3. Tercero";
		cout<<"\n Elija el piso:";
		cin>>op11;
		switch(op11)
		{
			case 1:
			Npiso1();
			break;

			case 2:
			Npiso2();
			break;

			case 3:
			Npiso3();
			break;

			default: cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir el piso(1.si/2.no):";
		cin>>op12;
	}while(op12==1);
}

//primer piso del area NORTE

void Npiso1()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Deportivo.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CNP1[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CNP1[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CNP1[x][y].fila=x;
								CNP1[x][y].columna=y;
								CNP1[x][y].documento=cc;
								CNP1[x][y].codigo=x+y+100;
								CNP1[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CNP1[x][y].area=norte;
				CNP1[x][y].piso=p1;
				CNP1[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CNP1[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CNP1[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CNP1[x][y].telefono;
				valorC=valorB+(valorB*25/100);
				valorC=valorC*t;
				CNP1[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CNP1[x][y].puesto << endl;
                entrada<< "--| Documento: " << CNP1[x][y].documento << endl;
                entrada<< "--| Nombre: " << CNP1[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CNP1[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CNP1[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CNP1[x][y].codigo << endl;
                entrada<< "--| Area: " << CNP1[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//segundo piso del area NORTE

void Npiso2()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Deportivo.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CNP2[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CNP2[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CNP2[x][y].fila=x;
								CNP2[x][y].columna=y;
								CNP2[x][y].documento=cc;
								CNP2[x][y].codigo=x+y+115;
								CNP2[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CNP2[x][y].area=norte;
				CNP2[x][y].piso=p2;
				CNP2[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CNP2[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CNP2[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CNP2[x][y].telefono;
				valorC=valorB+(valorB*20/100);
				valorC=valorC*t;
				CNP2[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CNP2[x][y].puesto << endl;
                entrada<< "--| Documento: " << CNP2[x][y].documento << endl;
                entrada<< "--| Nombre: " << CNP2[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CNP2[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CNP2[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CNP2[x][y].codigo << endl;
                entrada<< "--| Area: " << CNP2[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

// Tercer piso del area NORTE

void Npiso3()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Deportivo.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CNP3[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CNP3[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CNP3[x][y].fila=x;
								CNP3[x][y].columna=y;
								CNP3[x][y].documento=cc;
								CNP3[x][y].codigo=x+y+130;
								CNP3[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CNP3[x][y].area=norte;
				CNP3[x][y].piso=p3;
				CNP3[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CNP3[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CNP3[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CNP3[x][y].telefono;
				valorC=valorB+(valorB*15/100);
				valorC=valorC*t;
				CNP3[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CNP3[x][y].puesto << endl;
                entrada<< "--| Documento: " << CNP3[x][y].documento << endl;
                entrada<< "--| Nombre: " << CNP3[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CNP3[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CNP3[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CNP3[x][y].codigo << endl;
                entrada<< "--| Area: " << CNP3[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();
			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

// area del oriente

void Oriente()
{
	do
	{
		cout<<"\t Area del Oriente";
		cout<<"\n 1. Primero";
		cout<<"\n 2. Segundo";
		cout<<"\n 3. Tercero";
		cout<<"\n Elija el piso:";
		cin>>op11;
		switch(op11)
		{
			case 1:
			ORpiso1();
			break;

			case 2:
			ORpiso2();
			break;

			case 3:
			ORpiso3();
			break;

			default: cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir el piso(1.si/2.no):";
		cin>>op12;
	}while(op12==1);
}

//primer piso del area de ORIENTE

void ORpiso1()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CORP1[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CORP1[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CORP1[x][y].fila=x;
								CORP1[x][y].columna=y;
								CORP1[x][y].documento=cc;
								CORP1[x][y].codigo=x+y+145;
								CORP1[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CORP1[x][y].area=oriente;
				CORP1[x][y].piso=p1;
				CORP1[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CORP1[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CORP1[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CORP1[x][y].telefono;
				valorC=valorB+(valorB*45/100);
				valorC=valorC*t;
				CORP1[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CORP1[x][y].puesto << endl;
                entrada<< "--| Documento: " << CORP1[x][y].documento << endl;
                entrada<< "--| Nombre: " << CORP1[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CORP1[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CORP1[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CORP1[x][y].codigo << endl;
                entrada<< "--| Area: " << CORP1[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//segundo piso del area de Occidente

void ORpiso2()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CORP2[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CORP2[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CORP2[x][y].fila=x;
								CORP2[x][y].columna=y;
								CORP2[x][y].documento=cc;
								CORP2[x][y].codigo=x+y+1;;
								CORP2[x][y].silla=160;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CORP2[x][y].area=oriente;
				CORP2[x][y].piso=p2;
				CORP2[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CORP2[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CORP2[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CORP2[x][y].telefono;
				valorC=valorB+(valorB*40/100);
				valorC=valorC*t;
				CORP2[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

			    entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CORP2[x][y].puesto << endl;
                entrada<< "--| Documento: " << CORP2[x][y].documento << endl;
                entrada<< "--| Nombre: " << CORP2[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CORP2[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CORP2[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CORP2[x][y].codigo << endl;
                entrada<< "--| Area: " << CORP2[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

// Tercer piso del area de OCCIDENTE

void ORpiso3()
{

	do
	{

	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {

	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<3;x++)
		{
			for(y=0;y<3;y++)
			{
				cout<<CORP3[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=9)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 3";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<3)
					{
						if(y>=0 &&y<3)
						{
							if(CORP3[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CORP3[x][y].fila=x;
								CORP3[x][y].columna=y;
								CORP3[x][y].documento=cc;
								CORP3[x][y].codigo=x+y+175;
								CORP3[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CORP3[x][y].area=oriente;
				CORP3[x][y].piso=p3;
				CORP3[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CORP3[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CORP3[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CORP3[x][y].telefono;
				valorC=valorB+(valorB*35/100);
				valorC=valorC*t;
				CORP3[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

                entrada<< "-----------------------------------" << endl;
                entrada<< "--| Fila: " << x << endl;
                entrada<< "--| Columna: " << y << endl;
                entrada<< "--| Pocicion: " << CORP3[x][y].puesto << endl;
                entrada<< "--| Documento: " << CORP3[x][y].documento << endl;
                entrada<< "--| Nombre: " << CORP3[x][y].nombre << endl;
                entrada<< "--| Apellido: " << CORP3[x][y].apellido << endl;
                entrada<< "--| Telefono: " << CORP3[x][y].telefono << endl;
                entrada<< "--| Codigo: " << CORP3[x][y].codigo << endl;
                entrada<< "--| Area: " << CORP3[x][y].area << endl;
                entrada<< "-----------------------------------" << endl;

                system("cls");

                cout << "\t *******Registro guardado con exito...*******\n\n";
                system("pause");
                system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();

			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//FIN DE REGISTRO DEPORTIVO

//consulta del area deportiva

void ConsulD()
{
	do
	{
		cout<<"\t Consulta";
		cout<<"\n ingrese el numero de documento:";
		cin>>doc;
				if(doc==CSP1[x][y].documento)
				{
					cout<<"\n Ya compro boleta";
					cout<<"\nDocumento: "<<CSP1[x][y].documento<<"\n";
					cout<<"Nombre: "<<CSP1[x][y].nombre<<"\n";
					cout<<"Apellido: "<<CSP1[x][y].apellido<<"\n";
					cout<<"Tel: "<<CSP1[x][y].telefono<<"\n";
					cout<<"Valor boleta: "<<CSP1[x][y].valorboleta<<"\n";
					cout<<"Area: "<<CSP1[x][y].area<<"\n";
					cout<<"piso: "<<CSP1[x][y].piso<<"\n";
					cout<<"Voletas compradas: "<<CSP1[x][y].cant<<"\n";
					for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP1[x][y].codigo;
					if(CSP1[x][y].codigo>0)
					cout<<"Codigo :"<<CSP1[x][y].codigo<<" "<<"Fila :"<<CSP1[x][y].fila<<" "<<"Columna :"<<CSP1[x][y].columna<<"\n";
					}	}

			}
				else
				{
					if(doc==CSP2[x][y].documento)
					{
						cout<<"\n Ya compro boleta";
						cout<<"Documento: "<<CSP2[x][y].documento<<"\n";
						cout<<"Nombre: "<<CSP2[x][y].nombre<<"\n";
						cout<<"Apellido: "<<CSP2[x][y].apellido<<"\n";
						cout<<"Tel: "<<CSP2[x][y].telefono<<"\n";
						cout<<"Valor boleta: "<<CSP2[x][y].valorboleta<<"\n";
						cout<<"Area: "<<CSP2[x][y].area<<"\n";
						cout<<"Piso: "<<CSP2[x][y].piso<<"\n";
						cout<<"Voletas compradas: "<<CSP2[x][y].cant<<"\n";
						for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP2[x][y].codigo;
					if(CSP2[x][y].codigo>0)
					cout<<"Codigo :"<<CSP2[x][y].codigo<<" "<<"Fila :"<<CSP2[x][y].fila<<" "<<"Columna :"<<CSP2[x][y].columna<<"\n";
					}	}
					}
					else
					{
						if(doc==CSP3[x][y].documento)
						{
							cout<<"\n Ya compro boleta";
							cout<<"Documento: "<<CSP3[x][y].documento<<"\n";
							cout<<"Nombre: "<<CSP3[x][y].nombre<<"\n";
							cout<<"Apellido: "<<CSP3[x][y].apellido<<"\n";
							cout<<"Tel: "<<CSP3[x][y].telefono<<"\n";
							cout<<"Valor boleta: "<<CSP3[x][y].valorboleta<<"\n";
							cout<<"Area: "<<CSP3[x][y].area<<"\n";
							cout<<"Piso: "<<CSP3[x][y].piso<<"\n";
							cout<<"Voletas compradas: "<<CSP3[x][y].cant<<"\n";
						for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP3[x][y].codigo;
					if(CSP3[x][y].codigo>0)
					cout<<"Codigo :"<<CSP3[x][y].codigo<<" "<<"Fila :"<<CSP3[x][y].fila<<" "<<"Columna :"<<CSP3[x][y].columna<<"\n";
					}	}//ingresando codigos
						}
						else
						{
							if(doc==CNP1[x][y].documento)
							{
								cout<<"\n Ya compro boleta"<<"\n";
								cout<<"Documento: "<<CNP1[x][y].documento<<"\n";
								cout<<"Nombre: "<<CNP1[x][y].nombre<<"\n";
								cout<<"Apellido: "<<CNP1[x][y].apellido<<"\n";
								cout<<"Tel: "<<CNP1[x][y].telefono<<"\n";
								cout<<"Valor boleta: "<<CNP1[x][y].valorboleta<<"\n";
								cout<<"Area: "<<CNP1[x][y].area<<"\n";
								cout<<"Piso: "<<CNP1[x][y].piso<<"\n";
								cout<<"Voletas compradas: "<<CNP1[x][y].cant<<"\n";
									for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CNP1[x][y].codigo;
					if(CNP1[x][y].codigo>0)
					cout<<"Codigo :"<<CNP1[x][y].codigo<<" "<<"Fila :"<<CNP1[x][y].fila<<" "<<"Columna :"<<CNP1[x][y].columna<<"\n";
					}	}//ingresando codigos
							}
							else
							{
								if(doc==CNP2[x][y].documento)
								{
									cout<<"\n Ya compro boleta"<<"\n";
									cout<<"Documento: "<<CNP2[x][y].documento<<"\n";
									cout<<"Nombre: "<<CNP2[x][y].nombre<<"\n";
									cout<<"Apellido: "<<CNP2[x][y].apellido<<"\n";
									cout<<"Tel: "<<CNP2[x][y].telefono<<"\n";
									cout<<"Valor boleta: "<<CNP2[x][y].valorboleta<<"\n";
									cout<<"Area: "<<CNP2[x][y].area<<"\n";
									cout<<"Piso: "<<CNP2[x][y].piso<<"\n";
									cout<<"Voletas compradas: "<<CNP2[x][y].cant<<"\n";
									for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CNP2[x][y].codigo;
					if(CNP2[x][y].codigo>0)
					cout<<"Codigo :"<<CNP2[x][y].codigo<<" "<<"Fila :"<<CNP2[x][y].fila<<" "<<"Columna :"<<CNP2[x][y].columna<<"\n";
					}	}//ingresando codigos
								}
								else
								{
										if(doc==CNP3[x][y].documento)
									{
										cout<<"\n Ya compro boleta";

										cout<<"Documento: "<<CNP3[x][y].documento<<"\n";
										cout<<"Nombre: "<<CNP3[x][y].nombre<<"\n";
										cout<<"Apellido: "<<CNP3[x][y].apellido<<"\n";
										cout<<"Tel: "<<CNP3[x][y].telefono<<"\n";
										cout<<"Valor boleta: "<<CNP3[x][y].valorboleta<<"\n";
										cout<<"Area: "<<CNP3[x][y].area<<"\n";
										cout<<"Piso: "<<CNP3[x][y].piso<<"\n";
										cout<<"Voletas compradas: "<<CNP3[x][y].cant<<"\n";
										for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CNP3[x][y].codigo;
					if(CNP3[x][y].codigo>0)
					cout<<"Codigo :"<<CNP3[x][y].codigo<<" "<<"Fila :"<<CNP3[x][y].fila<<" "<<"Columna :"<<CNP3[x][y].columna<<"\n";
					}	}//ingresando codigos

									}
									else
									{
										if(doc==COCP1[x][y].documento)
										{
											cout<<"\n Ya compro boleta"<<"\n";

											cout<<"Documento: "<<COCP1[x][y].documento<<"\n";
											cout<<"Nombre: "<<COCP1[x][y].nombre<<"\n";
											cout<<"Apellido: "<<COCP1[x][y].apellido<<"\n";
											cout<<"Tel: "<<COCP1[x][y].telefono<<"\n";
											cout<<"Valor boleta: "<<COCP1[x][y].valorboleta<<"\n";
											cout<<"Area: "<<COCP1[x][y].area<<"\n";
											cout<<"Piso: "<<COCP1[x][y].piso<<"\n";
											cout<<"Voletas compradas: "<<COCP1[x][y].cant<<"\n";
											for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP1[x][y].codigo;
					if(COCP1[x][y].codigo>0)
					cout<<"Codigo :"<<COCP1[x][y].codigo<<" "<<"Fila :"<<COCP1[x][y].fila<<" "<<"Columna :"<<COCP1[x][y].columna<<"\n";
					}	}//ingresando codigos
										}
										else
										{
											if(doc==COCP2[x][y].documento)
											{
												cout<<"\n Ya compro boleta";
												cout<<"Documento: "<<COCP2[x][y].documento<<"\n";
												cout<<"Nombre: "<<COCP2[x][y].nombre<<"\n";
												cout<<"Apellido: "<<COCP2[x][y].apellido<<"\n";
												cout<<"Tel: "<<COCP2[x][y].telefono<<"\n";
												cout<<"Valor boleta: "<<COCP2[x][y].valorboleta<<"\n";
												cout<<"Area: "<<COCP2[x][y].area<<"\n";
												cout<<"Piso: "<<COCP2[x][y].piso<<"\n";
												cout<<"Voletas compradas: "<<COCP2[x][y].cant<<"\n";
												for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP2[x][y].codigo;
					if(COCP2[x][y].codigo>0)
					cout<<"Codigo :"<<COCP2[x][y].codigo<<" "<<"Fila :"<<COCP2[x][y].fila<<" "<<"Columna :"<<COCP2[x][y].columna<<"\n";
					}	}//ingresando codigos

											}
											else
											{
												if(doc==COCP3[x][y].documento)
												{
													cout<<"\n Ya compro boleta";
													cout<<"Documento: "<<COCP3[x][y].documento<<"\n";
													cout<<"Nombre: "<<COCP3[x][y].nombre<<"\n";
													cout<<"Apellido: "<<COCP3[x][y].apellido<<"\n";
													cout<<"Tel: "<<COCP3[x][y].telefono<<"\n";
													cout<<"Valor boleta: "<<COCP3[x][y].valorboleta<<"\n";
													cout<<"Area: "<<COCP3[x][y].area<<"\n";
													cout<<"Piso: "<<COCP3[x][y].piso<<"\n";
													cout<<"Voletas compradas: "<<COCP3[x][y].cant<<"\n";
													for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP3[x][y].codigo;
					if(COCP3[x][y].codigo>0)
					cout<<"Codigo :"<<COCP3[x][y].codigo<<" "<<"Fila :"<<COCP3[x][y].fila<<" "<<"Columna :"<<COCP3[x][y].columna<<"\n";
					}	}//ingresando codigos

												}
												else
												{
													if(doc==CORP1[x][y].documento)
													{
														cout<<"\n Ya compro boleta";
														cout<<"Documento: "<<CORP1[x][y].documento<<"\n";
														cout<<"Nombre: "<<CORP1[x][y].nombre<<"\n";
														cout<<"Apellido: "<<CORP1[x][y].apellido<<"\n";
														cout<<"Tel: "<<CORP1[x][y].telefono<<"\n";
														cout<<"Valor boleta: "<<CORP1[x][y].valorboleta<<"\n";
														cout<<"Area: "<<CORP1[x][y].area<<"\n";
														cout<<"Piso: "<<CORP1[x][y].piso<<"\n";
														cout<<"Voletas compradas: "<<CORP1[x][y].cant<<"\n";
														for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP1[x][y].codigo;
					if(CORP3[x][y].codigo>0)
					cout<<"Codigo :"<<CORP1[x][y].codigo<<" "<<"Fila :"<<CORP1[x][y].fila<<" "<<"Columna :"<<CORP1[x][y].columna<<"\n";
					}	}//ingresando codigos

													}
													else
													{
														if(doc==CORP2[x][y].documento)
														{
															cout<<"\n Ya compro boleta";

															cout<<"Documento: "<<CORP2[x][y].documento<<"\n";
															cout<<"Nombre: "<<CORP2[x][y].nombre<<"\n";
															cout<<"Apellido: "<<CORP2[x][y].apellido<<"\n";
															cout<<"Tel: "<<CORP2[x][y].telefono<<"\n";
															cout<<"Valor boleta: "<<CORP2[x][y].valorboleta<<"\n";
															cout<<"Area: "<<CORP2[x][y].area<<"\n";
															cout<<"Piso: "<<CORP2[x][y].piso<<"\n";
															cout<<"Voletas compradas: "<<CORP2[x][y].cant<<"\n";
															for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP2[x][y].codigo;
					if(CORP2[x][y].codigo>0)
					cout<<"Codigo :"<<CORP2[x][y].codigo<<" "<<"Fila :"<<CORP2[x][y].fila<<" "<<"Columna :"<<CORP2[x][y].columna<<"\n";
					}	}//ingresando codigos
														}
														else
														{
															if(doc==CORP3[x][y].documento)
															{
																cout<<"\n Ya compro boleta";

																cout<<"Documento: "<<CORP3[x][y].documento<<"\n";
																cout<<"Nombre: "<<CORP3[x][y].nombre<<"\n";
																cout<<"Apellido: "<<CORP3[x][y].apellido<<"\n";
																cout<<"Tel: "<<CORP3[x][y].telefono<<"\n";
																cout<<"Valor boleta: "<<CORP3[x][y].valorboleta<<"\n";
																cout<<"Area: "<<CORP3[x][y].area<<"\n";
																cout<<"Piso: "<<CORP3[x][y].piso<<"\n";
																cout<<"Voletas compradas: "<<CORP3[x][y].cant<<"\n";
																for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP3[x][y].codigo;
					if(CORP3[x][y].codigo>0)
					cout<<"Codigo :"<<CORP3[x][y].codigo<<" "<<"Fila :"<<CORP3[x][y].fila<<" "<<"Columna :"<<CORP3[x][y].columna<<"\n";
					}	}//ingresando codigos
															}
															else
															{
																	cout<<"\t ---no ha comprado---";
															}	//fin consulta
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
		}
//fin de la consulta
		cout<<"\n Desea volver a consultar(1.Si/2.No):";
		cin>>op14;
	}while(op14==1);

}

//funcion de cancelar evento

void CancelE()
{
	cout<<"\n \t Cancelando Evento\n";
	for(x=0;x<3;x++)
	{
		for(y=0;y<3;y++)
		{
			cout<<"\t .";
			CSP1[x][y].silla=0;
			CSP2[x][y].silla=0;
			CSP3[x][y].silla=0;
			CNP1[x][y].silla=0;
			CNP2[x][y].silla=0;
			CNP3[x][y].silla=0;
			CORP1[x][y].silla=0;
			CORP2[x][y].silla=0;
			CORP3[x][y].silla=0;
			COCP1[x][y].silla=0;
			COCP2[x][y].silla=0;
			COCP3[x][y].silla=0;
			COCP3[x][y].silla=0;
			CVIP[x][y].silla=0;
		}
		cout<<endl;
		}
	cout<<"\t Evento Cancelado";
}

//funcion de cancelar por compra

void CancelC()
{
	cout<<"\n \t***Cancelar Compra***";
	cout<<"\n Ingrese el codigo:";
	cin>>k;
{

	if(k=CSP1[x][y].codigo)
	{
		CSP1[x][y].silla=0;
		cout<<"\n Compra Cancelada";
	}
	else
	if(k=CSP2[x][y].codigo)
	{
		CSP2[x][y].silla=0;
		cout<<"\n \t *Compra Cancelada*";
	}
	else
	{
		if(k=CSP3[x][y].codigo)
		{
			CSP3[x][y].silla=0;
			cout<<"\n \t *Compra Cancelada*";
		}
		else
		{
			if(k=CNP1[x][y].codigo)
			{
				CNP1[x][y].silla=0;
				cout<<"\n \t *Compra Cancelada*";
			}
			else
			{
				if(k=CNP2[x][y].codigo)
				{
					CNP2[x][y].silla=0;
					cout<<"\n \t *Compra Cancelada*";
				}
				else
				{
					if(k=CNP3[x][y].codigo)
					{
						CNP3[x][y].silla==0;
						cout<<"\n \t *Compra Cancelada*";
					}
					else
					{
						if(k=CORP1[x][y].codigo)
						{
							CORP1[x][y].silla==0;
							cout<<"\n \t *Compra Cancelada*";
						}
						else
						{
							if(k=CORP2[x][y].codigo)
							{
								CORP2[x][y].silla==0;
								cout<<"\n \t *Compra Cancelada*";
							}
							else
							{
								if(k=CORP3[x][y].codigo)
								{
									CORP3[x][y].silla==0;
									cout<<"\n \t *Compra Cancelada*";
								}
								else
								{
									if(k=COCP1[x][y].codigo)
									{
										COCP1[x][y].silla==0;
										cout<<"\n \t *Compra Cancelada*";
									}
									else
									{
										if(k=COCP2[x][y].codigo)
										{
											COCP2[x][y].silla==0;
											cout<<"\n \t *Compra Cancelada*";
										}
										else
										{
											if(k=COCP3[x][y].codigo)
											{
												COCP3[x][y].silla==0;
												cout<<"\n \t *Compra Cancelada*";
											}
											else
											{
												if(k=COCP3[x][y].codigo)
												{
													COCP3[x][y].silla==0;
													cout<<"\n \t *Compra Cancelada*";
												}
												else
												{
													if(k=CVIP[x][y].codigo)
													{
														CVIP[x][y].silla==0;
														cout<<"\n \t *Compra Cancelada*";
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
}

//lista deportiva
void ListaD()
{
	cout<<"\n \tLista de clientes\n";


			cout<<"\n \t Lista Sur piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP1[x][y].nombre, CSP1[c][d].nombre)<=0)
			{
				strcpy(aux,CSP1[x][y].nombre);
				strcpy(CSP1[x][y].nombre,CSP1[c][d].nombre);
				strcpy(CSP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP1[x][y].nombre<<" "<<"Documento:"<<CSP1[x][y].documento;
				}
			}
			}
			//lista piso dos sur
			cout<<"\n \t Lista Sur piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP2[x][y].nombre, CSP2[c][d].nombre)<=0)
			{
				strcpy(aux,CSP2[x][y].nombre);
				strcpy(CSP2[x][y].nombre,CSP2[c][d].nombre);
				strcpy(CSP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP2[x][y].nombre<<" "<<"Documento:"<<CSP2[x][y].documento;
				}
			}
			}
			//lista  tres sur
			cout<<"\n \t Lista Sur piso 3";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP3[x][y].nombre, CSP3[c][d].nombre)<=0)
			{
				strcpy(aux,CSP3[x][y].nombre);
				strcpy(CSP3[x][y].nombre,CSP3[c][d].nombre);
				strcpy(CSP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP3[x][y].nombre<<" "<<"Documento:"<<CSP3[x][y].documento;
				}
			}
			}
			//lista  uno norte
			cout<<"\n \t Lista Norte piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CNP1[x][y].nombre, CNP1[c][d].nombre)<=0)
			{
				strcpy(aux,CNP1[x][y].nombre);
				strcpy(CNP1[x][y].nombre,CNP1[c][d].nombre);
				strcpy(CNP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CNP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CNP1[x][y].nombre<<" "<<"Documento:"<<CNP1[x][y].documento;
				}
			}
			}
						//lista  dos norte
			cout<<"\n \t Lista Norte piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CNP2[x][y].nombre, CNP2[c][d].nombre)<=0)
			{
				strcpy(aux,CNP2[x][y].nombre);
				strcpy(CNP2[x][y].nombre,CNP2[c][d].nombre);
				strcpy(CNP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CNP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CNP2[x][y].nombre<<" "<<"Documento:"<<CNP2[x][y].documento;
				}
			}
			}
						//lista  tres norte
			cout<<"\n \t Lista Norte piso 3";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CNP3[x][y].nombre, CNP3[c][d].nombre)<=0)
			{
				strcpy(aux,CNP3[x][y].nombre);
				strcpy(CNP3[x][y].nombre,CNP3[c][d].nombre);
				strcpy(CNP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CNP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CNP3[x][y].nombre<<" "<<"Documento:"<<CNP3[x][y].documento;
				}
			}
			}
						//lista  uno occidente
			cout<<"\n \t Lista Occidente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP1[x][y].nombre, COCP1[c][d].nombre)<=0)
			{
				strcpy(aux,COCP1[x][y].nombre);
				strcpy(COCP1[x][y].nombre,COCP1[c][d].nombre);
				strcpy(COCP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP1[x][y].nombre<<" "<<"Documento:"<<COCP1[x][y].documento;
				}
			}
			}
						//lista  DOS occidente
			cout<<"\n \t Lista Occidente piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP2[x][y].nombre, COCP2[c][d].nombre)<=0)
			{
				strcpy(aux,COCP2[x][y].nombre);
				strcpy(COCP2[x][y].nombre,COCP2[c][d].nombre);
				strcpy(COCP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP2[x][y].nombre<<" "<<"Documento:"<<COCP2[x][y].documento;
				}
			}
			}
						//lista  TRES occidente
			cout<<"\n \t Lista Occidente piso 3";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP3[x][y].nombre, COCP3[c][d].nombre)<=0)
			{
				strcpy(aux,COCP3[x][y].nombre);
				strcpy(COCP3[x][y].nombre,COCP3[c][d].nombre);
				strcpy(COCP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP3[x][y].nombre<<" "<<"Documento:"<<COCP3[x][y].documento;
				}
			}
			}
						//lista  uno ORIENTE
			cout<<"\n \t Lista Oriente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP1[x][y].nombre, CORP1[c][d].nombre)<=0)
			{
				strcpy(aux,CORP1[x][y].nombre);
				strcpy(CORP1[x][y].nombre,CORP1[c][d].nombre);
				strcpy(CORP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP1[x][y].nombre<<" "<<"Documento:"<<CORP1[x][y].documento;
				}
			}
			}
						//lista  DOS ORIENTE
			cout<<"\n \t Lista Oriente piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP2[x][y].nombre, CORP2[c][d].nombre)<=0)
			{
				strcpy(aux,CORP2[x][y].nombre);
				strcpy(CORP2[x][y].nombre,CORP2[c][d].nombre);
				strcpy(CORP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP2[x][y].nombre<<" "<<"Documento:"<<CORP2[x][y].documento;
				}
			}
			}
						//lista  TRES ORIENTE
			cout<<"\n \t Lista Oriente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP3[x][y].nombre, CORP3[c][d].nombre)<=0)
			{
				strcpy(aux,CORP3[x][y].nombre);
				strcpy(CORP3[x][y].nombre,CORP3[c][d].nombre);
				strcpy(CORP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP3[x][y].nombre<<" "<<"Documento:"<<CORP3[x][y].documento;
				}
			}
			}
}
//FIN DE LA LISTA

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void concierto()
{
			cout<<"Ingrese el tipo de evento:";
			cin>>tipo;
			cout<<"Ingrese el Nombre del evento:";
			cin>>Nomevent;
			cout<<"\n \tTipo de evento:"<<tipo<<" "<< Nomevent;
			cout<<"\n Ingrese el valor base:";
			cin>>valorB;

	do
	{
		cout<<"\n Que desea hacer";
		cout<<"\n 1.Registro";
		cout<<"\n 2.Consulta";
		cout<<"\n 3.Cancelar evento";
		cout<<"\n 4.Lista de clientes";
		cout<<"\n 5.Nostrar Archivo";
		cout<<"\n Que va hacer?: --->";
		cin>>op7;
		switch(op7)
		{
			case 1:
			RegC();
			break;

			case 2:
			ConsulC();
			break;

			case 3:
			Cancel();
			break;

			case 4:
			ListaC();
			break;

			case 5:
            ArC();
            break;

			default: cout<<"\n Error de opcion";
		}
		cout<<"\n Desea volver al menu de Artista o Orquesta(1.si/2.no):";
		cin>>op8;
	}while(op8==1);
}

void RegC(){

    cout<<"\t Inicio de registro";
	do
	{
		cout<<"\n Elija Area";
		cout<<"\n 1.Sur";
		cout<<"\n 2.Occidente";
		cout<<"\n 3.Oriente";
		cout<<"\n 4.Platino";
		cout<<"\n 5.VIP";
		cout<<"\n A cual area va a ir?";
		cin>>op9;
		switch(op9)
		{

			case 1:
			  Sur();
			break;

			case 2:
			  Occidente();
			break;

			case 3:
			   Oriente();
            break;

            case 4:
                Platino();
            break;

            case 5:
                VIP();
            break;

		default:cout<<"\n Error de opcion";
		}

		cout<<"\n Desea volver a eligir area(1.si/2.no):";
		cin>>op10;
	}while(op10==1);

}

//REGISTRO PLATINO
void Platino()
{

	do
	{
        ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {
	cout<<"\n Ingrese el documento:";
    cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<2;x++)
		{
			for(y=0;y<2;y++)
			{
				cout<<CPLAT[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=4)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 2";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<2)
					{
						if(y>=0 &&y<2)
						{
							if(CPLAT[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CPLAT[x][y].documento=cc;
								l=x+y;
								CPLAT[x][y].puesto=l;
								CPLAT[x][y].codigo=x+y+200;;
								CPLAT[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CPLAT[x][y].area=platino;
				CPLAT[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CPLAT[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CPLAT[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CPLAT[x][y].telefono;
				valorC=valorB+(valorB*100/100);
				valorC=valorC*t;
				CPLAT[x][y].valorboleta=valorC;
				cout<<" \n *******Su compra se ha realizado con exito*******\n";
			    printf("\n *******El valor de su compra es:%.1f \n\n",valorC,"*******");
			    system("pause");

                    entrada<< "-----------------------------------" << endl;
			        entrada<< "--| Fila: " << x << endl;
			        entrada<< "--| Columna: " << y << endl;
			        entrada<< "--| Pocicion: " << CPLAT[x][y].puesto << endl;
			        entrada<< "--| Documento: " << CPLAT[x][y].documento << endl;
			        entrada<< "--| Nombre: " << CPLAT[x][y].nombre << endl;
			        entrada<< "--| Apellido: " << CPLAT[x][y].apellido << endl;
			        entrada<< "--| Telefono: " << CPLAT[x][y].telefono << endl;
			        entrada<< "--| Codigo: " << CPLAT[x][y].codigo << endl;
			        entrada<< "--| Area: " << CPLAT[x][y].area << endl;
			        entrada<< "-----------------------------------" << endl;

			        system("cls");

			        cout << "\t *******Registro guardado con exito...*******\n\n";
			        system("pause");
			        system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();
			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//registro vip
void VIP()
{

	do
	{
	    ofstream entrada;
        entrada.open("Registro_Concierto.txt",ios::out|ios::app);
        if(entrada.is_open())
        {

	cout<<"\n Ingrese el documento:";
				cin>>cc;
	 //mostrando si la silla esta ocupada o desocupada
		for(x=0;x<2;x++)
		{
			for(y=0;y<2;y++)
			{
				cout<<CVIP[x][y].silla<<"\t";
			}
			cout<<endl;
		}

			cout<<"\n Cuantas boletas va comprar:";
			cin>>t;
			if(t<=4)
			{
					cout<<"\n El valor de las filas y columna deben ser mayor o igual a 0 y menor a 2";
					cout<<"\n Elija su puesto";
			   for(a=0;a<t;a++)
			   {
				do
				{
					cout<<"\n El valor de la fila:";
					cin>>x;
					cout<<"\n El valor de la columna:";
					cin>>y;
					if(x>=0 && x<2)
					{
						if(y>=0 &&y<2)
						{
							if(CVIP[x][y].silla==0)
							{
								cout<<"\n Silla desocupada";
								//ingresando la posicion
								CVIP[x][y].documento=cc;
								l=x+y;
								CVIP[x][y].codigo=x+y+250;;
								CVIP[x][y].silla=1;
							}
							else
							{
							cout<<"\n Silla ocupada";
							}
						}
						else
						{
					    	cout<<"\n columna no existe";
					    }

					}
					else
					{
				  	 	cout<<"\n Fila no existe";
					 }
				cout<<"\n \n solo si la silla no existe o esta ocupada, vuelva a escojer otra\n de lo contrario diga no(1.si/12.no):";
				cin>>op1;
				}while(op1==1);
		     }

//registro de comprador del area del sur piso uno
				cout<<"\t Puede registrar";
				CVIP[x][y].area=vip;
				CVIP[x][y].cant=t;//cantidad de boletas compradas
 				cout<<"\n Ingrese el nombre:\n";
				cin>>CVIP[x][y].nombre;
				cout<<"\n Ingrese apellido:\n";
				cin>>CVIP[x][y].apellido;
 				cout<<"\n Ingrese el numero de telefono:\n";
				cin>>CVIP[x][y].telefono;
				valorC=valorB+(valorB*80/100);
				valorC=valorC*t;
				CVIP[x][y].valorboleta=valorC;
				cout<<" \n Su compra se ha realizado con exito\n";
			    printf("\n El valor de su compra es:%.1f",valorC);

                    entrada<< "-----------------------------------" << endl;
			        entrada<< "--| Fila: " << x << endl;
			        entrada<< "--| Columna: " << y << endl;
			        entrada<< "--| Pocicion: " << CVIP[x][y].puesto << endl;
			        entrada<< "--| Documento: " << CVIP[x][y].documento << endl;
			        entrada<< "--| Nombre: " << CVIP[x][y].nombre << endl;
			        entrada<< "--| Apellido: " << CVIP[x][y].apellido << endl;
			        entrada<< "--| Telefono: " << CVIP[x][y].telefono << endl;
			        entrada<< "--| Codigo: " << CVIP[x][y].codigo << endl;
			        entrada<< "--| Area: " << CVIP[x][y].area << endl;
			        entrada<< "-----------------------------------" << endl;

			        system("cls");

			        cout << "\t *******Registro guardado con exito...*******\n\n";
			        system("pause");
			        system("cls");
        }else{
                    cout<<"Error, no se pudo crear el archivo \n";
        }
        entrada.close();
			}
			else
			{
			cout<<"\n Compro muchas boletas";
			}

	    cout<<"\n \n Va a eligir otra silla en este piso(1.si/2.no):";
		cin>>op13;
	}while(op13==1);
}

//LISTA CONCIERTO
void ListaC()
{
	cout<<"\n \tLista de clientes\n";


			cout<<"\n \t Lista Sur piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP1[x][y].nombre, CSP1[c][d].nombre)<=0)
			{
				strcpy(aux,CSP1[x][y].nombre);
				strcpy(CSP1[x][y].nombre,CSP1[c][d].nombre);
				strcpy(CSP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP1[x][y].nombre<<" "<<"Documento:"<<CSP1[x][y].documento;
				}
			}
			}
			//lista piso dos sur
			cout<<"\n \t Lista Sur piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP2[x][y].nombre, CSP2[c][d].nombre)<=0)
			{
				strcpy(aux,CSP2[x][y].nombre);
				strcpy(CSP2[x][y].nombre,CSP2[c][d].nombre);
				strcpy(CSP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP2[x][y].nombre<<" "<<"Documento:"<<CSP2[x][y].documento;
				}
			}
			}
			//lista  tres sur
			cout<<"\n \t Lista Sur piso 3";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CSP3[x][y].nombre, CSP3[c][d].nombre)<=0)
			{
				strcpy(aux,CSP3[x][y].nombre);
				strcpy(CSP3[x][y].nombre,CSP3[c][d].nombre);
				strcpy(CSP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CSP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CSP3[x][y].nombre<<" "<<"Documento:"<<CSP3[x][y].documento;
				}
			}
			}
			//lista  VIP
			cout<<"\n \t Lista VIP";
			for(x=0;x<2;x++){
			for(y=1;y<2;y++){
			if ( strcmp( CVIP[x][y].nombre, CVIP[c][d].nombre)<=0)
			{
				strcpy(aux,CVIP[x][y].nombre);
				strcpy(CVIP[x][y].nombre,CVIP[c][d].nombre);
				strcpy(CVIP[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CVIP[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CVIP[x][y].nombre<<" "<<"Documento:"<<CVIP[x][y].documento;
				}
			}
			}
						//lista  PLATINO
			cout<<"\n \t Lista Platino";
			for(x=0;x<2;x++){
			for(y=1;y<2;y++){
			if ( strcmp( CPLAT[x][y].nombre, CPLAT[c][d].nombre)<=0)
			{
				strcpy(aux,CPLAT[x][y].nombre);
				strcpy(CPLAT[x][y].nombre,CPLAT[c][d].nombre);
				strcpy(CPLAT[c][d].nombre,aux);
			}
}
}
			for(x=0;x<2;x++){
			for(y=0;y<2;y++){
			if(CPLAT[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CPLAT[x][y].nombre<<" "<<"Documento:"<<CPLAT[x][y].documento;
				}
			}
			}
						//lista  uno occidente
			cout<<"\n \t Lista Occidente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP1[x][y].nombre, COCP1[c][d].nombre)<=0)
			{
				strcpy(aux,COCP1[x][y].nombre);
				strcpy(COCP1[x][y].nombre,COCP1[c][d].nombre);
				strcpy(COCP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP1[x][y].nombre<<" "<<"Documento:"<<COCP1[x][y].documento;
				}
			}
			}
						//lista  DOS occidente
			cout<<"\n \t Lista Occidente piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP2[x][y].nombre, COCP2[c][d].nombre)<=0)
			{
				strcpy(aux,COCP2[x][y].nombre);
				strcpy(COCP2[x][y].nombre,COCP2[c][d].nombre);
				strcpy(COCP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP2[x][y].nombre<<" "<<"Documento:"<<COCP2[x][y].documento;
				}
			}
			}
						//lista  TRES occidente
			cout<<"\n \t Lista Occidente piso 3";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( COCP3[x][y].nombre, COCP3[c][d].nombre)<=0)
			{
				strcpy(aux,COCP3[x][y].nombre);
				strcpy(COCP3[x][y].nombre,COCP3[c][d].nombre);
				strcpy(COCP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(COCP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<COCP3[x][y].nombre<<" "<<"Documento:"<<COCP3[x][y].documento;
				}
			}
			}
						//lista  uno ORIENTE
			cout<<"\n \t Lista Oriente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP1[x][y].nombre, CORP1[c][d].nombre)<=0)
			{
				strcpy(aux,CORP1[x][y].nombre);
				strcpy(CORP1[x][y].nombre,CORP1[c][d].nombre);
				strcpy(CORP1[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP1[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP1[x][y].nombre<<" "<<"Documento:"<<CORP1[x][y].documento;
				}
			}
			}
						//lista  DOS ORIENTE
			cout<<"\n \t Lista Oriente piso 2";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP2[x][y].nombre, CORP2[c][d].nombre)<=0)
			{
				strcpy(aux,CORP2[x][y].nombre);
				strcpy(CORP2[x][y].nombre,CORP2[c][d].nombre);
				strcpy(CORP2[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP2[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP2[x][y].nombre<<" "<<"Documento:"<<CORP2[x][y].documento;
				}
			}
			}
						//lista  TRES ORIENTE
			cout<<"\n \t Lista Oriente piso 1";
			for(x=0;x<3;x++){
			for(y=1;y<3;y++){
			if ( strcmp( CORP3[x][y].nombre, CORP3[c][d].nombre)<=0)
			{
				strcpy(aux,CORP3[x][y].nombre);
				strcpy(CORP3[x][y].nombre,CORP3[c][d].nombre);
				strcpy(CORP3[c][d].nombre,aux);
			}
}
}
			for(x=0;x<3;x++){
			for(y=0;y<3;y++){
			if(CORP3[x][y].silla==1)
				{
				cout<<"\nNombre: "<<CORP3[x][y].nombre<<" "<<"Documento:"<<CORP3[x][y].documento;
				}
			}
			}
}

//Consulta concierto

void ConsulC()
{
	do
	{
		cout<<"\t Consulta";
		cout<<"\n ingrese el numero de documento:";
		cin>>doc;
				if(doc==CSP1[x][y].documento)
				{
					cout<<"\n Ya compro boleta";
					cout<<"\nDocumento: "<<CSP1[x][y].documento<<"\n";
					cout<<"Nombre: "<<CSP1[x][y].nombre<<"\n";
					cout<<"Apellido: "<<CSP1[x][y].apellido<<"\n";
					cout<<"Tel: "<<CSP1[x][y].telefono<<"\n";
					cout<<"Valor boleta: "<<CSP1[x][y].valorboleta<<"\n";
					cout<<"Area: "<<CSP1[x][y].area<<"\n";
					cout<<"piso: "<<CSP1[x][y].piso<<"\n";
					cout<<"Voletas compradas: "<<CSP1[x][y].cant<<"\n";
					for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP1[x][y].codigo;
					if(CSP1[x][y].codigo>0)
					cout<<"Codigo :"<<CSP1[x][y].codigo<<" "<<"Fila :"<<CSP1[x][y].fila<<" "<<"Columna :"<<CSP1[x][y].columna<<"\n";
					}	}

			}
				else
				{
					if(doc==CSP2[x][y].documento)
					{
						cout<<"\n Ya compro boleta";
						cout<<"Documento: "<<CSP2[x][y].documento<<"\n";
						cout<<"Nombre: "<<CSP2[x][y].nombre<<"\n";
						cout<<"Apellido: "<<CSP2[x][y].apellido<<"\n";
						cout<<"Tel: "<<CSP2[x][y].telefono<<"\n";
						cout<<"Valor boleta: "<<CSP2[x][y].valorboleta<<"\n";
						cout<<"Area: "<<CSP2[x][y].area<<"\n";
						cout<<"Piso: "<<CSP2[x][y].piso<<"\n";
						cout<<"Voletas compradas: "<<CSP2[x][y].cant<<"\n";
						for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP2[x][y].codigo;
					if(CSP2[x][y].codigo>0)
					cout<<"Codigo :"<<CSP2[x][y].codigo<<" "<<"Fila :"<<CSP2[x][y].fila<<" "<<"Columna :"<<CSP2[x][y].columna<<"\n";
					}	}
					}
					else
					{
						if(doc==CSP3[x][y].documento)
						{
							cout<<"\n Ya compro boleta";
							cout<<"Documento: "<<CSP3[x][y].documento<<"\n";
							cout<<"Nombre: "<<CSP3[x][y].nombre<<"\n";
							cout<<"Apellido: "<<CSP3[x][y].apellido<<"\n";
							cout<<"Tel: "<<CSP3[x][y].telefono<<"\n";
							cout<<"Valor boleta: "<<CSP3[x][y].valorboleta<<"\n";
							cout<<"Area: "<<CSP3[x][y].area<<"\n";
							cout<<"Piso: "<<CSP3[x][y].piso<<"\n";
							cout<<"Voletas compradas: "<<CSP3[x][y].cant<<"\n";
						for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CSP3[x][y].codigo;
					if(CSP3[x][y].codigo>0)
					cout<<"Codigo :"<<CSP3[x][y].codigo<<" "<<"Fila :"<<CSP3[x][y].fila<<" "<<"Columna :"<<CSP3[x][y].columna<<"\n";
					}	}//ingresando codigos
						}
						else
						{
							if(doc==CVIP[x][y].documento)
							{
								cout<<"\n Ya compro boleta"<<"\n";
								cout<<"Documento: "<<CVIP[x][y].documento<<"\n";
								cout<<"Nombre: "<<CVIP[x][y].nombre<<"\n";
								cout<<"Apellido: "<<CVIP[x][y].apellido<<"\n";
								cout<<"Tel: "<<CVIP[x][y].telefono<<"\n";
								cout<<"Valor boleta: "<<CVIP[x][y].valorboleta<<"\n";
								cout<<"Area: "<<CVIP[x][y].area<<"\n";
								cout<<"Piso: "<<CVIP[x][y].piso<<"\n";
								cout<<"Voletas compradas: "<<CVIP[x][y].cant<<"\n";
									for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CVIP[x][y].codigo;
					if(CVIP[x][y].codigo>0)
					cout<<"Codigo :"<<CVIP[x][y].codigo<<" "<<"Puesto :"<<CVIP[x][y].puesto<<"\n";
					}	}//ingresando codigos
							}
							else
						{
							if(doc==CPLAT[x][y].documento)
							{
								cout<<"\n Ya compro boleta"<<"\n";
								cout<<"Documento: "<<CPLAT[x][y].documento<<"\n";
								cout<<"Nombre: "<<CPLAT[x][y].nombre<<"\n";
								cout<<"Apellido: "<<CPLAT[x][y].apellido<<"\n";
								cout<<"Tel: "<<CPLAT[x][y].telefono<<"\n";
								cout<<"Valor boleta: "<<CPLAT[x][y].valorboleta<<"\n";
								cout<<"Area: "<<CPLAT[x][y].area<<"\n";
								cout<<"Piso: "<<CPLAT[x][y].piso<<"\n";
								cout<<"Voletas compradas: "<<CPLAT[x][y].cant<<"\n";
									for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CPLAT[x][y].codigo;
					if(CPLAT[x][y].codigo>0)
					cout<<"Codigo :"<<CPLAT[x][y].codigo<<" "<<"Puesto :"<<CPLAT[x][y].puesto<<"\n";
					}	}//ingresando codigos
							}
							else
							{
								if(doc==COCP1[x][y].documento)
								{
									cout<<"\n Ya compro boleta"<<"\n";
									cout<<"Documento: "<<COCP1[x][y].documento<<"\n";
									cout<<"Nombre: "<<COCP1[x][y].nombre<<"\n";
									cout<<"Apellido: "<<COCP1[x][y].apellido<<"\n";
									cout<<"Tel: "<<COCP1[x][y].telefono<<"\n";
									cout<<"Valor boleta: "<<COCP1[x][y].valorboleta<<"\n";
									cout<<"Area: "<<COCP1[x][y].area<<"\n";
									cout<<"Piso: "<<COCP1[x][y].piso<<"\n";
									cout<<"Voletas compradas: "<<COCP1[x][y].cant<<"\n";
									for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP1[x][y].codigo;
					if(COCP1[x][y].codigo>0)
					cout<<"Codigo :"<<COCP1[x][y].codigo<<" "<<"Puesto :"<<COCP1[x][y].puesto<<"\n";
					}	}//ingresando codigos
								}
								else
									{
										if(doc==COCP2[x][y].documento)
											{
												cout<<"\n Ya compro boleta";
												cout<<"Documento: "<<COCP2[x][y].documento<<"\n";
												cout<<"Nombre: "<<COCP2[x][y].nombre<<"\n";
												cout<<"Apellido: "<<COCP2[x][y].apellido<<"\n";
												cout<<"Tel: "<<COCP2[x][y].telefono<<"\n";
												cout<<"Valor boleta: "<<COCP2[x][y].valorboleta<<"\n";
												cout<<"Area: "<<COCP2[x][y].area<<"\n";
												cout<<"Piso: "<<COCP2[x][y].piso<<"\n";
												cout<<"Voletas compradas: "<<COCP2[x][y].cant<<"\n";
												for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP2[x][y].codigo;
					if(COCP2[x][y].codigo>0)
					cout<<"Codigo :"<<COCP2[x][y].codigo<<" "<<"Fila :"<<COCP2[x][y].fila<<" "<<"Columna :"<<COCP2[x][y].columna<<"\n";
					}	}//ingresando codigos

											}
											else
											{
												if(doc==COCP3[x][y].documento)
												{
													cout<<"\n Ya compro boleta";
													cout<<"Documento: "<<COCP3[x][y].documento<<"\n";
													cout<<"Nombre: "<<COCP3[x][y].nombre<<"\n";
													cout<<"Apellido: "<<COCP3[x][y].apellido<<"\n";
													cout<<"Tel: "<<COCP3[x][y].telefono<<"\n";
													cout<<"Valor boleta: "<<COCP3[x][y].valorboleta<<"\n";
													cout<<"Area: "<<COCP3[x][y].area<<"\n";
													cout<<"Piso: "<<COCP3[x][y].piso<<"\n";
													cout<<"Voletas compradas: "<<COCP3[x][y].cant<<"\n";
													for(x=0;x<3;x++){ for(y=0;y<3;y++){
					COCP3[x][y].codigo;
					if(COCP3[x][y].codigo>0)
					cout<<"Codigo :"<<COCP3[x][y].codigo<<" "<<"Fila :"<<COCP3[x][y].fila<<" "<<"Columna :"<<COCP3[x][y].columna<<"\n";
					}	}//ingresando codigos

												}
												else
												{
													if(doc==CORP1[x][y].documento)
													{
														cout<<"\n Ya compro boleta";
														cout<<"Documento: "<<CORP1[x][y].documento<<"\n";
														cout<<"Nombre: "<<CORP1[x][y].nombre<<"\n";
														cout<<"Apellido: "<<CORP1[x][y].apellido<<"\n";
														cout<<"Tel: "<<CORP1[x][y].telefono<<"\n";
														cout<<"Valor boleta: "<<CORP1[x][y].valorboleta<<"\n";
														cout<<"Area: "<<CORP1[x][y].area<<"\n";
														cout<<"Piso: "<<CORP1[x][y].piso<<"\n";
														cout<<"Voletas compradas: "<<CORP1[x][y].cant<<"\n";
														for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP1[x][y].codigo;
					if(CORP3[x][y].codigo>0)
					cout<<"Codigo :"<<CORP1[x][y].codigo<<" "<<"Fila :"<<CORP1[x][y].fila<<" "<<"Columna :"<<CORP1[x][y].columna<<"\n";
					}	}//ingresando codigos

													}
													else
													{
														if(doc==CORP2[x][y].documento)
														{
															cout<<"\n Ya compro boleta";

															cout<<"Documento: "<<CORP2[x][y].documento<<"\n";
															cout<<"Nombre: "<<CORP2[x][y].nombre<<"\n";
															cout<<"Apellido: "<<CORP2[x][y].apellido<<"\n";
															cout<<"Tel: "<<CORP2[x][y].telefono<<"\n";
															cout<<"Valor boleta: "<<CORP2[x][y].valorboleta<<"\n";
															cout<<"Area: "<<CORP2[x][y].area<<"\n";
															cout<<"Piso: "<<CORP2[x][y].piso<<"\n";
															cout<<"Voletas compradas: "<<CORP2[x][y].cant<<"\n";
															for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP2[x][y].codigo;
					if(CORP2[x][y].codigo>0)
					cout<<"Codigo :"<<CORP2[x][y].codigo<<" "<<"Fila :"<<CORP2[x][y].fila<<" "<<"Columna :"<<CORP2[x][y].columna<<"\n";
					}	}//ingresando codigos
														}
														else
														{
															if(doc==CORP3[x][y].documento)
															{
																cout<<"\n Ya compro boleta";

																cout<<"Documento: "<<CORP3[x][y].documento<<"\n";
																cout<<"Nombre: "<<CORP3[x][y].nombre<<"\n";
																cout<<"Apellido: "<<CORP3[x][y].apellido<<"\n";
																cout<<"Tel: "<<CORP3[x][y].telefono<<"\n";
																cout<<"Valor boleta: "<<CORP3[x][y].valorboleta<<"\n";
																cout<<"Area: "<<CORP3[x][y].area<<"\n";
																cout<<"Piso: "<<CORP3[x][y].piso<<"\n";
																cout<<"Voletas compradas: "<<CORP3[x][y].cant<<"\n";
																for(x=0;x<3;x++){ for(y=0;y<3;y++){
					CORP3[x][y].codigo;
					if(CORP3[x][y].codigo>0)
					cout<<"Codigo :"<<CORP3[x][y].codigo<<" "<<"Fila :"<<CORP3[x][y].fila<<" "<<"Columna :"<<CORP3[x][y].columna<<"\n";
					}	}//ingresando codigos
															}
															else
															{	
																	cout<<"\t ---no ha comprado---";
																
															}	//fin consulta
														}
													}
												}
											}
										}
									}
								}
							}
}
						}
//fin de la consulta
		cout<<"\n Desea volver a consultar(1.Si/2.No):";
		cin>>op14;
	}while(op14==1);

}

//CONSULTA ARCHIVO CONSIERTO
void ArC()
{
	salida.open("Registro_Concierto.txt",ios::in);
  	if (salida.fail())//PREGUNTAR SI EL ARCHIVO EXISTE
    {
    	cout<< "ERROR AL ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        while(!salida.eof()){
                getline(salida, AC);
                cout << AC << endl;
            }
	}
	salida.close();
}

//CONSULTA ARCHIVO DEPORTE
void ArD()
{
	salida.open("Registro_Deportivo.txt",ios::in);
  	if (salida.fail())//PREGUNTAR SI EL ARCHIVO EXISTE
    {
    	cout<< "ERROR AL ABRIR EL ARCHIVO"<<endl;
    }
    else
    {
        while(!salida.eof()){
                getline(salida, AD);
                cout << AD << endl;
            }
	}
	salida.close();
}
