package com.gruppo.services;

import java.util.List;
import java.util.Set;

import com.gruppo.entities.Brawler;

public interface BrawlerService {
	List<Brawler> getAllBrawlers();
	List<Brawler> getAllBrawlersByRarity(String rarity);
	List<Brawler> getAllBrawlersByCarattere(String carattere);
	Brawler getBrawler(int id);
	
	Set<String> getRarities();
	List<String> getCaratteri();
}
