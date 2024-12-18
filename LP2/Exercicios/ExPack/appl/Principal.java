import libs.br.uerj.ime.lp2.lp04.Calc;
import excp.*;

public class Principal {
    public static void main(String[] args) {
        try {
            // Verifica o número de argumentos
            if (args.length != 3) {
                throw new NumArgsEx("Número incorreto de argumentos.");
            }

            // Cria um objeto Calc
            Calc objeto = new Calc();

            String operacao = args[0];
            String nome1 = args[1];
            String nome2 = args[2];

            if (operacao.equals("soma")) {
                int soma = objeto.soma(nome1, nome2);
                System.out.println("Soma = " + soma);
            } else if (operacao.equals("div")) {
                double div = objeto.div(nome1, nome2);
                System.out.println("Divisão = " + div);
            } else {
                System.out.println("Operação matemática inválida.");
            }
        } catch (NumArgsEx | NaoNumEx | Div0ex e) {
            System.out.println("Erro: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Erro inesperado: " + e.getMessage());
        }
    }
}
