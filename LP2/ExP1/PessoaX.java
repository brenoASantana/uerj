import java.io.IOException;
import java.util.Date;

public class PessoaX{
    private String nome;
    private String sobrenome;
    private Date dataNascimento;
    private float peso;
    private float altura;
    private String genero;
    private PessoaX pai;
    private PessoaX mae;    
        
    public PessoaX PessoaX(String nome, String sobrenome, Date dataNascimento, float peso, float altura, String genero, PessoaX pai, PessoaX mae) throws IOException{
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.dataNascimento = dataNascimento;
        this.peso = peso;
        this.altura = altura;
        this.genero = genero;
        this.pai = pai;
        this.mae = mae;
        
        return this;
    }

    public String getNome(){
        return this.nome;
    }

    public String getSobrenome(){
        return this.sobrenome;
    }

    public Date getDataNascimento(){
        return this.dataNascimento;
    }

    public float getPeso(){
         return this.peso;
    }

    public float getAltura(){
         return this.peso;
    }

    public String  getGenero(){
        return this.genero;
    }

    public PessoaX getPai(){
        return this.pai;
    }

    public PessoaX getMae(){
        return this.mae;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setSobrenome(String sobrenome){
        this.sobrenome = sobrenome;
    }

    public void setDataNascimento(Date dataNascimento){
        this.dataNascimento = dataNascimento;
    }

    public void setPeso(float peso){
        this.peso = peso;
    }

    public void setAltura(float Altura){
        this.altura = altura;
    }

    public void setGenero(String genero){
        this.genero = genero;
    }

    public void setPai(PessoaX pai){
        this.pai = pai;
    }

    public void setMae(PessoaX mae){
        this.mae = mae;
    }

    public static void main(String[] args){
    
    }

}
