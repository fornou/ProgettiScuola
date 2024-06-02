<!DOCTYPE html>
<%@page import="java.util.ArrayList"%>
<%@page import="com.forneron.repos.FilmDAO"%>
<%@page import="model.Film"%>
<html>
<head>
<meta charset="UTF-8">
<title>MyFilm</title>
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no"/>
<link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous"/>
</head>
<body>	

	<div class="container">
		<h1 class="text-center">Aggiungi un Titolo alla lista</h1>
		
		<form class = "text-center" action = "addFilm.jsp" method = "post">
			<input class="form-control" type="text" name="titolo" placeholder="titolo"><br>
			<input class="form-control" type="number" name="anno" placeholder="anno"><br>
			<input class="form-control" type="text" name="rating" placeholder="rating"><br>
			<input class="form-control" type="text" name="regista" placeholder="regista"><br>
			<button type="submit" class="btn btn-dark " name="valore" value="addFilm">ADD FILM</button>
			<button type="submit" class="btn btn-dark " name="valore" value="remFilm">REMOVE FILM</button>
		</form>
		<h1 class="text-center">Lista di tutti i Titoli</h1>
		<div class="table-responsive">
			<table class="table table-hover  table table-bordered table-dark">
				<thead>
					<tr>
						<th scope="col">Id</th>
						<th scope="col">Titolo</th>
						<th scope="col">Anno</th>
						<th scope="col">Rating</th>
						<th scope="col">Regista</th>
					</tr>
				</thead>
				<tbody>
					<%
						FilmDAO td = new FilmDAO();
						ArrayList<Film> films = td.getFilms();
						for (Film l:  films) {
							out.println("<tr>");
							out.println("<th scope='row'>" + l.getId() + "</td>");
							out.println("<td>" + l.getTitolo() + "</td>");
							out.println("<td>" + l.getAnno() + "</td>");
							out.println("<td>" + l.getRating() + "</td>");
							out.println("<td>" + l.getRegista() + "</td>");
							out.println("</tr>");
						}
				
					%>
				</tbody>
			</table>
		</div>

	</div>

	<!-- Bootstrap JavaScript Libraries -->
	<script
	src="https://cdn.jsdelivr.net/npm/@popperjs/core@2.11.8/dist/umd/popper.min.js"
	integrity="sha384-I7E8VVD/ismYTF4hNIPjVp/Zjvgyol6VFvRkX/vR+Vc4jQkC+hVqc2pM8ODewa9r"
	crossorigin="anonymous"></script>

	<script
		src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/js/bootstrap.min.js"
		integrity="sha384-BBtl+eGJRgqQAUMxJ7pMwbEyER4l1g+O15P+16Ep7Q9Q+zqX6gSbd85u4mG4QzX+"
		crossorigin="anonymous">
	</script>

</body>
</html>