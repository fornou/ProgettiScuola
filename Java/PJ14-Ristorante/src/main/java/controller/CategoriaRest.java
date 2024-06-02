package controller;

import java.io.IOException;
import java.util.List;

import org.json.JSONArray;
import org.json.JSONObject;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import model.Categoria;
import model.Piatto;
import services.RistoranteServiceDAO;

@WebServlet("/categorie")
public class CategoriaRest extends HttpServlet{
	
	private int cont = 1, cont2 = 1;
	//private RistoranteServiceDAO service = new RistoranteServiceDAO() {
		
	public void CategoriaRest() {
		System.out.println("Servlet Categoria Costruita!!");
	}
		
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		cont ++;
		System.out.println("Richiesta get: " + cont);
		
		if(request.getParameter("pagina")!=null) {
			String pagina = request.getParameter("pagina");
			response.getWriter()
			.print("Ecco il parametro pagina" + pagina);
		}
		
		if(request.getParameter("nome categoria") != null) {
			String categoria = request.getParameter("");
			response.getWriter()
			.print("Ecco il parametro categoria" + categoria);
		}
		
		response.getWriter()
		.print("Richiesta get: " + cont);
		
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		cont2 ++;
		System.out.println("Richiesta post: " + cont2);
		
		response.getWriter()
		.print("Richiesta get: " + cont2);
	}
	
	
}
