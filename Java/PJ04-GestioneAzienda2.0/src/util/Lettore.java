package util;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Lettore {
	

	public ArrayList<String> leggiFile(String nomeFile) {
		ArrayList<String> lettura = new ArrayList<String>();
		File dipendenti = new File(nomeFile);
		
		try {
			Scanner in = new Scanner(dipendenti);
			while(in.hasNextLine()) {
				lettura.add(in.nextLine());		
				
			}
		}catch(FileNotFoundException e) {
			e.printStackTrace();
		}
		
		return lettura;
	}
}
