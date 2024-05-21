package repos;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import model.Corso;
import model.Student;

public class CorsoDAOImpl implements CorsoDAO{
	
	private Connessione cn;
	private PreparedStatement ps;
	private ResultSet rs;
	
	public CorsoDAOImpl() {
		cn = new Connessione();
	}
	
	@Override
	public List<Corso> findAll() {
		
		List<Corso> corsi = new ArrayList<Corso>();
		
		try {
			ps = cn.getConn().prepareStatement(FIND_ALL);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				
				String nome = rs.getString("nomecorso");
				
				Corso s = new Corso();
				s.setNome(nome);
				corsi.add(s);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return corsi;
	}

	@Override
	public Corso findById(int id) {

		Corso c = new Corso();
		
		try {
			ps = cn.getConn().prepareStatement(FIND_BY_ID);
			//Binding degli indirizzi
			ps.setInt(1,id);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				c.setCodCorso(id);
				c.setNome(rs.getString("nomecorso"));
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return c;
		
	}
	
}
