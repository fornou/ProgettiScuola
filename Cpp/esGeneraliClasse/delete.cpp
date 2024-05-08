#include "libArray.h"

bool ric(string p){
    bool trov = false;
    string ric = "";
    ric = in_parola_spazi("Parola da ricercare:", ric);
    cls();
    cout << "Parola con nome " << ric << ":"<< endl;
        if (p == ric){
            cout << p << endl;
            trov = true;  
    }
    return trov;
}

main(){
    if(!ric("Mare")){
        cout << "No\n";
    }
}