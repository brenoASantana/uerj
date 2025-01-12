package src.lp2g04.biblioteca;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Comparator;
import java.util.Hashtable;

public class Biblioteca {
    private Hashtable<String, Usuario> usuarios;
    private Hashtable<Integer, Livro> livros;

    public Biblioteca() {
        this.usuarios = new Hashtable<>();
        this.livros = new Hashtable<>();
    }

    public void carregaArquivos(String arqUsuarios, String arqLivros) throws IOException, ClassNotFoundException {
        usuarios = (Hashtable<String, Usuario>) leArquivo(arqUsuarios);
        livros = (Hashtable<Integer, Livro>) leArquivo(arqLivros);
    }

    public void salvaArquivo(Hashtable<?, ?> tabela, String nomeArquivo) throws IOException {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(nomeArquivo))) {
            oos.writeObject(tabela);
        }
    }

    public Hashtable<?, ?> leArquivo(String nomeArquivo) throws IOException, ClassNotFoundException {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(nomeArquivo))) {
            return (Hashtable<?, ?>) ois.readObject();
        }
    }

    public void cadastraUsuario(Usuario usuario) {
        if (usuarios.containsKey(usuario.getNumCPF())) {
            throw new IllegalArgumentException("Usuário com CPF " + usuario.getNumCPF() + " já está cadastrado.");
        }
        usuarios.put(usuario.getCpf(), usuario);
    }

    public void cadastraLivro(int codigo, String titulo, Categoria categoria, int quantidade) {
        livros.put(codigo, new Livro(codigo, titulo,categoria,quantidade));
    }

    public void emprestaLivro(String cpf, int codLivro) throws UsuarioNaoCadastradoEx, LivroNaoCadastradoEx {
        Usuario u = usuarios.get(cpf);
        Livro l = livros.get(codLivro);

        if (u == null)
            throw new UsuarioNaoCadastradoEx("Usuário não encontrado.");
        if (l == null)
            throw new LivroNaoCadastradoEx("Livro não encontrado.");

        u.addLivroHist(codLivro);
        l.addLivroHist( new Emprest(cpf, codLivro));
    }

    public void devolveLivro(String cpf, String codLivro) throws UsuarioNaoCadastradoEx, LivroNaoCadastradoEx {
        Usuario u = usuarios.get(cpf);
        Livro l = livros.get(codLivro);

        if (u == null)
            throw new UsuarioNaoCadastradoEx("Usuário não encontrado.");
        if (l == null)
            throw new LivroNaoCadastradoEx("Livro não encontrado.");

        for (Emprest e : l.hist) {
            if (e.toString().contains("Pendente") && e.toString().contains(cpf)) {
                e.devolve();
                return;
            }
        }
        System.out.println("Empréstimo não encontrado ou já devolvido.");
    }

    public void imprimeUsuarios() {
        usuarios.values().stream().sorted(Comparator.comparing(u -> u.toString())).forEach(System.out::println);
    }

    public void imprimeLivros() {
        livros.values().stream().sorted(Comparator.comparing(l -> l.toString())).forEach(System.out::println);
    }
}
