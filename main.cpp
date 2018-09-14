#include <iostream>

using namespace std;

/*
 * Esta es la clase MPointer la cual contiene un puntero generico y permitira manipular este puntero
 * de manera mas simple
 */
template <class T>
class MPointer{
private:
    T* dato = NULL;
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
    T operator &(){
        return *dato;
    }

    //Sobrecarga del operador = para asignar un dato al espacio de memoria a el que apunta dato
    void operator =(T dat){
        *dato = dat;
    }

    ////Sobrecarga del operador = para igualar dos instancias de MPointer
    void operator =(MPointer mp){
        this->dato = mp.dato;
    }

    void mostrar();

};

/*
 * Este metodo imprime en pantalla el valor contenido dentro del MPointer
 */
template <class T>
void MPointer<T>::mostrar(){
    cout<< "El dato ingresado es: "<< *dato <<endl;
}

/*
 * Este metodo asigna un bloque de memoria al puntero contenido dentro del MPointer
 */
template <class T>
void MPointer<T>::New(){
    dato = (T*) malloc(sizeof(T));
}



int main() {

    int a = 48;
    MPointer<int> mp;
    mp.New();
    MPointer<char> mp2;
    mp2.New();
    MPointer<char> mp3;
    mp3.New();
    MPointer<int> mp4;
    mp4.New();

    mp = 32;
    mp3 = 'z';
    mp2 = 't';
    mp4 = 1;
    mp.mostrar();
    mp2.mostrar();
    mp3.mostrar();
    mp4.mostrar();

    mp3 = mp2;
    mp = mp4;

    mp2.mostrar();
    mp3.mostrar();

    mp2 = 'a';
    mp4 = 900;

    mp3.mostrar();
    mp.mostrar();

    cout<<"FIN Main"<<endl;

    return 0;
}
