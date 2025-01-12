package lp2g04.biblioteca;

import java.io.*;
import java.util.*;

public class Biblioteca {
    private Hashtable<String, Usuario> usuarios;
    private Hashtable<Integer, Livro> livros;

    public Biblioteca() {
        this.usuarios = new Hashtable<>();
        this.livros = new Hashtable<>();
    }

    public void carregaArquivos(String arqUsuarios, String arqLivros) throws IOException, ClassNotFoundException {
        this.usuarios = (Hashtable<String, Usuario>) leArquivo(arqUsuarios);
        this.livros = (Hashtable<Integer, Livro>) leArquivo(arqLivros);
    }

    public void salvaArquivo(Hashtable<?, ?> tabela, String nomeArquivo) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(nomeArquivo))) {
            oos.writeObject(tabela);
        }
    }

    private Hashtable<?, ?> leArquivo(String nomeArquivo) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(nomeArquivo))) {
            return (Hashtable<?, ?>) ois.readObject();
        }
    }

    public void cadastraUsuario(String nome, String cpf) {
        if (usuarios.containsKey(cpf)) {
            throw new IllegalArgumentException("Usuário com CPF " + cpf + " já está cadastrado.");
        }
        usuarios.put(cpf, new Usuario(nome, cpf, "Endereço Padrão"));
    }

    public void cadastraLivro(int codigo2, String titulo, String codigoStr, int quantidade) {
        int codigo;
        try {
            codigo = Integer.parseInt(codigoStr);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Código do livro deve ser numérico.");
        }
        if (livros.containsKey(codigo)) {
            throw new IllegalArgumentException("Livro com código " + codigo + " já está cadastrado.");
        }
        livros.put(codigo, new Livro(codigo, titulo, Categoria.NAO_FICCAO, 1));
    }

    public void emprestaLivro(String cpf, int codigo) {
        Usuario usuario = usuarios.get(cpf);
        if (usuario == null) {
            throw new IllegalArgumentException("Usuário com CPF " + cpf + " não encontrado.");
        }

        Livro livro = livros.get(codigo);
        if (livro == null) {
            throw new IllegalArgumentException("Livro com código " + codigo + " não encontrado.");
        }

        try {
            livro.empresta();
            usuario.addLivroHist(new GregorianCalendar(), codigo);
        } catch (Exception e) {
            throw new IllegalStateException("Erro ao emprestar livro: " + e.getMessage());
        }
    }

    public void devolveLivro(String cpf, int codigo) {
        Usuario usuario = usuarios.get(cpf);
        if (usuario == null) {
            throw new IllegalArgumentException("Usuário com CPF " + cpf + " não encontrado.");
        }

        Livro livro = livros.get(codigo);
        if (livro == null) {
            throw new IllegalArgumentException("Livro com código " + codigo + " não encontrado.");
        }

        try {
            livro.devolve();
            usuario.setLivroDevolvido(codigo, new GregorianCalendar());
        } catch (Exception e) {
            throw new IllegalStateException("Erro ao devolver livro: " + e.getMessage());
        }
    }

    public void imprimeUsuarios() {
        usuarios.values().stream()
                .sorted(Comparator.comparing(Usuario::getNome))
                .forEach(System.out::println);
    }

    public void imprimeLivros() {
        livros.values().stream()
                .sorted(Comparator.comparing(Livro::getCodigo))
                .forEach(System.out::println);
    }
}
