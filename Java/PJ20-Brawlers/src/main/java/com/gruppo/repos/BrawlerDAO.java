package com.gruppo.repos;

import java.util.List;

import org.springframework.data.jpa.repository.JpaRepository;

import com.gruppo.entities.Brawler;

public interface BrawlerDAO extends JpaRepository<Brawler, Integer>{
	
    List<Brawler> findByCarattere(String carattere);
    List<Brawler> findByRarity(String rarity);

}
