#include "../Libreries/libArray.h"

void ripetizione()
{
    string parola = "aaaaa";
    int cont = 0, ris = 0;

    for (int i = 0; i < parola.length(); i++)
    {
        cont = 1;
        for (int j = 0; j < parola.length(); j++)
        {
            if (parola.at(i) == parola.at(j))
            {
                cont++;
            }
        }
        if (cont == 1)
        {
            ris += 1;
        }
    }
    cout << ris << " lettere che non si ripetono\n";
}

void maxMin()
{
    int n;

    cout << "Inserisci il numero di elementi: ";
    cin >> n;

    int temperaturaMax, temperaturaMin, escursione, mediaTempMax = 0, mediaTempMin = 0;
    string nome, cittaMax, cittaMin, cittaEsc;
    int maxEsc = numeric_limits<int>::min();
    int massimo = numeric_limits<int>::min();
    int minimo = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i)
    {
        cout << "Inserisci temperatura max " << i + 1 << ": ";
        cin >> temperaturaMax;
        cout << "Inserisci temperatura min " << i + 1 << ": ";
        cin >> temperaturaMin;
        cout << "Inserisci nome " << i + 1 << ": ";
        cin >> nome;

        escursione = temperaturaMax - temperaturaMin;

        mediaTempMax += temperaturaMax;
        mediaTempMin += temperaturaMin;

        if (temperaturaMax > massimo)
        {
            massimo = temperaturaMax;
            cittaMax = nome;
        }

        if (temperaturaMin < minimo)
        {
            minimo = temperaturaMin;
            cittaMin = nome;
        }

        if (escursione > maxEsc)
        {
            maxEsc = escursione;
            cittaEsc = nome;
        }
    }

    mediaTempMin /= n;
    mediaTempMax /= n;

    cout << "\n\n________________________________________________________________________________________________\n";
    cout << "Citta più fredda:\n"
         << cittaMin << "\tTemperatura: " << minimo << endl;
    cout << "Citta più calda:\n"
         << cittaMax << "\tTemperatura: " << massimo << endl;
    cout << "Citta con maggiore escursione termica:\n " << cittaEsc << "\tescursione termica: " << maxEsc << endl;

    cout << "\nMedia delle temperature minime: " << mediaTempMin << endl;
    cout << "\nMedia delle temperature massime: " << mediaTempMax << endl;
}

void distributore()
{
    int scelta = 0;
    double costo = 0, soldiInseriti = 0.1;
    boolean esci = false;
    vector<string> sceltePossibili = {"Acqua", "Bibita in lattina", "Bibita in bottiglietta", "Esci"};
    vector<double> tipoMon = {0.10, 0.20, 0.50, 1, 2};

    menuDinamico(sceltePossibili);
    cin >> scelta;

    switch (scelta)
    {
    case 1:
        costo = 0.50;
        break;

    case 2:
        costo = 0.80;
        break;

    case 3:
        costo = 1;
        break;

    case 4:

        break;

    default:
        cout << "Riprova numero digitato inesistente";
        break;
    }

    do
    {
        cout << "Inserisci monete per " << sceltePossibili[scelta - 1] << " che costa ancora " << costo << endl;

        do
        {
            if (find(tipoMon.begin(), tipoMon.end(), soldiInseriti) == tipoMon.end())
            {
                cout << "Monete accettate: 0.10, 0.20, 0.50, 1, 2\n";
            }
            cin >> soldiInseriti;

        } while (find(tipoMon.begin(), tipoMon.end(), soldiInseriti) == tipoMon.end());

        costo -= soldiInseriti;

        if (costo < 0)
        {
            double resto = abs(costo);
            cout << "Hai inserito troppo, ecco il tuo resto di " << resto << " euro\n";
            esci = true;
        }
        else if (costo == 0)
        {
            cout << "Ecco a te " << scelta << endl;
            esci = true;
        }
        else
        {
            cout << "Ti mancano ancora " << costo << " euro da inserire\n";
        }

    } while (esci == false);
}

boolean contiene01(const char *str)
{
    int trov = 0;
    while (*str && trov == 0)
    {
        if (*str != '0' && *str != '1')
        {
            cout << str << endl;
            trov = 1;
            return true; // Trovato un carattere non binario
        }
        str++;
    }
    return false; // Non trovato un carattere non binario
}

void binDec()
{
    const char *numBin = "1210";

    if (isdigit(*numBin) == 0)
    {
        cout << "Non è un numero \n";
    }
    else if (contiene01(numBin) == true)
    {
        cout << "Deve essere composto solo da 1 e 0 essendo binario \n";
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
        ripetizione();
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