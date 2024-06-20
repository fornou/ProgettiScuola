#include "../Libreries/libArray.h"


void minMaiusc()
{

    int n = 97;
    char lettera; // 65 = A 97 = a

    cout << "dammi una lettera " << endl;
    cin >> lettera;
    cout << "lettera appena inserita: " << int(lettera) << "<-->" << lettera << endl;

    if (lettera >= 97)
    {
        n = lettera - 32;
    }
    else
    {
        n = lettera + 32;
    }

    cout << "nuova lettera in int -->" << n << endl;
    lettera = n;
    cout << "nuova lettera in char -->" << lettera << endl;
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