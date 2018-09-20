#include <iostream>
#include "MPointer.cpp"
#include "Lista.h"
//#include "InsertionSort.h"
//#include "QuickSort.h"
//#include "BubbleSort .h"

using namespace std;
using namespace mpointer;

int main() {

    int* intdir;
    int num = 48;
    char letra = 'f';
    char* chardir = &letra;
    intdir = (int*)chardir;

    MPointer<int> mp;
    mp.New();
    MPointer<char> mp2;
    mp2.New();
    MPointer<char> mp3;
    mp3.New();
    MPointer<int> mp4;
    mp4.New();

    mp = 32;
    mp3 = 'z';
    mp2 = 't';
    mp4 = 10;
    mp.mostrar();
    mp2.mostrar();
    mp3.mostrar();
    mp4.mostrar();
    cout<<"El valor de num es:"<<num<<endl;

    mp3 = mp2;
    mp = mp4;

    mp2.mostrar();
    mp3.mostrar();

    *mp2 = 'k';
    *mp4 = 900;
    num = &mp;

    mp3.mostrar();
    mp.mostrar();

    cout<<"El valor de num es:"<<num<<endl;
    cout<<"El valor de intdir es:"<<intdir<<endl;

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

    cout<<(&(lista.get(40))).getNum()<<endl;
    Nodo nodo;
    nodo.ingresarDato(-34);
    nodo.enlazarSig((&(lista.get(4))).obtenerSig());
    lista.get(4) = nodo;
    lista.imprimirDatos();
    cout<<"FIN Main"<<num<<endl;


    return 0;
}