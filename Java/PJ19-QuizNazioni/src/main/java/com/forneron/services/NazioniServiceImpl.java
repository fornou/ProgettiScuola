package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.Nazione;
import com.forneron.repos.NazioneDAO;

@Service
public class NazioniServiceImpl implements NazioniService{

	@Autowired
	private NazioneDAO dao;

	@Override
	public List<Nazione> getNazioni() {
		return dao.findAll();
	}

	@Override
	public List<Nazione> getProdottiByPopolazione(int min, int max) {
		return dao.findByPopolazioneBetween(min, max);
	}

	@Override
	public Nazione getNazioniByCode(String code) {
		return dao.getReferenceById(code);
	}
	
	
	
	
	

}
