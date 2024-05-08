package repos;

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
	
	//Queries
	private final String TABELLA = "sad_film";
	public final String FIND_ALL = "SELECT * FROM " + TABELLA;
	public final String INSERT = "INSERT INTO " + TABELLA +
								 "(titolo, anno, rating, regista)" +
								 "VALUES (?,?,?,?)";
	public final String REMOVE = "DELETE FROM " + TABELLA +
            " WHERE titolo = ? AND " +
            " anno = ? AND " +
            " rating = ? AND " +
            " regista = ?";
	
	public FilmDAO() {
		
	}
	
	public ArrayList<Film> getFilms() throws SQLException{
		ArrayList<Film> titoli = new ArrayList<>();
		istruzione = myConn.getConn().createStatement();
		risultati = istruzione.executeQuery(FIND_ALL);
		
		while(risultati.next()) {
			Film t = new Film();
			t.setId(risultati.getInt("id"));
			t.setTitolo(risultati.getString("titolo"));
			t.setAnno(risultati.getInt("anno"));
			t.setRating(risultati.getInt("rating"));
			t.setRegista(risultati.getString("regista"));
			titoli.add(t);
		}
		return titoli;
	}

	public void addFilm(Film f) throws SQLException {
		istruzionePrep = myConn.getConn().prepareStatement(INSERT);
		//Binding degli indirizzi
		istruzionePrep. setString(1, f.getTitolo());
		istruzionePrep. setInt(2, f.getAnno());
		istruzionePrep. setDouble(3, f.getRating());
		istruzionePrep. setString(4, f.getRegista());
		istruzionePrep.execute();
	}
	
	public void remFilm(Film f) throws SQLException {
		istruzionePrep = myConn.getConn().prepareStatement(REMOVE);
		//Binding degli indirizzi
		istruzionePrep. setString(1, f.getTitolo());
		istruzionePrep. setInt(2, f.getAnno());
		istruzionePrep. setDouble(3, f.getRating());
		istruzionePrep. setString(4, f.getRegista());
		istruzionePrep.execute();
	}
}
