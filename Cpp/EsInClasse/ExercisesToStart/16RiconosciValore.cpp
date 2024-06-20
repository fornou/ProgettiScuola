#include "../Libreries/libArray.h"



void riconosciCifre()
{
    char a;
    cin >> a;
    if (isdigit(a) != 0)
    {
        cout << "é un numero\n";
    }
    else
    {
        cout << "è un carattere\n";
    }
}

void vocaleCons()
{
    char a;

    cin >> a;

    if (isdigit(a) != 0)
    {
        cout << "è un numero \n";
    }
    else if (isdigit(a) == 0)
    {
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            cout << "vocale\n";
        }
        else
        {
            cout << "consonante\n";
        }
    }
    else
    {
        cout << "riprova!!\n";
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