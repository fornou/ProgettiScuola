package database;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Connessione {

	private final String URL = "jdbc:mysql://localhost:3307/its_2024";
	private final String USER = "ITS_2024";
	private final String PASSWORD = "forneron";
	
	private Connection conn = null;
	
	public Connection getConn() {
		return this.conn;
	}
	
	public void connetti() {
		try{
			this.conn = DriverManager.getConnection(URL, USER, PASSWORD);
			System.out.println("Sei connesso");
		}catch(SQLException e) {
			System.out.println("Hai un problema nella connessione: " + e.getMessage());
		}
	}
}
