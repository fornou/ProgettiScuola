package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.LibrettoUniversitario;
import com.forneron.entities.Pokemon;
import com.forneron.entities.Studente;
import com.forneron.repos.LibrettoDAO;
import com.forneron.repos.PokemonDAO;
import com.forneron.repos.StudenteDAO;

@Service
public class ITSServiceImpl implements ITSService{
	@Autowired
	private StudenteDAO studenteDAO;
	@Autowired
	private LibrettoDAO librettoDAO;
	@Autowired
	private PokemonDAO pokemonDAO;
	
	@Override
	public List<Studente> getStudenti() {
		return studenteDAO.findAll();
	}

	@Override
	public Studente getStudenteById(int id) {
		return studenteDAO.getReferenceById((long)id);
	}

	@Override
	public List<LibrettoUniversitario> getLibretti() {
		return librettoDAO.findAll();
	}

	@Override
	public LibrettoUniversitario getLibretto(int id) {
		return librettoDAO.getReferenceById((long)id);
	}

	@Override
	public Studente addStudente(Studente s) {
		return studenteDAO.save(s);
	}

	@Override
	public LibrettoUniversitario addLibretto(LibrettoUniversitario lu) {
		return librettoDAO.save(lu);
	}

	@Override
	public List<Pokemon> getPokemon() {
		return pokemonDAO.findAll();
	}

	@Override
	public List<Pokemon> getPokemonByName(String name) {
		return pokemonDAO.findByNameContaining(name);
	}

}
