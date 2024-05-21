package repos;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

import model.Corso;
import model.Esame;
import model.Student;

public class EsameDAOImpl implements EsameDAO {

	private Connessione cn;
	private PreparedStatement ps;
	private ResultSet rs;
	
	private CorsoDAO daoCorsi = new CorsoDAOImpl();
	private StudentDAO daoStudenti = new StudentDAOImpl();
	
	public EsameDAOImpl(){
		cn = new Connessione();
	}
	
	@Override
	public List<Esame> getAll() {
		
		List<Esame> esami = new ArrayList<Esame>();
		
		try {
			ps = cn.getConn().prepareStatement(FIND_ALL);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				
				Esame e = new Esame();
			
				int matricola = rs.getInt("matricola");
				int vot = rs.getInt("voto");
				int codCorso = rs.getInt("codcorso");
				Date data = rs.getDate("data");
				
				Corso c = daoCorsi.findById(codCorso);
				Student s = daoStudenti.findById(matricola);
				LocalDate lc = data.toLocalDate();
				
				e.setCorso(c);
				e.setData(lc);
				e.setStudente(s);
				e.setVoto(vot);
				
				esami.add(e);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return esami;
	}

	@Override
	public void addEsame(Esame e) {
		try {
			ps = cn.getConn().prepareStatement(ADD_ESAME);
			
			ps.setInt(1, e.getStudente().getMatricola());
			ps.setInt(2, e.getCorso().getCodCorso());
			ps.setDate(3, Date.valueOf(e.getData()));
			ps.setInt(4, e.getVoto());
			
			ps.execute();
			
		} catch (SQLException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		

	}

}
