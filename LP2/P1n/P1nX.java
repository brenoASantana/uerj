import java.util.Scanner;
import java.util.InputMismatchException;

public class P1nX {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		try {
			// Validação de argumentos de linha de comando
			if (args.length != 9) {
				System.out.println(
						"Erro na entrada de dados. Sintaxe correta: java P1nX <genero> <nome> <sobrenome> <dia> <mes> <ano> <CPF> <peso> <altura>");
				return;
			}

			String genero = args[0];
			String nome = args[1];
			String sobreNome = args[2];
			int dia = Integer.parseInt(args[3]);
			int mes = Integer.parseInt(args[4]);
			int ano = Integer.parseInt(args[5]);
			String cpf = args[6];
			float peso = Float.parseFloat(args[7]);
			float altura = Float.parseFloat(args[8]);

			// Verificação e criação do objeto
			Pessoa pessoa;
			if ("homem".equalsIgnoreCase(genero)) {
				pessoa = new Homem(nome, sobreNome, dia, mes, ano, ValidaCPF.toLong(cpf), peso, altura);
			} else if ("mulher".equalsIgnoreCase(genero)) {
				pessoa = new Mulher(nome, sobreNome, dia, mes, ano, ValidaCPF.toLong(cpf), peso, altura);
			} else {
				System.out.println("Gênero inválido.");
				return;
			}
			System.out.println(pessoa);

			// Adição de mais objetos
			System.out.print("Quantos elementos adicionais você quer criar? ");
			int n;
			try {
				n = scanner.nextInt();
			} catch (InputMismatchException e) {
				System.out.println("Entrada inválida. Esperado um número inteiro.");
				return;
			}
			scanner.nextLine(); // limpar o buffer

			Pessoa[] pessoas = new Pessoa[n];
			for (int i = 0; i < n; i++) {
				System.out.print("Digite o gênero (homem/mulher): ");
				genero = scanner.nextLine();

				System.out.print("Digite o nome: ");
				nome = scanner.nextLine();

				System.out.print("Digite o sobrenome: ");
				sobreNome = scanner.nextLine();

				System.out.print("Digite o dia de nascimento: ");
				try {
					dia = scanner.nextInt();
				} catch (InputMismatchException e) {
					System.out.println("Entrada inválida. Esperado um número inteiro.");
					scanner.nextLine(); // limpar o buffer
					i--;
					continue;
				}

				System.out.print("Digite o mês de nascimento: ");
				try {
					mes = scanner.nextInt();
				} catch (InputMismatchException e) {
					System.out.println("Entrada inválida. Esperado um número inteiro.");
					scanner.nextLine(); // limpar o buffer
					i--;
					continue;
				}

				System.out.print("Digite o ano de nascimento: ");
				try {
					ano = scanner.nextInt();
				} catch (InputMismatchException e) {
					System.out.println("Entrada inválida. Esperado um número inteiro.");
					scanner.nextLine(); // limpar o buffer
					i--;
					continue;
				}

				System.out.print("Digite o CPF: ");
				cpf = scanner.next();

				System.out.print("Digite o peso: ");
				try {
					peso = scanner.nextFloat();
				} catch (InputMismatchException e) {
					System.out.println("Entrada inválida. Esperado um número decimal.");
					scanner.nextLine(); // limpar o buffer
					i--;
					continue;
				}

				System.out.print("Digite a altura: ");
				try {
					altura = scanner.nextFloat();
				} catch (InputMismatchException e) {
					System.out.println("Entrada inválida. Esperado um número decimal.");
					scanner.nextLine(); // limpar o buffer
					i--;
					continue;
				}
				scanner.nextLine(); // limpar o buffer

				if ("homem".equalsIgnoreCase(genero)) {
					pessoas[i] = new Homem(nome, sobreNome, dia, mes, ano, ValidaCPF.toLong(cpf), peso, altura);
				} else if ("mulher".equalsIgnoreCase(genero)) {
					pessoas[i] = new Mulher(nome, sobreNome, dia, mes, ano, ValidaCPF.toLong(cpf), peso, altura);
				} else {
					System.out.println("Gênero inválido.");
					i--; // repetir para entrada inválida
				}
			}

			// Exibir todos os objetos e contar
			int homens = 0, mulheres = 0;
			for (Pessoa p : pessoas) {
				if (p != null) {
					System.out.println(p);
					if (p instanceof Homem)
						homens++;
					if (p instanceof Mulher)
						mulheres++;
				}
			}
			System.out.println("Total de homens: " + homens);
			System.out.println("Total de mulheres: " + mulheres);

		} catch (Exception e) {
			System.out.println("Erro: " + e.getMessage());
		} finally {
			scanner.close();
		}
	}
}
