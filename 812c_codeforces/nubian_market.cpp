/*
time complexity: O(nlog^2 n)

*/
#include<iostream>
#include<algorithm>

using namespace std;

long long int* get_price_list(int *basecost, int k, int size){
  long long int *price_list = new long long int[size];
  //tenho de criar um novo array senao nao fica alocado
  for(int i=0; i<size; i++){
    price_list[i] = basecost[i] + (long long int) (i+1)*k;
  }
  
  sort(price_list,price_list + size);
  return price_list;
}

long long int get_cost(long long int *price_list, int k, int budget){
  long long int cost = 0;
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
  int low = 0, high = ns;
  long long int cost = 0;
  int middle = low + (high - low + 1)/2; 
  long long int result_cost = 0; //we need a variable to store the correct cost
  //the low variable will have the correct number of items
  
  while(low < high){
    middle = low + (high - low + 1)/2; //o +1 e para arredondar para cima
    long long int* price_list = get_price_list(basecost, middle, ns);
    cost = get_cost(price_list, middle, ns);
 
    if(cost > budget){//middle's cost is bigger than the budget
      high = middle - 1;
    }
    else{
      result_cost = cost;
      low = middle;
    }
  }
  
  //final print
  cout << low << " " << result_cost << "\n";
  
  return 0;
}






