package database;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

import model.Titolo;

public class TitoloDAO {
	private final String TABELLA = "fintech_piazzaaffari";
	public final String FIND_ALL = "SELECT * FROM " + TABELLA;
	public final String FIND_BY_RACCOMANDAZIONE = "SELECT * FROM " + TABELLA + " WHERE raccomandazioni = ?";
	public final String ADD_TITOLO = "INSERT INTO " + TABELLA + " (titolo, capitalMLN) VALUES = (?, ?)";
	public final String FIND_ONE = "SELECT * FROM " + TABELLA + "WHERE ID = ";
	public final String UPDATE_TITOLO = "UPDATE " + TABELLA + "SET capitale = ? WHERE id = ?";
	
	private Connessione myConn = new Connessione();
	
	PreparedStatement istruzione;
	ResultSet risultati;
	
	public TitoloDAO() {
		
	}
	
	public ArrayList<Titolo> getTitoli(String raccomandazione) throws SQLException{
		ArrayList<Titolo> titoli = new ArrayList<>();
		istruzione = myConn.getConn().prepareStatement(FIND_BY_RACCOMANDAZIONE);
		istruzione.setString(1, raccomandazione);
		risultati = istruzione.executeQuery();
		
		while(risultati.next()) {
			Titolo t = new Titolo();
			t.setId(risultati.getInt("id"));
			t.setNomeTitolo(risultati.getString("Titolo"));
			t.setRaccomandazione(risultati.getString("Raccomandazioni"));
			t.setCapitaleMLN(risultati.getInt("CapitalMLN"));
			titoli.add(t);
		}
		return titoli;
	}
	
	public ArrayList<Titolo> getTitoli() throws SQLException{
		ArrayList<Titolo> titoli = new ArrayList<>();
		istruzione = myConn.getConn().prepareStatement(FIND_ALL);
		risultati = istruzione.executeQuery();
		
		while(risultati.next()) {
			Titolo t = new Titolo();
			t.setId(risultati.getInt("id"));
			t.setNomeTitolo(risultati.getString("Titolo"));
			t.setRaccomandazione(risultati.getString("Raccomandazioni"));
			t.setCapitaleMLN(risultati.getInt("CapitalMLN"));
			titoli.add(t);
		}
		return titoli;
	}
	
	public void modificaTitoli(int idTitolo, int capitale) throws SQLException{
		istruzione = myConn.getConn().prepareStatement(UPDATE_TITOLO);
		istruzione.setInt(1, capitale);
		istruzione.setInt(2, idTitolo);
		istruzione.executeQuery();
	}
	
}
