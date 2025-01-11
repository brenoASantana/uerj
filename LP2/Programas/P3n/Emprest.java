class Emprest {
    private GregorianCalendar dataLocacao;
    private GregorianCalendar dataDevolucao;
    private int codigoLivro;

    public Emprest(GregorianCalendar dataLocacao, int codigoLivro) {
        this.dataLocacao = dataLocacao;
        this.codigoLivro = codigoLivro;
        this.dataDevolucao = null;
    }

    public GregorianCalendar getDataLocacao() {
        return dataLocacao;
    }

    public GregorianCalendar getDataDevolucao() {
        return dataDevolucao;
    }

    public int getCodigoLivro() {
        return codigoLivro;
    }

    public void setDataDevolucao(GregorianCalendar dataDevolucao) {
        this.dataDevolucao = dataDevolucao;
    }

    @Override
    public String toString() {
        String devolucao = (dataDevolucao == null) ? "Pendente" : dataDevolucao.getTime().toString();
        return "Emprest [dataLocacao=" + dataLocacao.getTime() + ", dataDevolucao=" + devolucao + ", codigoLivro="
                + codigoLivro + "]";
    }
}
