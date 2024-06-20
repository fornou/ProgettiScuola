#include "../libreries/libreria.h"

void insert(string &descr, double &prezzo, int &quant){
    cout << "Inserisci il prodotto: " && cin >> descr;
    do{
        cout << "Inserisci il prezzo: " && cin >> prezzo;
    }while(prezzo <= 0);
    do{
        cout << "Inserisci la quantita': " && cin >> quant;
    }while(quant <= 0);
}

double sconto(double perc, double &totale){
    return totale = totale - (totale*perc);
}

void calcolaSconto(double &totale, int quant, bool &scontato){
        if(totale > 50 )
        {
            totale = sconto(0.1, totale);
            scontato = true;
        }
        if(quant > 5){
            totale = sconto(0.07, totale);
            scontato = true;
        }     
}

void printScontrino(string descr, double prezzo, int quant, double totale){
    cout << descr<<"\t"<<prezzo<<"\t"<<quant<<"\t"<<totale<<"\n";
}

int main()
{
    string descr = "";
    double prezzo = 0, totale = 0;
    int quant = 0, scelta = 0;
    bool scont = false;
    do{
        system("cls");  

        cout << "_______________________\n";                       
        cout << "   GESTIONE SCONTRINO  \n";
        cout << "_______________________\n\n";
        cout << "_______________________\n";                       
        cout << "Menu' utente principale\n";
        cout << "_______________________\n";
        cout << "1)Inserimento articolo\n2)Applica sconto\n3)Stampa scontrino\n4)Esci\n";
        cout << "_______________________\n\n";
        cout << "Inserire scelta (1, 2 ,3, oppure 4): ";
        cin >> scelta;

        switch (scelta)
        {
            case 1:
                system("cls");
                cout << "_______________________\n";                       
                cout << "    INSERIMENTO DATI   \n";
                cout << "        ARTICOLO       \n";
                cout << "_______________________\n\n";
                insert(descr, prezzo, quant);
                scont = false;
                totale = prezzo * quant;
                cout << "Inserimento effettuato!! Totale: " << totale << "Euro\n";
                system("pause");
            break;

            case 2:
                system("cls");
                cout << "_______________________\n";                       
                cout << "     APPPLICAZIONE     \n";
                cout << "        SCONTO         \n";
                cout << "_______________________\n\n";

                if(scont == false){
                    if(descr == ""){
                        cout << "Articolo non inserito!! Inserisci prima un articolo\n";
                    }
                    else{
                        calcolaSconto(totale, quant, scont);
                        if(scont == true)
                        {
                            cout << "Sconto applicato: nuovo totale = " << totale <<endl;
                            scont = true;
                        }
                        else{
                            cout << "Nessuno sconto perche' non soddisfa i requisiti\n";  
                        } 
                    }
                }else{
                    cout << "Sconto gia' effettuato su questo prodotto\n";
                }
                system("pause");
                
            break;
            case 3:
                system("cls");

                cout << "_______________________\n";                       
                cout << "      STAMPA DATI      \n";
                cout << "       SCONTRINO       \n";
                cout << "_______________________\n\n";

                if(descr == ""){
                    cout << "Articolo non inserito!! Inserisci prima un articolo\n";
                }else{
                    cout << "Articolo\tPrezzo\tQuantita'\tTotale\n";
                    printScontrino(descr, prezzo, quant, totale);
                }
                system("pause");
            break;
            case 4:
                
                break;
            
            default:
                cout << "Error, retry!!";
                break;
        }
        
    }while(scelta!=4);
}
