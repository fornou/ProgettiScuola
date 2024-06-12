package com.forneron.repos;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.forneron.entities.Nazione;

public interface NazioneDAO extends JpaRepository<Nazione, String>{
	List<Nazione> findByPopolazioneBetween(double min, double max);
}
