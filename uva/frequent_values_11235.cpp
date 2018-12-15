#include<cstdio>
#include<map>

#define MAX 100005

int segment_tree[MAX];

void build_tree(int* input, int low, int high, int pos);
int query_aux(int low, int high, int x, int y, int pos);

int query(int* input, int low, int high){
  //i need to do some kind of search to get the first element that isn't an extreme
  
  return 0; 
}

int main(){
  //while(true){
    int n; scanf("%d", &n);
    if(n == 0) return 0;
    int nqueries; scanf("%d", &nqueries);
    int array[n];
    std::map<int, int> frequency;
    std::map<int, int>:: iterator it;
    
    for(int i=0; i<n; i++){
      scanf("%d", &array[i]);
      it = frequency.find(array[i]);
      if(it != frequency.end()){ //the item already exists in the set
	it->second = it->second + 1;
      }
      else{
	frequency.insert(std::make_pair(array[i],1));
      }
    }

    //getting each element's frequency O(n)
    for(int i=0; i<n;i++){
      it = frequency.find(array[i]);
      array[i] = it->second;
    }

    //building the tree  O(n)
    build_tree(array, 0, n-1, 0);
    
    //query time!  O(log n)
    for(int i=0; i<nqueries; i++){
      int a; scanf("%d", &a);
      int b; scanf("%d", &b);
      //int result = query(a,b,a,b,0);
      //printf("%d\n", result);
    }
    //}
}



void build_tree(int* input, int low, int high, int pos){
  if(low == high){ //total overlap
    segment_tree[pos] = input[low];
  }
  else{
    int mid = low + (high - low)/2;
    build_tree(input, low, mid, pos*2 + 1);
    build_tree(input, mid+1, high, pos*2 + 2);
    segment_tree[pos] = std::max(segment_tree[pos*2+1],segment_tree[pos*2+2]); 
  }
  printf("%d [%d,%d] = %d\n", pos, low, high, segment_tree[pos]);
}


int query_aux(int low, int high, int x, int y, int pos){
  //no overlap case
  if(low > y || high < x) return 0;
  //0 is minimal in this case because a frequency can't be < 0
  
  //total overlap case
  if(low >= x && high <= y){
    return segment_tree[pos];
  }

  //parcial overlap case
  int mid = low + (high - low)/2;
  int a = query_aux(low, mid, x, y, pos*2+1);
  int b = query_aux(mid + 1, high, x, y, pos*2+2);
  return std::max(a,b);
}
