public class HomemOld extends Pessoa {

	public HomemOld(String nome, String sobreNome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		super(nome, sobreNome, dia, mes, ano, numCPF, peso, altura);
	}

	@Override
	public String toString() {
		if (super.toString() == null) {
			return "Gênero: HomemOld";
		}
		return super.toString() + ", Gênero: HomemOld";
	}
}
