import java.time.LocalDate;
import java.time.Period;

public class Mulher extends PessoaIMC {
	private LocalDate dataNascimento;

	public Mulher(String nome, String sobrenome, int dia, int mes, int ano, long numCPF, float peso, float altura) {
		super(nome, sobrenome, dia, mes, ano, numCPF);
		this.dataNascimento = LocalDate.of(ano, mes, dia);
	}

	@Override
	public String toString() {
		return super.toString() + ", Gênero: Mulher, Idade: " + calcularIdade();
	}

	private int calcularIdade() {
		return Period.between(this.dataNascimento, LocalDate.now()).getYears();
	}

	@Override
	public String resultIMC() {
		float imc = calculaIMC(getPeso(), getAltura());
		String resultado = "";
		if (imc < 19) {
			resultado = "Abaixo do peso ideal";
		} else if (imc >= 19 || imc <= 25.8) {
			resultado = "Peso ideal";
		} else if (imc < 25.8) {
			resultado = "Acima do peso ideial";
		}
		return resultado;
	}
}
