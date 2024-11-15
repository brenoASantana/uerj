import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class ValidaData {

	private static final HashSet<String> meses;

	// Deixando esse valores estáticos pois podem ser usados sem a criação de uma
	// instancia
	static {
		meses = new HashSet<>();
		meses.add("janeiro");
		meses.add("fevereiro");
		meses.add("marco");
		meses.add("abril");
		meses.add("maio");
		meses.add("junho");
		meses.add("julho");
		meses.add("agosto");
		meses.add("setembro");
		meses.add("outubro");
		meses.add("novembro");
		meses.add("dezembro");
	}

	public static boolean isDia(int dia) {
		return dia >= 1 && dia <= 31;
	}

	public static boolean isMes(int mes) {
		return mes >= 1 && mes <= 12;
	}

	public static boolean isMes(String mes) {
		return meses.contains(mes.toLowerCase());
	}

	public static boolean isAno(int ano) {
		int anoAtual = new GregorianCalendar().get(GregorianCalendar.YEAR);
		return ano >= (anoAtual - 120) && ano <= anoAtual;
	}

	public static boolean isDataValida(int dia, int mes, int ano) {
		// Verifica se o dia é válido para o mês e ano informados.
		try {
			// Note que o mês é ajustado (mes - 1), pois os meses no GregorianCalendar são
			// indexados a partir de 0
			GregorianCalendar data = new GregorianCalendar(ano, mes - 1, dia);

			// Essa verificação é necessária porque o GregorianCalendar ajusta
			// automaticamente datas inválidas
			return data.get(GregorianCalendar.DAY_OF_MONTH) == dia && data.get(GregorianCalendar.MONTH) == mes - 1
					&& data.get(GregorianCalendar.YEAR) == ano;
		} catch (Exception e) {
			return false;
		}
	}

	public static boolean isDataValida(String dia, String mes, String ano) {
		try {
			return isDataValida(Integer.parseInt(dia), Integer.parseInt(mes), Integer.parseInt(ano));
		} catch (NumberFormatException e) {
			return false;
		}
	}
}
