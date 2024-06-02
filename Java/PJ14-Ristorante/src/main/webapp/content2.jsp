<%@page import="model.Categoria"%>
<%@page import="java.util.List"%>
<%@page import="model.Piatto"%>
<div class="row">
	
	<%List<Piatto> piatti = (List<Piatto>)request.getAttribute("piatti"); %>
	
	<%	
	for (Piatto p : piatti) {
	%>

	<div class="card" style="width: 18rem;">

		<img src="..." class="card-img-top" alt="...">
		<div class="card-body">
			<h5 class="card-title"><%= p.getNome() %></h5>
			<p class="card-text">
				Prezzo: <%= p.getPrezzo() %>
			</p>
			<p class="card-text">
				Categoria: <%= p.getCategoria().getNome() %>
			</p>
			<a href="#" class="btn btn-primary">Go somewhere</a>
		</div>

	</div>

	<%
	}
	%>

</div>