
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import controller.Azienda;
import model.Dipendente;
import model.Dirigente;
import model.Fattorino;
import model.Impiegato;
import util.Lettore;

public class Main {

	public static void main(String[] arg) {
		
		
		
		//a1.addDipendente("Stefania", "Bordino", "Fattorino");
		//a1.addDipendente("Marco", "Stefanini", "Fattorino");
		//a1.addDipendente("Matteo", "Ludovaci", "Fattorino");
		
		//a1.addDipendente(new Impiegato("Davide", "Botta"));
		//a1.addDipendente(new Impiegato("Salvatore", "Marci"));
		//a1.addDipendente(new Impiegato("Paolo", "Tanetti"));
		
		//a1.addDipendente("Marco", "Colli", "Dirigente");
		//a1.addDipendente("Marco", "Pieraccioni", "Dirigente");
		
		//a1.addDipendente("Luigi", "Paolini", "Direttore");
		
		//a1.getDipendenteById(1).setStipendio(1550);
		//a1.getDipendenteById(2).setStipendio(2450);
			
		//ArrayList<Dipendente> dipendenti = a1.getDipendenti();
		
		//for(Dipendente dipendente : dipendenti) {
			//System.out.println(dipendente);
		//}
		
		//System.out.println("Fattorini");
		
		//ArrayList<Dipendente> fattorini = a1.getFattorini();
		
		//for(Dipendente fattorino : fattorini) {
			//System.out.println(fattorino);
		//}
		
		//System.out.println("Impiegati");
		
		//ArrayList<Dipendente> impiegati = a1.getImpiegati();
		
		//for(Dipendente impiegato : impiegati) {
			//System.out.println(impiegato);
		//}
		
		//System.out.println(a1.listaDipendenti());
		
		
		Azienda a1 = new Azienda("Luxottica");
		Lettore l = new Lettore();
		
		ArrayList<String> letturaFile = l.leggiFile("files/dip.csv");
		
		System.out.println(letturaFile);
		
		for(String riga : letturaFile) {
			String [] split = riga.split(",");
			String nome = split [0];
			String cognome = split [1];
			String ruolo= split [3];
			int numero = Integer.parseInt(split[2]);
			
			if ( ruolo.equals("i")){
				Impiegato i = new Impiegato(nome, cognome);
				i.setOreLavoro(numero);
				i.setPagaBase(10);
				a1.addDipendente(i);
			}else 
			if ( ruolo .equals("f")){
				Fattorino f = new Fattorino(nome, cognome);
				f.setNumeroConsegne(numero);
				f.setPagaBase(8);
				a1.addDipendente(f);
			}else
			if ( ruolo.equals("d")){
				Dirigente d = new Dirigente(nome, cognome);
				d.setPagaBase(3000);
				a1.addDipendente(d);
			}
			else
			if ( ruolo.equals("a")){
				Dirigente a = new Dirigente(nome, cognome);
				a.setPagaBase(4000);
				a1.addDipendente(a);
			}
			
		}
		
		a1.calcolaStipendi();
		System.out.println(a1.listaDipendenti());
		
		File f = new File("files/cedolino_marzo.html");
		
		try {
			PrintWriter out = new PrintWriter(f);
			out.write(a1.listaDipendenti());
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
	}//end main

}//end Class
