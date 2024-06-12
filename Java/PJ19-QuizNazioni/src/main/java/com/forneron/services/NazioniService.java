package com.forneron.services;

import java.util.List;

import com.forneron.entities.Nazione;

public interface NazioniService {

	List<Nazione> getNazioni();
	List<Nazione> getProdottiByPopolazione(int min, int max);
	
	Nazione getNazioniByCode(String code);

	
	
	
}
