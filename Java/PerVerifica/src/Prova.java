import java.util.Scanner;

public class Prova {

	public static void asterischiNormali(int n) {

		for (int i = 0; i <= n; i++) {

			for (int j = 0; j < i; j++) {

				System.out.print("* ");

			}

			System.out.println();

		}

	}

	public static void asterischiRicorsivi(int n, int c) {

		if (n < c) {

			return;

		}

		for (int i = 0; i < c; i++) {

			System.out.print("* ");

		}

		System.out.println();

		asterischiRicorsivi(n, c + 1);

	}

public static void main(String[] args) {

Scanner t = new Scanner(System.in);

System.out.println("Digita un numero");

int n = t.nextInt();

System.out.println("Ast norm:");

asterischiNormali(n);

System.out.println("Ast ric:");

asterischiRicorsivi(n, 1);

}

}