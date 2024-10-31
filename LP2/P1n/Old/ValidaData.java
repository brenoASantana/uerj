import java.util.Calendar;
import java.util.GregorianCalendar;

public class ValidaData {

	public static boolean isDia(int dia) {
		return dia >= 1 && dia <= 31;
	}

	public static boolean isMes(int mes) {
		return mes >= 1 && mes <= 12;
	}

	public static boolean isAno(int ano) {
		int anoAtual = Calendar.getInstance().get(Calendar.YEAR);
		return ano >= (anoAtual - 120) && ano <= anoAtual;
	}

	public static boolean isDataValida(Integer dia, Integer mes, Integer ano) {
		if (dia == null || mes == null || ano == null) {
			return false;
		}

		if (!isDia(dia) || !isMes(mes) || !isAno(ano)) {
			return false;
		}

		try {
			Calendar cal = new GregorianCalendar(ano, mes - 1, dia);
			return (cal.get(Calendar.YEAR) == ano && cal.get(Calendar.MONTH) == mes - 1
					&& cal.get(Calendar.DAY_OF_MONTH) == dia);
		} catch (IllegalArgumentException e) {
			return false;
		}
	}
}