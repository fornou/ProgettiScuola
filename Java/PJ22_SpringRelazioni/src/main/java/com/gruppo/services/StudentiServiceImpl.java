package com.gruppo.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.gruppo.entities.Corso;
import com.gruppo.entities.Libretto;
import com.gruppo.entities.Studente;
import com.gruppo.repos.*;

@Service
public class StudentiServiceImpl implements StudentiService{
	
	@Autowired
	private StudenteDAO sDao;
	@Autowired
	private LibrettoDAO lDao;
	@Autowired
	private CorsoDAO cDao;

	@Override
	public List<Studente> getStudenti() {
		return sDao.findAll();
	}

	@Override
	public List<Libretto> getLibretti() {
		return lDao.findAll();
	}

	@Override
	public Libretto addLibretto(Libretto l) {
		return lDao.save(l);
	}

	@Override
	public Studente addStudente(Studente s) {
		return sDao.save(s);
	}

	@Override
	public List<Corso> getCorsi() {
		return cDao.findAll();
	}

	@Override
	public Corso addCorso(Corso c) {
		return cDao.save(c);
	}
	


}
