/*  
    NOMBRES:         HORACIO LOPEZ MORENO && KEVIN ARLEY ANDRADES MONDRAGON
    INSTITUCI√ìN:    INGENIERIAçA DE SISTEMAS
    TEMA:           PROYECTO FINAL DE ARBOLES
*/

//Librerias (System) ---------------------------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include <malloc.h>
#include <conio.h>

using namespace std;

//Estructura (nodo) ----------------------------------------------------------------------------------------------
struct nodo
{
    int goles ;
    nodo* der;
    nodo* izq;
};

//Nodos (Apuntadores) --------------------------------------------------------------------------------------------
nodo *raiz, *aux, *aux2, *aux3, *aux4, *remplazo;

//Variables ------------------------------------------------------------------------------------------------------
int numeros[11] = {30, 15, 45, 33, 12, 22, 43, 2, 16, 44,13};
	int buscar,temp;

//Funciones (Prototipos) -----------------------------------------------------------------------------------------
int posicionar();
int registrar();
int preorden();
int postorden();
int inorden();
int eliminar();
int caso1();
int caso2();
int ubicar();
int ubicarpadre();
int predecesor();
int ubicarmayor();
int remplazar();

//Funciones (x_x) -------------------------------------------------------------------------------------------------       
int posicionar(){
    if (aux -> goles < aux2 -> goles){
        if (aux2 -> izq != NULL){
            aux2 = aux2 -> izq;
            posicionar();
        }else{
            aux2 -> izq = aux;
        }
    }else if (aux -> goles > aux2 -> goles){
        if (aux2 -> der != NULL){
            aux2 = aux2 -> der;
            posicionar();
        }else{
            aux2 -> der = aux;
        }
    }
    return 0;
}

int registrar(){
    for (int i = 0; i < 11; i++){
        aux = ( struct nodo* ) malloc ( sizeof( struct nodo ) );
        aux -> goles = numeros[i];
        aux -> izq = aux -> der = NULL;

        if(raiz == NULL){
		raiz = aux;
        aux = NULL;
        free (aux);

        }else{
        aux2 = raiz;
        posicionar();
        }
    } 
    return 0;
}

int preorden(nodo *aux3){
	if(aux3!=NULL){
    cout << "======[ Goles: " << aux3 -> goles << endl;

    if (aux3 -> izq != NULL){
        preorden(aux3 -> izq);
    }
    if (aux3 -> der != NULL){
        preorden(aux3 -> der);
    }
	}else{
		cout<<"Arbol vacio"<<endl;
	}
    return 0;
}

int inorden(nodo *aux3){
	if(aux3!=NULL){
    if (aux3 -> izq != NULL){
        inorden(aux3 -> izq);
    }
    cout << "======[ Goles: " << aux3 -> goles << endl;

    if (aux3 -> der != NULL){
        inorden(aux3 -> der);
    }
	}else{
		cout<<"Arbol vacio"<<endl;
	}
    return 0;
}

int postorden(nodo *aux3){
    if(aux3!=NULL){
    if (aux3 -> izq != NULL){
        postorden(aux3 -> izq);
    }
    if (aux3 -> der != NULL){
        postorden(aux3 -> der);
    }
	}else{
		cout<<"Arbol vacio"<<endl;
	}
    cout << "======[ Goles: " << aux3 -> goles << endl;
	return 0;
}

int ubicar(nodo *aux3, int aguja){
    if (aux3 -> goles == aguja){
        aux = aux3;
        return 1;
    }else{
     if (aux3 -> izq != NULL)
    {
        ubicar(aux3 -> izq, aguja);
     }
    if (aux3 -> der != NULL)
    {
        ubicar(aux3 -> der, aguja);
    }
    
}
    return 0;
}

int ubicarpadre(nodo *padre){
    if ((padre -> izq != NULL) && (padre -> izq != aux)){
            ubicarpadre(padre -> izq);
        }
            if (padre -> izq == aux){
                aux2 = padre;
            }
        
                if ((padre -> der != NULL) && (padre -> der != aux)){
                    ubicarpadre(padre -> der);
                }
                    if (padre -> der == aux){
                        aux2 = padre;
                    }
    return 0;
}

