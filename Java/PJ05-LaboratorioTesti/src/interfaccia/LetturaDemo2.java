package interfaccia;

import java.io.FileNotFoundException;
import java.util.ArrayList;

import elaborazioni.*;

public class LetturaDemo2 {
	
	public static void main(String[] args) {
		
		try {
			ArrayList<String> risp = LeggiFile.leggi("files/studenti.csv", true);
			String query = "";
			for (String riga : risp) {
				String[] parole = riga.split(",");
				String cognome = parole[0];
				String nome = parole[1];
				String genere = parole[2];
				nome = nome.substring(0, 1).toUpperCase() + nome.substring(1);
				cognome = cognome.substring(0, 1).toUpperCase() + cognome.substring(1);
				query += "INSERT INTO studenti(cognome, nome, genere) VALUES ('"+nome+"', '"+cognome+"', '"+genere+"');\n";
			}
			LeggiFile.scrivi("files/query.txt", query);
			
		}catch(FileNotFoundException e){
			System.err.println("errore nella lettura del file");
			System.err.println(e.getMessage());
		}
	}
}
