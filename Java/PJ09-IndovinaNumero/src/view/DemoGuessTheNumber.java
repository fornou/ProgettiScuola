package view;

import java.util.Scanner;

import model.GuessTheNumber;

public class DemoGuessTheNumber {
	public static void main(String[] args) {
		
		//Dichiarazione Oggetti e variabili
		Scanner t = new Scanner(System.in);// istanza e inizializzazione della classe Scanner
		GuessTheNumber sn;// istanza della classe GuessTheNumber
		int numRic;
		String risp = "";
		
		
		System.out.println("Benvenuto a Indovina il Numero!");
		do {
			//input per il massimo e il minimo
			System.out.println("Inserisci il limite minore per il range dei numeri");
			int min = t.nextInt();
			System.out.println("Inserisci il limite superiore per il range dei numeri");
			int max = t.nextInt();
			
			//inizializzazione classe con parametri corrisposndeti alle variabili 
			sn = new GuessTheNumber(min, max);
			
			while(!sn.getWin()) {//ciclo che scorre fino a che l'attributo win non viene settato a true
				sn.incrementaTentativo();
				//input del numero da indovinare
				System.out.print("Tentativo " + sn.getTentativo() + ":");
				numRic = t.nextInt();
				//stampa istruzioni per utente in base al valore inserito in precedenza
				if(numRic == sn.getRandomNum()) {
					System.out.println("Complimenti! Hai indovinato il numero segreto " + sn.getRandomNum() + " in " + sn.getTentativo() + " tentativi!");
					System.out.println("Vuoi giocare ancora? (Sì/No):");
					risp = t.next();
					sn.setWin(true);//settaggio attributo win in caso di aver indovinato il numero
				}else if(numRic < sn.getRandomNum()) {
					System.out.println("Il mio numero è più grande!");
				}else if(numRic > sn.getRandomNum()){
					System.out.println("Il mio numero è più piccolo!");
				}
			}
			
		}while(risp.equalsIgnoreCase("si"));//scorre in base al valore della variabile risposta
		
		System.out.println("Grazie per aver giocato!");
		
	}
}
