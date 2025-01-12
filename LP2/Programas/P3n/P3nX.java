import java.util.Scanner;
import lp2g04.biblioteca.Biblioteca;

public class P3nX {

    public static void main(String[] args) {
        Biblioteca biblioteca = new Biblioteca();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Deseja carregar os cadastros de arquivos? (s/n)");
        String resposta = scanner.nextLine();
        if (resposta.equalsIgnoreCase("s")) {
            try {
                System.out.print("Nome do arquivo de usuários: ");
                String arqUsuarios = scanner.nextLine();
                System.out.print("Nome do arquivo de livros: ");
                String arqLivros = scanner.nextLine();
                biblioteca.carregaArquivos(arqUsuarios, arqLivros);
            } catch (Exception e) {
                System.out.println("Erro ao carregar arquivos: " + e.getMessage());
            }
        }

        boolean executando = true;
        while (executando) {
            System.out.println(
                    "1. Cadastrar Usuário\n2. Cadastrar Livro\n3. Emprestar Livro\n4. Devolver Livro\n5. Imprimir Usuários\n6. Imprimir Livros\n7. Sair");
            int opcao = scanner.nextInt();
            scanner.nextLine();

            try {
                switch (opcao) {
                    case 1 -> {
                        System.out.print("Nome Completo: ");
                        String nome = scanner.nextLine();
                        System.out.print("CPF: ");
                        String cpf = scanner.nextLine();
                        System.out.print("Endereço: ");
                        String endereco = scanner.nextLine();
                        biblioteca.cadastraUsuario(nome, cpf, endereco);
                    }
                    case 2 -> {
                        System.out.print("Título: ");
                        String titulo = scanner.nextLine();
                        System.out.print("Código: ");
                        int codigo = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Quantidade: ");
                        int quantidade = scanner.nextInt();
                        scanner.nextLine();
                        System.out.print("Categoria (ex: FICCAO, DRAMA): ");
                        String categoria = scanner.nextLine();
                        biblioteca.cadastraLivro(titulo, codigo, quantidade, categoria);
                    }
                    case 3 -> {
                        System.out.print("CPF do Usuário: ");
                        String cpf = scanner.nextLine();
                        System.out.print("Código do Livro: ");
                        int codigo = scanner.nextInt();
                        scanner.nextLine();
                        biblioteca.emprestaLivro(cpf, codigo);
                    }
                    case 4 -> {
                        System.out.print("CPF do Usuário: ");
                        String cpf = scanner.nextLine();
                        System.out.print("Código do Livro: ");
                        int codigo = scanner.nextInt();
                        scanner.nextLine();
                        biblioteca.devolveLivro(cpf, codigo);
                    }
                    case 5 -> biblioteca.imprimeUsuarios();
                    case 6 -> biblioteca.imprimeLivros();
                    case 7 -> executando = false;
                    default -> System.out.println("Opção inválida!");
                }
            } catch (Exception e) {
                System.out.println("Erro: " + e.getMessage());
            }
        }
        scanner.close();
    }
}
