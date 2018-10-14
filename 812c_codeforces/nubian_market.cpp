#include<iostream>
#include<algorithm> //sort
#include<climits> //INT_MAX

using namespace std;


int main(){
  int n; cin >> n;
  int budget; cin >> budget;

  //ignoring the array's first position to simplify calculations
  int basecost[n+1];//cost of each item without the seller's bullshit
  int maxitems = 0;//max items i can buy
  int totalcost = INT_MAX;//cost of the max items i can buy

  for(int i=1; i<=n; i++){
    cin >> basecost[i];
  }

  for(int i=1; i<=n; i++){//faz-se um vetor para o custo dos items se so se comprar 1,2,3
    int cost[n+1];
    for(int j=1; j<=n; j++){
      cost[j] = basecost[j] + j*i;
    }

    
    for(int j=0;j<n+1; j++)
      printf("%d, ",cost[j]);
    cout << "\n";
	     
    
    sort(cost+1,cost+n+1);

    int k = 0;
    for(int j=1; j<=i; j++){//sum of costs til I reach the items i was going to buy
      k += cost[j];
      printf("HAY HAY %d %d\n", i , k);
    }
    if(k > budget){//if we dont have money we dont buy
      continue;
    }
    if(maxitems <= i){
      maxitems = i;
      if(k < totalcost){
	totalcost = k;
      }
    }
    
    
  }
  printf("%d %d\n", maxitems, totalcost);
  
  
}
