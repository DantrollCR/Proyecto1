//
// Created by luisk on 13/09/18.
//

#include <iostream>

using namespace std;

namespace mpointer {

/*
 * Esta es la clase MPointer la cual contiene un puntero generico y permitira manipular este puntero
 * de manera mas simple
 */
    template<class T>
    class MPointer {
    private:
        int id = NULL;
        T *dato = NULL;
    public:

        void New();

        /*
         * Este es el destructor de la clase si funciona pero la cosa es que se llama solo y destruye la instancia
         * antes de lo esperado entoncs aqui queda para ver como se acopla o que con lo del MPointerGC
         *
        ~MPointer(){
            cout<<"Entramos en el destructor de MPointer"<<endl;
            if (dato != NULL){
                cout<<"Efectivamente no era NULL y lo estamos liberando"<<endl;
                free(dato);
                dato = NULL;
            }
        }
         */

        //Sobrecarga del operador &
        T operator&() {
            return *dato;
        }

        //Sobrecarga del operador = para asignar un dato al espacio de memoria a el que apunta dato
        void operator=(T dat) {
            *dato = dat;
        }

        //Sobrecarga del operador = para igualar dos instancias de MPointer
        void operator=(MPointer mp) {
            this->dato = mp.dato;
        }

        void mostrar();

    };

/*
 * Este metodo imprime en pantalla el valor contenido dentro del MPointer
 */
    template<class T>
    void MPointer<T>::mostrar() {
        cout << "El dato del MPointer con id:"<<id<<" es: " << *dato << endl;
    }

/*
 * Este metodo asigna un bloque de memoria al puntero contenido dentro del MPointer
 */
    template<class T>
    void MPointer<T>::New() {
        dato = (T *) malloc(sizeof(T));
        //Aqui hay que llamar al GC y asignar a id lo que devuelva el GC
        id = rand();//en ves de este random va el id que devuelva el GC
    }

}