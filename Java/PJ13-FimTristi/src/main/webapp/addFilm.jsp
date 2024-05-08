<%@page import="model.Film"%>
<%@page import="repos.FilmDAO"%>
<%@page import="java.util.Scanner"%>

<%
	
	Film f = new Film();
	FilmDAO dao = new FilmDAO();
	
	String titolo = request.getParameter("titolo");
	String regista = request.getParameter("regista");
	int anno = Integer.parseInt(request.getParameter("anno"));
	double rating = Double.parseDouble(request.getParameter("rating"));
	
	f.setTitolo(titolo);
	f.setRegista(regista);
	f.setAnno(anno);
	f.setRating(rating);
	
	String valore = request.getParameter("valore");
	
	if(valore!=null){
		if(valore.equals("addFilm")){
			dao.addFilm(f);
		}else if(valore.equals("remFilm")){
			dao.remFilm(f);
		}
	}

	response.sendRedirect("index.jsp");



%>