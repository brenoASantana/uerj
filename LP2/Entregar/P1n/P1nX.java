import java.util.ArrayList;
import java.util.Scanner;

public class P1nX {

	public static void main(String[] args) {
		ArrayList<Pessoa> pessoas = new ArrayList<>();
		Scanner scanner = new Scanner(System.in);
		boolean sucesso = false;
		boolean continuar = true;

		while (!sucesso) {
			try {
				char genero = args[0].trim().toUpperCase().charAt(0);
				String nome = args[1].trim();
				String sobrenome = args[2].trim();
				int dia = Integer.parseInt(args[3].trim());
				int mes = Integer.parseInt(args[4].trim());
				int ano = Integer.parseInt(args[5].trim());

				if (!ValidaData.isDataValida(dia, mes, ano)) {
					throw new IllegalArgumentException("Data de nascimento inválida.");
				}

				String cpfStr = ValidaCPF.convertCPF(args[6].trim());

				if (!ValidaCPF.isCPF(cpfStr)) {
					throw new IllegalArgumentException("CPF inválido.");
				}

				long cpf = ValidaCPF.toLong(cpfStr);

				float peso = Float.parseFloat(args[7].trim());

				float altura = Float.parseFloat(args[8].trim());

				Pessoa pessoa;
				if (genero == 'M') {
					pessoa = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
				} else if (genero == 'F') {
					pessoa = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
				} else {
					throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
				}

				pessoas.add(pessoa);
				System.out.println("Pessoa adicionada com sucesso!");

				System.out.println("Deseja adicionar outra pessoa? (S/N):");
				continuar = scanner.nextLine().trim().equalsIgnoreCase("S");
				
				while(continuar) {
					System.out.println("Digite o nome:");
	                nome = scanner.nextLine().trim();
	                
	                System.out.println("Digite o sobrenome:");
	                sobrenome = scanner.nextLine().trim();
	                
	                System.out.println("Digite o dia de nascimento:");
	                dia = Integer.parseInt(scanner.nextLine().trim());
	                
	                System.out.println("Digite o mês de nascimento (número entre 1 e 12):");
	                mes = Integer.parseInt(scanner.nextLine().trim());
	                
	                System.out.println("Digite o ano de nascimento:");
	                ano = Integer.parseInt(scanner.nextLine().trim());
	                
	                if (!ValidaData.isDataValida(dia, mes, ano)) {
	                    throw new IllegalArgumentException("Data de nascimento inválida.");
	                }
	                
	                System.out.println("Digite o CPF (apenas números):");
	                cpfStr = scanner.nextLine().trim();
	                
	                if (!ValidaCPF.isCPF(cpfStr)) {
	                    throw new IllegalArgumentException("CPF inválido.");
	                }
	                
	                cpf = ValidaCPF.toLong(cpfStr);
	                
	                System.out.println("Digite o peso (kg):");
	                peso = Float.parseFloat(scanner.nextLine().trim());
	                
	                System.out.println("Digite a altura (m):");
	                altura = Float.parseFloat(scanner.nextLine().trim());
	                
	                System.out.println("Digite o gênero (M para masculino, F para feminino):");
	                genero = scanner.nextLine().trim().toUpperCase().charAt(0);
	                
	                if (genero == 'M') {
	                    pessoa = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
	                } else if (genero == 'F') {
	                    pessoa = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
	                } else {
	                    throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
	                }
	                
	                pessoas.add(pessoa);
	                System.out.println("Pessoa adicionada com sucesso!");
	                
	                System.out.println("Deseja adicionar outra pessoa? (S/N):");
	                continuar = scanner.nextLine().trim().equalsIgnoreCase("S");
				}
				
			} catch (Exception e) {
				System.out.println("Erro: " + e.getMessage());
				System.out.println("Por favor, tente novamente.");
			}
		}

		scanner.close();

		// Contagem de Homens e Mulheres
		int totalHomens = 0;
		int totalMulheres = 0;

		for (Pessoa pessoa : pessoas) {
			if (pessoa instanceof Homem) {
				totalHomens++;
			} else if (pessoa instanceof Mulher) {
				totalMulheres++;
			}
			System.out.println(pessoa);
		}

		System.out.println("\nResumo:");
		System.out.println("Total de pessoas: " + Pessoa.numPessoas());
		System.out.println("Total de homens: " + totalHomens);
		System.out.println("Total de mulheres: " + totalMulheres);
	}
}
