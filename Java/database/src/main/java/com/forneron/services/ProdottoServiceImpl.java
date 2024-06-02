package com.forneron.services;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.forneron.entities.Prodotto;
import com.forneron.repos.ProdottoDAO;

@Service
public class ProdottoServiceImpl implements ProdottoService {
	@Autowired
	private ProdottoDAO dao;
	
	@Override
	public Prodotto addProdotto(Prodotto p) {
		return dao.save(p);
	}

	@Override
	public Prodotto getProdottoById(int id) {
		return dao.getReferenceById((long) id);
	}

	@Override
	public List<Prodotto> getProdotti() {
		return dao.findAll();
	}

	@Override
	public Prodotto updateProdotto(Prodotto p) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void deleteProdotto(Prodotto p) {
		dao.delete(p);
	}

	@Override
	public void deleteProdotto(int id) {
		dao.deleteById((long)id);
	}

}
