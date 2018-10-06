//
// Created by aykull on 18/09/18.
//
#include <stdio.h>
/* no se usa
void swap(int *n1, int *n2){
    int aux = *n1;
    *n1 = *n2;
    *n2 = aux;
}*/

void bubbleSort(Lista lista, int n){
    cout<<"Lista sin ordenar ";
    lista.imprimirDatos();
    int i, j;
    bool sorted;
    for (int i = 0; i < n-1;i++){
        sorted=false;
        for(int j = 0; j<n-i-1;j++ ){
            if( (&(lista.get(j))).getNum()>(&(lista.get(j + 1))).getNum()){
              Nodo aux;
              aux =  (&(lista.get(j)));
              lista.insertar(&(lista.get(j+1)),j);
              lista.insertar(aux,j+1);
              sorted = true;

            }
        }
        if (!sorted){
           cout<<"Lista ordenada ";
           lista.imprimirDatos();
            break;
        }
    }

}


