package controllflow;
import java.util.*;


public class DemoForEach {
	public static void riempiIntArray(int n, int[] v){
		Random random = new Random();
		int max = 30, min = 20;
		for(int i = 0; i < n; i++){
			v[i] = random.nextInt(max - min + 1) + min;
		}
	}
	public static int stampaArray(int d, int[]voti){
		int i = 0, tot = 0;
		for(int voto : voti){
			i++;
			System.out.printf("%d- %d\n", i, voto);
			tot += voto;
		}
		return tot/=d;
	}
	public static void main(String[] args) {
		
		int[] voti = new int[5];
		int dim = voti.length;
		riempiIntArray(dim, voti);
		System.out.println("La media: "+ stampaArray(dim,voti));
	}
}
