import java.util.Calendar;
import java.util.GregorianCalendar;

public class PessoaOld {
	private static int contador = 0;
	private String nome;
	private String sobreNome;
	private GregorianCalendar dataNasc;
	private long numCPF;
	private float peso;
	private float altura;

	public PessoaOld(String nome, String sobreNome, int dia, int mes, int ano) {
		this(nome, sobreNome, dia, mes, ano, 0, 0.0f, 0.0f);
	}

	public PessoaOld(String nome, String sobreNome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		if (nome == null || sobreNome == null) {
			throw new NullPointerException("Nome e sobrenome não podem ser nulos.");
		}
		this.nome = nome;
		this.sobreNome = sobreNome;
		try {
			this.dataNasc = new GregorianCalendar(ano, mes - 1, dia);
		} catch (IllegalArgumentException e) {
			throw new IllegalArgumentException("Data de nascimento inválida.", e);
		}
		this.numCPF = numCPF;
		this.peso = peso;
		this.altura = altura;
		contador++;
	}

	public static int numPessoas() {
		return contador;
	}

	@Override
	public String toString() {
		return "Nome: " + nome + " " + sobreNome + ", CPF: " + numCPF + ", Data de Nascimento: " + dataNasc.getTime();
	}
}
