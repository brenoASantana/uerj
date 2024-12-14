import java.util.Locale;
import java.util.Scanner;

public class P2nX {
	public static void main(String[] args) {
		Locale.setDefault(Locale.US); // Usar ponto como separador decimal
		Scanner scanner = new Scanner(System.in);

		// Criar instância de MinhaListaOrdenavel
		MinhaListaOrdenavel listaOrdenavel = new MinhaListaOrdenavel();

		// Adicionar 10 objetos PessoaIMC manualmente
		listaOrdenavel.add(new Homem("Carlos", "Silva", 15, 3, 1990, 80.5f, 1.75f));
		listaOrdenavel.add(new Mulher("Ana", "Oliveira", 20, 7, 1995, 60.0f, 1.65f));
		listaOrdenavel.add(new Homem("João", "Souza", 5, 1, 1985, 85.0f, 1.80f));
		listaOrdenavel.add(new Mulher("Maria", "Costa", 18, 9, 1992, 55.5f, 1.60f));
		listaOrdenavel.add(new Homem("Pedro", "Martins", 10, 12, 1988, 90.0f, 1.85f));
		listaOrdenavel.add(new Mulher("Juliana", "Ferreira", 25, 5, 2000, 58.0f, 1.68f));
		listaOrdenavel.add(new Homem("Lucas", "Ribeiro", 3, 8, 1993, 78.0f, 1.72f));
		listaOrdenavel.add(new Mulher("Carla", "Pereira", 30, 6, 1998, 65.0f, 1.70f));
		listaOrdenavel.add(new Homem("Fernando", "Almeida", 7, 4, 1982, 95.0f, 1.90f));
		listaOrdenavel.add(new Mulher("Fernanda", "Nascimento", 12, 11, 1991, 63.0f, 1.67f));

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
					System.out.println("Opcao invalida!!");
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
		System.out.println("8. Idade");
		System.out.println("9. Data de Nascimento");
		System.out.println("10. CPF");

		System.out.print("Digite sua opcao: ");
		int criterio = Integer.parseInt(scanner.nextLine().trim());

		listaOrdenavel.ordena(criterio);

		System.out.println("\nLista ordenada:");
		listaOrdenavel.mostrarLista();
	}
}
