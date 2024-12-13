public abstract class PessoaIMC extends Pessoa {
    protected float peso;
    protected float altura;

    public PessoaIMC(String nome, String sobrenome, int dia, int mes, int ano, float peso, float altura) {
        super(nome, sobrenome, dia, mes, ano);
        this.peso = peso;
        this.altura = altura;
    }

    public float getPeso() {
        return peso;
    }

    public void setPeso(float peso) {
        if (peso > 0) {
            this.peso = peso;
        }
    }

    public float getAltura() {
        return altura;
    }

    public void setAltura(float altura) {
        if (altura > 0) {
            this.altura = altura;
        }
    }

    public float calculaIMC() {
        return peso / (altura * altura);
    }

    @Override
    public String toString() {
        return super.toString() + String.format("\nPeso: %.2f\nAltura: %.2f", peso, altura);
    }

    public abstract String resultIMC();
}