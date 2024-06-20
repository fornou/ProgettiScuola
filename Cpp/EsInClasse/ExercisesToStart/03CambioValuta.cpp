#include "../Libreries/libArray.h"
void cambioValuta()
{
    map<string, double> valute{
        {"Euro_Dollaro", 1.09},
        {"Dollaro_Euro", 0.92},
        {"Euro_Lira", 1936.27},
        {"Lira_Euro", 0.032}};
    double valore = 0;
    int j, scelta = 0, pos = 0;
    string risp = "", valutaP = "";

    do
    {
        j = 0;

        for (map<string, double>::iterator i = valute.begin(); i != valute.end(); i++)
        {
            j++;
            cout << j << "- " << i->first << " -> " << i->second << endl;
        }

        cout << "Quale cambio di valuta vuoi effetuare:" << endl && cin >> scelta;

        j = 0;

        for (map<string, double>::iterator i = valute.begin(); i != valute.end(); i++)
        {
            j++;
            if (j == scelta)
            {
                pos = i->first.find('_');
                valutaP = i->first.substr(0, pos);
                cout << "Digita il valore in " << valutaP << " per conversione " << i->first << endl;
                cin >> valore;

                valore *= i->second;

                cout << "La conversione è avvenuta da " << i->first << " e vale " << valore << endl;
            }
        }
        if (scelta >= 5 || scelta <= 0)
        {
            cout << "Riprova, errore con scelta" << endl;
        }

        cout << "Continuare:\n - si\n - no" << endl && cin >> risp && system("CLS");

    } while (risp == "si");
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