package poligoni;

import luoghi.*;

public class Triangolo extends Poligono{
	
	Punto a, b, c;
	Segmento ab, ac, bc;

	public Triangolo(Punto a, Punto b, Punto c) {
		super("Triangolo", 3, 3);
		//angoli
		this.a = a;
		this.b = b;
		this.c = c;
		//lati
		this.ab  = new Segmento(a, b);
		this.ac  = new Segmento(a, c);
		this.bc  = new Segmento(b, c);
		
		this.perimetro = perimetro();
		this.area = area();
	}
	
	@Override
	public double perimetro() {
		return ab.lunghezza()+ ac.lunghezza()+ bc.lunghezza();
	}
	
	@Override
	public double area() {
		double sp = (this.perimetro) / 2;
		return Math.sqrt(
				sp *
				(sp - ab.lunghezza()) *
				(sp - ac.lunghezza()) *
				(sp - bc.lunghezza())
				);
		 
	}

	

	
	
	
	
	
	
	
}
