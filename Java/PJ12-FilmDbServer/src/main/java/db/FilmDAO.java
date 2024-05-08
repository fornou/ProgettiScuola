package db;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import model.Film;

public class FilmDAO {
	private Connessione myConn = new Connessione();
	
	private Statement istruzione;
	private PreparedStatement istruzionePrep;
	private ResultSet risultati;
	

	private final String TABELLA = "filmanim";
	public final String FIND_ALL = "SELECT * FROM " + TABELLA;
	public final String FIND_BY_RACCOMANDAZIONE = "SELECT * FROM " + TABELLA + " WHERE raccomandazioni = ?";
	public final String ADD_TITOLO = "INSERT INTO " + TABELLA + " (titolo, capitalMLN) VALUES = (?, ?)";
	public final String FIND_ONE = "SELECT * FROM " + TABELLA + "WHERE ID = ";
	public final String UPDATE_TITOLO = "UPDATE " + TABELLA + "SET capitale = ? WHERE id = ?";
	
	public FilmDAO() {
		
	}
	private int id, anno;
	private String titolo;
	private double rating;
	
	public ArrayList<Film> getFilms() throws SQLException{
		ArrayList<Film> titoli = new ArrayList<>();
		istruzione = myConn.getConn().createStatement();
		risultati = istruzione.executeQuery(FIND_ALL);
		
		while(risultati.next()) {
			Film t = new Film();
			t.setId(risultati.getInt("id"));
			t.setTitolo(risultati.getString("Titolo"));
			t.setAnno(risultati.getInt("Anno"));
			t.setRating(risultati.getInt("Rating"));
			titoli.add(t);
		}
		return titoli;
	}
	
}
