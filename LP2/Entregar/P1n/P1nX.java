import java.util.Locale;
import java.util.Scanner;

public class P1nX {

	public static void main(String[] args) {

		Locale.setDefault(Locale.US); // Para utilizar formato de PONTO

		Scanner scanner = new Scanner(System.in);
		Pessoa primeiraPessoa = null;
		boolean primeiroSucesso = true;

		// Tratamento dos argumentos da linha de comando
		try {
			if (args.length < 9) {
				primeiroSucesso = false;
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

			validaNome(nome, "Nome");
			validaNome(sobrenome, "Sobrenome");

			validarPeso(peso);
			validarAltura(altura);
			validarData(dia, mes, ano);
			validarCPF(cpfStr);

			long cpf = ValidaCPF.toLong(cpfStr);

			if (genero == 'M') {
				primeiraPessoa = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
			} else if (genero == 'F') {
				primeiraPessoa = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
			} else {
				primeiroSucesso = false;
				throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
			}

			System.out.println("Pessoa criada com sucesso:");
			System.out.println(primeiraPessoa);
		} catch (Exception e) {
			primeiroSucesso = false;
			System.out.println("Erro: " + e.getMessage());
			System.out.println(
					"Uso correto: java P1nX <genero> <nome> <sobrenome> <dia> <mes> <ano> <CPF> <peso> <altura>");
			System.out.println("Gênero: 'M' para Masculino ou 'F' para Feminino.");
		}

		if (primeiroSucesso) {
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

					validaNome(nome, "Nome");
					validaNome(sobrenome, "Sobrenome");

					System.out.println("Digite o dia de nascimento:");
					int dia = Integer.parseInt(scanner.nextLine().trim());

					System.out.println("Escreva o mês de nascimento:");
					int mes = ValidaData.convertMes(scanner.nextLine().trim().toLowerCase());

					System.out.println("Digite o ano de nascimento:");
					int ano = Integer.parseInt(scanner.nextLine().trim());

					validarData(dia, mes, ano);

					System.out.println("Digite o CPF:");
					String cpfStr = ValidaCPF.convertCPF(scanner.nextLine().trim());

					validarCPF(cpfStr);
					long cpf = ValidaCPF.toLong(cpfStr);

					System.out.println("Digite o peso (kg):");
					float peso = Float.parseFloat(scanner.nextLine().trim());

					validarPeso(peso);

					System.out.println("Digite a altura (m):");
					float altura = Float.parseFloat(scanner.nextLine().trim());

					validarAltura(altura);

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
			System.out.println("\nInformações inseridas:");
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

	private static void validaNome(String valor, String campo) throws IllegalArgumentException {
		if (valor.contains("0") || valor.contains("1") || valor.contains("2") || valor.contains("3")
				|| valor.contains("4") || valor.contains("5") || valor.contains("6") || valor.contains("7")
				|| valor.contains("8") || valor.contains("9")) {
			throw new IllegalArgumentException(campo + " inválido. Não deve conter números.");
		}
	}

	private static void validarPeso(float peso) throws IllegalArgumentException {
		if (peso < 1 || peso > 635) {
			throw new IllegalArgumentException("Peso inválido. Insira um peso possível.");
		}
	}

	private static void validarAltura(float altura) throws IllegalArgumentException {
		if (altura < 0.30 || altura > 2.38) {
			throw new IllegalArgumentException("Altura inválida. Insira uma altura possível.");
		}
	}

	private static void validarData(int dia, int mes, int ano) throws IllegalArgumentException {
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
	}

	private static void validarCPF(String cpfStr) throws IllegalArgumentException {
		if (!ValidaCPF.isCPF(cpfStr)) {
			throw new IllegalArgumentException(
					"CPF inválido! Certifique-se de que o CPF inserido é válido e utilize um dos formatos aceitos: 12345678901, 123.456.789-01 ou 123.456.789/01.");
		}
	}
}
