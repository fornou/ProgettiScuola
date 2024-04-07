#include <stdlib.h>
#include <iostream>
#include <map>
#include <string>
#include <istream>
#include <windows.h>
#include <cstdlib>
#include <thread> 
#include <chrono>
#include <locale>
#include <conio.h>
#include <vector>
#include <algorithm> 
#include <math.h>
#include <cmath>
#include <ctype.h>
#include <limits> 

using namespace std;
using namespace this_thread;
using namespace chrono;
 
void mediaTemp()
{
    float somma = 0, temp = 0, media = 0;
    int n = 0;
    string risp;
    bool esci = false;

    while(esci==false)
    {
        cout<<"Digita la temperatura\n";
        cin>>temp;
        somma+= temp;
        cout<<"Continuare...(si/no)\n";
        cin>>risp;

        if(risp =="no")
        {
            esci = true;
        }
        n++;
    }

    media=somma/n;
    cout<< "La media delle temperature: "<<media<<"";
}

void prodotto()
{
    int a = 0, b = 0;

    cout << "Digita due valori per farne il prodotto" << endl;
    cin >> a, b;

    int prod = a*b;

    cout << "il prodotto è " << prod;
}

void cambioValuta()
{
    map<string, double> valute{ 
                { "Euro_Dollaro", 1.09 },
                { "Dollaro_Euro", 0.92 },
                { "Euro_Lira", 1936.27 },
                { "Lira_Euro", 0.032 }
    };
    double valore = 0;
    int j, scelta = 0, pos = 0;
    string risp = "", valutaP = "";

    do{
        j = 0;

        for (map<string, double>::iterator i = valute.begin(); i != valute.end(); i++) 
        {
            j++;
            cout <<j << "- " << i->first << " -> " << i->second << endl;
        }

        cout << "Quale cambio di valuta vuoi effetuare:" << endl && cin >> scelta;

        j = 0;

        for (map<string, double>::iterator i = valute.begin(); i != valute.end(); i++) 
        {
            j++;
            if(j == scelta)
            {
                pos = i->first.find('_');
                valutaP =  i->first.substr(0, pos);
                cout << "Digita il valore in " <<  valutaP << " per conversione " << i->first << endl;
                cin >> valore;

                valore *= i->second;

                cout << "La conversione è avvenuta da " << i->first << " e vale " << valore << endl;
            }
            
        }
        if(scelta >= 5 || scelta <= 0)
        {
            cout << "Riprova, errore con scelta" <<endl;
        }

        cout <<"Continuare:\n - si\n - no" <<endl && cin >>risp && system("CLS");
    
    }while(risp=="si");

}

void guess()
{
    int iSecret, iGuess;
    srand (time(NULL));

    iSecret = rand() % 10 + 1;

    do {
        cout << "Guess the number (1 to 10): " << endl;
        cin >> iGuess;
        sleep_for(seconds{1});
        if (iSecret<iGuess) cout << "The secret number is lower" << endl;
        else if (iSecret>iGuess) cout << "The secret number is higher" <<endl;
        sleep_for(seconds{2});
    
        system("cls");
    } while (iSecret!=iGuess);

    cout << "Congratulations!" <<endl;
}
 
void stringhe(){
    wstring str = L"";

    int lunghezza = str.length();
    char lettera = str.at(0), car1, car2;

    car1 = getch();//inserisci senza vedere cosa digiti

    car2 = getchar();

    wcout << lunghezza <<" "<< lettera <<" "<< car1 <<" "<< car2;

}

void estrai4(){
    string risp;
    vector<int> g1;
    int valore = 0,  scelta = 0, cont, somma;

    do{
        cout << "Inserisci 4 valori: ";
        for(int i = 0; i < 4; i++){
            cin >> valore;
            g1.push_back(valore);
        }

        do {
            cout << "Continuare(si/no)" && cin >> risp;
            system("cls");
        }while(risp != "si" && risp != "no");
        system("cls");
    }while(risp == "si" || g1.size()%4 != 0);
        
    do{

        cout << "\nScelta: \n-1 modo somma 1 \n-2 modo somma 2\n-3 esci\n" && cin >> scelta;

        system("cls");

        cout << "Valori inseriti: ";
        for (auto i = g1.begin(); i != g1.end(); ++i){
            cout << *i << " ";
        }

        cout <<endl;
        
        switch(scelta)
        {
            case 1:
                cont = 0;
                somma = 0;
                for (auto i = g1.begin(); i != g1.end(); ++i)
                {
                    somma += *i;
                    cont++;

                    if(cont == 4)
                    {
                        cout << "Somma a 4 dei valori inseriti: " << somma << endl;
                        somma = 0;
                        cont = 0;
                    }   
                }
            break;

            case 2:
                for (int i = 0; i <= g1.size()-4; i++)
                {
                    somma = 0;
                    for(int j = 0; j <4; j++)
                    {
                        cout << g1.at(i+j) << " ";
                        somma += g1.at(i+j);
                    } 
                    cout << "| La somma quartina " << cont << ": " << somma << endl;
                    cont++;
                }
                                                     
            break;

            case 3:
            system("cls");
            break;

            default:
                cout << "Errore, ridigita!!!";
            break;
        }

    }while(scelta != 3);    
}

