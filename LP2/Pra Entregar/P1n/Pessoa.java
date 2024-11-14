import java.util.GregorianCalendar;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private GregorianCalendar dataNascimento;
	private long numCPF;
	private float peso;
	private float altura;
	private static int quantInstancia = 0;

	public Pessoa(String nome, String sobrenome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
		this.numCPF = numCPF;
		this.peso = peso;
		this.altura = altura;
		quantInstancia++;
	}

	public static int numPessoas() {
		return quantInstancia;
	}

	@Override
	public String toString() {
		return String.format("Nome: %s %s, Data de Nascimento: %tF, Peso: %.2f, Altura: %.2f, CPF: %011d",
				nome, sobrenome, dataNascimento, peso, altura, numCPF);
	}
}
