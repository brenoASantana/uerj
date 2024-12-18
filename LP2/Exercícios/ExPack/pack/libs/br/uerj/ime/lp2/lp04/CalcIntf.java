package libs.br.uerj.ime.lp2.lp04;

import com.start.excp.Div0ex;

public interface CalcIntf {
	public int soma(int a, int b) throws ErrParEx;

	public int sub(int a, int b) throws ErrParEx;

	public double mult(double a, double b);

	public double div(double a, double b) throws Div0ex;
}