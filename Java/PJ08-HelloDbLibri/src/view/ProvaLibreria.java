package view;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.sql.SQLException;

import controller.Libreria;
import model.Libro;

public class ProvaLibreria {
	public static void main(String[] args) throws FileNotFoundException {
		Libreria lib = new Libreria();
		
		try {
			lib.riempiLibreriaDaDb();
			
			PrintWriter pw = new PrintWriter(new File("files/libri.html"));
			pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"></head><body><h1>Ecco tutti i libri presenti nel db</h1>");
			pw.println("<table><tr><td>Id</td><td>Titolo</td><td>Autore</td><td>Editore</td><td>Classificazione</td><td>Anno</td></tr>");
			
			for (Libro l: lib.getLibri() ) {
				
				pw.println("<tr><td>" + l.getId() + "</td>");
				pw.println("<td>" + l.getTitolo() + "</td>");
				pw.println("<td>" + l.getAutore() + "</td>");
				pw.println("<td>" + l.getEditore() + "</td>");
				pw.println("<td>" + l.getClassificazione() + "</td>");
				pw.println("<td>" + l.getAnno() + "</td></tr>");
			}
			pw.println("</table></body><html>");
			pw.close();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//l.leggiLibri();
		
	}
}
