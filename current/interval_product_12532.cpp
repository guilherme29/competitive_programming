#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;


int merge(int a, int b){ //para atribuir ao st
  return a * b;
}


void construct_tree(int input[], int st[], int low, int high, int pos){
  if(low == high){
    st[pos] = input[low];
    return;
  }
  
  int mid = (low + high)/2;
  construct_tree(input, st, low, mid, 2*pos+1);
  construct_tree(input, st, mid + 1, high, 2*pos+2);
  st[pos] = merge(st[2*pos+1], st[2*pos+2]);
}


void update_lazy(int st[], int lazy[], int ulow, int uhigh, int delta, int low, int high, int pos) {
  if(low > high) {
    return;
  }

  //make sure all propagation is done at pos. If not update tree
  //at pos and mark its children for lazy propagation.
  if (lazy[pos] != 0) {
    st[pos] += lazy[pos];
    if (low != high) { //not a leaf node
      lazy[2 * pos + 1] += lazy[pos];
      lazy[2 * pos + 2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  //no overlap
  if(ulow > high || uhigh < low) {
    return;
  }

  //total overlap
  if(ulow <= low && uhigh >= high) {
    st[pos] = delta; //should change according to the merge function
    if(low != high) {
      lazy[2*pos + 1] += delta;
      lazy[2*pos + 2] += delta;
    }
    return;
  }

  //partial overlap
  int mid = (low + high)/2;
  update_lazy(st, lazy, ulow, uhigh, delta, low, mid, 2*pos+1);
  update_lazy(st, lazy, ulow, uhigh, delta, mid+1, high, 2*pos+2);
  st[pos] = merge(st[2*pos + 1], st[2*pos + 2]);
}


int query_lazy(int st[], int lazy[], int qlow, int qhigh, int low, int high, int pos) {
  
  if(low > high) {
    return 1; //must change accordingly with the merge function
  }

  //make sure all propagation is done at pos. If not update tree
  //at pos and mark its children for lazy propagation.
  if (lazy[pos] != 0) {
    st[pos] += lazy[pos];
    if (low != high) { //not a leaf node
      lazy[2 * pos + 1] += lazy[pos];
      lazy[2 * pos + 2] += lazy[pos];
    }
    lazy[pos] = 0;
  }

  //no overlap
  if(qlow > high || qhigh < low){
    return 1; //must change accordingly with the merge function
  }

  //total overlap
  if(qlow <= low && qhigh >= high){
    return st[pos];
  }

  //partial overlap
  int mid = (low+high)/2;
  return merge(query_lazy(st, lazy, qlow, qhigh, low, mid, 2 * pos + 1),
	       query_lazy(st, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2));

}


void print(int val){
  if(val == 0){
    printf("0");
  }
  else if(val > 0){
    printf("+");
  }
  else{
    printf("-");
  }
}

int read_number(int k){
  if(k == 0) return 0;
  else if(k > 0) return 1;
  else return -1;
}


int main(){
  int n;
  int k;
  while(scanf("%d %d", &n, &k) != EOF){
    int st[100005];
    int lazy[100005];
    int input[100005];
  
    for(int i=0; i<n; i++){
      int aux; scanf("%d", &aux);
      //scanf("%d", &input[i]);
      input[i] = read_number(aux);
    }
  
    construct_tree(input, st, 0, n-1, 0);
  
    for(int i=0; i<k; i++){
      char c = getchar(); //flushing the \n
      char letter = getchar();
      int a, b; scanf("%d %d", &a, &b);
      //printf("%d %d \n", a,b);
      switch(letter){
      case 'P':{
	a--;//ajustar os indices
	b--;
	int result = query_lazy(st, lazy, a, b, 0, n-1, 0);
	print(result);
	break; 
      }
      case 'C':{
	a--;//ajustar o indice
	b = read_number(b);
	update_lazy(st, lazy, a, a, b, 0, n-1, 0);
	break;
      }
      }
    }
    printf("\n");

  }
}
