import java.util.GregorianCalendar;
import java.util.Calendar;

public class Pessoa {
    private String nome;
    private String sobrenome;
    private GregorianCalendar dataNascimento;
    private long numCPF;
    private int idade;
    private static int quantInstancia = 0;

    public Pessoa(String nome, String sobrenome, int dia, int mes, int ano) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        this.idade = calcularIdade();
        quantInstancia++;
    }

    public Pessoa(String nome, String sobrenome, int dia, int mes, int ano, long numCPF) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        this.numCPF = numCPF;
        this.idade = calcularIdade();
        quantInstancia++;
    }

    public static int numPessoas() {
        return quantInstancia;
    }

    private int calcularIdade() {
        Calendar hoje = new GregorianCalendar();
        int anoAtual = hoje.get(Calendar.YEAR);
        int mesAtual = hoje.get(Calendar.MONTH);
        int diaAtual = hoje.get(Calendar.DAY_OF_MONTH);

        int anoNascimento = dataNascimento.get(Calendar.YEAR);
        int mesNascimento = dataNascimento.get(Calendar.MONTH);
        int diaNascimento = dataNascimento.get(Calendar.DAY_OF_MONTH);

        int idadeCalculada = anoAtual - anoNascimento;

        if (mesAtual < mesNascimento || (mesAtual == mesNascimento && diaAtual < diaNascimento)) {
            idadeCalculada--;
        }

        return idadeCalculada;
    }

    @Override
    public String toString() {
        return String.format(
                "Nome: %s %s\nData de Nascimento: %tF\nCPF: %011d\nIdade: %d anos",
                nome, sobrenome, dataNascimento, numCPF, idade);
    }

    // Getters e setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        if (nome != null && nome.length() > 0) {
            this.nome = nome;
        }
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        if (sobrenome != null && sobrenome.length() > 0) {
            this.sobrenome = sobrenome;
        }
    }

    public GregorianCalendar getDataNascimento() {
        return dataNascimento;
    }

    public void setDataNascimento(GregorianCalendar dataNascimento) {
        if (dataNascimento != null) {
            this.dataNascimento = dataNascimento;
            this.idade = calcularIdade(); // Recalcula a idade ao definir uma nova data de nascimento
        }
    }

    public long getNumCPF() {
        return numCPF;
    }

    public void setNumCPF(long numCPF) {
        if (numCPF != 0) {
            this.numCPF = numCPF;
        }
    }

    public int getIdade() {
        return idade;
    }
}
