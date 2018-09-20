//
// Created by aykull on 20/09/18.
//

#include "Nodo.h"

class Lista{
private:
    MPointer<Nodo> head;
    int size = 0;

public:
    //Se ingresa un numero y el metodo se encarga de realizar la reserva de memoria y asignarlo a la lista
    void add(int num){
        if(size == 0){
            cout<<"OK"<<endl;
            head.New();
            Nodo nodo;
            nodo.ingresarDato(num);
            head = nodo;
            size++;
        }else {
            cout << "OK Nel" << endl;
            MPointer<Nodo> nuevo;
            nuevo.New();
            Nodo nodo;
            nodo.ingresarDato(num);
            nodo.enlazarSig(head);
            nuevo = nodo;
            head = nuevo;
            size++;
        }
    }

    //Este metodo permite obtener el MPointer<Nodo> que se encuentra en la posicion
    // del indice que ingresemos
    MPointer<Nodo> get(int indice){
        if(indice < size){
            MPointer<Nodo> aux;
            aux.New();
            aux = head;
            while(indice > 0){
                aux = (&aux).obtenerSig();
                indice--;
            }
            return aux;
        }else{
            cout<<"El indice solicitado no existe!";
            MPointer<Nodo> aux;
            aux.New();
            Nodo nodo;
            nodo.ingresarDato(0);
            aux = nodo;
            return aux;
        }
    }

    void imprimirDatos(){
        MPointer<Nodo> aux;
        aux.New();
        aux = head;
        cout<<"{";
        for(int i = 0; i<size;i++){
            if(i<size-1) {
                cout << (&aux).getNum() << ",";
                aux = (&aux).obtenerSig();
            }else{
                cout << (&aux).getNum();
                aux = (&aux).obtenerSig();
            }
        }
        cout<<"}"<<endl;
    }

    //Retorna el prime nodo de la lista
    MPointer<Nodo>& getHead(){
        return head;
    }

};


