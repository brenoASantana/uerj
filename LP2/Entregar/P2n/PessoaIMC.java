
public abstract class PessoaIMC extends Pessoa {
	private float peso;
	private float altura;

	public PessoaIMC(String nome, String sobrenome, int dia, int mes, int ano) {
		super(nome, sobrenome, dia, mes, ano);
	}

	public PessoaIMC(String nome, String sobrenome, int dia, int mes, int ano, long numCPF) {
		super(nome, sobrenome, dia, mes, ano, numCPF);
	}

	public float calculaIMC(float peso, float altura) {
		return (float) (peso / Math.pow(altura, 2));
	}

	public abstract String resultIMC();

	@Override
	public String toString() {
		return String.format("Nome: %s %s\nData de Nascimento: %tF\nPeso: %.2f\nAltura: %.2f\n", getNome(),
				getSobrenome(), getDataNascimento(), peso, altura);
	}

	public float getPeso() {
		return peso;
	}

	public void setPeso(float peso) {
		this.peso = peso;
	}

	public float getAltura() {
		return altura;
	}

	public void setAltura(float altura) {
		this.altura = altura;
	}

}
