package biblioteca;

import java.util.Hashtable;

class Biblioteca {
    private Hashtable<Long, Usuario> usuarios;
    private Hashtable<Integer, Livro> livros;

    public Biblioteca() {
        this.usuarios = new Hashtable<>();
        this.livros = new Hashtable<>();
    }

    public void cadastraUsuario(Usuario usuario) {
        if (usuarios.containsKey(usuario.getCpf())) {
            throw new IllegalArgumentException("Usuário com CPF " + usuario.getCpf() + " já está cadastrado.");
        }
        usuarios.put(usuario.getCpf(), usuario);
    }

    public void cadastraLivro(Livro livro) {
        if (livros.containsKey(livro.getCodigo())) {
            throw new IllegalArgumentException("Livro com código " + livro.getCodigo() + " já está cadastrado.");
        }
        livros.put(livro.getCodigo(), livro);
    }

    public Usuario getUsuario(long cpf) throws UsuarioNaoCadastradoEx {
        Usuario usuario = usuarios.get(cpf);
        if (usuario == null) {
            throw new UsuarioNaoCadastradoEx("Usuário não cadastrado.");
        }
        return usuario;
    }

    public Livro getLivro(int codigo) throws LivroNaoCadastradoEx {
        Livro livro = livros.get(codigo);
        if (livro == null) {
            throw new LivroNaoCadastradoEx("Livro não cadastrado.");
        }
        return livro;
    }
}