#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main(){
  
  int table[1005][1005];
  int ntest; scanf("%d", &ntest);
  char str1[1005], str2[1005];
  int k=1;
  while(ntest-- > 0){

    scanf("%s", str1);
    int length = strlen(str1);

    //fazer uma segunda string inversa da primeira
    strcpy(str2, str1);
    reverse(str2, str2 + length);

    //preenchimento da tabela
    for(int i=0; i<=length; i++){
      table[i][0] = i;
    }
    for(int j=0; j<=length; j++){
      table[0][j] = j;
    }
    for(int i=1; i<=length; i++){
      for(int j=1; j<=length; j++){

	if(str1[i-1] == str2[j-1]){ //letras sao iguais
	  table[i][j] = table[i-1][j-1]; //copia-se a diagonal
	}
	else { //letras diferentes
	  //soma-se um ao minimo entre o valor na diagonal, a esquerda e a direita
	  table[i][j] = min( min(table[i-1][j],table[i][j-1]), table[i-1][j-1]) + 1;
	}
	
      }
    }
    printf("Case %d: %d\n", k, table[length][length]/2);
    k++;
    
  }
  return 0;
}
