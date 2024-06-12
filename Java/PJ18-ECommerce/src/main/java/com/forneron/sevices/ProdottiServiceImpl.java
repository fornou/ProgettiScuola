package com.forneron.sevices;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.Prodotto;
import com.forneron.repos.ProdottoDAO;
@Service
public class ProdottiServiceImpl implements ProdottiService{

	@Autowired
	private ProdottoDAO dao;
	
	@Override
	public List<Prodotto> getProdotti() {
		return dao.findAll();
	}

	@Override
	public List<Prodotto> getProdottiByPrice(double min, double max) {
		return dao.findByPriceBetween(min, max);
	}

	@Override
	public Prodotto addProdotto(Prodotto p) {
		return dao.save(p);
	}

	@Override
	public Prodotto updateProdotto(Prodotto p) {
		return dao.save(p);
	}

	@Override
	public void deleteProdotto(Prodotto p) {
		dao.delete(p);
	}

}
