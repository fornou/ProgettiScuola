
public class ProvaCarattere {
	public static void main(String[] args) {
		int volte = 25600;
		
		for(int i = 0; i < volte; i++) {
			System.out.print((char)i + " ");
			if(i % 80 == 0) {
				System.out.println();
			}
		}
	}
}
