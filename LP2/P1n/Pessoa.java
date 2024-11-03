import java.time.LocalDate;
import java.time.Period;
import java.util.GregorianCalendar;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private GregorianCalendar dataNascimento;
	private long numCPF;
	private float peso;
	private float altura;
	private static int quantInstancia = 0; // Quantidade de instancias da classe Pessoa foram criadas

	public Pessoa(String nome, String sobrenome, String diaNasc, String mesNasc, String anoNasc) {
		this.nome = nome;
		this.sobrenome = sobrenome;

		quantInstancia++;
	}

	public Pessoa(String nome, String sobrenome, String diaNasc, String mesNasc, String anoNasc, long numCPF,
			float peso, float altura) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = dataNascimento;
		this.numCPF = numCPF;
		this.peso = peso;
		this.altura = altura;
		quantInstancia++;
	}

	public String getNome() {
		return nome == null ? "" : nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSobrenome() {
		return sobrenome == null ? "" : sobrenome;
	}

	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}

	public GregorianCalendar getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(GregorianCalendar dataNascimento) {
		if (dataNascimento != null) {
			this.dataNascimento = dataNascimento;
		}
	}

	public double getNumCPF() {
		return numCPF;
	}

	public void setNumCPF(String numCPF) {

		if (ValidaCPF.isCPF(numCPF))
			this.numCPF = ValidaCPF.toLong(numCPF);

	}

	public double getPeso() {
		return peso;
	}

	public void setPeso(float peso) {

		if (peso < 2) // Se o peso for menor que 2 quilos, o valor padrão será 2 quilos
			peso = 2;
		else if (peso > 300) // Se o peso for maior que 300 quilos, o valor padrão será 300 quilos
			peso = 300;
		this.peso = peso;

	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(float altura) {

		if (altura < 0.5) // Se a altura for menor que 0.5 metros, o valor padrão será 0.5 metros
			altura = (float) 0.5;
		else if (altura > 2.5) // Se a altura for maior que 2.5 metros, o valor padrão será 2.5 metros
			altura = (float) 2.5;
		this.altura = altura;

	}

	@Override
	public String toString() {
		return String.format("Nome: %s %s, Data de Nascimento: %s, Peso: %.2f, Altura: %.2f, CPF: %s", getNome(),
				getSobrenome(), getDataNascimento(), getPeso(), getAltura(), getNumCPF());
	}

}