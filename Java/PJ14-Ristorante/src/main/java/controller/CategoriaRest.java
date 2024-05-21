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
	
	
	private RistoranteServiceDAO service = new RistoranteServiceDAO() {
		
	public void CategoriaRest() {
		System.out.println("Servlet Categoria Costruita!!");
	}
		
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		response.setContentType("application/api");
		
		JSONArray array = new JSONArray();
		JSONObject obj1 = new JSONObject();
		JSONObject obj2 = new JSONObject();
		JSONObject obj3 = new JSONObject();
		
		array.put(obj1);
		array.put(obj2);
		array.put(obj3);
		
		response.getWriter().print(array.toString());
		
		
		
	}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		@Override
		public Piatto getPiattoById(int id) {
			// TODO Auto-generated method stub
			return null;
		}
		
		@Override
		public List<Piatto> getPiattiByCategoria(Categoria c) {
			// TODO Auto-generated method stub
			return null;
		}
		
		@Override
		public List<Piatto> getPiatti() {
			// TODO Auto-generated method stub
			return null;
		}
		
		@Override
		public List<Categoria> getCategorie() {
			// TODO Auto-generated method stub
			return null;
		}
		
		@Override
		public Categoria getCategoriaById(int id) {
			// TODO Auto-generated method stub
			return null;
		}
	};
	
}
