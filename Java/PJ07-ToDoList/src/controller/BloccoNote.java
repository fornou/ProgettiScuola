package controller;

import java.util.ArrayList;

import model.Todo;

public class BloccoNote {
	private ArrayList<Todo> toDoList;
	private String nome;
	
	
	public BloccoNote(String nome) {
		this.nome = nome;
		this.toDoList = new ArrayList<>();
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void addTodo(Todo t){
		toDoList.add(t);
	}
	
	public void addTodo(String desc){
		Todo t = new Todo(desc);
		toDoList.add(t);
	}
	
	public ArrayList<Todo> getAll(){
		return toDoList;
	}
	
	public Todo getTodoById(int id) {
		return toDoList.get(id);
	}
	
	
}
