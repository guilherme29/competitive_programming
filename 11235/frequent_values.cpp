#include<cstdio>
#include<map>

#define MAX 100005

int segment_tree[MAX];

void build_tree(int* input, int low, int high, int pos){
  if(low == high){ //total overlap
    segment_tree[pos] = input[low];
  }
  else{
    int mid = low + (high - low)/2;
    build_tree(input, low, mid, segment_tree[mid]*2+1);
    build_tree(input, mid+1, high, segment_tree[mid]*2+2);
  }
}

int query(int low, int high, int x, int y, int pos){
  //no overlap case
  if(high > y || low < x) return 0; //0 is minimal in this case because a frequency can't be < 0
  
  //total overlap case
  if(low >= x && high <= y){
    return segment_tree[pos];
  }

  //parcial overlap case
  int mid = low + (high - low)/2;
  int a = query(low, mid, x, y, pos*2+1);
  int b = query(mid + 1, high, x, y, pos*2+2);
  return std::max(a,b);
}


int main(){
  while(true){
    int n; scanf("%d", &n);
    int nqueries; scanf("%d", &nqueries);
    int array[n];
    std::map<int, int> frequency;
    std::map<int,int>:: iterator it;
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
    build_tree(array, 0, n, 0);
  
    //query time!  O(log n)
    for(int i=0; i<nqueries; i++){
      int a; scanf("%d", &a);
      int b; scanf("%d", &b);
      int result = query(a,b,a,b,0);
      printf("%d\n", result);
    }


  }
  
  
  
}
