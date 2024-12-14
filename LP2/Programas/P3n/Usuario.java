import java.util.ArrayList;

public class Usuario extends Pessoa {

    private String endereco;
    private ArrayList<Emprest> hist;

    public Usuario(String nome, String sobrenome, int dia, int mes, int ano, String cpfStr, String endereco) {
        super(nome, sobrenome, dia, mes, ano, cpfStr);
        this.endereco = endereco;
    }
}
