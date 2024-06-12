package com.forneron.repos;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.forneron.entities.Prodotto;

public interface ProdottoDAO extends JpaRepository<Prodotto, Integer>{
	//derived query
	List<Prodotto> findByPriceBetween(double min, double max);
	
}
