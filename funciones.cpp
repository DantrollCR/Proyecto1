#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
int * ptr;

void* allocatemem(int cantidad){
    ptr = (int*) malloc(cantidad*sizeof(int));
}
int almacenarint(int dato){
    int i = 0;
    bool start = true;
    int counter = 0;

    while(counter == 0){
        if(*(ptr+i)==0){
            *(ptr+i)=dato;
            counter++;
        }
        else{
            i++;
        }
    }

}



void recibir_datos(){

}


int main() {

    *ptr = 3;
    *(ptr+1)= 5;
    almacenarint (7);
    almacenarint (8);








    std::cout << "Hello, World!" << *(ptr+11) << std::endl;
    return 0;
}