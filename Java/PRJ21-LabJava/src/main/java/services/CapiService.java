package services;

import java.util.Collection;

import entities.CapoAbbigliamento;
import repos.CapiDAO;

public class CapiService {
	
	private CapiDAO capiDao = new CapiDAO();
	
	public void addCapo(CapoAbbigliamento c) {
		capiDao.getCapiMap().put(c.getCodProdotto(), c);
	}
	
	public CapoAbbigliamento getCapo(int codProdotto) {
		return capiDao.getCapiMap().get(codProdotto);
	}
	
	public Collection<CapoAbbigliamento> getCapi(){
		return capiDao.getCapiMap().values();
	}
	
}
