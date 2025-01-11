class EmprestPara {
    private GregorianCalendar dataLocacao;
    private GregorianCalendar dataDevolucao;
    private long cpfUsuario;

    public EmprestPara(GregorianCalendar dataLocacao, GregorianCalendar dataDevolucao, long cpfUsuario) {
        this.dataLocacao = dataLocacao;
        this.dataDevolucao = dataDevolucao;
        this.cpfUsuario = cpfUsuario;
    }

    @Override
    public String toString() {
        String devolucao = (dataDevolucao == null) ? "Pendente" : dataDevolucao.getTime().toString();
        return "EmprestPara [dataLocacao=" + dataLocacao.getTime() + ", dataDevolucao=" + devolucao + ", cpfUsuario="
                + cpfUsuario + "]";
    }
}