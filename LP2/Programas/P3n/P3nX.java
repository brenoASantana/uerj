import java.util.Arrays;
import java.util.GregorianCalendar;
import java.util.Scanner;

import biblioteca.Usuario;

public class P3nX {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Biblioteca biblioteca = new Biblioteca();

        while (true) {
            System.out.println("\n--- Menu Principal ---");
            System.out.println("1. Cadastrar Usuário");
            System.out.println("2. Cadastrar Livro");
            System.out.println("3. Emprestar Livro");
            System.out.println("4. Devolver Livro");
            System.out.println("5. Sair");
            System.out.print("Escolha uma opção: ");

            int opcao = scanner.nextInt();
            scanner.nextLine(); // Limpar o buffer

            try {
                switch (opcao) {
                    case 1:
                        System.out.print("Nome do usuário: ");
                        String nome = scanner.nextLine();
                        System.out.print("CPF do usuário: ");
                        long cpf = scanner.nextLong();
                        scanner.nextLine(); // Limpar o buffer
                        System.out.print("Endereço do usuário: ");
                        String endereco = scanner.nextLine();

                        biblioteca.cadastraUsuario(new Usuario(nome, cpf, endereco));
                        System.out.println("Usuário cadastrado com sucesso!");
                        break;

                    case 2:
                        System.out.print("Código do livro: ");
                        int codigo = scanner.nextInt();
                        scanner.nextLine(); // Limpar o buffer
                        System.out.print("Título do livro: ");
                        String titulo = scanner.nextLine();
                        System.out.println("Categorias disponíveis: " + Arrays.toString(Categoria.values()));
                        System.out.print("Categoria do livro: ");
                        String categoriaStr = scanner.nextLine();
                        Categoria categoria = Categoria.valueOf(categoriaStr.toUpperCase());
                        System.out.print("Quantidade de cópias: ");
                        int quantidade = scanner.nextInt();

                        biblioteca.cadastraLivro(new Livro(codigo, titulo, categoria, quantidade));
                        System.out.println("Livro cadastrado com sucesso!");
                        break;

                    case 3:
                        System.out.print("CPF do usuário: ");
                        cpf = scanner.nextLong();
                        System.out.print("Código do livro: ");
                        codigo = scanner.nextInt();

                        Usuario usuario = biblioteca.getUsuario(cpf);
                        Livro livro = biblioteca.getLivro(codigo);

                        livro.empresta();
                        usuario.addLivroHist(new GregorianCalendar(), codigo);

                        System.out.println("Empréstimo realizado com sucesso!");
                        break;

                    case 4:
                        System.out.print("CPF do usuário: ");
                        cpf = scanner.nextLong();
                        System.out.print("Código do livro: ");
                        codigo = scanner.nextInt();

                        usuario = biblioteca.getUsuario(cpf);
                        livro = biblioteca.getLivro(codigo);

                        livro.devolve();
                        usuario.setLivroDevolvido(codigo, new GregorianCalendar());

                        System.out.println("Devolução realizada com sucesso!");
                        break;

                    case 5:
                        System.out.println("Encerrando o programa...");
                        scanner.close();
                        return;

                    default:
                        System.out.println("Opção inválida. Tente novamente.");
                }
            } catch (Exception e) {
                System.out.println("Erro: " + e.getMessage());
            }
        }
    }
}
