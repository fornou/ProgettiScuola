# Documentazione Librerie

Benvenuto alla documentazione ufficiale delle librerie dello sviluppatore Mattia Forneron!

## Menu

1. [Introduzione](#introduzione)
2. [Guida all'Installazione](#guida-allinstallazione)
3. [Utilizzo & Funzioni](#utilizzo-e-funzioni)
4. [Configurazione](#configurazione)
5. [Funzioni](#funzioni)
6. [Contatti](#contatti)

## Introduzione

Questo documento fornisce una guida dettagliata su come utilizzare e configurare le librerie per poter  usufruire delle funzioni.

## Guida all'Installazione

Occorre semplicemente inserire il file o i files .h nella cartella del progetto progetto e richiamarlo nel file .cpp:
1. [Interno a caretella ulteriore](#interno-a-cartella-ulteriore)
2. [Nella stessa cartella](#nella-stessa-cartella)

### Interno a cartella ulteriore
#include "file.h" 

### Nella stessa cartella
#include "/nomecartella/file.h

## Utilizzo e Funzioni
1. [libArray.h](#libarrayh)
2. [libreria.h](#libreriah)

## libArray.h 
### newDimArray()
```cpp
int newDimArray(int newDim, int DIM){
    cout << "Inserisci la dimensione massima(max " << DIM << ")\n";
    return ins_in_range(newDim, 0, DIM);
}
```
Descrizione della funzione 1 e come utilizzarla.

### copiaArray()
```cpp
void copiaArray(int v[], int n, int c[]){
    for(int i = 0; i < n; i++){
        c[i] = v[i];
    }
}
```
Descrizione della funzione 2 e come utilizzarla.

### caricaArray()
```cpp
void caricaArray( int v[], int dim){
    for(int i = 0; i < dim; i++){
        v[i] = rand_in_range(0, 10);
    }
}
```
Descrizione della funzione 3 e come utilizzarla.

### stampa()
```cpp
void stampa(int v[], int n){
    for(int i = 0; i < n; i++){
        cout << i <<"- " << v[i] << endl;
    } 
}
```
Descrizione della funzione 3 e come utilizzarla.

### media()
```cpp
double media(int v[], int n, double media){
    for(int i = 0; i < n; i++){
        media += v[i];
    } 
    return media /= n;
}
```

### minimo()
```cpp
int minimo(int n, int min, int v[]){
    for(int i = 0; i < n; i++){
        if(v[i] < min){
            min = v[i];
        }
    } 
    return min;
}
```

### massimo()
```cpp
int massimo(int n, int max, int v[]){
    for(int i = 0; i < n; i++){
        if(v[i] > max){
            max = v[i];
        }
    } 
    return max;
}
```
### stampa_mmm()
```cpp
void stampa_mmm(int min, int max, double media){
    cout << "La media: " << media << "\nIl minimo: " << min << "\nil massimo: " << max;
}
```
# libreria.h 

## Contatti

Per ulteriori domande, commenti o feedback, puoi contattare il team di sviluppo del progetto utilizzando i seguenti canali di comunicazione.

Gmail: mattiaforneron@gmail.com

**Autore:** Forneron Mattia  
**Ultima Modifica:** 15 marzo 2024
