package entities;

public abstract class CapoAbbigliamento implements Comparable<CapoAbbigliamento> {
	
	private static int counter = 1;//proprietà della classe
	
	private int codProdotto;//proprietà di oggetto di tipo classe
	private String nome;
	private double prezzo;
	private Taglie taglia;
	
	public CapoAbbigliamento(String nome) {
		this.codProdotto = counter++;
		this.nome = nome;
	}
	
	public CapoAbbigliamento(String nome, double prezzo) {
		this(nome);//richiamo costruttore con un argomento
		this.prezzo = prezzo;
	}

	public CapoAbbigliamento(String nome, double prezzo, Taglie taglia) {
		this(nome, prezzo);//richiamo costruttore con due argomenti
		this.taglia = taglia;
	}

	public int getCodProdotto() {
		return codProdotto;
	}

	public void setCodProdotto(int codProdotto) {
		this.codProdotto = codProdotto;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getPrezzo() {
		return prezzo;
	}

	public void setPrezzo(double prezzo) {
		this.prezzo = prezzo;
	}

	public Taglie getTaglia() {
		return taglia;
	}

	public void setTaglia(Taglie taglia) {
		this.taglia = taglia;
	}

	@Override
	public String toString() {
		StringBuilder builder = new StringBuilder();
		builder.append("CapoAbbigliamento [codProdotto=");
		builder.append(codProdotto);
		builder.append(", nome=");
		builder.append(nome);
		builder.append(", prezzo=");
		builder.append(prezzo);
		builder.append("]");
		return builder.toString();
	}
	
	
	
	

	
	
	
	
}
