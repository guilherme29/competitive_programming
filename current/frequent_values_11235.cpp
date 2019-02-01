#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;



int merge2(int pos, int a, int b, int st[]){ //para atribuir ao aux
  printf("merge2: %d %d\n", a, b);
  if(st[pos*2+1] == st[pos*2+2]){
    return a + b;
  }
  else {
    return a > b ? a : b;
  }
}

int merge(int pos, int a, int b, int aux[]){ //para atribuir ao st
  if(aux[pos*2+1] == aux[pos*2+2]){
    return a;
  }
  else{
    return aux[pos*2+1] >= aux[pos*2+2] ? a : b;
  }
}


void construct_tree(int input[], int st[], int aux[], int low, int high, int pos){
  if(low == high){
    st[pos] = input[low];
    aux[pos] = 1;
    return;
  }
  
  int mid = (low + high)/2;
  construct_tree(input, st, aux, low, mid, 2*pos+1);
  construct_tree(input, st, aux, mid + 1, high, 2*pos+2);

  aux[pos] = merge2(pos, aux[2*pos+1], aux[2*pos+2], st); //merge da arvore auxiliar com frequencias
  st[pos] = merge(pos, st[2*pos+1], st[2*pos+2], aux);
}

int fquery(int st[], int aux[], int qlow, int qhigh, int low, int high, int pos){
  if(qlow <= low && qhigh >= high){
    return aux[pos];
  }
  if(qlow > high || qhigh < low){
    return 0;
  }
  int mid = (low + high)/2;
  return merge2(pos,
		fquery(st, aux, qlow, qhigh, low, mid, 2*pos+1),
		fquery(st, aux, qlow, qhigh, mid+1, high, 2*pos+2),
		st
		);

}


int main(){
  //while(true) {
 
  int n; scanf("%d", &n);
  //int q; scanf("%d", &q);
  
  int input[1000000];
  
  for(int i=0; i<n; i++){
    scanf("%d", &input[i]);
  }
  
  int st[200000]; //segment tree dos numeros do input (para fazer as frequencias preciso desta)
  int aux[200000];//segment tree das frequencias dos numeros do input
  construct_tree(input, st, aux, 0, n -1, 0);
  /*
  for(int i=0; i<q; i++){
    int q1; scanf("%d", &q1);
    q1--;
    int q2; scanf("%d", &q2);
    q2--;
    int result = fquery(st, aux, q1, q2, 0, n, 0);
    printf("%d\n", result);
  }
  
  */
  
  printf("\n\n\n");
  for(int i=0; i<n*5; i++){
    printf("%d ", st[i]);
  }
  printf("\n");
    for(int i=0; i<n*5; i++){
    printf("%d ", aux[i]);
  }
  printf("\n");

  
  return 0;
}
