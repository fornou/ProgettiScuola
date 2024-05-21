package db;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

import model.Categoria;

public class CategoriaDAOImpl implements CategoriaDAO { 
	
	private Connessione cn =  null;
	private Statement st;
	private PreparedStatement ps;
	private ResultSet rs;
	
	public CategoriaDAOImpl() {
		cn = new Connessione();
	}
	
	@Override
	public List<Categoria> getCategorie() {
		List<Categoria> categorie = new ArrayList<>(); 
		try {
			st = cn.getConn().createStatement();
			rs = st.executeQuery(FIND_ALL);
			
			while(rs.next()) {
				Categoria c = new Categoria();
				
				c.setId(rs.getInt("id"));
				c.setNome(rs.getString("nome"));
				
				categorie.add(c);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return categorie;
	}

	@Override
	public Categoria getCategoriaById(int id) {
		try {
			ps = cn.getConn().prepareStatement(FIND_ONE);
			ps.setInt(1, id);
			ps.execute();
			
			boolean next = rs.next();// mi dice se ha qualche elemento
			if(next) {
				Categoria c = new Categoria(); 
				c.setId(rs.getInt("id"));
				c.setNome(rs.getString("nome"));
				return c;
			}else {
				System.err.println("Errore, non c'è elemento con questo id!");
			}
			
			
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return null;
	}
}
