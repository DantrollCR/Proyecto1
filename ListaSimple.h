//
// Created by aykull on 20/09/18.
//

#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
    int* data;
    int referencias = 0;
    int id;
    int idMax;
    int size;
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


template<typename T>
int add(SimpleList &list, T* data){
    int* dato = (int*)data;
    SimpleList l1, l2 = new(struct Node);

    l2->data  = dato;
    l2->next = NULL;

    if(list==NULL){
        list = l2;
        list->id = 1;
        list->referencias=1;
        list->idMax = 1;
        list->size++;
        return 1;
    }
    else{
        int indice = 2;
        l1 = list;
        while(l1->next!=NULL){
            if(l1->data == dato){
                //cout<<"Si entramos"<<endl;
                l1->referencias++;
                return l1->id;
            }else {
                l1 = l1->next;
                indice++;
            }
        }
        if(l1->data == dato) {
            //cout<<"Si entramos3"<<endl;
            l1->referencias++;
            return l1->id;
        }else{
            //cout<<"Si entramos4"<<endl;
            l2->referencias++;
            l1->next = l2;
            list->idMax++;
            l2->id = list->idMax;
            list->size++;
            return l2->id;
        }

    }
}

template<typename T>
void search(SimpleList list, T* data) {
    int* dato = (int*) data;
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

template<typename T>
int mostrarLista(SimpleList &list, T* data) {
    int i = 0;
    if(list == NULL) {
        cout << "Lista Vacia!!"<<endl;
    }else{
        while (list != NULL) {
            cout << ' ' << i + 1 << ") " << "id:" << list->id << " , direccion guarda:" << list->data
                 << " , referencias:" << list->referencias << endl;
            list = list->next;
            i++;
        }
    }
    return 1;
}

template <typename T>
void deleteSL(SimpleList &list, T* data) {
    int* dato = (int*) data;
    SimpleList l1,l2;
    l1 = list;

    if(list!=NULL) {
        while(l1!=NULL) {
            if(l1->data==dato) {
                if (l1->referencias == 1) {
                    //cout<<"OKY"<<endl;
                    if (l1->data != NULL){
                        //cout<<"Efectivamente no era NULL y lo estamos liberando"<<endl;
                        free(l1->data);
                        l1->data = NULL;
                    }
                    if (l1 == list) {
                        (list->next)->size = (list->size)-1;
                        (list->next)->idMax = (list->idMax);
                        list = list->next;
                    }else{
                        l2->next = l1->next;
                    }
                    return;

                }else{
                    //cout<<"OKYDOKY"<<endl;
                    l1->referencias--;
                    return;
                }

            }
            l2 = l1;
            l1 = l1->next;
        }
        //cout<<"El dato que se desea eliminar no existe"<<endl;
    }
    else
        cout<<" Lista vacia..!";
}