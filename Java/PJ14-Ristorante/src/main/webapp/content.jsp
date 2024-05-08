<%@page import="java.util.ArrayList"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="db.Connessione"%>
<h1>Ecco il nostro Menù</h1>

<%
	String pagina = "";
	String query = "select * from studenti";

	ArrayList<String> ris = new ArrayList<>();
	
	if(request.getParameter("pagina") != null){
		pagina = request.getParameter("pagina");
	}
	switch(pagina){
		
		case "primi":
			%>
			<%@include file="primi.html" %>
			<%
		break;
			
		case "secondi":
			query = "select * from piatti where tipo_piatto = 'secondi'";
		break;
			
		case "dessert":
		break;
			
		case "bevande":
		break;
		
		case "prova=si":
			break;
			
		default:
			Connessione cn = new Connessione();
			Statement st = cn.getConn().createStatement();
			ResultSet rs = st.executeQuery(query);
			
			while(rs.next()){
				ris.add(rs.getString("cognome"));
				ris.add(rs.getString("nome"));
			}
			
			
			out.print("<h1>" + pagina + "</h1>");
		break;
	}
	
	
	
	for(String studente : ris){
		out.print("<h2>" + studente + "</h2>");
	}
	
	
	

%>

