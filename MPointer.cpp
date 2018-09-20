//
// Created by luisk on 13/09/18.
//
#include <iostream>
#include <thread>

using namespace std;

namespace mpointer {

/*
 * Esta es la clase MPointer la cual contiene un puntero generico y permitira manipular este puntero
 * de manera mas simple
 */
    template<class T>
    class MPointer{
    private:
        int id = 0;
        T *dato = 0;
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
            this->dato = mp.dato;
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

    template<class T>
    MPointer<T> operator *(const MPointer<T> mp){
        return mp;
    }

    //El destructor
    template<class T>
    MPointer<T>::~MPointer(){
        /*
        cout<<"Destruyendo el MPointer id: "<<id<<endl;
        if (dato != NULL){
            cout<<"Efectivamente no era NULL y lo estamos liberando"<<endl;
            free(dato);
            dato = NULL;
        }
        */

    }




    /*
    class NodoGC{
    private:
        MPointer<int>* direccion;
        int referencias = 0;
    public:
        NodoGC(MPointer<int> * dir){
            direccion = dir;
            referencias++;
        }
    };
    class ListaGC{
    private:
        NodoGC head;
    };
    class MPointerGC{
    private:
        MPointerGC();
        ListaGC listagc;
    public:
        static MPointerGC& getInstance();
        MPointerGC& operator=(const MPointerGC&) = delete;
    };
     */





//-------------------------------------------------------------------------------------------------------------





    /*
     * Esta es la clase nodo la cual de la cual va a estar conformada la lista enlazada
     *
     * paso la clase nodo a un archivo independiente
    class Nodo{
    private:
        MPointer<int> numero;
        MPointer<Nodo> siguiente;
        MPointer<Nodo> anterior;

    public:
        void ingresarDato(int num){
            numero.New();
            numero = num;
            numero.mostrar();
        }

        int getNum(){
            return &numero;
        }

        void enlazarSig(const MPointer<Nodo> &sig){
            siguiente.New();
            siguiente = sig;
        }

        MPointer<Nodo>& obtenerSig(){
            return siguiente;
        }
    };*/


    /*
     * Esta clase nos brinda los metodos para manipular la lista enlazada
     *
    class Lista{
    private:
        MPointer<Nodo> head;
        int size = 0;

    public:
        //Se ingresa un numero y el metodo se encarga de realizar la reserva de memoria y asignarlo a la lista
        void add(int num){
            if(size == 0){
                cout<<"OK"<<endl;
                head.New();
                Nodo nodo;
                nodo.ingresarDato(num);
                head = nodo;
                size++;
            }else {
                cout << "OK Nel" << endl;
                MPointer<Nodo> nuevo;
                nuevo.New();
                Nodo nodo;
                nodo.ingresarDato(num);
                nodo.enlazarSig(head);
                nuevo = nodo;
                head = nuevo;
                size++;
            }
        }

        //Este metodo permite obtener el MPointer<Nodo> que se encuentra en la posicion
        // del indice que ingresemos
        MPointer<Nodo> get(int indice){
            if(indice < size){
                MPointer<Nodo> aux;
                aux.New();
                aux = head;
                while(indice > 0){
                    aux = (&aux).obtenerSig();
                    indice--;
                }
                return aux;
            }else{
                cout<<"El indice solicitado no existe!";
                MPointer<Nodo> aux;
                aux.New();
                Nodo nodo;
                nodo.ingresarDato(0);
                aux = nodo;
                return aux;
            }
        }

        void imprimirDatos(){
            MPointer<Nodo> aux;
            aux.New();
            aux = head;
            cout<<"{";
            for(int i = 0; i<size;i++){
                if(i<size-1) {
                    cout << (&aux).getNum() << ",";
                    aux = (&aux).obtenerSig();
                }else{
                    cout << (&aux).getNum();
                    aux = (&aux).obtenerSig();
                }
            }
            cout<<"}"<<endl;
        }

        //Retorna el prime nodo de la lista
        MPointer<Nodo>& getHead(){
            return head;
        }

    };*/

}

