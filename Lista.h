//
// Created by luisk on 15/09/18.
//

#include "Nodo.h"
/*
 * Esta clase nos brinda los metodos para manipular la lista enlazada
 */
class Lista{
private:

    MPointer<Nodo> last;
    int size = 0;

public:

    int getSize(){
        return size;
    }

    //Se ingresa un numero y el metodo se encarga de realizar la reserva de memoria y asignarlo a la lista
    void add(int num){
        if(size == 0){
            cout<<"OK"<<endl;
            last.New();
            Nodo nodo;
            nodo.ingresarDato(num);
            nodo.enlazarSig(last);
            nodo.enlazarAnt(last);
            last = nodo;
            size++;
        }else {
            cout << "OK Nel" << endl;
            MPointer<Nodo> mpnuevo;
            mpnuevo.New();
            Nodo nodoNuevo;
            nodoNuevo.ingresarDato(num);
            nodoNuevo.enlazarAnt(last);
            nodoNuevo.enlazarSig((&last).obtenerSig());
            (!((!last)->obtenerSig()))->enlazarAnt(mpnuevo);
            (!last)->enlazarSig(mpnuevo);
            mpnuevo = nodoNuevo;
            last = mpnuevo;
            size++;
        }
    }

    //Este metodo permite obtener el MPointer<Nodo> que se encuentra en la posicion
    // del indice que ingresemos
    MPointer<Nodo> get(int indice){
        if(indice < size){
            MPointer<Nodo> aux;
            aux.New();
            aux = last;
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
        aux = last;
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
        return last;
    }

};