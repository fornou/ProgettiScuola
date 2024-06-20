#include "../Libreries/libArray.h"


void sconto1()
{

    double somma = 0, prezzo = 0, sconto = 0;
    string parola = "non scontato", parola1 = "perchè non supera i 125$";

    for (int i = 0; i < 15; i++)
    {
        cout << "digita in prezzo del prodotto " << i << endl;
        cin >> prezzo;

        somma += prezzo;
    }

    if (somma >= 125)
    {
        sconto = somma * 15 / 100;
        parola1 = "perchè supera i 125$\n";
        parola = "scontato";
    }

    cout << "Lo sconto è di " << sconto << " su " << somma << " " << parola1 << endl;

    somma -= sconto;

    cout << "Il prezzo " << parola << " è di " << somma << endl;
}

void sconto2()
{

    double scontoTot = 0, prezzo = 0, sconto = 0, sommaPrezzi = 0;

    for (int i = 0; i < 15; i++)
    {
        cout << "digita in prezzo del prodotto " << i << endl;
        cin >> prezzo;

        if (prezzo >= 125)
        {
            sconto = prezzo * 15 / 100;
            cout << "Lo sconto su questo prodotto è di " << sconto << endl;
            scontoTot += sconto;
            cout << "Lo sconto totale parziale è di " << scontoTot << endl;
        }

        sommaPrezzi += prezzo;

        cout << "Lo somma totale parziale senza sconti effettuati è di " << sommaPrezzi << endl;
    }

    sommaPrezzi -= scontoTot;

    cout << "Lo sconto totale è di " << scontoTot << endl;

    cout << "Il prezzo totale è " << sommaPrezzi << endl;
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string risp = "";

    do
    {
        system("cls");
        do
        {
            cout << "Vuoi continuare(si/no):\n";
            cin >> risp;
            if (risp != "si" && risp != "no")
            {
                system("cls");
                cout << "Il sistema accetta solo si o no come input\n";
            }
        } while (risp != "si" && risp != "no");

    } while (risp == "si");

    system("cls");
}