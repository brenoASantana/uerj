import java.util.Locale;
import java.util.Scanner;

public class P2nX {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		Scanner scanner = new Scanner(System.in);

		MinhaListaOrdenavel listaOrdenavel = new MinhaListaOrdenavel();

		// Coloquei meu CPF em todas as instancias de pessoas pois eh o unico que eu sei
		// que vai passar pelo validador de CPF
		listaOrdenavel
				.add(new Homem("Carlos", "Silva", 15, 3, 1990, ValidaCPF.convertCPF("20565581732"), 100.5f, 1.75f));
		listaOrdenavel
				.add(new Mulher("Ana", "Oliveira", 20, 7, 1995, ValidaCPF.convertCPF("20565581732"), 30.0f, 1.65f));
		listaOrdenavel.add(new Homem("João", "Souza", 5, 1, 1985, ValidaCPF.convertCPF("20565581732"), 70.0f, 1.80f));
		listaOrdenavel
				.add(new Mulher("Maria", "Costa", 18, 9, 1992, ValidaCPF.convertCPF("20565581732"), 44.5f, 1.60f));
		listaOrdenavel
				.add(new Homem("Pedro", "Martins", 10, 12, 1988, ValidaCPF.convertCPF("20565581732"), 98.0f, 1.85f));
		listaOrdenavel
				.add(new Mulher("Juliana", "Ferreira", 25, 5, 2000, ValidaCPF.convertCPF("20565581732"), 62.0f, 1.68f));
		listaOrdenavel
				.add(new Homem("Lucas", "Ribeiro", 3, 8, 1993, ValidaCPF.convertCPF("20565581732"), 120.0f, 1.72f));
		listaOrdenavel
				.add(new Mulher("Carla", "Pereira", 30, 6, 1998, ValidaCPF.convertCPF("20565581732"), 49.0f, 1.70f));
		listaOrdenavel
				.add(new Homem("Fernando", "Almeida", 7, 4, 1982, ValidaCPF.convertCPF("20565581732"), 102.0f, 1.90f));
		listaOrdenavel.add(
				new Mulher("Fernanda", "Nascimento", 12, 11, 1991, ValidaCPF.convertCPF("20565581732"), 55.0f, 1.67f));

		boolean continuar = true;
		while (continuar) {
			System.out.println("\n1. Imprimir Lista");
			System.out.println("2. Sair");
			System.out.print("Digite sua opcao: ");

			String opcao = scanner.nextLine().trim();
			switch (opcao) {
				case "1":
					mostrarMenuOrdenacao(listaOrdenavel, scanner);
					break;
				case "2":
					continuar = false;
					System.out.println("Programa encerrado.");
					break;
				default:
					System.out.println("Opcao invalida!");
			}
		}

		scanner.close();
	}

	private static void mostrarMenuOrdenacao(MinhaListaOrdenavel listaOrdenavel, Scanner scanner) {
		System.out.println("\nEscolha seu modo de ordenacao:");
		System.out.println("1. Alfabetica (A-Z)");
		System.out.println("2. Alfabetica (Z-A)");
		System.out.println("3. Menor Peso");
		System.out.println("4. Maior Peso");
		System.out.println("5. Menor IMC");
		System.out.println("6. Maior IMC");
		System.out.println("7. Homem/Mulher");
		System.out.println("8. Do mais jovem ate o mais velho");
		System.out.println("9. Do mais velho ate o mais jovem");
		System.out.println("10. Data de Nascimento");
		System.out.println("11. CPF");

		System.out.print("Digite sua opcao: ");
		int criterio = Integer.parseInt(scanner.nextLine().trim());

		if (1 > criterio || criterio > 11) {
			System.out.println("Opcao Invalida!");
		} else {

			listaOrdenavel.ordena(criterio);

			System.out.println("\nLista ordenada:");
			listaOrdenavel.mostrarLista();
		}
	}
}
