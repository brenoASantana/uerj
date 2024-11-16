import java.util.Locale;
import java.util.Scanner;

public class P1nX {

	public static void main(String[] args) {

		Locale.setDefault(Locale.US); // Para utilizar formato de PONTO

		Scanner scanner = new Scanner(System.in);
		Pessoa primeiraPessoa = null;
		boolean falhou = false;

		// Tratamento dos argumentos da linha de comando
		try {
			if (args.length < 9) {
				falhou = true;
				throw new IllegalArgumentException("Informações faltando. Por favor, preencha todos os dados.");
			}

			char genero = args[0].trim().toUpperCase().charAt(0);
			String nome = args[1].trim();

			String sobrenome = args[2].trim();

			int dia = Integer.parseInt(args[3].trim());
			int mes = Integer.parseInt(args[4].trim());
			int ano = Integer.parseInt(args[5].trim());
			String cpfStr = ValidaCPF.convertCPF(args[6].trim());
			float peso = Float.parseFloat(args[7].trim());
			float altura = Float.parseFloat(args[8].trim());

			if (nome.contains("0") || nome.contains("1") || nome.contains("2") || nome.contains("3")
					|| nome.contains("4") || nome.contains("5") || nome.contains("6") || nome.contains("7")
					|| nome.contains("8") || nome.contains("9"))
				throw new IllegalArgumentException("Nome inválido. O nome não deve conter números.");

			if (sobrenome.contains("0") || sobrenome.contains("1") || sobrenome.contains("2") || sobrenome.contains("3")
					|| sobrenome.contains("4") || sobrenome.contains("5") || sobrenome.contains("6")
					|| sobrenome.contains("7") || sobrenome.contains("8") || sobrenome.contains("9"))
				throw new IllegalArgumentException("Sobrenome inválido. O sobrenome não deve conter números.");

			if (peso < 1 || peso > 635) {
				throw new IllegalArgumentException("Peso inválido. Insira um peso possível.");
			}

			if (altura < 0.30 || altura > 2.38) {
				throw new IllegalArgumentException("Altura inválida. Insira uma altura possível.");
			}

			if (!ValidaData.isDia(dia)) {
				throw new IllegalArgumentException("Dia inválido. Insira um dia existente.");
			}

			if (!ValidaData.isMes(mes)) {
				throw new IllegalArgumentException("Mês inválido. Insira um mês existente.");
			}

			if (!ValidaData.isAno(ano)) {
				throw new IllegalArgumentException("Ano inválido. Insira um ano existente.");
			}

			if (!ValidaData.isDataValida(dia, mes, ano)) {
				throw new IllegalArgumentException("Data de nascimento inválida.");
			}

			if (!ValidaCPF.isCPF(cpfStr)) {
				throw new IllegalArgumentException(
						"CPF inválido! Certifique-se de que o CPF inserido existe e utilize um dos formatos aceitos: 12345678901, 123.456.789-01 ou 123.456.789/01.");
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
		if (!falhou) {
			// Entrada de dados para o array
			System.out.println("\nQuantas pessoas a mais deseja inserir?");
			int numElementos = 0;
			while (true) {
				try {
					numElementos = Integer.parseInt(scanner.nextLine().trim());
					if (numElementos < 0) {
						throw new IllegalArgumentException("Quantidade inválida! Insira um número positivo.");
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

					if (nome.contains("0") || nome.contains("1") || nome.contains("2") || nome.contains("3")
							|| nome.contains("4") || nome.contains("5") || nome.contains("6") || nome.contains("7")
							|| nome.contains("8") || nome.contains("9"))
						throw new IllegalArgumentException("Nome inválido. O nome não deve conter números.");

					if (sobrenome.contains("0") || sobrenome.contains("1") || sobrenome.contains("2")
							|| sobrenome.contains("3") || sobrenome.contains("4") || sobrenome.contains("5")
							|| sobrenome.contains("6") || sobrenome.contains("7") || sobrenome.contains("8")
							|| sobrenome.contains("9"))
						throw new IllegalArgumentException("Sobrenome inválido. O sobrenome não deve conter números.");

					System.out.println("Digite o dia de nascimento:");
					int dia = Integer.parseInt(scanner.nextLine().trim());

					if (!ValidaData.isDia(dia)) {
						throw new IllegalArgumentException("Dia inválido. Insira um dia existente.");
					}

					System.out.println("Escreva o mês de nascimento:");
					int mes = ValidaData.convertMes(scanner.nextLine().trim().toLowerCase());

					if (!ValidaData.isMes(mes)) {
						throw new IllegalArgumentException("Mês inválido. Insira um mês existente.");
					}

					System.out.println("Digite o ano de nascimento:");
					int ano = Integer.parseInt(scanner.nextLine().trim());

					if (!ValidaData.isAno(ano)) {
						throw new IllegalArgumentException("Ano inválido. Insira um ano existente.");
					}

					if (!ValidaData.isDataValida(dia, mes, ano)) {
						throw new IllegalArgumentException("Data de nascimento inválida.");
					}

					System.out.println("Digite o CPF:");
					String cpfStr = ValidaCPF.convertCPF(scanner.nextLine().trim());

					if (!ValidaCPF.isCPF(cpfStr)) {
						throw new IllegalArgumentException(
								"CPF inválido! Certifique-se de que o CPF inserido é válido e utilize um dos formatos aceitos: 12345678901, 123.456.789-01 ou 123.456.789/01.");
					}
					long cpf = ValidaCPF.toLong(cpfStr);

					System.out.println("Digite o peso (kg):");
					float peso = Float.parseFloat(scanner.nextLine().trim());

					if (peso < 1 || peso > 635) {
						throw new IllegalArgumentException("Peso inválido. Insira um peso possível.");
					}

					System.out.println("Digite a altura (m):");
					float altura = Float.parseFloat(scanner.nextLine().trim());

					if (altura < 0.30 || altura > 2.38) {
						throw new IllegalArgumentException("Altura inválida. Insira uma altura possível.");
					}

					System.out.println("Esta pessoa é do gênero feminino ou masculino (f ou m)?");
					char genero = scanner.nextLine().trim().toUpperCase().charAt(0);

					if (genero == 'M') {
						pessoas[index] = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
					} else if (genero == 'F') {
						pessoas[index] = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
					} else {
						throw new IllegalArgumentException(
								"Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
					}

					System.out.println("Pessoa adicionada com sucesso!");

					index++;
				} catch (Exception e) {
					System.out.println("Erro: " + e.getMessage());
					System.out.println("Por favor, tente novamente.");
				}

			}

			System.out.println("-----------------------------------------------------------");
			// Exibindo os dados das pessoas
			System.out.println("\nInformações inseridas::");
			System.out.println(primeiraPessoa);
			for (Pessoa pessoa : pessoas) {
				if (pessoa != null) {
					System.out.println(pessoa);
				}
			}

			// Contagem de Homens e Mulheres
			int totalHomens = 0;
			int totalMulheres = 0;

			if (primeiraPessoa instanceof Homem)
				totalHomens++;
			else if (primeiraPessoa instanceof Mulher)
				totalMulheres++;

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

		}
		scanner.close();
		System.out.println("Programa encerrado.");

	}

}
