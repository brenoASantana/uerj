import java.time.LocalDate;
import java.time.Period;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private LocalDate dataNascimento;
	private double peso;
	private double altura;
	private Genero genero;
	private Pessoa pai;
	private Pessoa mae;
	private static int quantInstancia = 0; // Quantidade de instancias da classe Pessoa foram criadas
	private String status;

	public Pessoa(String nome) {
		this.nome = nome;
		quantInstancia++;
	}

	public Pessoa(String nome, String sobrenome, LocalDate dataNascimento, double peso, double altura, Genero genero,
			Pessoa pai, Pessoa mae, String status) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = dataNascimento;
		this.peso = peso;
		this.altura = altura;
		this.genero = genero;
		this.pai = pai;
		this.mae = mae;
		this.status = status;
		quantInstancia++;
	}

	public Pessoa() {
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

	public LocalDate getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(LocalDate dataNascimento) {
		if (dataNascimento != null) {
			this.dataNascimento = dataNascimento;
		}
	}

	public double getPeso() {
		return peso;
	}

	public void setPeso(double peso) {
		
		if (peso < 2) // Se o peso for menor que 2 quilos, o valor padrão será 2 quilos
			peso = 2;
		else if (peso > 300) // Se o peso for maior que 300 quilos, o valor padrão será 300 quilos
			peso = 300;
		this.peso = peso;
		
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura) {

		if (altura < 0.5) // Se a altura for menor que 0.5 metros, o valor padrão será 0.5 metros
			altura = 0.5;
		else if (altura > 2.5) // Se a altura for maior que 2.5 metros, o valor padrão será 2.5 metros
			altura = 2.5;
		this.altura = altura;

	}

	public Genero getGenero() {
		return genero;
	}

	public void setGenero(Genero genero) {
		this.genero = genero;
	}

	public Pessoa getPai() {
		return pai;
	}

	public void setPai(Pessoa pai) {
		this.pai = pai;
	}

	public Pessoa getMae() {
		return mae;
	}

	public void setMae(Pessoa mae) {
		this.mae = mae;
	}

	public static int getQuantInstancia() {
		return quantInstancia;
	}

	public String getStatus() {
		return status == null ? "" : status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	@Override
	public String toString() {
		return String.format("Nome: %s %s, Idade: %d, Peso: %.2f, Altura: %.2f, Gênero: %s, Status: %s", getNome(),
				getSobrenome(), calcularIdade(), getPeso(), getAltura(), getGenero(), getStatus());
	}

	private int calcularIdade() {
		if (this.dataNascimento == null) {
			return 0;
		}
		int idade = Period.between(this.dataNascimento, LocalDate.now()).getYears();

		if (idade < 0) // Se a idade for menor que 0 anos, o valor padrão será 0 anos
			idade = 0;
		else if (idade > 120) // Se a idade for maior que 120 anos, o valor padrão será 120 anos
			idade = 120;
		return idade;

	}
}