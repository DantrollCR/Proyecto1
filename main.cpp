#include <iostream>
#include "MPointerGC.h"
#include "MPointer.h"
#include "Lista.h"

using namespace std;

int main() {

/*
    int num = 48;

    MPointer<int> mp;
    mp.New();
    MPointer<char> mp2;
    mp2.New();
    MPointer<char> mp3;
    mp3.New();
    MPointer<int> mp4;
    mp4.New();
    MPointer<char> mp5;
    mp5.New();
    MPointer<char> mp6;
    mp6.New();
    MPointer<char> mp7;
    mp7.New();
    MPointer<char> mp8;

    mp = 32;
    mp3 = 'z';
    mp2 = 't';
    mp4 = 69;

    mp.mostrar();
    mp2.mostrar();
    mp3.mostrar();
    mp4.mostrar();
    mp8.mostrar();
    cout<<"El valor de num es:"<<num<<endl;

    mp = mp4;
    mp3 = mp2;
    mp5 = mp2;
    mp6 = mp2;
    mp7 = mp2;


    mp2.mostrar();
    mp3.mostrar();
    mp7.mostrar();

    num = &mp;

    cout<<"El valor de num es:"<<num<<endl;

*/
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;


    Lista lista = Lista();
    lista.add(45);
    lista.add(24);
    lista.add(98);
    lista.add(47);
    lista.add(10);
    lista.add(1);
    lista.add(69);
    lista.add(999);
    lista.add(53);
    lista.imprimirDatos();
    Nodo nodo;
    nodo.ingresarDato(-34);
    nodo.enlazarSig((&(lista.get(4))).obtenerSig());
    lista.get(4) = nodo;
    lista.imprimirDatos();
    cout<<(&((&(lista.get(5))).obtenerAnt())).getNum()<<"este es!!"<<endl;


    MPointerGC* gc1 = MPointerGC::getInstance();

    gc1->imprimirGC();


    cout<<"FIN Main"<<endl;
    return 0;
}

