#include "../Libreries/libArray.h"

void doppio()
{
    int a = 0;

    for (int i = 0; i < 3; i++)
    {
        cin >> a;
        cout << a * 2 << endl;
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