#include "../Libreries/libArray.h"

void ordina()
{

    vector<int> g1;
    int j = 0, ran = 0;

    srand(time(NULL));

    for (j = 0; j < 8; j++)
    {
        ran = rand() % 9 + 1;
        g1.push_back(ran);
    }

    cout << "Valori inseriti in disordine:\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }

    sort(g1.begin(), g1.end());

    cout << endl;

    cout << "Valori inseriti in ordine crescente:\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }

    sort(g1.begin(), g1.end(), greater<int>());

    cout << endl;

    cout << "Valori inseriti in ordine decrescente:\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }
}

void n3Ord()
{
    int a = 0, b = 0, c = 0, temp = 0;

    cin >> a >> b >> c;

    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    cout << a << " " << b << " " << c;
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