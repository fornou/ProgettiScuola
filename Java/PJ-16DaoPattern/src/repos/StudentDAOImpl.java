package repos;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import model.Student;

public class StudentDAOImpl implements StudentDAO{
	
	private Connessione cn;
	private PreparedStatement ps;
	private ResultSet rs;
	
	public StudentDAOImpl() {
		cn = new Connessione();
	}
	
	@Override
	public List<Student> findAll() {
		
		List<Student> studenti = new ArrayList<Student>();
		
		try {
			ps = cn.getConn().prepareStatement(FIND_ALL);
			rs = ps.executeQuery();
			
			while(rs.next()) {
				
				int matricola = rs.getInt("matricola");
				String nome = rs.getString("nome");
				String cognome = rs.getString("cognome");
				
				Student s = new Student();
				s.setCognome(cognome);
				s.setMatricola(matricola);
				s.setNome(nome);
				studenti.add(s);
			}
		} catch (SQLException e) {
			e.printStackTrace();
		}
		
		return studenti;
	}
	
	public Student findById(int id) {

		List<Student> all = findAll();
		Student s = new Student();
		
		for(Student t : all) {
			if(t.getMatricola() == id) {
				s.setCognome(t.getCognome());
				s.setMatricola(t.getMatricola());
				s.setNome(t.getNome());
				
			}
		}
		return s;

	}
}
