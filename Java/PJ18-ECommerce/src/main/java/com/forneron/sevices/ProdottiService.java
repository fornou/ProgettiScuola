package com.forneron.sevices;

import java.util.List;

import org.springframework.stereotype.Service;

import com.forneron.entities.Prodotto;

public interface ProdottiService {
	List<Prodotto> getProdotti();
	List<Prodotto> getProdottiByPrice(double min, double max);

	Prodotto addProdotto(Prodotto p);
	Prodotto updateProdotto(Prodotto p);

	void deleteProdotto(Prodotto p);
}
