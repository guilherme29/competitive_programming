#include<cstdio>
#include<algorithm>
#include<map>

using namespace std;



int merge(int a, int b){ //para atribuir ao st
  return a * b;
}


//the propagation tree doesn't need to be constructed since initially it's just an empty tree of the same size
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
    st[pos] += delta;
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


int main() {

}
