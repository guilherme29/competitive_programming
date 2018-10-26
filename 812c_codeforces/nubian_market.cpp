/*
time complexity: O(nlog^2 n)

*/
#include<iostream>
#include<algorithm>

using namespace std;

int* get_price_list(int *basecost, int k, int size){
  int *price_list = new int[size]; //tenho de criar um novo array se n n fica alocado
  for(int i=0; i<size; i++){
    price_list[i] = basecost[i] + (i+1)*k;
  }


  printf(">>>>%d\n", k);
  for(int i=0;i<size;i++){
    cout << price_list[i] << " ";
  }
  cout << "\n";

  sort(price_list,price_list + size);
  return price_list;
}

int get_cost(int *price_list, int k, int budget){
  int cost = 0;
  for(int i=0; i<k; i++){
    cost+=price_list[i];
  }
  return cost;
}


int main(){
  int ns, budget;//ns -> numero de souveniers
  scanf("%d %d", &ns, &budget);
  int basecost[ns];
  for(int i=0; i<ns; i++){
    scanf("%d",&basecost[i]);
  }


  //binary search
  int low = 0, high = ns, cost = 0;
  int middle = low + (high - low)/2;
  while(low < high){
    middle = low + (high - low)/2;
    int* price_list = get_price_list(basecost, middle, ns);
    cost = get_cost(price_list, middle, ns);

    /*
    cout << "--------\n";
    for(int i=0; i<ns; i++){
      cout << "[" << price_list[i] << "]\n";
    }
    cout << cost << "  " << middle << "\n";
    cout << "--------\n";
    */
    
    if(cost > budget){//middle's cost is bigger than the budget
      high = middle;
    }
    else{
      low = middle + 1;
    }
  }

  //final print
  if(cost > budget){
    printf("0 0\n");
  }
  else{
    printf("middle:%d cost:%d\n",middle, cost);
  }  

  return 0;
}






