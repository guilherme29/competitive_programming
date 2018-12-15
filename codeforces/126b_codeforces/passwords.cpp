#include<iostream>

int main(){
  
}

int *compute_prefix(char word[], int size){ //assuming there's an empty postion at the front of the array (size should be size + 1 of the real size)
  int* pi = new int[size];
  pi[1] = 0;
  int k = 0;
  for(int q=2; q<size; q++){
    while(k > 0 && word[k+1] != word[q]){
      k = pi[k];
    }
    if(word[k+1] == word[q]){
      k = k + 1;
    }
    pi[q] = k;
  }
  return pi;
}
