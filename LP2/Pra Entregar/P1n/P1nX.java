import java.util.ArrayList;
import java.util.Scanner;

public class P1nX {

    public static void main(String[] args) {
        ArrayList<Pessoa> pessoas = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        boolean continuar = true;

        while (continuar) {
            try {
                System.out.println("Digite o nome:");
                String nome = scanner.nextLine().trim();
                
                System.out.println("Digite o sobrenome:");
                String sobrenome = scanner.nextLine().trim();
                
                System.out.println("Digite o dia de nascimento:");
                int dia = Integer.parseInt(scanner.nextLine().trim());
                
                System.out.println("Digite o mês de nascimento (número entre 1 e 12):");
                int mes = Integer.parseInt(scanner.nextLine().trim());
                
                System.out.println("Digite o ano de nascimento:");
                int ano = Integer.parseInt(scanner.nextLine().trim());
                
                if (!ValidaData.isDataValida(dia, mes, ano)) {
                    throw new IllegalArgumentException("Data de nascimento inválida.");
                }
                
                System.out.println("Digite o CPF (apenas números):");
                String cpfStr = scanner.nextLine().trim();
                
                if (!ValidaCPF.isCPF(cpfStr)) {
                    throw new IllegalArgumentException("CPF inválido.");
                }
                
                long cpf = ValidaCPF.toLong(cpfStr);
                
                System.out.println("Digite o peso (kg):");
                float peso = Float.parseFloat(scanner.nextLine().trim());
                
                System.out.println("Digite a altura (m):");
                float altura = Float.parseFloat(scanner.nextLine().trim());
                
                System.out.println("Digite o gênero (M para masculino, F para feminino):");
                char genero = scanner.nextLine().trim().toUpperCase().charAt(0);
                
                Pessoa pessoa;
                if (genero == 'M') {
                    pessoa = new Homem(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
                } else if (genero == 'F') {
                    pessoa = new Mulher(nome, sobrenome, dia, mes, ano, cpf, peso, altura);
                } else {
                    throw new IllegalArgumentException("Gênero inválido. Use 'M' para masculino ou 'F' para feminino.");
                }
                
                pessoas.add(pessoa);
                System.out.println("Pessoa adicionada com sucesso!");
                
                System.out.println("Deseja adicionar outra pessoa? (S/N):");
                continuar = scanner.nextLine().trim().equalsIgnoreCase("S");
                
            } catch (Exception e) {
                System.out.println("Erro: " + e.getMessage());
                System.out.println("Por favor, tente novamente.");
            }
        }

        scanner.close();

        // Contagem de Homens e Mulheres
        int totalHomens = 0;
        int totalMulheres = 0;

        for (Pessoa pessoa : pessoas) {
            if (pessoa instanceof Homem) {
                totalHomens++;
            } else if (pessoa instanceof Mulher) {
                totalMulheres++;
            }
            System.out.println(pessoa);
        }

        System.out.println("\nResumo:");
        System.out.println("Total de pessoas: " + Pessoa.numPessoas());
        System.out.println("Total de homens: " + totalHomens);
        System.out.println("Total de mulheres: " + totalMulheres);
    }
}
