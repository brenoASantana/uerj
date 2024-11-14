import java.util.InputMismatchException;

public class ValidaCPF {

	public static boolean isCPF(String CPF) {
		// Remove caracteres não numéricos
		CPF = CPF.replaceAll("[^0-9]", "");

		// Verifica se o CPF tem 11 dígitos e não é uma sequência de números iguais
		if (CPF.length() != 11 || CPF.matches("(\\d)\\1{10}")) {
			return false;
		}

		try {
			// Cálculo do primeiro dígito verificador
			int sm = 0, peso = 10;
			for (int i = 0; i < 9; i++) {
				int num = (int) (CPF.charAt(i) - '0');
				sm += (num * peso--);
			}
			int r = 11 - (sm % 11);
			char dig10 = (r == 10 || r == 11) ? '0' : (char) (r + '0');

			// Cálculo do segundo dígito verificador
			sm = 0;
			peso = 11;
			for (int i = 0; i < 10; i++) {
				int num = (int) (CPF.charAt(i) - '0');
				sm += (num * peso--);
			}
			r = 11 - (sm % 11);
			char dig11 = (r == 10 || r == 11) ? '0' : (char) (r + '0');

			return (dig10 == CPF.charAt(9) && dig11 == CPF.charAt(10));
		} catch (InputMismatchException e) {
			return false;
		}
	}

	public static long toLong(String CPF) {
		// Remove caracteres não numéricos e converte para long
		CPF = CPF.replaceAll("[^0-9]", "");
		return Long.parseLong(CPF);
	}
}
