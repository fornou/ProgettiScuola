package model;

import java.time.LocalDate;

public class Todo {
	private static int cont = 1;
	
	private int id;
	private String desc;
	private LocalDate data;
	private boolean fatto;
	
	
	public Todo(String desc, LocalDate data, boolean fatto) {
		this.id = cont++;
		this.desc = desc;
		this.data = data;
		this.fatto = fatto;
	}
	
	public Todo(String desc) {
		this.id = cont++;
		this.desc = desc;
		this.data = LocalDate.now();
		this.fatto = false;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getDesc() {
		return desc;
	}
	public void setDesc(String desc) {
		this.desc = desc;
	}
	public LocalDate getData() {
		return data;
	}
	public void setData(LocalDate data) {
		this.data = data;
	}
	public boolean isFatto() {
		return fatto;
	}
	public void setFatto(boolean fatto) {
		this.fatto = fatto;
	}
	
	
}
