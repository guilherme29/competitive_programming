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

int query(int st[], int qlow, int qhigh, int low, int high, int pos){
  if(qlow <= low && qhigh >= high){
    return st[pos];
  }
  if(qlow > high || qhigh < low){
    return 1;
  }
  int mid = (low + high)/2;
  printf("->%d %d\n", qlow, qhigh);
  int q1 = query(st, qlow, qhigh, low, mid, 2*pos+1);
  int q2 = query(st, qlow, qhigh, mid+1, high, 2*pos+2);
  
  
  return merge(q1, q2);
}

void update(int st[], int index, int delta, int low, int high, int pos) {
  //if index to be updated is less than low or higher than high just return.
  if(index < low || index > high){
    return;
  }
        
  //if low and high become equal, then index will be also equal to them and update
  //that value in segment tree at pos
  if(low == high){
    segmentTree[pos] += delta;
    return;
  }
  //otherwise keep going left and right to find index to be updated 
  //and then update current tree position if min of left or right has
  //changed.
  int mid = (low + high)/2;
  update(st, index, delta, low, mid, 2 * pos + 1);
  update(st, index, delta, mid + 1, high, 2 * pos + 2);
  st[pos] = merge(st[2*pos+1], st[2*pos + 2]);
}


int main(){
  int st[1000000];
  int input[1000000];
  int n; scanf("%d", &n);
  int k; scanf("%d", &k);
  
  for(int i=0; i<n; i++){
    scanf("%d", &input[i]);
  }
  
  construct_tree(input, st, 0, n-1, 0);

  for(int i=0; i<n*4; i++) printf("%d ", st[i]);
  printf("\n");


  

}
