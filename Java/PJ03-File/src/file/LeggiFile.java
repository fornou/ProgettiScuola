package file;

import java.io.*;
import java.util.*;

public class LeggiFile {

	public static void main(String[] args) {
		File canzoni = new File("C:\\Users\\ICTS23-25.189\\Downloads\\canzoni2020.csv");
		
		try {
			Scanner in = new Scanner(canzoni);
			while(in.hasNextLine()) {//fino a che c'è un'altra riga
				String riga = in.nextLine();
				
				
				String[] parole = riga.split(",");
				String titolo = parole[0];
				String cantanti = null;
				
				if(parole.length > 1)
					cantanti = parole[1];
				
				Canzone c = new Canzone(titolo, cantanti);
				
				if(c.stampa()=="Manca un elemento"){
					System.err.println(c.stampa());
				}else {
					System.out.println(c.stampa());
				}
				
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		
		
		
		
		
	}

}
