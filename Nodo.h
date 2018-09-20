//
// Created by luisk on 15/09/18.
//

using namespace mpointer;
/*
    * Esta es la clase nodo la cual de la cual va a estar conformada la lista enlazada
    */
class Nodo{
private:
    MPointer<int> numero;
    MPointer<Nodo> siguiente;
    MPointer<Nodo> anterior;

public:
    void ingresarDato(int num){
        numero.New();
        numero = num;
        numero.mostrar();
    }

    int getNum(){
        return &numero;
    }

    void enlazarSig(const MPointer<Nodo> &sig){
        siguiente.New();
        siguiente = sig;
    }

    MPointer<Nodo>& obtenerSig(){
        return siguiente;
    }

    void enlazarAnt(const MPointer<Nodo> &ant){
        anterior.New();
        anterior = ant;
    }

    MPointer<Nodo>& obtenerAnt(){
        return anterior;
    }
};