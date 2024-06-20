#include "../libreries/libreria.h"

bool isBisestile(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValid(int gg,int mm,int aaaa){

    if (gg < 1 || mm < 1 || mm > 12 || aaaa < 0 || aaaa > 3000) {
        return false; 
    }
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && gg > 30) {
        return false;  
    } else if (mm == 2) {
        
        if (gg > 29 || (gg > 28 && !isBisestile(aaaa))) {
            return false;
        }
    } else if (gg > 31) {
        return false;  
    }

    return true; 
}

int giorniInMese(int month, int year){
    if (month == 2) {
        return isBisestile(year) ? 29 : 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

int calcolagiorni_1990(int gg,int mm,int aaaa){
    int giorniTotali = 0;

    for (int year = 1900; year < aaaa; ++year) {
        giorniTotali += isBisestile(year) ? 366 : 365;
    }

    for (int month = 1; month < mm; ++month) {
        giorniTotali += giorniInMese(month, aaaa);
    }

    giorniTotali += gg - 1;

    return giorniTotali;

}

int calcolagiorni(int gg1,int mm1,int aaaa1, int gg2, int mm2, int aaaa2){
    int giorniTotali = 0;

    for (int year = aaaa1; year < aaaa2; ++year) {
        giorniTotali += (isBisestile(year) ? 366 : 365);
    }

    for (int month = 1; month < mm1; ++month) {
        giorniTotali -= giorniInMese(month, aaaa1);
    }

    for (int month = 1; month < mm2; ++month) {
        giorniTotali += giorniInMese(month, aaaa2);
    }

    giorniTotali = giorniTotali + gg2 -gg1;

    return giorniTotali;

}

void inserisciData(){
    int giorno, mese, anno;

    do{
        cout << "DATA:\n";
        cout << "digita giorno mese e anno in questo formato --> gg mm aaaa\n";
        cin >> giorno >> mese >> anno;
        cout << "DATA: " << giorno << "/" << mese << "/" << anno << endl;
        if(isValid(giorno, mese, anno)!= true)
        {
            system("cls");
            cout << "Ridigita data per problema nel formato!!\n";
        }

    }while(isValid(giorno, mese, anno)!= true);
    

    int result = calcolagiorni_1990(giorno, mese, anno);

    cout << "I giorni passati dal 01/01/1900 sono " << result <<endl;

}

void inserisciDate(){
    int giorno1, giorno2, mese1, mese2, anno1, anno2;
    do{

        do{
        cout << "PRIMA DATA:\n";
        cout << "digita giorno mese e anno in questo formato --> gg mm aaaa\n";
        cin >> giorno1 >> mese1 >> anno1;
        if(isValid(giorno1, mese1, anno1)!= true)
        {
            system("cls");
            cout << "PRIMA DATA errata: " << giorno1 << "/" << mese1 << "/" << anno1 << endl;
            cout << "Ridigita data per problema nel formato!!\n";
        }

        }while(isValid(giorno1, mese1, anno1)!= true);

        do{
            cout << "SECONDA DATA:\n";
            cout << "digita giorno mese e anno in questo formato --> gg mm aaaa\n";
            cin >> giorno2 >> mese2 >> anno2;

            if(isValid(giorno2, mese2, anno2)!= true)
            {
                system("cls");
                cout << "SECONDA DATA errata: " << giorno2 << "/" << mese2 << "/" << anno2 << endl;
                cout << "Ridigita data per problema nel formato!!\n";
            }

        }while(isValid(giorno2, mese2, anno2)!= true);

        if (anno1 > anno2 || (anno1 == anno2 && (mese1 > mese2 || (mese1 == mese2 && giorno1 > giorno2)))) {
            system("cls");
            cout << "La prima data è maggiore della seconda." << endl;
        } else if(anno1 == anno2 && mese1 == mese2 && giorno1 == giorno2){
            system("cls");
            cout << "Le date sono uguali." << endl;
        }

    }while((anno1 > anno2 || (anno1 == anno2 && (mese1 > mese2 || (mese1 == mese2 && giorno1 > giorno2))))||((anno1 == anno2 && mese1 == mese2 && giorno1 == giorno2)));
    

    cout << "PRIMA DATA: " << giorno1 << "/" << mese1 << "/" << anno1 << endl;
    cout << "SECONDA DATA: " << giorno2 << "/" << mese2 << "/" << anno2 << endl;

    int result = calcolagiorni(giorno1, mese1, anno1, giorno2, mese2, anno2);

    cout << "I giorni passati sono " << result <<endl;
}

void siNo(){
    system("cls");
    setlocale(LC_ALL, "it_IT.UTF-8");

    string risp = "";

    do{
        system("cls");
        inserisciDate();
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

int main()
{
    siNo();
}
