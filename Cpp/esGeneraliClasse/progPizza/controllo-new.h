using namespace std;
bool controlloinput(){
	bool r=true;
	if(cin.fail()){ //caso di input che è completamente errato
	//	cout <<"Errore! inserimento errato!!\n";
		cin.clear(); //resetta lo stato del cin
		cin.ignore(1000,'\n'); 
		r=false;		
	}else{ //caso di input parziale errato
		cin.ignore(1000,'\n');
		if(cin.gcount()>1){
		//	cout <<"Errore! inserimento errato!!\n";
			r=false;
		}
	}
	return r;
}

double input_numero(){
	bool t=true;
	double b;
	do{
		cout <<"inserisci un numero: ";
		cin >>b;
		if(controlloinput()==false){
			cout <<"Hai inserito una lettera!! Inserisci un numero!!\n";
			t=false;
		}else{
			t=true;
		}
	}while(t==false);
	return b;
}


double input_range(string st,int m1,int m2 ){
	bool t;
	double b;
	do{
		t=true;		
		cout <<st; /*" "<<m1 << " e "<<m2<<" : ";*/
		cin >>b;

		if(controlloinput()==false){
			cout <<"Hai inserito una lettera!! Inserisci un numero!!\n";
			t=false;
		}else if(b<m1 || b>m2 ){
			cout <<"errore! input fuori dal range\n";
		}
	}while(t==false ||  b<m1 || b>m2);
	return b;
}
//ordinamento di un array 
void ord_insertion(int arr[],int dim){
	for (int i = 0; i<dim-1; i++) {
		for (int j=i+1; j<dim ; j++) {
			if (arr[i]>arr[j]) {
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	return;
}

