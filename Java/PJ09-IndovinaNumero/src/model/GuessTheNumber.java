package model;

import java.util.Random;

public class GuessTheNumber {
	//Attributi classe
	private int min, max, randomNum, numTentativo;
	private boolean win;
	
	//Costruttore classe che in base a 2 parametri crea il valore e setta la win a false
	public GuessTheNumber(int min, int max){
		Random rand = new Random();
		randomNum = rand.nextInt((max - min) + 1) + min;
		numTentativo = 0;
		win = false;
	}
	//incrementa il tentativo
	public void incrementaTentativo() {
		numTentativo++;
	}
	// getters & setters
	public int getTentativo() {
		return numTentativo;
	}
	
	public boolean getWin() {
		return win;
	}

	public void setWin(boolean win) {
		this.win = win;
	}

	public int getMin() {
		return min;
	}

	public void setMin(int min) {
		this.min = min;
	}

	public int getMax() {
		return max;
	}

	public void setMax(int max) {
		this.max = max;
	}
	
	public int getRandomNum() {
		return randomNum;
	}
	

}
