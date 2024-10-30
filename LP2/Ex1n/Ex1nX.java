import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Ex1nX {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            String line;

            // Loop principal que continua até que o usuário pressione apenas ENTER
            while (true) {
                System.out.print("Digite uma string (pressione ENTER para sair): ");
                line = reader.readLine();

                // Se o usuário pressionar apenas ENTER, o programa termina
                if (line == null || line.isEmpty()) {
                    System.out.println("Programa encerrado.");
                    break;
                }

                // Array para armazenar a contagem de cada letra (26 posições para as letras
                // A-Z)
                int[] letterCount = new int[26];

                // Percorre cada caractere da string
                for (int location = 0; location < line.length(); location++) {
                    char letter = line.charAt(location);

                    // Verifica se o caractere é uma letra (maiúscula ou minúscula)
                    if (Character.isLetter(letter)) {
                        // Converte a letra para maiúscula para unificar a contagem
                        int index = Character.toUpperCase(letter) - 'A';
                        if (index >= 0 && index < letterCount.length) {
                            letterCount[index]++;
                        }
                    }
                }

                // Exibe a contagem de letras
                System.out.println("Contagem de letras:");
                for (int index = 0; index < letterCount.length; index++) {
                    if (letterCount[index] > 0) {
                        System.out.println("O total de '" + (char) (index + 'A') + "' é: " + letterCount[index]);
                    }
                }
            }
        } catch (IOException e) {
            System.err.println("Erro ao ler do teclado: " + e.getMessage());
        }
    }
}
