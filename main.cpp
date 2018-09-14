#include <iostream>
#include "MPointer.cpp"

using namespace std;
using namespace mpointer;

int main() {

    int num = 48;
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
    cout<<"El valor de num es:"<<num<<endl;

    mp3 = mp2;
    mp = mp4;

    mp2.mostrar();
    mp3.mostrar();

    mp2 = 'k';
    mp4 = 900;
    num = &mp;

    mp3.mostrar();
    mp.mostrar();

    cout<<"El valor de num es:"<<num<<endl;

    cout<<"FIN Main"<<endl;

    return 0;
}
