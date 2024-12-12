import java.time.LocalDate;
import java.time.Period;

public class Homem extends Pessoa {
	private LocalDate dataNascimento;

	public Homem(String nome, String sobrenome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		super(nome, sobrenome, dia, mes, ano, numCPF, peso, altura);
		if (ano == 0) {
			throw new IllegalArgumentException("Ano de nascimento inválido.");
		}
		if (mes == 0) {
			throw new IllegalArgumentException("Mês de nascimento inválido.");
		}
		if (dia == 0) {
			throw new IllegalArgumentException("Dia de nascimento inválido.");
		}
		this.dataNascimento = LocalDate.of(ano, mes, dia);
	}

	@Override
	public String toString() {
		if (dataNascimento == null) {
			throw new NullPointerException("Data de nascimento nula.");
		}
		return super.toString() + ", Gênero: Homem, Idade: " + calcularIdade();
	}

	private int calcularIdade() {
		if (dataNascimento == null) {
			throw new NullPointerException("Data de nascimento nula.");
		}
		return Period.between(this.dataNascimento, LocalDate.now()).getYears();
	}
}
