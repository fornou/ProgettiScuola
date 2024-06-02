<%@page import="java.util.ArrayList"%>
<%@page import="java.sql.ResultSet"%>
<%@page import="java.sql.Statement"%>
<%@page import="db.Connessione"%>
<h1>Ecco il nostro Menù</h1>

<div class  ="content">

<%
	String pagina = "";
	String query = "select p.nome, p.prezzo, tp.nome as categoria " +
			"from piatti p inner join tipi_piatto as tp " +
			"on tp.id = p.tipo_piatto_id ";
	Connessione cn;
	Statement st;
	ResultSet rs;
	ArrayList<String> ris = new ArrayList<>();
	
	if(request.getParameter("pagina") != null){
		pagina = request.getParameter("pagina");
	}
	switch(pagina){
		
		case "primi":
			%>
			<%--  <%@include file="primi.html" %> --%>
			<%
			query += "where tp.nome = 'Primo'";
		break;
			
		case "secondi":
			query += "where tp.nome = 'Secondo'";
		break;
			
		case "dessert":
			query += "where tp.nome = 'Dessert'";
		break;
			
		case "bevande":
			query += "where tp.nome = 'Bevanda'";
		break;
			
		default:
			out.print("<h1>" + pagina + "</h1>");
		break;
	}
	
	
	cn = new Connessione();
	st = cn.getConn().createStatement();
	rs = st.executeQuery(query);
	
	while(rs.next()){
		ris.add(rs.getString("nome")+","+rs.getString("prezzo"));
	}
	
	
	for(String stringa : ris){
		
		String[] valori = stringa.split(",");
	    String nome = valori[0];
	    String prezzo = valori[1];
		
	%> 	<div class="card" style="width: 18rem;">

		<img src="..." class="card-img-top" alt="...">
		<div class="card-body">
			<h5 class="card-title"><%= nome %></h5>
			<p class="card-text">
				Prezzo: <%= prezzo %>
			</p>
			<a href="#" class="btn btn-primary">Informazioni</a>
		</div>

	</div>
	<% 
	}
	
	
	

%>
</div>
