import java.time.LocalDate;
import java.time.Period;

public class Homem extends Pessoa {
	private LocalDate dataNascimento;

	public Homem(String nome, String sobrenome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		super(nome, sobrenome, dia, mes, ano, numCPF, peso, altura);
		this.dataNascimento = LocalDate.of(ano, mes, dia);
	}

	@Override
	public String toString() {
		return super.toString() + ", Gênero: Homem, Idade: " + calcularIdade();
	}

	private int calcularIdade() {
		return Period.between(this.dataNascimento, LocalDate.now()).getYears();
	}
}