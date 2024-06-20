#include "../Libreries/libArray.h"
void menuDinamico(vector<string> g1)
{

    // si richiama così menuDinamico(sceltePossibili);
    // prende un vettore come parametro e ne crea un menù visivo
    // vector<string> sceltePossibili = {"A","B","C","D","E","F","G","H"};

    cout << "_______________________\n\n";
    cout << "         MENU'         \n";
    cout << "_______________________\n\n";
    cout << "Effettua la tua scelta:\n";
    int cont = 1, scelta = 0;

    for (auto i = g1.begin(); i != g1.end(); i++)
    {
        cout << "-" << cont << " " << *i << "\n";
        cont++;
    }
}
int main()
{
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string risp = "";

    do
    {
        system("cls");
        //menuDinamico();
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