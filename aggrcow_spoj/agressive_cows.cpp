#include<cstdio>
#include<algorithm>

using namespace std;

int stalls_for_cows(int* stalls, int size, int ncows, int min); //O( n )

int main(){
  int ntests; scanf("%d", &ntests);
  while(ntests-- >0){
    int nstalls; scanf("%d", &nstalls);
    int ncows; scanf("%d", &ncows);
    int stalls[nstalls];
    for(int i=0; i<nstalls; i++){
      scanf("%d", &stalls[i]);
    }
    sort(stalls, stalls + nstalls); //O( n log n)


    for(int i=0; i<nstalls; i++){
      printf("%d ", stalls[i]);
    }
    printf("\n");

    int result = stalls_for_cows(stalls, nstalls, ncows, 3);
    printf("%d\n", result);
    
    
  }
  return 0;
}


int stalls_for_cows(int* stalls, int size, int ncows, int min){
  //returns 1 if it's possible to fit all cows within min distance else -1
  int a = 0, b = 1;

  while(b < size){
    if(stalls[a] + min <= stalls[b]){
      ncows--;
      a++;
      b++;
    }
    else{
      b++;
    }
  }
  
  if(ncows > 0) return -1;
  else return 1;
}
