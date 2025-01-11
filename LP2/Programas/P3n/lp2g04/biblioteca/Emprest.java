package lp2g04.biblioteca;

public class Emprest implements Serializable {
    private String cpf;
    private String codLivro;
    private Date dataEmprestimo;
    private Date dataDevolucao;

    public Emprest(String cpf, String codLivro) {
        this.cpf = cpf;
        this.codLivro = codLivro;
        this.dataEmprestimo = new Date();
        this.dataDevolucao = null;
    }

    public void devolve() {
        this.dataDevolucao = new Date();
    }

    @Override
    public String toString() {
        String devolucao = (dataDevolucao == null) ? "Pendente" : dataDevolucao.toString();
        return "CPF: " + cpf + ", Livro: " + codLivro + ", Empréstimo: " + dataEmprestimo + ", Devolução: " + devolucao;
    }
}