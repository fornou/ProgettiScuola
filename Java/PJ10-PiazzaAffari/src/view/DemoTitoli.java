package view;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.sql.SQLException;

import database.TitoloDAO;
import model.Titolo;

public class DemoTitoli {
	
	public static void main(String[] args) throws FileNotFoundException {
		TitoloDAO td = new TitoloDAO();
		
		try {
			
			PrintWriter pw = new PrintWriter(new File("files/titoliAzionari.html"));
			pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"></head><body><h1>Ecco tutti i titoli presenti nel db</h1>");
			pw.println("<table><tr><td>Id</td><td>Nome Titolo</td><td>Raccomandazione</td><td>Capitale</td></tr>");
			
			for (Titolo l: td.getTitoli() ) {
				pw.println("<tr><td>" + l.getId() + "</td>");
				pw.println("<td>" + l.getNomeTitolo() + "</td>");
				pw.println("<td>" + l.getRaccomandazione() + "</td>");
				pw.println("<td>" + l.getCapitaleMLN() + "</td></tr>");
				System.out.println(l);
			}
			pw.println("</table></body><html>");
			pw.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
