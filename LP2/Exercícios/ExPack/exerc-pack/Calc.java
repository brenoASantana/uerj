public class Calc // implementar a intercefe CalcIntf
{
	
	public Calc(/*completar se necessário */)
	{
		// completar se necessário
	}
	
	/* testa se o número de argumentos está ok e joga a exceção confirmada NumArgsEx caso contrário */
	public void TestaArgs(String[] args) 
	{
	      
		
	}

    /* joga testa se o número de argumentos está correto e joga NumArgsEx caso contrário, e joga NaoNumEx se algum argumento não for convertível para inteiro */ 
	{
	public int soma (String num1, String num2) // completar
	{
	    int valor1=0, valor2 =0;
           
	   	// completar
		
	    try
	    {
	    	
		  valor1 = Integer.parseInt(num1);
		  valor2 = Integer.parseInt(num2);
				
	    }
	    // completar
	    	
			
	    return valor1 + valor2;
	}

	
	/* pode jogar NumArgsEx, NaoNumEx, Div0ex */
	public double div (String num1, String num2) throws // completar
	{
	    double valor1=0, valor2=0,resultado=0;

	   
	    try
	    {
		  valor1 = Double.parseDouble(num1);
		  valor2 = Double.parseDouble(num2);
	    }
	    catch(Exception e)
	    {
		  throw new NaoNumEx("Letra passada como argumento: Nao eh possivel converter.");
	    }
		 
	    if (valor2 == 0)
		// jogar a esceção correta ...
	    else
		resultado = valor1/valor2;	
			
	    return  resultado;
	}
	
	// pode introduzir outros métodos
}
