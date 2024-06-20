#include "../Libreries/libArray.h"


void sommaMediaCicli()
{
    int i = 0;
    float n = 0, s = 0;

    cout << "Inserisci n numeri e calcola la loro somma e media con 0\n";

    do
    {
        cin >> n;
        s += n;
        i++;

    } while (n != 0);

    cout << "La somma dei " << i-- << " numeri inseriti --> " << s << endl;
    s /= i;
    cout << "La media dei " << i << " numeri inseriti --> " << s << endl;
}

void pariDispCicli()
{
    int pari = 0, dispari = 0, n = 0;

    cout << "Inserisci n numeri e calcola quanti dispari e pari con 0\n";

    do
    {
        cin >> n;
        if (n % 2 == 0)
        {
            pari++;
        }
        else
        {
            dispari++;
        }

    } while (n != 0);

    cout << "Numeri pari--> " << pari - 1 << endl;
    cout << "Numeri dispari--> " << dispari << endl;
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