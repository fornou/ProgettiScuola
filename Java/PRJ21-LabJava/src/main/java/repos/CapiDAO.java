package repos;

import java.util.Map;
import java.util.TreeMap;

import entities.CapoAbbigliamento;
import entities.Maglia;

public class CapiDAO {
	
	private Map<Integer, CapoAbbigliamento> capiMap = new TreeMap<>();
	
	//Blocco di inizializzazione parte prima del costruttore
	{
		System.out.println("Sono nel blocco di init");
		Maglia m1 = new Maglia();
		capiMap.put(m1.getCodProdotto(), m1);
	}

	public Map<Integer, CapoAbbigliamento> getCapiMap() {
		return capiMap;
	}
	
	
	
}
