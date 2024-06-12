package com.forneron.services;

import java.util.List;

import com.forneron.entities.LibrettoUniversitario;
import com.forneron.entities.Pokemon;
import com.forneron.entities.Studente;

public interface ITSService {
	List<Studente> getStudenti();
	Studente getStudenteById(int id);
	
	List<LibrettoUniversitario> getLibretti();
	LibrettoUniversitario getLibretto(int id);
	
	Studente addStudente(Studente s);
	LibrettoUniversitario addLibretto(LibrettoUniversitario lu);

	List<Pokemon> getPokemon();
	List<Pokemon> getPokemonByName(String name);

}
