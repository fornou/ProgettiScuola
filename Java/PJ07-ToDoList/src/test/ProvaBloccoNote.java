package test;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

import controller.BloccoNote;
import model.Todo;

public class ProvaBloccoNote {
	
	public static void cls() {  
	    System.out.print("\033[H\033[2J");  
	    System.out.flush();  
	} 
	
	public static void main(String[] args) {
		
		Scanner t = new Scanner(System.in);
		
		BloccoNote bn = new BloccoNote("Tutto quello che devo fare");
				
		int scelta = 0, idRic = 0;
		
		//Todo oggetto1 = new Todo("Spesa");
		//Todo oggetto2 = new Todo("Pulizia");
		//Todo oggetto3 = new Todo("Compiti",  LocalDate.of(2024, 4, 19), true);
				
		//oggetto1.setData( LocalDate.of(2024, 4, 16));
		//oggetto2.setData( LocalDate.of(2024, 4, 12));
		
		//bn.addTodo(oggetto1);
		//bn.addTodo(oggetto2);
		//bn.addTodo(oggetto3);
		
		//ArrayList<Todo> oggetti = bn.getAll();
		
		//System.out.println(bn.getNome());
		//
		//System.out.println("I To_Do totali:");
		//
		//for (Todo oggetto : oggetti) {
		//	System.out.println("Id: " + oggetto.getId() + "| Data: " + oggetto.getData().toString() + "| Descrizione: " + oggetto.getDesc() + "| Fatto: " + oggetto.isFatto());
		//}
		
		do {
			do {
				System.out.println("Menù\n1- Aggiungi un nuovo Gruppo\n2- Visualizza Gruppi\n3- Visualizza Gruppi specifici\n4- Visualizza dati gruppo specifico\n5- Modifica stato\n0- Esci");
				scelta = t.nextInt();
			}while(scelta < 0 || scelta > 5);
			
			switch (scelta) {
			
				case 1:
					System.out.println("Nome della nuovo Gruppo");
					String nome = t.next();
					bn.addTodo(nome);
				break;
				
				case 2:
					if(bn.getAll().isEmpty() == false){
						System.out.println("I Gruppi sono:");
						for (Todo oggetto : bn.getAll()) {
							System.out.println(oggetto.getDesc());
						}
					}else{
						System.out.println("Aggiungi prima un oggetto!");
					}
					
				break;
				
				case 3:
					if(bn.getAll().isEmpty() == false){
						System.out.println("I Gruppi sono:");
						for (Todo oggetto : bn.getAll()) {
							System.out.println("Id: " + oggetto.getId() + "| Descrizione: " + oggetto.getDesc() + "| Data: " + oggetto.getData().toString() + "| Fatto: " + oggetto.isFatto());
						}
					}else{
						System.out.println("Aggiungi prima un oggetto!");
					}
				break;
				
				case 4:
					if(bn.getAll().isEmpty() == false){
						do {
							System.out.println("Inserisci l'id del Gruppo");
							idRic = t.nextInt();
							idRic--;
						}while(idRic >= bn.getAll().size()|| idRic < 0);
						Todo oggRic = bn.getTodoById(idRic);
						System.out.println("Id: " + oggRic.getId() + "| Descrizione: " + oggRic.getDesc() + "| Data: " + oggRic.getData().toString() + "| Fatto: " + oggRic.isFatto());
					}else{
						System.out.println("Aggiungi prima un oggetto!");
					}
				break;
				
				case 5:
					if(bn.getAll().isEmpty() == false){
						do {
							System.out.println("Inserisci l'id del Gruppo");
							idRic = t.nextInt();
							idRic--;
						}while(idRic >= bn.getAll().size()|| idRic < 0);
						Todo oggRic = bn.getTodoById(idRic);
						if(oggRic.isFatto()==true) {
							oggRic.setFatto(false);
						}else {
							oggRic.setFatto(true);
						}
					}else{
						System.out.println("Aggiungi prima un oggetto!");
					}
					
				break;
				
				case 0:
					
				break;
	
				default:
					System.out.println("ERROR: numero non valido");
				break;
			}
			cls();
			
		} while (scelta != 0);
		
		System.out.println("PROGRAM FINISHED");
		
		
	}
}
