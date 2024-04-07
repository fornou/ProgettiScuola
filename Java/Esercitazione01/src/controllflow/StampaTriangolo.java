package controllflow;

public class StampaTriangolo {
	public static void main(String[] args) {
		int righe = 60;
		
		for(int i = 0; i < righe; i++) {
			for(int j = 0; j < i; j++) {
				System.out.print("A");
			}
			System.out.println();
		}
	}
}
