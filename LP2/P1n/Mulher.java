public class Mulher extends Pessoa {

	public Mulher(String nome, String sobreNome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		super(nome, sobreNome, dia, mes, ano, numCPF, peso, altura);
	}

	@Override
	public String toString() {
		return super.toString() + ", Gênero: Mulher";
	}
}