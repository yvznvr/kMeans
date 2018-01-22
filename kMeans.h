#ifndef KMEANS_H
#define KMEANS_H

#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

template <class T, int N>
class kMeans
{
    public:
        kMeans();
        virtual ~kMeans();
        void initMeans();
        bool kumele();
        void atama();
        void guncelle();
        void setDataList(T);
        void setOrnekSayisi(int);
        template <typename U>
        friend ifstream& operator>>(ifstream &in ,kMeans<T,N> &k);

    protected:

    private:
        int eklenenEleman;
        T *merkez;
        T *veri;
        int *etiket;
        int ornekSayisi;
        int kumeSayisi;
        //int test[15] = {1,1,1,3,5,7,9,30,42,25,32,16,18,12,23};
        void copyData(T*,T*);

};

template <class T, int N>
void kMeans<T,N>::setDataList(T i)
{
    veri[eklenenEleman] = i;
    eklenenEleman++;
}

template <class T, int N>
void kMeans<T,N>::setOrnekSayisi(int i)
{
    ornekSayisi = i;
    veri = new T[ornekSayisi];
    etiket = new int[ornekSayisi];
}

template <class T, int N>
kMeans<T,N>::kMeans()
{
    eklenenEleman = 0;
    ornekSayisi = 0;
    kumeSayisi = N;
    merkez = new T[N];
    //veri = new T[ornekSayisi];
    //etiket = new int[ornekSayisi];
}

template <class T, int N>
kMeans<T,N>::~kMeans()
{
    delete[] etiket;
    delete[] veri;

}


template <class T, int N>
void kMeans<T,N>::initMeans()
{
    //veri = test;
    //srand (time(NULL));
    for (int i=0; i<N;i++)
    {
        int temp = rand() % ornekSayisi;
        merkez[i] = veri[temp];
    }
    for(int j=0;j<N;j++)
    {
        cout << j << ". kume merkezi " << merkez[j] << endl;
    }
}


template <class T, int N>
bool kMeans<T,N>::kumele()
{
    T *temp = new T[N];
    copyData(merkez, temp);
    bool flag = false;
    int esitMerkezSayisi = 0; // Bir önceki merkezlerle denk olan merkez sayisi
    while(true)
    {
        atama();
        guncelle();
        esitMerkezSayisi = 0;
        for (int i=0;i<N;i++)
        {
            if (temp[i] != merkez[i])
            {
                copyData(merkez, temp);
                break;
            }
            else esitMerkezSayisi++;
        }
        if (esitMerkezSayisi==N) break;
    }
    return true;
}

template <class T, int N>
void kMeans<T,N>::atama()
{
    int tempUzaklik = 0;
    int tempEtiket;
    for(int i=0;i<ornekSayisi;i++)
    {
        tempEtiket=0;
        for(int j=0;j<N;j++)
        {
            int uzaklik = abs(veri[i] - merkez[j]);
            if(uzaklik<tempUzaklik && j>0)
            {
                tempUzaklik = uzaklik;
                tempEtiket = j;
            }

            tempUzaklik = uzaklik;
        }
        etiket[i] = tempEtiket;
    }

    cout << "veri -> kume" << endl;
    for (int i=0; i<ornekSayisi;i++)
    {
        cout << veri[i] << " -> " << etiket[i] << endl;
    }

}

template <class T, int N>
void kMeans<T,N>::guncelle()
{
    T temp = 0;
    for(int j=0;j<N;j++)
    {
        int elemSayisi = 0;
        for(int i=0;i<ornekSayisi;i++)
        {
            if(etiket[i]==j)
            {
                temp = temp+veri[i];
                elemSayisi++;
            }
        }
        if (temp!=0)
            merkez[j] = temp/elemSayisi;
        temp = 0;
    }

    for(int j=0;j<N;j++)
    {
        cout << j << ". kume merkezi " << merkez[j] << endl;
    }
}

template <class T, int N>
void kMeans<T,N>::copyData(T *a, T *b)
{
    // ilk parametreyi ikinciye kopyalar
    //b = new T[N];
    for(int i=0;i<N;i++)
    {
        b[i] = a[i];
    }

}


#endif // KMEANS_H
