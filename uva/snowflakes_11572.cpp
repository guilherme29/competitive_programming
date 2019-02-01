/*
exercicio 11572_uva
*/

#include<iostream>
#include<unordered_set>
#include<list>
using namespace std;

int main(){
  int ntest;
  cin >> ntest;

  while(ntest-- > 0){
    unordered_set<int> data; //set para guardar os diferentes numeros duma subsequencia
    list<int> list1; //lista para poder fazer backtrack

    int n;
    cin >> n;
    int cur_max = 0;
    for(int i=0; i<n; i++){
      int flock;
      cin >> flock;
      list1.push_front(flock); //adiciona-se o numero a frente da lista

      unordered_set<int>::const_iterator it = data.find(flock); //verifica-se se o numero ja esta na subsequencia corrente

      if(it == data.end()){ //se o numero ainda nao esta no set
        data.insert(flock); //insere-se
        if(data.size() > cur_max){ //atualiza-se o cur_max
          cur_max = data.size();
        }
      }
      else{ //se o numero ja esta no set
        if(data.size() > cur_max){ //atualiza-se o cur_max
          cur_max = data.size();
        }
        data.clear(); //limpa-se o set

        for(int elem : list1){ //faz-se backtrack e adiciona-se todos os numeros ate a repeticao
          it = data.find(elem);
          if(it == data.end()){
            data.insert(elem);
          }
          else{
            break;//para-se o backtracking
          }
        }
      }
    }
    cout << cur_max << "\n"; //print do cur_max
  }
}
