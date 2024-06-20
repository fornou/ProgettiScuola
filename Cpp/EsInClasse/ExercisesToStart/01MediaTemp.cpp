#include "../Libreries/libArray.h"
void mediaTemp()
{
    float somma = 0, temp = 0, media = 0;
    int n = 0;
    string risp;
    bool esci = false;

    while (esci == false)
    {
        cout << "Digita la temperatura\n";
        cin >> temp;
        somma += temp;
        cout << "Continuare...(si/no)\n";
        cin >> risp;

        if (risp == "no")
        {
            esci = true;
        }
        n++;
    }
    media = somma / n;
    cout << "La media delle temperature: " << media << "";
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string risp = "";

    do
    {
        system("cls");
        mediaTemp();
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