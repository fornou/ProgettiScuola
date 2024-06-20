#include "../Libreries/libArray.h"

void guess()
{
    int iSecret, iGuess;
    srand(time(NULL));

    iSecret = rand() % 10 + 1;

    do
    {
        cout << "Guess the number (1 to 10): " << endl;
        cin >> iGuess;
        sleep_for(seconds{1});
        if (iSecret < iGuess)
            cout << "The secret number is lower" << endl;
        else if (iSecret > iGuess)
            cout << "The secret number is higher" << endl;
        sleep_for(seconds{2});

        system("cls");
    } while (iSecret != iGuess);

    cout << "Congratulations!" << endl;
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