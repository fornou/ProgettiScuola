package com.gruppo.services;

import java.util.List;

import com.gruppo.entities.Corso;
import com.gruppo.entities.Libretto;
import com.gruppo.entities.Studente;

public interface StudentiService {
	List<Studente> getStudenti();
	List<Libretto> getLibretti();
	List<Corso> getCorsi();
	
	Libretto addLibretto(Libretto l);
	Studente addStudente(Studente s);
	Corso addCorso(Corso c);
}
