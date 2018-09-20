//
// Created by aykull on 20/09/18.
//


#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};

typedef struct Node *SimpleList;
/*agrega al inicio
void add(SimpleList &list, int data){
    SimpleList list1;
    list1 = new(struct Node);
    list1->data = data;
    list1->next = list;
    list  = list1;
}
*/
//agrega al final
void add(SimpleList &list, int data){
    SimpleList l1, l2 = new(struct Node);

    l2->data  = data;
    l2->next = NULL;

    if(list==NULL){
        list = l2;
    }
    else{
        l1 = list;
        while(l1->next!=NULL){
            l1 = l1->next;
        }
        l1->next = l2;
    }

}


void search(SimpleList list, int data) {
    SimpleList l1 = list;
    int i = 1, band = 0;

    while(l1!=NULL) {
        if(l1->data==data) {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        l1 = l1->next;
        i++;
    }

    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}

void print(SimpleList list) {
    int i = 0;

    while(list != NULL) {
        cout <<' '<< i+1 <<") " << list->data << endl;
        list = list->next;
        i++;
    }
}


void deleteSL(SimpleList &list, int data) {
    SimpleList l1,l2;
    l1 = list;

    if(list!=NULL) {

        while(l1!=NULL) {

            if(l1->data==data) {

                if(l1==list)
                    list = list ->next;
                else
                    l2->next = l1->next;

                delete(l1);
                return;
            }
            l2 = l1;
            l1 = l1->next;
        }
    }
    else
        cout<<" Lista vacia..!";
}

