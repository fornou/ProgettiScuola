<!DOCTYPE html>
<%@page import="java.util.ArrayList"%>
<%@page import="db.FilmDAO"%>
<%@page import="model.Film"%>
<html>
<head>
<meta charset="UTF-8">
<title>MIAOOOOOOOOO</title>
<link rel="stylesheet" href="style.css">
</head>
<body>	
	<h1>Ecco tutti i titoli presenti nel db</h1>
	<table>
		<tr>
			<td>Id</td>
			<td>Titolo</td>
			<td>Anno</td>
			<td>Rating</td>
		</tr>
		
	<%
		FilmDAO td = new FilmDAO();
		ArrayList<Film> films = td.getFilms();
		for (Film l:  films) {
			out.println("<tr>");
			out.println("<td>" + l.getId() + "</td>");
			out.println("<td>" + l.getTitolo() + "</td>");
			out.println("<td>" + l.getAnno() + "</td>");
			out.println("<td>" + l.getRating() + "</td>");
			out.println("</tr>");
		}
		
	%>
	
	</table>
</body>
</html>