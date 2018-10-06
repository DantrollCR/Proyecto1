//
// Created by aykull on 18/09/18.
//

#include<stdio.h>


int partition(Lista lista,int low, int high) {
    int pivot = (&(lista.get(high))).getNum();
    int i = (low-1);

    for (int j = low; j <= high - 1; j++) {
        if ((&(lista.get(j))).getNum() <= pivot) {
            i++;
            Nodo aux;
            aux =  (&(lista.get(i)));
            lista.insertar(&(lista.get(j)),i);
            lista.insertar(aux,j);
        }
    }

    Nodo aux;
    aux =  (&(lista.get(i+1)));
    lista.insertar(&(lista.get(high)),i+1);
    lista.insertar(aux,high);
    return (i+1);

}
void quickSort(Lista lista, int low, int high) {
    cout << "Lista ";
    lista.imprimirDatos();
    if (low < high) {
        int pi = partition(lista, low, high);
        quickSort(lista, low, pi - 1);
        quickSort(lista, pi + 1, high);
    }

}













