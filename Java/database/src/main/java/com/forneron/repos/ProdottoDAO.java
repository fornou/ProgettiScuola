package com.forneron.repos;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.forneron.entities.Prodotto;

@Repository
public interface ProdottoDAO extends JpaRepository<Prodotto, Long>{
	
	
	
}
