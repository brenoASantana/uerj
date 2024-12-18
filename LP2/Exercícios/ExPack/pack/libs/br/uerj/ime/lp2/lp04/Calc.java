package libs.br.uerj.ime.lp2.lp04;

import excp.*;

public class Calc implements CalcIntf {

    public Calc() {
        // Construtor padrão
    }

    @Override
    public int soma(String num1, String num2) throws NaoNumEx {
        int valor1, valor2;

        try {
            valor1 = Integer.parseInt(num1);
            valor2 = Integer.parseInt(num2);
        } catch (NumberFormatException e) {
            throw new NaoNumEx("Argumento não é um número inteiro.");
        }

        return valor1 + valor2;
    }

    @Override
    public double div(String num1, String num2) throws NaoNumEx, Div0ex {
        double valor1, valor2;

        try {
            valor1 = Double.parseDouble(num1);
            valor2 = Double.parseDouble(num2);
        } catch (NumberFormatException e) {
            throw new NaoNumEx("Argumento não é um número válido.");
        }

        if (valor2 == 0) {
            throw new Div0ex("Divisão por zero não é permitida.");
        }

        return valor1 / valor2;
    }

    @Override
    public int sub(int a, int b) {
        return a - b;
    }

    @Override
    public double mult(double a, double b) {
        return a * b;
    }
}
