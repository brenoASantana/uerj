import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Locale;
import java.util.Scanner;

public class ExP1TesteX {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		scanner.useLocale(Locale.US); // Define o scanner para aceitar ponto como separador decimal

		int numeroPessoa = Integer.parseInt(args[0]);
		Pessoa[] pessoa = new Pessoa[numeroPessoa];

		// Criação das instâncias de Pessoa
		for (int i = 0; i < numeroPessoa; i++) {
			System.out.printf(
					"Deseja informar quais dados da Pessoa nº %d?\n 1 - Todos\n 2 - Somente primeiro nome \n 3 - Nenhum\n",
					i + 1);
			int op = scanner.nextInt();
			scanner.nextLine(); // Consumir nova linha

			String nome = null, sobrenome = null, status = null;
			LocalDate dataNascimento = null;
			double peso = 0.0, altura = 0.0;
			Genero genero = null;
			Pessoa pai = null, mae = null;

			switch (op) {
			case 1:
				System.out.print("Informe o primeiro nome: ");
				nome = scanner.nextLine();

				System.out.print("Informe o sobrenome: ");
				sobrenome = scanner.nextLine();

				System.out.print("Informe a data de nascimento (dd/MM/yyyy): ");
				String dataStr = scanner.nextLine();
				dataNascimento = LocalDate.parse(dataStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));

				System.out.print("Informe o peso: ");
				peso = scanner.nextDouble();

				System.out.print("Informe a altura: ");
				altura = scanner.nextDouble();
				scanner.nextLine(); // Consumir nova linha

				genero = selecionarGenero(scanner);

				System.out.print("Informe o nome do pai: ");
				pai = new Pessoa(scanner.nextLine());

				System.out.print("Informe o nome da mãe: ");
				mae = new Pessoa(scanner.nextLine());

				System.out.print("Informe o status: ");
				status = scanner.nextLine();

				pessoa[i] = new Pessoa(nome, sobrenome, dataNascimento, peso, altura, genero, pai, mae, status);
				break;
			case 2:
				System.out.print("Informe o primeiro nome: ");
				nome = scanner.nextLine();

				pessoa[i] = new Pessoa(nome);
				break;
			case 3:
				pessoa[i] = new Pessoa();
				break;
			default:
				System.out.println("Opção inválida!");
				i--; // Repetir a criação para o mesmo índice
				break;
			}
		}

		// Menu para editar dados de pessoas criadas
		int op = 0;
		do {
			System.out.println("\nDeseja alterar algum dado de alguma pessoa?\n 1 - Sim\n 2 - Não");
			op = scanner.nextInt();
			scanner.nextLine(); // Consumir nova linha

			if (op == 1) {
				System.out.print("Informe o número da pessoa a editar (1 a " + numeroPessoa + "): ");
				int numPessoaEdit = scanner.nextInt() - 1;
				scanner.nextLine(); // Consumir nova linha

				if (numPessoaEdit >= 0 && numPessoaEdit < numeroPessoa) {
					editarPessoa(scanner, pessoa[numPessoaEdit]);
				} else {
					System.out.println("Número inválido.");
				}
			} else if (op != 2) {
				System.out.println("Opção inválida!");
			}
		} while (op != 2);

		// Exibição das informações das pessoas
		System.out.println("Informações das pessoas criadas:\n");
		for (Pessoa p : pessoa) {
			System.out.println(p.toString());
			System.out.println("\n------------------------------------------------\n");
		}
		scanner.close();
	}

	private static Genero selecionarGenero(Scanner scanner) {
		Genero genero = null;
		do {
			System.out.print("Informe o gênero:\n 1 - Masculino\n 2 - Feminino\n");
			int genOp = scanner.nextInt();
			scanner.nextLine(); // Consumir nova linha
			if (genOp == 1) {
				genero = Genero.Masculino;
			} else if (genOp == 2) {
				genero = Genero.Feminino;
			} else {
				System.out.println("Opção inválida! Tente novamente.");
			}
		} while (genero == null);
		return genero;
	}

	private static void editarPessoa(Scanner scanner, Pessoa pessoa) {
		int opEdit;
		do {
			System.out.println("Selecione o dado para editar:\n"
					+ " 1 - Nome\n 2 - Sobrenome\n 3 - Data de Nascimento\n 4 - Peso\n 5 - Altura\n 6 - Gênero\n"
					+ " 7 - Pai\n 8 - Mãe\n 9 - Status\n 10 - Sair");
			opEdit = scanner.nextInt();
			scanner.nextLine(); // Consumir nova linha

			switch (opEdit) {
			case 1:
				System.out.print("Novo nome: ");
				pessoa.setNome(scanner.nextLine());
				break;
			case 2:
				System.out.print("Novo sobrenome: ");
				pessoa.setSobrenome(scanner.nextLine());
				break;
			case 3:
				System.out.print("Nova data de nascimento (dd/MM/yyyy): ");
				String dataStr = scanner.nextLine();
				pessoa.setDataNascimento(LocalDate.parse(dataStr, DateTimeFormatter.ofPattern("dd/MM/yyyy")));
				break;
			case 4:
				System.out.print("Novo peso: ");
				pessoa.setPeso(scanner.nextDouble());
				scanner.nextLine(); // Consumir nova linha
				break;
			case 5:
				System.out.print("Nova altura: ");
				pessoa.setAltura(scanner.nextDouble());
				scanner.nextLine(); // Consumir nova linha
				break;
			case 6:
				pessoa.setGenero(selecionarGenero(scanner));
				break;
			case 7:
				System.out.print("Novo nome do pai: ");
				pessoa.setPai(new Pessoa(scanner.nextLine()));
				break;
			case 8:
				System.out.print("Novo nome da mãe: ");
				pessoa.setMae(new Pessoa(scanner.nextLine()));
				break;
			case 9:
				System.out.print("Novo status: ");
				pessoa.setStatus(scanner.nextLine());
				break;
			case 10:
				System.out.println("Saindo do modo de edição.");
				break;
			default:
				System.out.println("Opção inválida!");
				break;
			}
		} while (opEdit != 10);
	}
}
