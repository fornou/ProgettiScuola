package its;
//classe
public class Impiegato {
	//attributi
    private String id, nome, cognome;
    private int annoNascita, stipendio;

    //costruttore
    public Impiegato(String nome, String cognome, int annoNascita) {
		this.nome = nome;
		this.cognome = cognome;
		this.annoNascita = annoNascita;
        String id = Segreteria.creaId(nome, cognome, annoNascita);
        setId(id);
	}
    //metodi getters & setters
	public String getId() {
		return id;
	}
	private void setId(String id) {
		this.id = id;
	}
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getCognome() {
		return cognome;
	}
	public void setCognome(String cognome) {
		this.cognome = cognome;
	}
	public int getAnnoNascita() {
		return annoNascita;
	}
	public void setAnnoNascita(int annoNascita) {
		this.annoNascita = annoNascita;
	}
	public int getStipendio() {
		return stipendio;
	}
	public void setStipendio(int stipendio) {
		this.stipendio = stipendio;
	}
	
	public String toString() {
		return "Impiegato [id=" + id + ", nome=" + nome + ", cognome=" + cognome + ", annoNascita=" + annoNascita
				+ ", stipendio=" + stipendio + "]";
	}
    
	
}
