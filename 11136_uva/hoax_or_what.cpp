/*
exercicio 11136_uva
complexidade O(n log n) pois a insercao num multiset custa n log n e e a complexidade majorante do programa
 */


#include<iostream>
#include<set>
#include<climits>

using namespace std;
long long raffle(int ndays);

int main(){
  int ndays; cin >> ndays;
  while(ndays > 0){
    long long payment = raffle(ndays);
    cout << payment << "\n"; 
    cin >> ndays;
  }
  return 0;

}


long long raffle(int ndays){
  multiset<int> bills;
  long long payment = 0;
  for(int i=0; i<ndays; i++){
    //reading the data
    int nbills; cin >> nbills;
    while(nbills-- > 0){
      int k; cin >> k;
      bills.insert(k);
    }
    //getting the largest and smallest bill
    multiset<int>::iterator lit;
    lit = --bills.end();
    int max = *lit;
    
    multiset<int>::iterator it;
    it = bills.begin();
    int min = *it;
    
    payment += max - min;
    //removing said bills
    bills.erase(lit);
    bills.erase(it);
    
  }
  
  return payment;


}
