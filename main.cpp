#include <iostream>
#include <time.h>
#include <fstream>
#include <stdlib.h>
#include "kMeans.h"

using namespace std;

template <int N>
ifstream& operator>>(ifstream &in ,kMeans<int,N> &k)
{
    int ornekSayisi, boyut;
    int temp;
    in >> ornekSayisi >> boyut;
    k.setOrnekSayisi(ornekSayisi);
    for(int i=0;i<ornekSayisi;i++)
    {
        in >> temp; // ornek verileri okuyoruz
        k.setDataList(temp);
    }
    return in;
}

int main()
{
    srand (time(NULL));

    kMeans<int,2> ornek1;

    ifstream dosya1(string("inputInt.txt").c_str());
    dosya1>>ornek1;

    ornek1.initMeans();
    while(!ornek1.kumele())
        ornek1.initMeans();


    return 0;
}
