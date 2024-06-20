#include "../Libreries/libArray.h"
void calc()
{
    vector<string> g1 = {"+", "-", "/", "*", "^", "RAD", "%", "EXIT"};
    int scelta, cont;
    int a = 0, b = 0;
    float res = 0;

    cont = 1;

    cout << "Scegli fra queste possibilità\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << "-" << cont << " " << *i << "\n";
        cont++;
    }

    cin >> scelta;

    cout << "Digita a:";
    cin >> a;
    if (scelta != 6)
    {
        cout << "Digita b:";
        cin >> b;
    }
    switch (scelta)
    {

    case 1:
        res = a + b;
        break;

    case 2:
        res = a - b;
        break;

    case 3:
        res = a / b;
        break;

    case 4:
        res = a * b;
        break;

    case 5:
        res = pow(a, b);
        break;

    case 6:
        res = sqrt(a);
        break;

    case 7:
        res = a % b;
        break;

    case 8:
        break;

    default:
        cout << "ridigita";
    }
    cout << "il result --> " << res;
}

void equaz()
{
    double a, b, c;
    double delta, x1, x2;

    cout << "Inserisci il coefficiente a: ";
    cin >> a;

    cout << "Inserisci il coefficiente b: ";
    cin >> b;

    cout << "Inserisci il coefficiente c: ";
    cin >> c;

    delta = b * b - 4 * a * c;

    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "Le soluzioni sono reali e distinte: x1 = " << x1 << ", x2 = " << x2 << endl;
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        cout << "L'equazione ha una soluzione reale e coincidente: x = " << x1 << endl;
    }
    else
    {
        cout << "E' impossibile!! " << endl;
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