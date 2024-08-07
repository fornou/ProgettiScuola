package interfaccia;

import java.io.FileNotFoundException;
import java.util.ArrayList;

import elaborazioni.*;

public class LetturaDemo {
	
	public static void main(String[] args) {
		
		try {
			ArrayList<String> risp = LeggiFile.leggi("files/studenti.csv", true);
			//System.out.println(risp);
			String query = "";
			query += "<h1>Elenco</h1>\n<ul>\n";
			for (String riga : risp) {
				//System.out.println(riga);
				String[] parole = riga.split(",");
				String nome = parole[0];
				String cognome = parole[1];
				nome = nome.substring(0, 1).toUpperCase() + nome.substring(1);
				cognome = cognome.substring(0, 1).toUpperCase() + cognome.substring(1);
				//query += "INSERT INTO studenti(nome, cognome) VALUES ('"+nome+"','"+cognome +"');";
				query += "<li>"+nome + " "+ cognome +"</li>\n";
			}
			query += "</ul>\n";
			LeggiFile.scrivi("files/html.html", query);
			//LeggiFile.scrivi("files/query.sql", query);
			
		}catch(FileNotFoundException e){
			System.err.println("errore nella lettura del file");
			System.err.println(e.getMessage());
		}
	}
}
