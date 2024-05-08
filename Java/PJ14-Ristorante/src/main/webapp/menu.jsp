<nav>
<ul>

<li> <a href="?">Home</a> </li>
<li> <a href="?pagina=primi">Primi</a> </li>
<li> <a href="?pagina=secondi">Secondi</a> </li>
<li> <a href="?pagina=dessert">Dessert</a> </li>
<li> <a href="?pagina=bevande">Bevande</a> </li>

<li>
	<div class=form-container>
	
		<form action = "">
			<input type = "text" name = "prova" placeholder = "Cerca Piatto...">
			<input type = "submit" value = "Search">
		</form>
	
	
	</div>

</li>


</ul>



<%
	if(request.getParameter("prova") != null){
		String risposta = request.getParameter("prova");
		
		if(risposta.equalsIgnoreCase("Pasta al Forno")){
			out.print("<h1>Piatto disponibile " + risposta + "</h1>");
		}else if(risposta.equals("")){
			
		}else{
			out.print("<p>Piatto non disponibile nel menù</p>");
		}
	}
%>
</nav>