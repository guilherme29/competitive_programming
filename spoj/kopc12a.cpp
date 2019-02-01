#include<iostream>

long long int total_cost(int* buildings, int* cost, int size, int height){
  long long int total = 0;
  for(int i=0; i < size; i++){
    int k = height - buildings[i];
    if(k < 0) { k = k*-1; } //passar a diferenca a positiva
    total += k*cost[i];
  }
  return total;
}

int main(){
  int ntests; scanf("%d", &ntests);
  while(ntests-- > 0){
    int n; scanf("%d", &n);
    int buildings[n];
    for(int i=0; i<n; i++){
      scanf("%d", &buildings[i]);
    }
    int cost[n];
    for(int i=0; i<n; i++){
      scanf("%d", &cost[i]);
    }

    int low = 0;
    int high = 10000;
    int precision = 3;//precisao minima = distancia minima maxima entre o low e o high, como sao apenas numeros naturais e 3

    while(true){ //pesquisa ternaria
      int k = high - low;
      if(k < 0) { k = k * -1; }
      if(k < precision){
	       break;
      }
      //calculo da posicao dos dois mids
      int mid1 = low + (high - low)/3;
      int mid2 = high - (high - low)/3;
      //calculo dos custos
      long long int cost1 = total_cost(buildings, cost, n, mid1);
      long long int cost2 = total_cost(buildings, cost, n, mid2);

      if(cost1 >= cost2){
	       low = mid1;
      }
      else {
	       high = mid2;
      }
    }
    //atingida a precisao 3, o resultado vai estar exatamente entre o low e o high
    long long int result = (low + high) / 2;
    printf("%lld\n", total_cost(buildings, cost, n, result));
  }
  return 0;
}
