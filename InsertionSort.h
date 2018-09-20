//
// Created by aykull on 18/09/18.
//
/*
#include <stdio.h>
#include <math.h>

using namespace mpointer;
//apadtacion a la lista simple
//falta que sea doble

void insertionSort(Lista lista, int n) {
    cout<<"entra";
    int i, j;
    Nodo key;
    for (i = 1; i < n; i++) {
        // & agregado
        key = &lista.get(i);
        j = i-1;
        //& y getNum()
        while (j >= 0 && (&(lista.get(j))).getNum() > key.getNum()) {

            lista.get(j+1) = lista.get(j);
            j = j-1;
        }
        lista.get(j+1) = key;
    }
}



* Caso base u original del IS con array
 *
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
          Mueve los elementos del array o lista, que son
          mayores a la llave o key, una posicion adelante
          a su posicion actual

while (j >= 0 && arr[j] > key){
 arr[j+1] = arr[j];
 j = j-1;
}
 arr[j+1] = key;
 }
}

// Funcion para imprimir un array
void printArray(int arr[], int n){
    int i;
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



Test IS
int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
 */
