package finestre;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class HelloFinestra {
	public static void main(String[] args) {
		
		JFrame finestra = new JFrame();
		
		JLabel testo = new JLabel("Tutti i pokemon");
		
		JTextField nomePokemon = new JTextField();
		nomePokemon.setSize(new Dimension(100, 20));
		
		JButton bottone = new JButton();
		bottone.setText("Click");
		
		bottone.addActionListener(
				e -> System.out.println("Funziona -> " + nomePokemon.getText())
		);
		
		BorderLayout layout = new BorderLayout();
		
		finestra.setLayout(layout);
		
		
		finestra.add(testo, BorderLayout.NORTH);
		finestra.add(nomePokemon, BorderLayout.CENTER);
		finestra.add(bottone, BorderLayout.SOUTH);
		
		
		
		
		
		
		
		
		finestra.setTitle("Pokemon Gallery");
		
		finestra.setSize(500,400);// height, width
		//chiudo e esco non continua
		finestra.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		finestra.setVisible(true);
		
		
		
	}
}
