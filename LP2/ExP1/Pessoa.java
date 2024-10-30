import java.time.LocalDate;
import java.time.Period;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private LocalDate dataNascimento;
	private double peso;
	private double altura;
	private char genero;
	private Pessoa pai;
	private Pessoa mae;
	private String status;
	private static int contadorInstancias = 0;

	// Construtores
	public Pessoa() {
		contadorInstancias++;
	}

	public Pessoa(String nome) {
		this.nome = nome;
		contadorInstancias++;
	}

	public Pessoa(String nome, String sobrenome, LocalDate dataNascimento, double peso, double altura, char genero) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		setDataNascimento(dataNascimento);
		setPeso(peso);
		setAltura(altura);
		this.genero = genero;
		contadorInstancias++;
	}

	// Getters e Setters com verificações
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getSobrenome() {
		return sobrenome;
	}

	public void setSobrenome(String sobrenome) {
		this.sobrenome = sobrenome;
	}

	public LocalDate getDataNascimento() {
		return dataNascimento;
	}

	public void setDataNascimento(LocalDate dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public double getPeso() {
		return peso;
	}

	public void setPeso(double peso) {
		this.peso = (peso < 2 || peso > 300) ? 70 : peso; // Valor padrão caso seja inválido
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura) {
		this.altura = (altura < 0.5 || altura > 2.5) ? 1.7 : altura; // Valor padrão caso seja inválido
	}

	public char getGenero() {
		return genero;
	}

	public void setGenero(char genero) {
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

	public String getStatus() {
		return status;
	}

	public void setStatus(String status) {
		this.status = status;
	}

	// Método para contar instâncias
	public static int getContadorInstancias() {
		return contadorInstancias;
	}

	// Método privado para calcular a idade
	private int calcularIdade() {
		return Period.between(this.dataNascimento, LocalDate.now()).getYears();
	}

	// Método toString
	@Override
	public String toString() {
		return String.format("Nome: %s %s, Idade: %d, Peso: %.2f, Altura: %.2f, Gênero: %c, Status: %s", nome,
				sobrenome, calcularIdade(), peso, altura, genero, status);
	}
}
