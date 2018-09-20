//
// Created by aykull on 18/09/18.
//

#include<stdio.h>
#include "MPointer.cpp"
//falta adaptar

/*Base sin adaptar al Mpointer del QS
 * void swapQS(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // indice del elemento mas peque;o

    for (int j = low; j <= high- 1; j++) {
        // si el elemento actual es mas grande o mas peque;o que el pivot
        if (arr[j] <= pivot) {
            i++;    // incrementa indice que menor elemento
            swapQS(&arr[i], &arr[j]);
        }
    }
    swapQS(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
    //pi es particion de indice, ahora el
    //indice deberia estar en el lugar correcto

        int pi = partition(arr, low, high);

        //Separacion de elementos antes y
        //despues de la particion


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("n");
}

    //QS test

 int arr[] = {10, 7, 8, 9, 1, 5};
 int n = sizeof(arr)/sizeof(arr[0]);
 quickSort(arr, 0, n-1);
 printf("Sorted array: n");
 printArray(arr, n);
 return 0;

*/



