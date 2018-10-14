#include<iostream>
#include<algorithm> //sort
#include<climits>   //INT_MAX

using namespace std;

int binary_search_max(int* arr, int r, int max);

int main(){
  int n; cin >> n;
  int budget; cin >> budget;

  //ignoring the array's first position to simplify calculations
  int basecost[n+1];//cost of each item without the seller's bullshit
  
  for(int i=1; i<=n; i++){
    cin >> basecost[i];
  }


  //this array should be something like
  // [cheapest item, 2 cheapest items if bought together, 3 cheapest items if bought together..]
  //this will allow for binary search of the biggest possible buy
  int sum_cost[n+1] = { }; //initialize all elements to 0

  
  for(int i=1; i<=n; i++){//faz-se um vetor para o custo dos items se so se comprar 1,2,3
    int cost[n+1];
    for(int j=1; j<=n; j++){
      cost[j] = basecost[j] + j*i;
    }
    sort(cost+1,cost+n+1); //this could be much reduced if i had a guarantee the items come ordered

    for(int j=0;j<n+1; j++)
      printf("%d, ",cost[j]);
    cout << "\n";

    
    for(int j=1; j<=i; j++){
      sum_cost[i] += cost[j];
    }

  }

  for(int j=0;j<n+1; j++)
    printf("%d, ",sum_cost[j]);
  cout << "\n";

  int k = binary_search_max(sum_cost, n, budget);
  printf("%d\n", k);
  
}

//PRECISO DE CORRIGIR A FUNÇAO DE PROCURA BINARIA

int binary_search_max(int* arr, int r, int max){
  int mid = r/2+1;
  
  if( *(arr+mid) > max){
    return binary_search_max(arr, mid-1, max);
  }
  return mid;
  
}



/*

int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
  
        // If the element is present at the middle  
        // itself 
        if (arr[mid] == x)   
            return mid; 
  
        // If element is smaller than mid, then  
        // it can only be present in left subarray 
        if (arr[mid] > x)  
            return binarySearch(arr, l, mid-1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binarySearch(arr, mid+1, r, x); 
   } 
  
   // We reach here when element is not  
   // present in array 
   return -1; 
} 

*/




/*
NOTAS:

precos:          2  3  5   |
comprar 1 item:  3  5  8   | i
comprar 2 item:  4  7  11  |
comprar 3 item:  5  9  14  v
                ---------->
		     j



 */
