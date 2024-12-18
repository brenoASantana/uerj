package libs.br.uerj.ime.lp2.lp04;

import excp.*;

public interface CalcIntf {
	int soma(String a, String b) throws NaoNumEx;

	int sub(int a, int b);

	double mult(double a, double b);

	double div(String a, String b) throws NaoNumEx, Div0ex;
}
