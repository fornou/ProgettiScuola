package elaborazioni;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class LeggiFile {
	
	public static void scrivi(String nomeFile, ArrayList<String> stringhe) throws FileNotFoundException {
		File f = new File(nomeFile);
		PrintWriter out = new PrintWriter(f);//scrive caratteri
		for (String stringa : stringhe) {
			out.println(stringa);
		}
		out.close();//chiude e salva
	}
	
	public static void scrivi(String nomeFile, String stringa) throws FileNotFoundException {
		File f = new File(nomeFile);
		PrintWriter out = new PrintWriter(f);//scrive caratteri
		out.println(stringa);
		out.close();//chiude e salva
	}
	
	public static String leggi(String nomeFile)throws FileNotFoundException {
		StringBuilder sb = new StringBuilder();
		
		File f = new File(nomeFile); 
		Scanner in = new Scanner(f);
		
		while(in.hasNextLine()) {
			String riga = in.nextLine();
			sb.append(riga);
			sb.append("\n");
		}
		
		return sb.toString();
	}
	
	public static ArrayList<String> leggi(String nomeFile, boolean b)throws FileNotFoundException {
		
		ArrayList<String> al = new ArrayList<String>();
		File f = new File(nomeFile); 
		Scanner in = new Scanner(f);
		
		while(in.hasNextLine()) {
			String riga = in.nextLine();
			al.add(riga);
		}
		
		return al;
	}
}
