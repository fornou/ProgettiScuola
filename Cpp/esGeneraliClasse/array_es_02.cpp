#include "libArray.h"

int main()
{
    cls();
    setlocale(LC_ALL, "Italian"); 

    int vett[DIM];
    double media; 
    int max = vett[0], min = vett[0];
    int n = leggiDim(n);
    caricaVett(vett, n);
    pause();
    stampa(vett, n);
    stampa_mmm(min, max, media);
    


    pause();
    cls();
}
