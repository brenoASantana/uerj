public class Mulher extends PessoaIMC {
    public Mulher(String nome, String sobrenome, int dia, int mes, int ano, String cpfStr, float peso, float altura) {
        super(nome, sobrenome, dia, mes, ano, cpfStr, peso, altura);
    }

    @Override
    public String resultIMC() {
        double imc = calculaIMC();
        if (imc < 19) {
            return "Abaixo do peso ideal";
        } else if (19 <= imc && imc <= 25.8) {
            return "Peso ideal";
        } else {
            return "Acima do peso ideal";
        }
    }

    @Override
    public String toString() {
        return super.toString()
                + String.format("\nGênero: Mulher\nIMC: %.2f\nResultado IMC: %s", calculaIMC(), resultIMC());
    }
}
