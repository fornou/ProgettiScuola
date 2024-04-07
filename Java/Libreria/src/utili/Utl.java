package utili;
import java.util.*;

public class Utl{
   public static Scanner in = new Scanner(System.in);

   public Utl() {
   }

   public static void prntString(String var0) {
      System.out.println(var0);
   }

   public static void cls() {
      prntString("\u001b[H\u001b[2J");
   }

   public static void pause() {
      prntString("Premere un tasto...");
      in.nextLine();
   }

}
