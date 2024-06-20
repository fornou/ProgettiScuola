#include "../Libreries/libArray.h"
void estrai4()
{
    string risp;
    vector<int> g1;
    int valore = 0, scelta = 0, cont, somma;

    do
    {
        cout << "Inserisci 4 valori: ";
        for (int i = 0; i < 4; i++)
        {
            cin >> valore;
            g1.push_back(valore);
        }

        do
        {
            cout << "Continuare(si/no)" && cin >> risp;
            system("cls");
        } while (risp != "si" && risp != "no");
        system("cls");
    } while (risp == "si" || g1.size() % 4 != 0);

    do
    {

        cout << "\nScelta: \n-1 modo somma 1 \n-2 modo somma 2\n-3 esci\n" && cin >> scelta;

        system("cls");

        cout << "Valori inseriti: ";
        for (auto i = g1.begin(); i != g1.end(); ++i)
        {
            cout << *i << " ";
        }

        cout << endl;

        switch (scelta)
        {
        case 1:
            cont = 0;
            somma = 0;
            for (auto i = g1.begin(); i != g1.end(); ++i)
            {
                somma += *i;
                cont++;

                if (cont == 4)
                {
                    cout << "Somma a 4 dei valori inseriti: " << somma << endl;
                    somma = 0;
                    cont = 0;
                }
            }
            break;

        case 2:
            for (int i = 0; i <= g1.size() - 4; i++)
            {
                somma = 0;
                for (int j = 0; j < 4; j++)
                {
                    cout << g1.at(i + j) << " ";
                    somma += g1.at(i + j);
                }
                cout << "| La somma quartina " << cont << ": " << somma << endl;
                cont++;
            }

            break;

        case 3:
            system("cls");
            break;

        default:
            cout << "Errore, ridigita!!!";
            break;
        }

    } while (scelta != 3);
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