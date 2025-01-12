package src.lp2g04.biblioteca;

import java.util.GregorianCalendar;

public class Emprest {
	private String cpf;
	private int codigoLivro;
	private GregorianCalendar dataLocacao;
	private GregorianCalendar dataDevolucao;

	// Caso o registro do empréstimo seja atual
	public Emprest(String cpf, int codigoLivro) {
		this.cpf = cpf;
		this.codigoLivro = codigoLivro;
		this.dataLocacao = new GregorianCalendar();
		this.dataDevolucao = null;
	}

	// Caso o registro do empréstimo seja passado
	public Emprest(GregorianCalendar dataLocacao, int codigoLivro) {
		this.dataLocacao = dataLocacao;
		this.codigoLivro = codigoLivro;
		this.dataDevolucao = null;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public int getCodigoLivro() {
		return codigoLivro;
	}

	public void setCodigoLivro(int codigoLivro) {
		this.codigoLivro = codigoLivro;
	}

	public GregorianCalendar getDataEmprestimo() {
		return dataLocacao;
	}

	public void setDataEmprestimo(GregorianCalendar dataEmprestimo) {
		this.dataLocacao = dataEmprestimo;
	}

	public GregorianCalendar getDataDevolucao() {
		return dataDevolucao;
	}

	public void setDataDevolucao(GregorianCalendar dataDevolucao) {
		this.dataDevolucao = dataDevolucao;
	}

	public void devolve() {
		this.dataDevolucao = new GregorianCalendar();
	}

	@Override
	public String toString() {
		String devolucao = (dataDevolucao == null) ? "Pendente" : dataDevolucao.toString();
		return "CPF: " + cpf + ", Livro: " + codigoLivro + ", Empréstimo: " + dataLocacao + ", Devolução: "
				+ devolucao;
	}
}