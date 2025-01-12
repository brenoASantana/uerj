package lp2g04.biblioteca;

import java.util.ArrayList;
import java.util.GregorianCalendar;

public class Usuario extends Pessoa {
	private String endereco;
	private ArrayList<Emprest> hist;
	private int livrosEmprestados;

	public Usuario(String nome, String cpf, String endereco) {
		super(nome, cpf);
		this.endereco = endereco;
		this.hist = new ArrayList<>();
		this.livrosEmprestados = 0;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public int getLivrosEmprestados() {
		return livrosEmprestados;
	}

	public void setLivrosEmprestados(int livrosEmprestados) {
		this.livrosEmprestados = livrosEmprestados;
	}

	public void addLivroHist(GregorianCalendar dataLocacao, int codigoLivro) {
		hist.add(new Emprest(dataLocacao, codigoLivro));
		livrosEmprestados++;
	}

	public void setLivroDevolvido(int codigoLivro, GregorianCalendar dataDevolucao) {
		for (Emprest e : hist) {
			if (e.getCodigoLivro() == codigoLivro && e.getDataDevolucao() == null) {
				e.setDataDevolucao(dataDevolucao);
				livrosEmprestados--;
				break;
			}
		}
	}

	@Override
	public String toString() {
		return super.toString() + ", endereco=" + endereco + ", livrosEmprestados=" + livrosEmprestados;
	}
}
