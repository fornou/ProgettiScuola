package entities;

public class Giacca extends CapoAbbigliamento {

	public Giacca() {
		super("pantalone");
	}

	@Override
	public int compareTo(CapoAbbigliamento o) {
		return Double.compare(this.getPrezzo(), o.getCodProdotto());
	}

}
