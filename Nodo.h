//
// Created by aykull on 20/09/18.
//

using namespace mpointer;

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
};
