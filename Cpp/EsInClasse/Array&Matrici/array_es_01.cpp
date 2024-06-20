#include "libArray.h"
#define DIM 50
int main()
{
    cls();
    setlocale(LC_ALL, "Italian"); 

    int vett[DIM];
    int copia[DIM];

    vector<string> sceltePossibili = {"MODIFICA GRANDEZZA ARRAY INIZIALE","CARICA ARRAY","STAMPA ARRAY CREATO","COPIA ARRAY CREATO","STAMPA ARRAY COPIATO","EXIT"};
    int scelta, n = 0, v;
    bool insLength = false, insCaric = false, insCaric2 = false;
    cls();

    do{
        menuDinamico(sceltePossibili);
        scelta = in_int(scelta);
        cls();
        switch (scelta)
        {
            case 1:
                cout << "MODIFICA GRANDEZZA ARRAY INIZIALE\n";
                n = newDimArray(n, DIM); 
                insCaric = false;
                break;

            case 2:
                if(n != 0){
                    cout << "CARICA ARRAY\n";
                    caricaArray(vett, n);
                    insCaric = true;
                }else{
                    cls();
                    cout << "Errore non dichiarata grandezza\n";
                }
                break;
            case 3: 
                if(insCaric){
                    cout << "STAMPA ARRAY CARICATO\n";
                    stampa(vett, n);
                }else{
                    cls();
                    cout << "Errore non caricato array 1\n";
                }
                break;
            case 4:
                if(insCaric){
                    cout << "COPIA ARRAY CREATO\n";
                    copiaArray(vett, n, copia);
                    insCaric2 = true;
                    v = n;
                }else{
                    cls();
                    cout << "Errore non caricato array 1\n";
                }
                break;
            case 5:
                if(insCaric2){
                    cout << "STAMPA ARRAY COPIATO\n";
                    stampa(copia, v);
                }else{
                    cls();
                    cout << "Errore non caricato array 2\n";
                }
                break;
                case 6:
                break;
            default:
                cout << "Error!!\n";
                break;
        }
        pause();
        cls();

    }while(scelta != 6);

    
    
    

    

    

    
}
