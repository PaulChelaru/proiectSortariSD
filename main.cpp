#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <cmath>
using namespace std;

long* vec = new long[100000000];

bool vectorSortat(long vec[], long arraySize){
    int ok = 1;
    for (int i = 0; i < arraySize - 1; ++i)
        if (vec[i] > vec[i + 1]) {
            ok = 0;
            return false;
        }
    return true;
}

void bubbleSort(long vec[], int arraySize)
{
    for (int i = 0; i < arraySize - 1; ++ i)
        for (int j = 0; j < arraySize - i - 1; ++ j)
            if (vec[j] > vec[j + 1])
                swap(vec[j], vec[j + 1]);
}

void merge(long vec[], int st, int mij, int dr)
{
    int n1 = mij - st + 1;
    int n2 = dr - mij;
    long* L = new long[n1];
    long* R = new long[n2];
    for (int i = 0; i < n1; ++ i)
        L[i] = vec[st + i];
    for (int j = 0; j < n2; ++ j)
        R[j] = vec[mij + 1 + j];
    int i = 0, j = 0, k = st;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            vec[k] = L[i ++];
        else
            vec[k] = R[j ++];
        k ++;
    }
    while (i < n1)
        vec[k ++] = L[i ++];
    while (j < n2)
        vec[k ++] = R[j ++];
}

void mergeSort(long v[], int st, int dr){
    if(st >= dr)
        return;
    int mij = (st + dr) / 2;
    mergeSort(v, st, mij);
    mergeSort(v, mij + 1, dr);
    merge(v, st, mij, dr);
}

int part (long vec[], int st, int dr)
{
    long pivot = vec[dr];
    int i = (st - 1);
    for (int j = st; j < dr; ++ j)
    {
        if (vec[j] < pivot)
        {
            i ++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[dr]);
    return (i + 1);
}
void quickSort(long vec[], int st, int dr)
{
    if (st < dr)
    {
        int p = part(vec, st, dr);
        quickSort(vec, st, p - 1);
        quickSort(vec, p + 1, dr);
    }
}

int maxNr(long vec[], int arraySize)
{
    int max = vec[0];
    for (int i = 1; i < arraySize; ++i) {
        if (vec[i] > max)
            max = vec[i];
    }
    return max;
}

void countSort(long vec[], int arraySize) {
    long *output = new long[arraySize];
    int *count = new int[arraySize];
    int max = maxNr(vec, arraySize);

    for (int i = 0; i <= max; ++ i)
        count[i] = 0;

    for (int i = 0; i < arraySize; i ++)
        count[vec[i]] ++;

    for (int i = 1; i <= max; i ++)
        count[i] += count[i - 1];

    for (int i = arraySize - 1; i >= 0; i --) {
        output[count[vec[i]] - 1] = vec[i];
        count[vec[i]] --;
    }

    for (int i = 0; i < arraySize; i++)
        vec[i] = output[i];
}

void countSortRadix(long vec[], int arraySize, int exp)
{
    long *output = new long[arraySize];
    int i, count[10] = { 0 };

    for (i = 0; i < arraySize; i++)
        count[(vec[i] / exp) % 10] ++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = arraySize - 1; i >= 0; i--) {
        output[count[(vec[i] / exp) % 10] - 1] = vec[i];
        count[(vec[i] / exp) % 10] --;
    }

    for (i = 0; i < arraySize; i++)
        vec[i] = output[i];
}

void radixSort(long vec[], int arraySize)
{
    int maxx = maxNr(vec, arraySize);
    for (int i = 1; maxx / i > 0; i *= 10)
        countSortRadix(vec, arraySize, i);
}

void genVecRandom(long arraySize){
    for (int i = 0; i < arraySize; ++ i)
        vec[i] = 1 + (rand() % 10000);
}

void genVecCresc(long arraySize){
    for(int i = 0; i < arraySize; ++ i)
        vec[i] = i;
}

void genVecDesc(long arraySize){
    for(long i = arraySize - 1; i >= 0; i --)
        vec[i] = i;
}

void genVecApCresc(long arraySize){
    for(int i = 0; i < arraySize; i ++)
        vec[i] = i;
    for(int i = sqrt(arraySize); i < arraySize; i += sqrt(arraySize))
            vec[i] = 1 + (rand() % 1000);

}

void genVecApDesc(long arraySize){
    for(int i = arraySize - 1; i >= 0; i --)
        vec[i] = i;
    for(int i = sqrt(arraySize); i < arraySize; i += sqrt(arraySize))
        vec[i] = 1 + (rand() % 1000);

}

