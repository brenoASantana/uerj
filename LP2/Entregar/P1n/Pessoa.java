import java.util.GregorianCalendar;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private GregorianCalendar dataNascimento;
	private long numCPF;
	private float peso;
	private float altura;
	private static int quantInstancia = 0;

	public Pessoa(String nome, String sobrenome, int dia, int mes, int ano) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
		quantInstancia++;
	}

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

	public String toString() {
		return String.format("Nome: %s %s, Data de Nascimento: %tF, Peso: %.2f, Altura: %.2f, CPF: %011d", nome,
				sobrenome, dataNascimento, peso, altura, numCPF);
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if (nome != null && nome.length() > 0) {
			this.nome = nome;
		}
	}

	public String getSobrenome() {
		return sobrenome;
	}

	public void setSobrenome(String sobrenome) {
		if (sobrenome != null && sobrenome.length() > 0) {
			this.sobrenome = sobrenome;
		}
	}

	public GregorianCalendar getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(GregorianCalendar dataNascimento) {
		if (dataNascimento != null) {
			this.dataNascimento = dataNascimento;
		}
	}

	public long getNumCPF() {
		return numCPF;
	}

	public void setNumCPF(long numCPF) {
		if (numCPF != 0) {
			this.numCPF = numCPF;
		}
	}

	public float getPeso() {
		return peso;
	}

	public void setPeso(float peso) {
		if (peso > 0) {
			this.peso = peso;
		}
	}

	public float getAltura() {
		return altura;
	}

	public void setAltura(float altura) {
		if (altura > 0) {
			this.altura = altura;
		}
	}

}
