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
    /*
    for(int i=0; i<nstalls; i++){
      printf("%2d ", stalls[i]);
    }
    printf("\n");
    for(int i=1; i<=stalls[nstalls-1]; i++){
      printf("%2d ", stalls_for_cows(stalls, nstalls, ncows, i));
    }
    printf("\n");
    */

    
    //binary search O (log n)
    int low = 0;
    int high = stalls[nstalls - 1];
    while(low < high){
      int middle = low + (high - low + 1) / 2;
      //printf(">>> %d\n", middle);
      if(!stalls_for_cows(stalls, nstalls, ncows, middle)){
	high = middle - 1;
      }
      else{
	low = middle;
      }      
    }
    
    printf("%d\n", low);
    
  }
  return 0;
}


int stalls_for_cows(int* stalls, int size, int ncows, int min){
  //returns 1 if it's possible to fit all cows within min distance else 0
  int a = 0, b = 1; //b = a + 1
  while(b < size){
    if(stalls[a] + min <= stalls[b]){
      ncows--;
      a = b;
    }
    b++;
  }
  
  if(ncows > 1) return 0;//the first cow is already placed on a = 0
  else return 1;
}
