import java.time.LocalDate;

public class ExP1TesteX {
	public static void main(String[] args) {
		int numeroPessoas = Integer.parseInt(args[0]);
		Pessoa[] pessoas = new Pessoa[numeroPessoas];

		try {
			// Criando pessoas com vários construtores
			pessoas[0] = new Pessoa("Ana", "Silva", LocalDate.of(1985, 5, 10), 55, 1.65, 'F');
			pessoas[1] = new Pessoa("Carlos", "Silva", LocalDate.of(1983, 3, 22), 80, 1.8, 'M');
			pessoas[2] = new Pessoa("João");

			// Definindo relações (pai e mãe)
			if (pessoas[1] != null && pessoas[0] != null) {
				pessoas[2].setPai(pessoas[1]);
				pessoas[2].setMae(pessoas[0]);
			}

			// Exercitando métodos
			for (Pessoa pessoa : pessoas) {
				if (pessoa != null) {
					System.out.println(pessoa.toString());
				}
			}

			// Exibindo a quantidade de instâncias criadas
			System.out.println("Total de pessoas criadas: " + Pessoa.getContadorInstancias());
		} catch (NullPointerException npe) {
			System.err.println("Erro: " + npe.getMessage());
		} catch (Exception e) {
			System.err.println("Erro: " + e.getMessage());
		}
	}
}