void ordina(){

    vector<int> g1;
    int j = 0, ran = 0;

    srand (time(NULL));

    for(j = 0; j<8; j++)
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

    cout <<endl;

    cout << "Valori inseriti in ordine crescente:\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }

    sort(g1.begin(), g1.end(), greater<int>());

    cout <<endl;

    cout << "Valori inseriti in ordine decrescente:\n";

    for (auto i = g1.begin(); i != g1.end(); ++i)
    {
        cout << *i << " ";
    }
}

void n3Ord(){
    int a = 0, b = 0, c = 0, temp = 0;

    cin >> a >> b >> c;

    if(a>b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(b>c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    cout << a <<" "<< b <<" "<< c;
}

void calc(){
    vector<string> g1 = {"+","-","/","*","^","RAD","%","EXIT"};
    int scelta, cont;
    int a = 0, b = 0;
    float  res = 0;

    cont = 1;

    cout <<"Scegli fra queste possibilità\n";

    for (auto i = g1.begin(); i != g1.end(); ++i){
        cout <<"-"<<cont<< " "<< *i << "\n";
        cont++;
    }

    cin >> scelta;

    cout <<"Digita a:";
    cin >> a;
    if(scelta != 6)
    {
        cout <<"Digita b:";
        cin >> b;
    }
    switch(scelta){

        case 1: 
            res = a+b;
        break;

        case 2: 
            res = a-b;
        break;

        case 3:
            res = a/b; 
        break;

        case 4: 
            res = a*b;
        break;

        case 5: 
            res = pow(a,b);
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

void equaz() {
    double a, b, c;
    double delta, x1, x2;

    cout << "Inserisci il coefficiente a: ";
    cin >> a;

    cout << "Inserisci il coefficiente b: ";
    cin >> b;

    cout << "Inserisci il coefficiente c: ";
    cin >> c;

    delta = b * b - 4 * a * c;

    if (delta > 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        cout << "Le soluzioni sono reali e distinte: x1 = " << x1 << ", x2 = " << x2 << endl;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "L'equazione ha una soluzione reale e coincidente: x = " << x1 << endl;
    } else {
        cout << "E' impossibile!! "<< endl;
    }

}

void menuDinamico(vector<string> g1){

    //si richiama così menuDinamico(sceltePossibili);
    //prende un vettore come parametro e ne crea un menù visivo
    //vector<string> sceltePossibili = {"A","B","C","D","E","F","G","H"};
    
    cout << "_______________________\n\n";                       
    cout << "         MENU'         \n";
    cout << "_______________________\n\n";
    cout << "Effettua la tua scelta:\n";
    int cont = 1, scelta = 0;

    
    for (auto i = g1.begin(); i != g1.end(); i++)
    {
        cout <<"-" <<cont << " " << *i << "\n";
        cont++;
    }  

}

void spazioFrenata()
{
    int scelta, v = 0;
    float f = 0;

        cout << "inserisci la velocità\n";
        cin >> v;

        cout << "Tipo di asfalto\n";

        vector<string> sceltePossibili = {"liscio","ruvido","bagnato","ghicciato","Esci"};
        menuDinamico(sceltePossibili);

        
        cin >> scelta;

        switch(scelta)
        {
            case 1:
                f = 0.6;
            break;

            case 2:
                f = 0.5;
            break;

            case 3:
                f = 0.4;
            break;

            case 4:
                f = 0.1;
            break;

            default:
                cout << "Riprova";
            break;

        }

        int spazio = pow(v,2) / (250*f);

        cout << "Ci metterai metri: " << spazio << endl;
}

void alfabeto(){
    char a = 'a';

    for(int i = 0; i <26; i++){
        cout << a++ << "\t";
        if(i == 12)
            cout << endl;
    }

    cout << "\n";
}

void minMaiusc(){

    int n = 97;
    char lettera;  //65 = A 97 = a

    cout << "dammi una lettera "<<endl;
    cin >> lettera;
    cout << "lettera appena inserita: " << int(lettera) << "<-->" << lettera <<endl;

    if(lettera >= 97)
    {
        n = lettera - 32;
    }
    else{
        n = lettera + 32;
    }

    cout <<"nuova lettera in int -->" << n <<endl;
    lettera = n;
    cout << "nuova lettera in char -->" << lettera <<endl;

}

void EsCiclo()
{
    int i = 0;
    float n = 0, s = 0;

    cout << "Inserisci n numeri e calcola la loro somma e media con 0\n";

    do{
        cin >> n;
        s += n;
        i++;
        
    }while(n != 0);

    cout << "La somma dei "<< i-- <<" numeri inseriti --> " << s <<endl;
    s /= i;
    cout << "La media dei "<< i <<" numeri inseriti --> " << s <<endl;
    
}

void EsCiclo2()
{
    int pari = 0, dispari = 0, n = 0;

    cout << "Inserisci n numeri e calcola quanti dispari e pari con 0\n";

    do{
        cin >> n;
        if(n%2==0)
        {
            pari++;
        }
        else{
            dispari++;
        }

        
    }while(n != 0);

    cout << "Numeri pari--> "<< pari-1 <<endl;
    cout << "Numeri dispari--> "<< dispari <<endl;
    
}

void sconto1(){

    double somma = 0, prezzo = 0, sconto = 0;
    string parola = "non scontato", parola1 = "perchè non supera i 125$";

    for(int i = 0; i< 15; i++)
    {
        cout << "digita in prezzo del prodotto " << i <<endl;
        cin >> prezzo;

        somma += prezzo;
    }

    if(somma >= 125)
    {
        sconto = somma*15/100;
        parola1 = "perchè supera i 125$\n";
        parola = "scontato";
    }

    cout << "Lo sconto è di "<< sconto << " su " <<somma << " " << parola1 <<endl;

    somma -= sconto;

    cout << "Il prezzo " << parola << " è di " << somma <<endl;
    
}

void sconto2(){

    double scontoTot = 0, prezzo = 0, sconto = 0, sommaPrezzi = 0;

    for(int i = 0; i< 15; i++)
    {
        cout << "digita in prezzo del prodotto " << i <<endl;
        cin >> prezzo;

        if(prezzo >= 125)
        {
            sconto = prezzo*15/100;
            cout << "Lo sconto su questo prodotto è di "<< sconto <<endl;
            scontoTot += sconto;
            cout << "Lo sconto totale parziale è di "<< scontoTot <<endl;
        }

        sommaPrezzi += prezzo;

        cout << "Lo somma totale parziale senza sconti effettuati è di "<< sommaPrezzi <<endl;
   
    }

    sommaPrezzi -= scontoTot;

    cout << "Lo sconto totale è di "<< scontoTot <<endl;

    cout << "Il prezzo totale è " << sommaPrezzi <<endl;
    
}

void doppio30(){
    int a = 0;

    for( int i = 0; i < 3; i++)
    {
        cin >> a; 
        cout << a*2 <<endl;
    }
}

void riconosciCifre(){
    char a;
    cin >> a;
    if(isdigit(a) != 0)
    {
        cout << "é un numero\n";
    }
    else{
        cout << "è un carattere\n";
    }
}

void vocaleCons(){
    char a;

    cin >> a;

    if(isdigit(a)!= 0)
    {
        cout << "è un numero \n";
    }
    else if(isdigit(a) == 0){
        if(a == 'a'  || a == 'e' || a == 'i' || a == 'o'|| a == 'u')
        {
            cout << "vocale\n";
        }
        else{
            cout << "consonante\n";
        }
    }
    else{
        cout << "riprova!!\n";
    }
    
}

void pitagoricTable(){
    int n =0;
    cout <<"Digita il numero per la sua tabellina" <<endl;
    cin >> n;

    for(int i = 1; i<=10; i++)
    {
        cout << n*i <<"\t";
    }
}

void fattoriale(){
    int n =0, m = 1;
    cin >> n;

    int dim = n;

    for(int i = 1; i<dim; i++)
    {
        n*=i;
        cout << n<<"\t";
    }
    cout << n <<"\n";
}

void magDiK(){
    int k =0, n = 0, cont = 0, risp;

    cout << "inserisci k -->\n";
    cin >> k;

    do{
        cout << "inserisci numero -->\n";
        cin >> n;
        if(n>k)
        {
            cont++;
        }
        cout << "1 per continuare\n";
        cin >> risp;

    }while(risp==1);

    cout << "numeri inseriti maggiori di"<< k << " -> " << cont <<"\n";
}

void ripetizione(){

    string parola = "salaminal";
    int cont = 0, ris = 0;

    for(int i = 0; i< parola.length(); i++){
        cont = 0;
        for(int j = 0; j < parola.length(); j++)
        {
            if(parola.at(i) == parola.at(j))
            {
                cont++;
            }
        }  
        if(cont == 1)
        {
            ris += 1;
        }
    }
}

void maxMin(){
    int n;

    std::cout << "Inserisci il numero di elementi: ";
    std::cin >> n;

    int temperaturaMax, temperaturaMin, escursione, mediaTempMax = 0, mediaTempMin = 0;
    string nome, cittaMax, cittaMin, cittaEsc;
    int maxEsc = numeric_limits<int>::min(); 
    int massimo = numeric_limits<int>::min(); 
    int minimo = numeric_limits<int>::max(); 

    for (int i = 0; i < n; ++i) {
        cout << "Inserisci temperatura max " << i + 1 << ": ";
        cin >> temperaturaMax;
        cout << "Inserisci temperatura min " << i + 1 << ": ";
        cin >> temperaturaMin;
        cout << "Inserisci nome " << i + 1 << ": ";
        cin >> nome;

        escursione = temperaturaMax - temperaturaMin;

        mediaTempMax += temperaturaMax;
        mediaTempMin += temperaturaMin;

        if (temperaturaMax > massimo) {
            massimo = temperaturaMax;
            cittaMax = nome;
        }

        if (temperaturaMin < minimo) {
            minimo = temperaturaMin;
            cittaMin = nome;
        }

        if (escursione > maxEsc) {
            maxEsc = escursione;
            cittaEsc = nome;
        }
    }

    mediaTempMin/= n;
    mediaTempMax/= n;

    cout << "\n\n________________________________________________________________________________________________\n";
    cout << "Citta più fredda:\n" << cittaMin <<"\tTemperatura: "<< minimo << endl;
    cout << "Citta più calda:\n" << cittaMax <<"\tTemperatura: "<< massimo << endl;
    cout << "Citta con maggiore escursione termica:\n " << cittaEsc << "\tescursione termica: " << maxEsc << endl;

    cout << "\nMedia delle temperature minime: " << mediaTempMin <<endl;
    cout << "\nMedia delle temperature massime: " << mediaTempMax <<endl;

}

void distributore(){
    int scelta = 0;
    double costo = 0, soldiInseriti = 0.1;
    boolean esci = false;
    vector<string> sceltePossibili = {"Acqua","Bibita in lattina","Bibita in bottiglietta", "Esci"};
    vector<double> tipoMon = {0.10, 0.20, 0.50, 1, 2};
    
    menuDinamico(sceltePossibili);
    cin >> scelta;

    switch(scelta)
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

    do{
        cout <<"Inserisci monete per "<< sceltePossibili[scelta-1] << " che costa ancora " << costo <<endl;
        
        do{
            if(find(tipoMon.begin(), tipoMon.end(), soldiInseriti) == tipoMon.end()){
                cout << "Monete accettate: 0.10, 0.20, 0.50, 1, 2\n";
            }
            cin >> soldiInseriti;
            
        }while(find(tipoMon.begin(), tipoMon.end(), soldiInseriti) == tipoMon.end());
        
        costo -=soldiInseriti; 

        if(costo < 0)
        {
            double resto = abs(costo);
            cout << "Hai inserito troppo, ecco il tuo resto di " << resto << " euro\n";
            esci = true;
        }else if(costo == 0){
            cout << "Ecco a te " << scelta <<endl;
            esci = true;
        }
        else{
            cout << "Ti mancano ancora " << costo << " euro da inserire\n";
        }

    }while(esci == false);
    


}

boolean contiene01(const char *str){
    int trov = 0;
    while (*str && trov == 0) {
        if (*str != '0' && *str != '1') {
            cout << str << endl;
            trov = 1;
            return true;  // Trovato un carattere non binario
        }
        str++;
    }
    return false; // Non trovato un carattere non binario
}

void binDec(){
    const char *numBin = "1210";

    if(isdigit(*numBin)== 0)
    {
        cout << "Non è un numero \n";
    }
    else if(contiene01(numBin) == true)
    {
        cout << "Deve essere composto solo da 1 e 0 essendo binario \n";
    }
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string risp = "";

    do{
        system("cls");
        binDec();
        do{
            cout << "Vuoi continuare(si/no):\n";
            cin >> risp;
            if(risp!="si" && risp != "no")
            {
                system("cls");
                cout << "Il sistema accetta solo si o no come input\n";
            }
        }while(risp != "si" && risp != "no");

    }while(risp == "si");

    system("cls");
}