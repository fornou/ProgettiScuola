#include "libreria.h"

int newDimArray(int newDim, int DIM, string nome){
    cout << "Inserisci numero "<< nome << "("<< 1 <<"-" << DIM <<")\n";
    return ins_in_range(newDim, 1, DIM);
}

void copiaArray(int v[], int n, int c[]){
    for(int i = 0; i < n; i++){
        c[i] = v[i];
    }
}

void caricaArray( int v[], int dim){
    for(int i = 0; i < dim; i++){
        v[i] = rand_in_range(0, 10);
    }
}

void stampa(int v[], int n){
    for(int i = 0; i < n; i++){
        cout << i <<"- " << v[i] << endl;
    } 
}

void stampa2(int v[], int n){
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    } 
    cout <<endl;
}

double media(int v[], int n, double media){
    for(int i = 0; i < n; i++){
        media += v[i];
    } 
    return media /= n;
}

int minimo(int n, int min, int v[]){
    for(int i = 0; i < n; i++){
        if(v[i] < min){
            min = v[i];
        }
    } 
    return min;
}

int massimo(int n, int max, int v[]){
    for(int i = 0; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
    } 
    return max;
}

void stampa_mmm(int min, int max, double media){
    cout << "La media: " << media << "\nIl minimo: " << min << "\nil massimo: " << max;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
