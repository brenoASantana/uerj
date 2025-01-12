package lp2g04.biblioteca;

import java.util.GregorianCalendar;

public class Pessoa {
	private String nome;
	private String sobrenome;
	private GregorianCalendar dataNascimento;
	private String cpf;
	private float peso;
	private float altura;
	private static int quantInstancia = 0;

	public Pessoa(String nome, String sobrenome, int dia, int mes, int ano) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
		quantInstancia++;
	}

	public Pessoa(String nome, String sobrenome, int dia, int mes, int ano, String cpf, float peso, float altura) {
		this.nome = nome;
		this.sobrenome = sobrenome;
		this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
		this.cpf = cpf;
		this.peso = peso;
		this.altura = altura;
		quantInstancia++;
	}

	// Construtor facilitado para uso em bibliotecas
	public Pessoa(String nome, String cpf) {
		this.nome = nome;
		this.cpf = cpf;
	}

	public static int numPessoas() {
		return quantInstancia;
	}

	public String toString() {
		return String.format("Nome: %s, Data de Nascimento: %tF, Peso: %.2f, Altura: %.2f, CPF: %s", nome,
				dataNascimento, peso, altura, cpf);
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

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

}
