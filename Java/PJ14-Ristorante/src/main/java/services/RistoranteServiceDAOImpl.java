package services;

import java.util.ArrayList;
import java.util.List;

import model.Categoria;
import db.CategoriaDAO;
import db.CategoriaDAOImpl;

import model.Piatto;
import db.PiattoDAO;
import db.PiattoDAOImpl;

public class RistoranteServiceDAOImpl implements RistoranteServiceDAO {
	
	private PiattoDAO daoPiatti = new PiattoDAOImpl();
	private CategoriaDAO daoCategorie = new CategoriaDAOImpl();

	@Override
	public List<Categoria> getCategorie() {
		return daoCategorie.getCategorie();
	}

	@Override
	public List<Piatto> getPiatti() {
		return daoPiatti.getPiatti();
	}

	@Override
	public Piatto getPiattoById(int id) {
		/*return daoPiatti.getPiatti()
				.stream()
				.filter(p -> p.getId() == id)
				.toList()
				.get(0);*/
		
		//Piatto p = null;
		
		for (Piatto p1 : daoPiatti.getPiatti()) {
			if(p1.getId()==id) {
				return p1;
			}
		}
		return null;
	}

	@Override
	public Categoria getCategoriaById(int id) {
		return daoCategorie.getCategoriaById(id);
	}

	@Override
	public List<Piatto> getPiattiByCategoria(Categoria c) {
		
		List<Piatto> piattiByCategoria = new ArrayList<>();
		
		for (Piatto p: daoPiatti.getPiatti()) {
			if(p.getCategoria().getId() == c.getId()) {
				piattiByCategoria.add(p);
			}
		}
		return piattiByCategoria;
		
		/*return dao.getPiatti()
				.stream()
				.filter(p -> p.getCategoria().getId() == c.getId())
				.toList;*/
	}
}
