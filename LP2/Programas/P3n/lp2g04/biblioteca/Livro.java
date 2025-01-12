package lp2g04.biblioteca;

import java.util.ArrayList;
import java.util.GregorianCalendar;

public class Livro {
	private int codigo;
	private String titulo;
	private Categoria categoria;
	private int quantidade;
	private int emprestados;
	private ArrayList<EmprestPara> hist;

	public Livro(int codigo, String titulo, Categoria categoria, int quantidade) {
		this.codigo = codigo;
		this.titulo = titulo;
		this.categoria = categoria;
		this.quantidade = quantidade;
		this.emprestados = 0;
		this.hist = new ArrayList<>();
	}

	public void empresta() throws CopiaNaoDisponivelEx {
		if (emprestados >= quantidade) {
			throw new CopiaNaoDisponivelEx("Todas as cópias estão emprestadas.");
		}
		emprestados++;
	}

	public void devolve() throws NenhumaCopiaEmprestadaEx {
		if (emprestados <= 0) {
			throw new NenhumaCopiaEmprestadaEx("Nenhuma cópia foi emprestada.");
		}
		emprestados--;
	}

	public void addUsuarioHist(GregorianCalendar dataLocacao, GregorianCalendar dataDevolucao, long cpfUsuario) {
		hist.add(new EmprestPara(dataLocacao, dataDevolucao, cpfUsuario));
	}

	public int getCodigo() {
		return codigo;
	}

	@Override
	public String toString() {
		return "Livro -> Codigo:" + codigo + ", Titulo:" + titulo + ", Categoria:" + categoria + ", Quantidade:"
				+ quantidade + ", Emprestados:" + emprestados;
	}
}