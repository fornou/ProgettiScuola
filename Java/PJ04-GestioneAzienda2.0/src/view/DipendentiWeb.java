package view;

import java.util.ArrayList;
import model.Dipendente;

public class DipendentiWeb {

	public String creaLista(ArrayList<Dipendente>dipendenti){
		StringBuilder sb = new StringBuilder();
		
		sb.append("<table>\n");
		sb.append("<tr><td>nome</td><td>cognome</td><td>stipendio</td></tr>");
		
		for (Dipendente d : dipendenti) {
			sb.append("<tr>");
			sb.append("<td>"+ d.getNome() + "</td> <td> " + d.getCognome() + "</td> <td>" + d.getStipendio() + "</td>");
			sb.append("</tr>\n");
		}
		
		sb.append("</table>");
				
		return sb.toString();
	}
	
	
}
