package com.forneron.services;

import java.util.List;

import com.forneron.entities.Prodotto;

public interface ProdottoService {
	//Crud
	//Create
		Prodotto addProdotto(Prodotto p);
	//Read
	Prodotto getProdottoById(int id);
	List<Prodotto> getProdotti();
	//Update
	Prodotto updateProdotto(Prodotto p);
	//Delete
	void deleteProdotto(Prodotto p);//Overload
	void deleteProdotto(int id);

}
