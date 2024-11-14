import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);

            System.out.println("Graduando ou Mestrando?");

            if ((sc.nextLine()).equals("Graduando")){
                Graduando gradu = new Graduando();
            }

        } catch (Exception e) {
            System.out.println("Erro");
        } finally {
            sc.close();
        }
    }
}
