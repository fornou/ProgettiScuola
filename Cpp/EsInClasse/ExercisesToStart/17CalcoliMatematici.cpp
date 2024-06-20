#include "../Libreries/libArray.h"

void pitagoricTable()
{
    int n = 0;
    cout << "Digita il numero per la sua tabellina" << endl;
    cin >> n;

    for (int i = 1; i <= 10; i++)
    {
        cout << n * i << "\t";
    }
}

void fattoriale()
{
    int n = 0, m = 1;
    cin >> n;

    int dim = n;

    for (int i = 1; i < dim; i++)
    {
        n *= i;
        cout << n << "\t";
    }
    cout << n << "\n";
}

void magDiK()
{
    int k = 0, n = 0, cont = 0, risp;

    cout << "inserisci k -->\n";
    cin >> k;

    do
    {
        cout << "inserisci numero -->\n";
        cin >> n;
        if (n > k)
        {
            cont++;
        }
        cout << "1 per continuare\n";
        cin >> risp;

    } while (risp == 1);

    cout << "numeri inseriti maggiori di" << k << " -> " << cont << "\n";
}