//
// Created by luisk on 30/10/18.
//

#include <stdio.h>
#include <math.h>
using namespace mpointer;
//apadtacion a la lista simple
//falta que sea doble

    void insertionSort(Lista lista) {
        cout<<"Lista sin ordenar:";
        lista.imprimirDatos();
        int size = lista.getSize();
        int  j;
        Nodo key;
        for (int i = 1; i < size; i++){
            key = &lista.get(i);
            j = i - 1;
            while (j >= 0 && (&(lista.get(j))).getNum() > key.getNum()) {
                lista.insertar(&(lista.get(j)),j+1);
                j = j - 1;
            }
            lista.insertar(key,j+1);
        }
        cout<<"Lista ordenada:";
        lista.imprimirDatos();
    }