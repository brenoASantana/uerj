import java.util.GregorianCalendar;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

public class ValidaData {

	private static final Map<String, Integer> mesesPorNome;

	// Deixando esse valores estáticos pois podem ser usados sem a criação de uma
	// instancia
	static {
		mesesPorNome = new HashMap<>();
		mesesPorNome.put("janeiro", 1);
		mesesPorNome.put("fevereiro", 2);
		mesesPorNome.put("marco", 3);
		mesesPorNome.put("abril", 4);
		mesesPorNome.put("maio", 5);
		mesesPorNome.put("junho", 6);
		mesesPorNome.put("julho", 7);
		mesesPorNome.put("agosto", 8);
		mesesPorNome.put("setembro", 9);
		mesesPorNome.put("outubro", 10);
		mesesPorNome.put("novembro", 11);
		mesesPorNome.put("dezembro", 12);
	}

	public static int convertMes(String mes) {
		return mesesPorNome.get(mes);
	}
	public static boolean isDia(int dia) {
		return dia >= 1 && dia <= 31;
	}

	public static boolean isMes(int mes) {
		return mes >= 1 && mes <= 12;
	}

	public static boolean isMes(String mes) {
		return mesesPorNome.containsKey(mes.toLowerCase());
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