int casouno(){
    if (aux != raiz)
    {
        ubicarpadre(raiz);
    }

    if (aux2 -> izq == aux){
        aux2 -> izq = NULL;

    } else if (aux2 -> der == aux){
        aux2 -> der = NULL;
    }
    else if(raiz==aux){
	if(aux->izq==NULL){
		raiz=aux->der;
	}else if(aux->der==NULL){
		raiz=aux->izq;
	}		
	}
    aux=NULL;
    free(aux);
    return 0;   
}

int casodos(){
    if (aux != raiz){
        ubicarpadre(raiz);
    }

    if (aux2 -> izq == aux){
        if(aux -> izq != NULL){
            aux2 -> izq = aux -> izq;

        }else if(aux -> der != NULL){
            aux2 -> izq = aux -> der;
        }
        
    } else if (aux2 -> der == aux){
	 if(aux -> izq != NULL){
            aux2 -> der = aux -> izq;
        }else if(aux -> der != NULL){
            aux2 ->der = aux -> der;
        }
    }
    else if(raiz==aux){
	if(aux->izq==NULL){
		raiz=aux->der;
	}else if(aux->der==NULL){
		raiz=aux->izq;
	}	
	}
    aux=NULL;
	aux=NULL;
    free(aux);
    return 0;
}

int ubicarmayor(nodo *aux4){
	
if (aux4->goles > temp ){
	temp=aux4->goles;
	remplazo=aux4;
         cout<<"El numero mayor es: "<<remplazo->goles<<endl;
    }
     if (aux4 -> izq != NULL)
    {
        ubicarmayor(aux4 -> izq);
     }
    if(aux4 -> der != NULL)
    {
        ubicarmayor(aux4 -> der);
    }

	return 0;
}

int remplazar(){
	ubicar(raiz,buscar);
	aux->goles=remplazo->goles;
	remplazo=NULL;
	free(remplazo);
	temp=0;
	return 0;	
}

int predecesor(){
		ubicarmayor(aux->izq);
		ubicar(raiz,remplazo->goles);
	if((aux->der==NULL)&&(aux->izq==NULL)){
		cout<<"caso uno"<<endl;
		casouno();
	}
	else if(((aux->der==NULL)&&(aux->izq!=NULL)) || ((aux->der!=NULL)&&(aux->izq==NULL))){
			cout<<"caso dos"<<endl;
			casodos();
	}
	
		remplazar();
	
	return 0;
}

int eliminar(){
 aux=NULL;
 if(raiz!=NULL){
	cout<<"Numero a buscar"<<endl;
	cin>>buscar;
	ubicar(raiz,buscar);
	if(aux==NULL){
    	cout<<"Numero no encontrado "<<endl;
    	return 1;
	}
	 else if((aux->der==NULL)&&(aux->izq==NULL)){
		cout<<"caso uno"<<endl;
		casouno();
	}
	else if(((aux->der==NULL)&&(aux->izq!=NULL)) || ((aux->der!=NULL)&&(aux->izq==NULL))){
			cout<<"caso dos"<<endl;
			casodos();
	}
	else if((aux->der!=NULL)&&(aux->izq!=NULL)){
			cout<<"caso tres- predecesor"<<endl;
			predecesor();
	 }
	}else{
		cout<<"Arbol vacio"<<endl;
	}
	return 0;
}
	
//Funcion (Principal) ------------------------------------------------------------------------------------------
int main(){
	int opc;
    registrar(); 
    do
    {
        cout << "=======================================================" << endl;
        cout << "\t\n================[ 24th ]======================\n\n" << endl;
        cout << "====== [1] Preorden" << endl;
        cout << "====== [2] inorden" << endl;
        cout << "====== [3] Postorden" << endl;
        cout << "====== [4] Eliminar" << endl;
        cout << "====== [5] Salir \n\n" << endl;
        cout << "=======================================================\n" << endl;
        cout << "Escoje una opcion------>: ";
		cin >> opc;

        switch(opc){
	 		case 1: 
              preorden(raiz); break;
            case 2:
                inorden(raiz);  break;
            case 3:
               postorden(raiz); break;
            case 4:
                eliminar(); break;
            case 5: 
                 cout << "\t ------- Hasta pronto... :-) -------- \n\n"; break;
          defaul: cout << " || Error de opcion.... || \n" << endl; break;
        }
         system("pause");
         system("cls");
    } while (opc != 5);
    
    return 0;
}
