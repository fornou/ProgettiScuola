package db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Connessione {
	private final String URL = "jdbc:mysql://localhost:3307/its_2024";
	private final String USER = "ITS_2024";
	private final String PASSWORD = "forneron";
	
	private Connection conn;
	
	public Connection getConn() {
		return this.conn;
	}
	
	public Connessione() {
		connetti();
	}
	
	public void connetti() {
		try{
			this.conn = DriverManager.getConnection(URL, USER, PASSWORD);
			System.out.println("Sei connesso");
		}catch(SQLException e) {
			System.out.println("Hai un problema nella connessione: " + e.getMessage());
		}
	}
	
	public void disconnetti() {
		try{
			this.conn.close();
			System.out.println("Sei stato sconnesso");
		}catch(SQLException e) {
			System.out.println("Hai un problema nella sconnessione: " + e.getMessage());
		}
	}
}
