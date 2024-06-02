package db;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import model.Categoria;
import model.Piatto;

public class PiattoDAOImpl implements PiattoDAO { 
	
	private Connessione cn =  null;
	private Statement st;
	private PreparedStatement ps;
	private ResultSet rs;
	
	public PiattoDAOImpl(){
		cn = new Connessione();
	}
	
	@Override
	public List<Piatto> getPiatti() {
		List<Piatto> piatti = new ArrayList<>(); 
		try {
			st = cn.getConn().createStatement();
			rs = st.executeQuery(FIND_ALL);
			
			while(rs.next()) {
				Piatto p = new Piatto();
				Categoria c = new Categoria();
				
				p.setId(rs.getInt("id"));
				p.setNome(rs.getString("nome"));
				p.setPrezzo(rs.getDouble("prezzo"));
				c.setId(rs.getInt("tipo_piatto_id"));
				p.setCategoria(c);
				
				piatti.add(p);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return piatti;
	}

	@Override
	public void addPiatto(Piatto p) {
	
		try {
			ps = cn.getConn().prepareStatement(ADD);
			//binding
			ps.setString(1, p.getNome());//non cf'è bisogno di costruire l'oggetto
			ps.setDouble(2, p.getPrezzo());
			ps.setInt(3, p.getCategoria().getId());
			ps.execute();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	@Override
	public Piatto getPiattoById(int id) {
		try {
			ps = cn.getConn().prepareStatement(FIND_ONE);
			ps.setInt(1, id);
			ps.execute();
			
			boolean next = rs.next();// mi dice se ha qualche elemento
			if(next) {
				Piatto p = new Piatto(); 
				p.setId(rs.getInt("id"));
				p.setNome(rs.getString("nome"));
				p.setPrezzo(rs.getDouble("prezzo"));
				
				Categoria c = new Categoria();
				c.setId(rs.getInt("tipo_piatto_id"));
				p.setCategoria(c);
				
				return p;
				
			}else {
				System.err.println("Errore, non c'è elemento con questo id!");
			}
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
}
