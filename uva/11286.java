import java.util.HashMap;
import java.util.Scanner;
import java.util.Arrays;
import java.io.*;
import java.util.*;

//E PRECISO MUDAR O NOME DO FICHEIRO PARA Main.java PARA CONSEGUIR CORRER E SUBMETER CORRETAMENTE

class Main{

    public static void main (String args[])  // entry point from OS
    {
        Main myWork = new Main();  // create a dinamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin(){
		
	Scanner stdin = new Scanner(System.in);
	
	int n = stdin.nextInt();
	while(true){
	    HashMap<String, Integer> data = new HashMap<String,Integer>();


	    if(n == 0) break;

	    int maxCount = 0; //quantas entradas tem tantos alunos como a entrada maxima
	    int maxEntryCount = 0;//quantos alunos tem a entrada maxima
	    
	    for(int k=0; k<n; k++){

		int[] classes = new int[5];
		for(int i=0;i<5;i++){
		    classes[i] = stdin.nextInt();
		}
	    
		Arrays.sort(classes);

		String sclasses = "";
		for(int i=0;i<5;i++){
		    sclasses += classes[i] + " ";

		}

		//System.out.println(Arrays.toString(classes));

		Integer val = data.get(sclasses);
		
		if(val == null){
		    //System.out.println("adicionou " + sclasses);
		    data.put(sclasses, 1);
		    if(maxCount == 0){ //ainda nao ha nenhum maximo
			maxEntryCount = 1;
			maxCount = 1;
		    }
		    else if(maxCount == 1){ //ja ha maximo e este e igual
			maxEntryCount++;
		    }
		    
		}
		else{
		    //System.out.println(">> " + sclasses + "," + val + "+1");
		    data.remove(sclasses);
		    data.put(sclasses, val + 1);
		    if(maxCount == val + 1){
			maxEntryCount++;
		    }
		    else if(maxCount < val + 1){
			maxCount = val + 1;
			maxEntryCount = 1;
		    }
		}

	    }

	    System.out.println(maxEntryCount * maxCount);

	    
	    if((n = stdin.nextInt()) == 0) break;

	}


    }
}

