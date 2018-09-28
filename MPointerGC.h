//
// Created by luisk on 20/09/18.
//
#include "ListaSimple.h"

namespace gc {

    class MPointerGC {
    private:
        MPointerGC()= default;
        SimpleList list = NULL;


    public:

        static MPointerGC * getInstance(){
            static MPointerGC * instancia = nullptr;
            if(!instancia) instancia = new MPointerGC();
            return instancia;
        }

        int setDirection(int * dir){
            return add(list,dir);
        }

        void imprimirGC(){
            int i = 0;
            mostrarLista(list,&i);
        }

        void deletDirection(int * dir){
            deleteSL(list, dir);
        }


    };


}