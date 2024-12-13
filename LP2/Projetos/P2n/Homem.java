public class Homem extends PessoaIMC {
    public Homem(String nome, String sobrenome, int dia, int mes, int ano, float peso, float altura) {
        super(nome, sobrenome, dia, mes, ano, peso, altura);
    }

    @Override
    public String resultIMC() {
        double imc = calculaIMC();
        if (imc < 20.7) {
            return "Abaixo do peso ideal";
        } else if (20.7 <= imc && imc <= 26.4) {
            return "Peso ideal";
        } else {
            return "Acima do peso ideal";
        }
    }

    @Override
    public String toString() {
        return super.toString()
                + String.format("\nGênero: Homem\nIMC: %.2f\nResultado IMC: %.s", calculaIMC(), resultIMC());
    }
}
