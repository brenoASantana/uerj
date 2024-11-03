import java.time.LocalDate;
import java.time.Period;

public class Mulher extends Pessoa {

	public Mulher(String nome, String sobrenome, String diaNasc, String mesNasc, String anoNasc) {
		super(nome, sobrenome, diaNasc, mesNasc, anoNasc);
		// TODO Auto-generated constructor stub
	}

	public Mulher(String nome, String sobrenome, String diaNasc, String mesNasc, String anoNasc, long numCPF,
			float peso, float altura) {
		super(nome, sobrenome, diaNasc, mesNasc, anoNasc, numCPF, peso, altura);
		// TODO Auto-generated constructor stub
	}

	@Override
	public String toString() {
		return String.format("Nome: %s %s, Idade: %d, Peso: %.2f, Altura: %.2f, CPF: %s, Gênero: %s", getNome(), getSobrenome(),
				calcularIdade(), getPeso(), getAltura(), getNumCPF(), "Mulher");
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