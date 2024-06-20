#include "../Libreries/libArray.h"

void prodotto()
{
    int a = 0, b = 0;

    cout << "Digita due valori per farne il prodotto" << endl;
    cin >> a, b;

    int prod = a * b;

    cout << "il prodotto è " << prod;
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