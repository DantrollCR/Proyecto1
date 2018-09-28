//
// Created by luisk on 13/09/18.
//

#include <iostream>
#include <thread>

using namespace std;
using namespace gc;

namespace mpointer {

/*
 * Esta es la clase MPointer la cual contiene un puntero generico y permitira manipular este puntero
 * de manera mas simple
 */
    template<class T>
    class MPointer{
    private:
        int id = 0;
        T *dato = NULL;
        MPointerGC* gc1 = NULL;
        void Destructor();

    public:

        void New();

        /*
         * Este es el destructor de la clase si funciona pero la cosa es que se llama solo y destruye la instancia
         * antes de lo esperado entoncs aqui queda para ver como se acopla o que con lo del MPointerGC
         */
        ~MPointer();

        //Sobrecarga del operador &
        T operator&() {
            return *dato;
        }

        //Sobrecarga del operador = para asignar un dato al espacio de memoria a el que apunta dato
        void operator=(T dat) {
            *dato = dat;
        }

        //Sobrecarga del operador = para igualar dos instancias de MPointer     dynamic_cast<const T*>(dat) != nullptr
        void operator=(const MPointer mp) {
            if(mp.dato == NULL){
                cout<<"NO se puede igualar algo NULL"<<endl;
            }else {
                if(gc1 == NULL){
                    gc1 = MPointerGC::getInstance();
                    gc1->setDirection((int*)(mp.dato));
                    Destructor();
                    this->dato = mp.dato;
                    this->id = mp.id;
                }else {
                    gc1->setDirection((int*) (mp.dato));
                    Destructor();
                    this->dato = mp.dato;
                    this->id = mp.id;
                }
            }

        }

        T* operator!(){
            return dato;
        }

        void mostrar();
    };

/*
 * Este metodo imprime en pantalla el valor contenido dentro del MPointer
 */
    template<class T>
    void MPointer<T>::mostrar() {
        if(dato == NULL){
            cout<<"Este MPointer no contiene nada"<<endl;
        }else {
            cout << "El dato del MPointer con id:" << id << " es: " << *dato << endl;
        }
    }

/*
 * Este metodo asigna un bloque de memoria al puntero contenido dentro del MPointer
 */
    template<class T>
    void MPointer<T>::New() {
        dato = (T *) malloc(sizeof(T));
        gc1 = MPointerGC::getInstance();
        id = gc1->setDirection((int*)dato);
        //cout<<"MPointer: "<<id<<endl;
    }

    template<class T>
    MPointer<T> operator *(const MPointer<T> mp){
        return mp;
    }

    //El destructor
    template<class T>
    MPointer<T>::~MPointer(){
        /*
        if(gc1 != NULL){
            gc1->deletDirection((int*)this->dato);
        }
        */

        /*
        cout<<"Destruyendo el MPointer id: "<<id<<endl;

        if (dato != NULL){
            cout<<"Efectivamente no era NULL y lo estamos liberando"<<endl;
            free(dato);
            dato = NULL;
        }
        */

    }

    template<class T>
    void MPointer<T>::Destructor(){
        if(gc1 == NULL)
            gc1 = MPointerGC::getInstance();
        this->gc1->deletDirection((int*)this->dato);
    }
}