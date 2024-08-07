package com.forneron.entities;

import com.fasterxml.jackson.annotation.JsonIgnore;

import jakarta.persistence.Entity;
import jakarta.persistence.GeneratedValue;
import jakarta.persistence.GenerationType;
import jakarta.persistence.Id;
import jakarta.persistence.JoinColumn;
import jakarta.persistence.OneToOne;
import jakarta.persistence.Table;

@Entity
@Table(name="students_book")
public class LibrettoUniversitario {
	@Id
	@GeneratedValue(strategy= GenerationType.IDENTITY)
	private Long id;
	
	private String numeroMatricola;
	
	@OneToOne
	@JoinColumn(name = "studente_id")
	@JsonIgnore // se no creerebbe un loop che richiama se stesso
	private Studente studente;

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getNumeroMatricola() {
		return numeroMatricola;
	}

	public void setNumeroMatricola(String numeroMatricola) {
		this.numeroMatricola = numeroMatricola;
	}

	public Studente getStudente() {
		return studente;
	}

	public void setStudente(Studente studente) {
		this.studente = studente;
	}
	
	
}
