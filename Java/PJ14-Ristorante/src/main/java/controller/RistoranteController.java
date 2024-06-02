package controller;

import java.io.IOException;
import java.util.List;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import model.Categoria;
import model.Piatto;
import services.RistoranteServiceDAOImpl;

@WebServlet("/piatti")
public class RistoranteController extends HttpServlet {

    private RistoranteServiceDAOImpl service = new RistoranteServiceDAOImpl();
   
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	
    	if(request.getParameter("id")!= null) {
    		int id = Integer.parseInt(request.getParameter("id"));
    		Piatto p = service.getPiattoById(id);
    		
    		response.setContentType("text/html");
    		response.getWriter().print("<h1>Piatto con id "+id+"</h1>");
    		response.getWriter().print(p.getNome());
    	}else {
    		//1 includi header
        	request.getRequestDispatcher("header.jsp").include(request, response);
        	
        	//2 verifico se vuole un piatto o tutti
        	
        	//3 se solo uno -> metodo che ritorna un piatto
        	
        	//4 se tutti -> metodo che ritorna tutti i piatti
        	List<Piatto> piatti = service.getPiatti();
        	List<Categoria> categorie = service.getCategorie();
        	/*for (Piatto piatto : piatti) {
        		response.getWriter().print("<p>" + piatto.getNome() + "</p>");
        	}*/
        	
        	//5 stampo a video i piatti
        	request.setAttribute("piatti", piatti);
        	request.setAttribute("categorie", categorie);
        	request.getRequestDispatcher("content2.jsp").include(request, response);
        	
        	//includo footer
        	request.getRequestDispatcher("footer.jsp").include(request, response);
    	}
    	
    	
        
    }
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	if(request.getParameter("nome")!= null) {
    		
    		String nome = request.getParameter("nome");
    		double prezzo = Double.parseDouble(request.getParameter("prezzo"));
    		int idCategoria = Integer.parseInt(request.getParameter("categoria"));
    		Piatto p = new Piatto();
    		
    		p.setNome(nome);
    		p.setPrezzo(prezzo);
    		
    		Categoria c = new Categoria();
    		c.setId(idCategoria);
    		c.setNome("primi");
    		
    		p.setCategoria(c);
    		
    		service.addPiatto(p);
    		
    		
    	}else {
    		
    	}
    }
}
