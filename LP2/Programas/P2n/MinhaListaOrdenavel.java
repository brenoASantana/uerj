import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class MinhaListaOrdenavel {
    private ArrayList<PessoaIMC> lista;

    public static final int NOME_A_Z = 1;
    public static final int NOME_Z_A = 2;
    public static final int PESO_CRESCENTE = 3;
    public static final int PESO_DECRESCENTE = 4;
    public static final int IMC_CRESCENTE = 5;
    public static final int IMC_DECRESCENTE = 6;
    public static final int GENERO = 7;
    public static final int JOVEM_ATE_VELHO = 8;
    public static final int VELHO_ATE_JOVEM = 9;
    public static final int DATA_NASCIMENTO = 10;
    public static final int CPF = 11;

    public MinhaListaOrdenavel() {
        lista = new ArrayList<>();
    }

    public void add(PessoaIMC p) {
        lista.add(p);
    }

    public PessoaIMC get(int index) {
        if (index >= 0 && index < lista.size()) {
            return lista.get(index);
        }
        return null;
    }

    public Comparator<PessoaIMC> nomeC = Comparator.comparing(p -> p.getNome());
    public Comparator<PessoaIMC> nomeCReverso = nomeC.reversed();

    public Comparator<PessoaIMC> pesoC = Comparator.comparingDouble(p -> p.getPeso());
    public Comparator<PessoaIMC> pesoCReverso = pesoC.reversed();

    public Comparator<PessoaIMC> imcC = Comparator.comparingDouble(p -> p.calculaIMC());
    public Comparator<PessoaIMC> imcCReverso = imcC.reversed();

    public Comparator<PessoaIMC> generoC = Comparator.comparing(p -> p instanceof Homem ? "Homem" : "Mulher");

    public Comparator<PessoaIMC> idadeC = Comparator.comparingInt(p -> p.getIdade());
    public Comparator<PessoaIMC> idadeCReverso = idadeC.reversed();

    public Comparator<PessoaIMC> dataNascimentoC = Comparator.comparing(p -> p.getDataNascimento());

    public Comparator<PessoaIMC> cpfC = Comparator.comparingLong(p -> p.getNumCPF());

    public ArrayList<PessoaIMC> ordena(int criterio) {
        switch (criterio) {
            case NOME_A_Z:
                Collections.sort(lista, nomeC);
                break;
            case NOME_Z_A:
                Collections.sort(lista, nomeCReverso);
                break;
            case PESO_CRESCENTE:
                Collections.sort(lista, pesoC);
                break;
            case PESO_DECRESCENTE:
                Collections.sort(lista, pesoCReverso);
                break;
            case IMC_CRESCENTE:
                Collections.sort(lista, imcC);
                break;
            case IMC_DECRESCENTE:
                Collections.sort(lista, imcCReverso);
                break;
            case GENERO:
                Collections.sort(lista, generoC);
                break;
            case JOVEM_ATE_VELHO:
                Collections.sort(lista, idadeC);
                break;
            case VELHO_ATE_JOVEM:
                Collections.sort(lista, idadeCReverso);
                break;
            case DATA_NASCIMENTO:
                Collections.sort(lista, dataNascimentoC);
                break;
            case CPF:
                Collections.sort(lista, cpfC);
                break;
            default:
                System.out.println("Critério inválido!");
        }
        return lista;
    }

    public void mostrarLista() {
        for (PessoaIMC p : lista) {
            System.out.println(p);
            System.out.println("------------------------");
        }
    }
}