void genVecConst(int arraySize){
    for(int i = 0; i < arraySize; i ++)
        vec[i] = 5;
}

int main(){
    int tipVec;
    cout << "Tipuri de vectori:" << endl;
    cout << "1 - Vector random" << endl;
    cout << "2 - Vector sortat crescator" << endl;
    cout << "3 - Vector sortat descrescator" << endl ;
    cout << "4 - Vector sortat aproape crescator" << endl;
    cout << "5 - Vector sortat aproape descrescator" << endl ;
    cout << "6 - Vector constant" << endl ;
    cout << "Alegeti un vector: ";
    cin >> tipVec;

    switch (tipVec) {
        case 1:
            cout << "Ati ales Vector random." << endl;
            cout << endl;
            break;
        case 2:
            cout << "Ati ales vector sortat crescator" << endl;
            cout << endl;
            break;
        case 3:
            cout << "Ati ales vector sortat descrescator" << endl;
            cout << endl;
            break;
        case 4:
            cout << "Ati ales vector sortat aproape crescator." << endl;
            cout << endl;
            break;
        case 5:
            cout << "Ati ales vector sortat aproape descrescator" << endl;
            cout << endl;
            break;
        case 6:
            cout << "Ati ales vector constant" << endl;
            cout << endl;
            break;
    }

    cout << "Sortarile disponibile:" << endl;
    cout << "1 - QuickSort" << endl;
    cout << "2 - MergeSort" << endl;
    cout << "3 - CountSort" << endl ;
    cout << "4 - RadixSort" << endl;
    cout << "5 - BubbleSort" << endl;
    cout << "6 - Sortarea nativa" << endl;
    cout << "Alegeti o sortare pentru testare: ";
    int nrSortare;
    int arraySize;

    cin >> nrSortare;
    switch (nrSortare) {
        case 1:
            cout << "Ati ales QuickSort." << endl;
            cout << endl;
            break;
        case 2:
            cout << "Ati ales MergeSort." << endl;
            cout << endl;
            break;
        case 3:
            cout << "Ati ales CountSort." << endl;
            cout << endl;
            break;
        case 4:
            cout << "Ati ales RadixSort." << endl;
            cout << endl;
            break;
        case 5:
            cout << "Ati ales BubbleSort." << endl;
            cout << endl;
            break;
        case 6:
            cout << "Ati ales sortarea nativa." << endl;
            cout << endl;
            break;
    }

    arraySize = 100;
    int exponent = 2;
    while( arraySize != 100000000) {
        arraySize *= 10;
        exponent ++;

        switch (tipVec) {
            case 1:
                genVecRandom(arraySize);
                break;
            case 2:
                genVecCresc(arraySize);
                break;
            case 3:
                genVecDesc(arraySize);
                break;
            case 4:
                genVecApCresc(arraySize);
                break;
            case 5:
                genVecApDesc(arraySize);
                break;
            case 6:
                genVecConst(arraySize);
                break;
        }

        const auto t1 = chrono::high_resolution_clock::now();
        switch (nrSortare) {
            case 1:
                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                quickSort(vec, 0, arraySize);
                break;
            case 2:
                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                mergeSort(vec, 0, arraySize);
                break;
            case 3:

                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                countSort(vec , arraySize);
                break;
            case 4:
                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                radixSort(vec, arraySize);
                break;
                // radixSor
            case 5:
                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                bubbleSort(vec, arraySize);
                break;
            case 6:
                cout << "Marimea vectorului este de: " << 10 << "ˆ" << exponent << "." << endl;
                cout << "Cel mai mare numar este: " << 1000 << "." << endl;
                int n = sizeof(vec) / sizeof(vec[0]);
                sort(vec, vec + n);
                break;
        }

        const auto t2 = chrono::high_resolution_clock::now();
        if(chrono::duration_cast<chrono::seconds>(t2 - t1).count() > 0)
            cout << "Timp executie: " << chrono::duration_cast<chrono::seconds>(t2 - t1).count() << " secunde\n";
        else cout << "Timp executie: " << chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanosecunde\n";

        cout << "Vectorul";
        if(vectorSortat(vec, arraySize) == true) cout << " este: sortat." << endl;
        else cout << "nu este: sortat." << endl;

        cout << endl;
        cout << "--------------------------------" << endl;
        cout << endl;
    }
    return 0;
}