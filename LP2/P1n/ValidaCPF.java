import java.util.regex.Pattern;

public class ValidaCPF {

	public static boolean isCPF(String cpf) {
		if (cpf == null) {
			return false;
		}

		// Remove caracteres não numéricos
		cpf = cpf.replaceAll("[^0-9]", "");

		// Verifica o tamanho e padrões inválidos
		if (cpf.length() != 11 || cpf.matches("(\\d)\\1{10}")) {
			return false;
		}

		// Calcula os dígitos verificadores
		int[] peso = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 11, 10 };
		int soma = 0;
		for (int i = 0; i < 9; i++) {
			soma += Character.getNumericValue(cpf.charAt(i)) * peso[i];
		}
		int digito1 = 11 - (soma % 11);
		digito1 = (digito1 >= 10) ? 0 : digito1;

		soma = 0;
		for (int i = 0; i < 10; i++) {
			soma += Character.getNumericValue(cpf.charAt(i)) * peso[i];
		}
		int digito2 = 11 - (soma % 11);
		digito2 = (digito2 >= 10) ? 0 : digito2;

		return (Character.getNumericValue(cpf.charAt(9)) == digito1
				&& Character.getNumericValue(cpf.charAt(10)) == digito2);
	}

	public static String formataCPF(String cpf) {
		if (cpf == null) {
			return null;
		}
		cpf = cpf.replaceAll("[^0-9]", "");
		return cpf.replaceFirst("(\\d{3})(\\d{3})(\\d{3})(\\d{2})", "$1.$2.$3-$4");
	}

	public static long toLong(String cpf) {
		if (cpf == null) {
			throw new IllegalArgumentException("CPF cannot be null");
		}
		cpf = cpf.replaceAll("[^0-9]", "");
		return Long.parseLong(cpf);
	}
}
