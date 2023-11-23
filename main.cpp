#include <iostream>
#include <stdlib.h>
using namespace std;
//clase para los nodos del arbol
class Nodo{
private:
    int numero;
    Nodo *izquierda;
    Nodo *derecha;

public:
// constructor de Nodo:
    Nodo(int n){
    numero=n;
    izquierda=NULL;
    derecha=NULL;
    }

   int getNumero(){
   return numero;
   }
// la funcion retorna una referencia para un puntero
   Nodo*& getizquierda(){
   return izquierda;
   }

Nodo*& getderecha(){
return derecha;
}
};

//Clase para el arbol

class Arbol{
public:
    int nivel_arbol=-1;

public:
    // constructor de arbol
    Arbol(){};

// funcion para insertar nodos al arbol
    void insertar_nodo(Nodo *&sub_arbol,int Numero){

        if(sub_arbol==NULL){
        Nodo *nuevo=new Nodo(Numero);// se genera un nuevo nodo
        sub_arbol=nuevo;
        nivel_arbol++;// sub_arbol se iguala a ese nuevo nodo y toma todos sus atributos
        }

// Los nodos se va a insertar en el arbol de manera ordenada dependiendo del valor de la raiz

else if(sub_arbol->getNumero()>Numero){
insertar_nodo(sub_arbol->getizquierda(),Numero);
}// si el numero del nuevo nodo es menor que el de la raiz este nuevo nodo se inserta en la izquierda del nodo raiz

else if(sub_arbol->getNumero()<Numero){
    insertar_nodo(sub_arbol->getderecha(),Numero);
}//si el numero del nuevo nodo es mayor que el de la raiz este nuevo nodo se inserta en la derecha del nodo raiz
}// fin de la funcion insertar_nodo

void recorrido_preorden(Nodo *arbol){// Raiz-izquierda-derecha
if (arbol==NULL){
    return;
}
else {
    cout<< arbol->getNumero()<<"-";
    recorrido_preorden(arbol->getizquierda());
    recorrido_preorden(arbol->getderecha());
}
}//fin recorrido_preorden

void recorrido_Inorden(Nodo *arbol){//Izquierda-Raiz-Derecha

if(arbol==NULL){
    return;
}
else{
    recorrido_Inorden(arbol->getizquierda());
    cout<< arbol->getNumero()<<"-";
    recorrido_Inorden(arbol->getderecha());
}

}//fin recorrido InOrden

void recorrido_postorden(Nodo *arbol){//Izquierda-Derecha-Raiz

if (arbol==NULL){
    return;
}
else{
    recorrido_postorden(arbol->getizquierda());
    recorrido_postorden(arbol->getderecha());
    cout<< arbol->getNumero()<<"-";
}

}//fin del recorrido PostOrden

void mostrar_niveles(Nodo *arbol, int nivel){
if (arbol==NULL){
    return;
}
if(nivel==0){
    cout<< arbol->getNumero()<<" ";
}

else if(nivel>0){

    mostrar_niveles(arbol->getizquierda(),nivel-1);
    mostrar_niveles(arbol->getderecha(),nivel-1);
}


}

};//fin de la clase Arbol;

// clase para el menu
class Menu{
    private:
int opciones;
Nodo *_Arbol;
Arbol Arbol_completo;

public:
    //constructor de menu
    Menu(Nodo *arbol, Arbol A){
        _Arbol=arbol;
        Arbol_completo=A;
        }
void Mostrar_opciones(){
int regresar_menu, busqueda_nivel;
    cout<< endl;
cout<< "Ingrese una opcion "<<endl;
cout<< "1)PosOrden"<<endl;
cout<< "2)PreOrden"<<endl;
cout<< "3)Inorden"<<endl;
cout<< "4)Mostrar niveles del arbol"<<endl;
cout<< "5)Salir"<<endl;
cin>> opciones;
switch(opciones){
case 1:
system("cls");
cout<< "El recorrido PostOrden del arbol es: "<<endl;
    Arbol_completo.recorrido_postorden(_Arbol);
    cout<<endl;
    cout<<endl;
    cout<< "1) Regresar al menu "<<endl;
    cout<< "2) Salir"<<endl;
    cin>> regresar_menu;
    if(regresar_menu==1){
            system("cls");
    Mostrar_opciones();
    //regresa al menu
    }
    else{break;//sale del programa}
    break;

case 2:
    system("cls");
cout<< "El recorrido PreOrden del arbol es: "<<endl;
    Arbol_completo.recorrido_preorden(_Arbol);
    cout<<endl;
    cout<<endl;
    cout<< "1) Regresar al menu "<<endl;
    cout<< "2) Salir"<<endl;
    cin>> regresar_menu;
    if(regresar_menu==1){
            system("cls");
    Mostrar_opciones();
    }
    else{break;}
    break;

case 3:
    system("cls");
cout<< "El recorrido InOrden del arbol es: "<<endl;
    Arbol_completo.recorrido_Inorden(_Arbol);
    cout<<endl;
    cout<<endl;
    cout<< "1) Regresar al menu "<<endl;
    cout<< "2) Salir"<<endl;
    cin>> regresar_menu;
    if(regresar_menu==1){
            system("cls");
    Mostrar_opciones();
    }
    else{break;}
    break;

case 4:
    system("cls");
    cout<< "Ingrese el nivel que quiere buscar"<<endl;
    cin>> busqueda_nivel;
    cout<< "Los elementos que se encuentran en el nivel "<< busqueda_nivel<< " son:"<<endl;
    Arbol_completo.mostrar_niveles(_Arbol,busqueda_nivel);
    cout<<endl;
    cout<<endl;
    cout<< "1) Regresar al menu "<<endl;
    cout<< "2) Salir"<<endl;
    cin>> regresar_menu;
    if(regresar_menu==1){
            system("cls");
    Mostrar_opciones();
    }
    else{break;}
    break;

    case 5:
        break;
}
}
}
};//fin de la clase menu

int main()
{
    Nodo *arbol=NULL;

    Arbol a;
    a.insertar_nodo(arbol,10);
    a.insertar_nodo(arbol,4);
    a.insertar_nodo(arbol,5);
    a.insertar_nodo(arbol,12);
    a.insertar_nodo(arbol,14);
    a.insertar_nodo(arbol,6);
    a.insertar_nodo(arbol,8);
    a.insertar_nodo(arbol,15);
    a.insertar_nodo(arbol,11);
    a.insertar_nodo(arbol,22);
    a.insertar_nodo(arbol,3);
    a.insertar_nodo(arbol,7);
    a.insertar_nodo(arbol,2);
    //El arbol ingresado es:
    //                   10
    //                /      \
    //               4        12
    //             /   \    /    \
    //            3     5  11    14
    //           /       \         \
    //          2         6         15
    //                     \          \
    //                      8          22
    //                     /
    //                    7

    Menu menu(arbol,a);
    menu.Mostrar_opciones();

}
