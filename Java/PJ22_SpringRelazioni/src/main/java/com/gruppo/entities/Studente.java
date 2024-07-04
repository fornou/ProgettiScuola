package com.gruppo.entities;

import jakarta.persistence.CascadeType;
import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.ManyToOne;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name="students")
public class Studente {
	
	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;
	
	private String nome;
	
	//uno a uno uno studente ha un solo libretto
	@OneToOne(mappedBy = "studente", cascade = CascadeType.ALL) // campo studente in classe Libretto
	private Libretto libretto;
	
	@ManyToOne
	@JoinColumn(name = "corso_id")//specifica chiave esterna 
	private Corso corso;
	
	public Long getId() {
		return id;
	}
	public void setId(Long id) {
		this.id = id;
	}
	public String getNome() {
		return nome;
	}
	public Corso getCorso() {
		return corso;
	}
	public void setCorso(Corso corso) {
		this.corso = corso;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public Libretto getLibretto() {
		return libretto;
	}
	public void setLibretto(Libretto libretto) {
		this.libretto = libretto;
	}
	
}
