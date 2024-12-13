import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class MinhaListaOrdenavel {
    private ArrayList<PessoaIMC> lista;

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

    public void ordenarPorNome() {
        Collections.sort(lista, Comparator.comparing(Pessoa::getNome));
    }

    public void ordenarPorIMC() {
        Collections.sort(lista, Comparator.comparingDouble(PessoaIMC::calculaIMC));
    }

    public void mostrarLista() {
        for (PessoaIMC p : lista) {
            System.out.println(p);
            System.out.println("Resultado IMC: " + p.resultIMC());
            System.out.println("------------------------");
        }
    }
}
