package poligoni;

import luoghi.*;

public class Quadrato extends Rettangolo {
	
	public Quadrato(Segmento lato) {
		super(lato, lato);
		this.nome = "Quadrato";
		this.perimetro = perimetro();
		this.area = area();
	}
	
}
