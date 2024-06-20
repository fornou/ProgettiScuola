#include "../Libreries/libArray.h"
void stringhe()
{
    wstring str = L"";

    int lunghezza = str.length();
    char lettera = str.at(0), car1, car2;

    car1 = getch(); // inserisci senza vedere cosa digiti

    car2 = getchar();

    wcout << lunghezza << " " << lettera << " " << car1 << " " << car2;
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