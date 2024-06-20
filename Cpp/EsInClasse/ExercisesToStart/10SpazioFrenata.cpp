#include "../Libreries/libArray.h"
void spazioFrenata()
{
    int scelta, v = 0;
    float f = 0;

    cout << "inserisci la velocità\n";
    cin >> v;

    cout << "Tipo di asfalto\n";

    vector<string> sceltePossibili = {"liscio", "ruvido", "bagnato", "ghicciato", "Esci"};
    menuDinamico(sceltePossibili);

    cin >> scelta;

    switch (scelta)
    {
    case 1:
        f = 0.6;
        break;

    case 2:
        f = 0.5;
        break;

    case 3:
        f = 0.4;
        break;

    case 4:
        f = 0.1;
        break;

    default:
        cout << "Riprova";
        break;
    }

    int spazio = pow(v, 2) / (250 * f);

    cout << "Ci metterai metri: " << spazio << endl;
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