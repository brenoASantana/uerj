package lp2g04.biblioteca;

public enum Categoria {
    FICCAO,
    NAO_FICCAO,
    DRAMA,
    EDUCACAO,
    TECNICO,
    OUTROS;

    public static Categoria isThere(String categoria) {
        try {
            return Categoria.valueOf(categoria);
        } catch (IllegalArgumentException e) {
            return Categoria.OUTROS; // Valor padrão, caso o valor não exista
        }
    }
}