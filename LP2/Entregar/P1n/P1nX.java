import java.util.Scanner;

public class P1nX {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		Pessoa primeiraPessoa = null;

		// Tratamento dos argumentos da linha de comando
		try {
			if (args.length < 9) {	
				throw new IllegalArgumentException("Número insuficiente de argumentos.");
			}

			char genero = args[0].trim().toUpperCase().charAt(0);
			String nome = args[1].trim();
			String sobrenome = args[2].trim();
			int dia = Integer.parseInt(args[3].trim());
			int mes = Integer.parseInt(args[4].trim());
			int ano = Integer.parseInt(args[5].trim());
			String cpfStr = args[6].trim();
			float peso = Float.parseFloat(args[7].trim());
			float altura = Float.parseFloat(args[8].trim());

			if (!ValidaData.isDataValida(dia, mes, ano)) {
				throw new IllegalArgumentException("Data de nascimento inválida.");
			}

			if (!ValidaCPF.isCPF(cpfStr)) {
				throw new IllegalArgumentException("CPF inválido.");
			}

			long cpf = ValidaCPF.toLong(cpfStr);

			if (genero == 'M') {
				primeiraPessoa = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
			} else if (genero == 'F') {
				primeiraPessoa = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
			} else {
				throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
			}

			System.out.println("Pessoa criada com sucesso:");
			System.out.println(primeiraPessoa);
		} catch (Exception e) {
			System.out.println("Erro: " + e.getMessage());
			System.out.println(
					"Uso correto: java P1nX <genero> <nome> <sobrenome> <dia> <mes> <ano> <CPF> <peso> <altura>");
			System.out.println("Gênero: 'M' para Masculino ou 'F' para Feminino.");
		}

		// Entrada de dados para o array
		System.out.println("\nQuantos elementos adicionais você deseja criar?");
		int numElementos = 0;
		while (true) {
			try {
				numElementos = Integer.parseInt(scanner.nextLine().trim());
				if (numElementos < 0) {
					throw new IllegalArgumentException("O número de elementos não pode ser negativo.");
				}
				break;
			} catch (Exception e) {
				System.out.println("Erro: " + e.getMessage() + " Digite novamente.");
			}
		}

		Pessoa[] pessoas = new Pessoa[numElementos];
		int index = 0;

		while (index < numElementos) {
			try {
				System.out.println("Digite o nome (ou pressione ENTER para parar):");
				String nome = scanner.nextLine().trim();
				if (nome.isEmpty()) {
					break;
				}

				System.out.println("Digite o sobrenome:");
				String sobrenome = scanner.nextLine().trim();

				System.out.println("Digite o dia de nascimento:");
				int dia = Integer.parseInt(scanner.nextLine().trim());

				System.out.println("Digite o mês de nascimento (número entre 1 e 12):");
				int mes = Integer.parseInt(scanner.nextLine().trim());

				System.out.println("Digite o ano de nascimento:");
				int ano = Integer.parseInt(scanner.nextLine().trim());

				if (!ValidaData.isDataValida(dia, mes, ano)) {
					throw new IllegalArgumentException("Data de nascimento inválida.");
				}

				System.out.println("Digite o CPF (apenas números):");
				String cpfStr = scanner.nextLine().trim();
				if (!ValidaCPF.isCPF(cpfStr)) {
					throw new IllegalArgumentException("CPF inválido.");
				}
				long cpf = ValidaCPF.toLong(cpfStr);

				System.out.println("Digite o peso (kg):");
				float peso = Float.parseFloat(scanner.nextLine().trim());

				System.out.println("Digite a altura (m):");
				float altura = Float.parseFloat(scanner.nextLine().trim());

				System.out.println("Digite o gênero (M para masculino, F para feminino):");
				char genero = scanner.nextLine().trim().toUpperCase().charAt(0);

				if (genero == 'M') {
					pessoas[index] = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
				} else if (genero == 'F') {
					pessoas[index] = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
				} else {
					throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
				}

				System.out.println("Pessoa adicionada com sucesso!");
				index++;
			} catch (Exception e) {
				System.out.println("Erro: " + e.getMessage());
				System.out.println("Por favor, tente novamente.");
			}
		}

		// Exibindo os dados das pessoas
		System.out.println("\nPessoas cadastradas:");
		for (Pessoa pessoa : pessoas) {
			if (pessoa != null) {
				System.out.println(pessoa);
			}
		}

		// Contagem de Homens e Mulheres
		int totalHomens = 0;
		int totalMulheres = 0;

		for (Pessoa pessoa : pessoas) {
			if (pessoa instanceof Homem) {
				totalHomens++;
			} else if (pessoa instanceof Mulher) {
				totalMulheres++;
			}
		}

		System.out.println("\nResumo:");
		System.out.println("Total de pessoas: " + Pessoa.numPessoas());
		System.out.println("Total de homens: " + totalHomens);
		System.out.println("Total de mulheres: " + totalMulheres);

		scanner.close();
	}
}
