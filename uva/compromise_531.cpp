#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
// O algoritmo usado e O(m*n) e como apenas lemos o input antes O(n) e
// andamos para tras +-O(n) no print,
// o programa e O(m*n) 

using namespace std;

int main(){
  int i, j, len1, len2;
  char text1[101][31], text2[101][31];
  while(true){
    for(len1 = 0; len1<101; len1++) {
      if(scanf("%s", text1[len1]) != 1){
	return 0;
      }
      if(!strcmp(text1[len1], "#")){
	break;
      }
    }
    for(len2 = 0; len2<101; len2++) {
      if(scanf("%s", text2[len2]) != 1){
	return 0;
      }
      if(!strcmp(text2[len2], "#")){
	break;
      }
        
    }
    //vou usar uma outra matriz para me guardar o caminho
    //para depois ser mais facil
    int lcs[101][101]={}, track[101][101]={};
    for(i=0; i<=len1; i++){
      lcs[i][0]=0;
    }
    for(i=0; i<=len2; i++){
      lcs[0][i]=0;
    }
    
    for(i=1; i<=len1; i++){
      for(j=1; j<=len2; j++){
	// palavras sao iguais
	if(strcmp(text1[i-1],text2[j-1])==0){
	  lcs[i][j]=lcs[i-1][j-1]+1;
	  track[i][j]=0;
	}
	else{
	  if(lcs[i-1][j]>lcs[i][j-1]){
	    // veio de cima
	    lcs[i][j]=lcs[i-1][j];
	    track[i][j]=1;
	  }
	  else{
	    // veio do lado
	    lcs[i][j]=lcs[i][j-1];
	    track[i][j]=2;
	  }
	}
      }
    }


    //print final
    i=len1;
    j=len2;
    vector<string> print; //vou usar como pilha para poder dar print sem recursao
    // Backtrack
    while(i>0 && j>0){
      if(track[i][j]==0){
	print.push_back(text1[i-1]);
	i--;
	j--;
      }
      else if(track[i][j]==1){
	i--;
      }
      else{
	j--;
      }
    }
    while(print.size()>1){
      cout << print.back() << " ";
      print.pop_back();
    }
    cout << print.back() << endl;
  }
  return 0;
}
