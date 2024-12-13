import java.util.GregorianCalendar;

public class Pessoa {
    private String nome;
    private String sobrenome;
    private GregorianCalendar dataNascimento;
    private long numCPF;
    private static int quantInstancia = 0;

    public Pessoa(String nome, String sobrenome, int dia, int mes, int ano) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        quantInstancia++;
    }

    public Pessoa(String nome, String sobrenome, int dia, int mes, int ano, long numCPF) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNascimento = new GregorianCalendar(ano, mes - 1, dia);
        this.numCPF = numCPF;
        quantInstancia++;
    }

    public static int numPessoas() {
        return quantInstancia;
    }

    public String toString() {
        return String.format("Nome: %s %s, Data de Nascimento: %tF, CPF: %011d", nome,
                sobrenome, dataNascimento, numCPF);
    }

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

}
