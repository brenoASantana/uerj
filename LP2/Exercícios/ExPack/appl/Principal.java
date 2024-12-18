public class Principal {
	public static void main(String[] args) {
		String nome1, nome2;
		// cria um objeto Calc para usar ...
		int soma;
		double div;

		// testa o número de argumentos

		// vê qual a operação

		// faz a chamada para executar a operação

		// trata as esceções

		/// completar

		if (args[0].equals("soma")) {
			nome1 = args[1];
			nome2 = args[2];
			soma = objeto.soma(nome1, nome2);
			System.out.println("Soma = " + soma);
		} else if (args[0].equals("div")) {
			nome1 = args[1];
			nome2 = args[2];
			div = objeto.div(nome1, nome2);
			System.out.println("Divisao = " + div);
		} else
			// ou completa, ou deixa assim ...
			System.out.println("Operacao matematica invalida.");
	}

}
