package view;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.sql.SQLException;

import db.FilmDAO;
import model.Film;

public class DemoFilms {
	
	public static void main(String[] args) throws FileNotFoundException {
		FilmDAO td = new FilmDAO();
		
		try {
			
			PrintWriter pw = new PrintWriter(new File("files/titoliFilm.html"));
			pw.println("<html><head><link rel=\"stylesheet\" href=\"style.css\"></head><body><h1>Ecco tutti i titoli presenti nel db</h1>");
			pw.println("<table><tr><td>Id</td><td>Titolo</td><td>Anno</td><td>Rating</td></tr>");
			
			for (Film l: td.getFilms() ) {
				pw.println("<tr><td>" + l.getId() + "</td>");
				pw.println("<td>" + l.getTitolo() + "</td>");
				pw.println("<td>" + l.getAnno() + "</td>");
				pw.println("<td>" + l.getRating() + "</td></tr>");
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
