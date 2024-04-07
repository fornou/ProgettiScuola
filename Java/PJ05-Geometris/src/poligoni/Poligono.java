package poligoni;

public abstract class Poligono {
	
	String nome;
	int numLati, numAngoli;
	double perimetro, area;
	
	public Poligono(String nome, int numLati, int numAngoli) {
		this.nome = nome;
		this.numLati = numLati;
		this.numAngoli = numAngoli;
	}
	
	public abstract double perimetro();
	
	public abstract double area();

	@Override
	public String toString() {
		return "Poligono "
				+ "[nome=" + nome + 
				", numLati=" + numLati +
				", numAngoli=" + numAngoli + 
				", perimetro=" + perimetro +
				", area=" + area +
				"]";
	}
		
	
	
	
	
}
