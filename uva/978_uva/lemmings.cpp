#include<iostream>
#include<list>
#include<queue>
using namespace std;



int main(){
  int ntest; cin >> ntest;
  while(ntest-- > 0){
    int nbfs; cin >> nbfs; //number of battlefields
    int ngreen; cin >> ngreen; //number of green lemmings
    int nblue; cin >> nblue; //number of blue lemmings
    priority_queue<int> green_army;
    priority_queue<int> blue_army;
    //to prevent soldiers from fighting again, we store them on a list temporarly
    list<int> green_done;
    list<int> blue_done;
    //reading each soldier stats
    int k;
    for(int i=0;i<ngreen;i++){
      cin >> k;
      green_army.push(k);
    }
    for(int i=0;i<nblue;i++){
      cin >> k;
      blue_army.push(k);
    }

    while(green_army.size()>0 && blue_army.size()>0){
      for(int i=0;i<nbfs;i++){//for each battlefield
	if(green_army.size()>0 && blue_army.size()>0){
	  int green = green_army.top();
	  green_army.pop();
	  int blue = blue_army.top();
	  blue_army.pop();

	  int victor = 0;
	  if(blue > green){ //blue wins
	    victor = blue - green;
	    blue_done.push_back(victor);
	  }
	  else if(blue < green){ //green wins
	    victor = green - blue;
	    green_done.push_back(victor);
	  }
	  
	}
	else break;
      }
      
      //push the battle hardened lemmings back into the ranks
      int elem = 0;
      while(blue_done.size() > 0){ 
	elem = blue_done.front();
	blue_done.pop_front();
	blue_army.push(elem);
      }
      while(green_done.size() > 0){
	elem = green_done.front();
	green_done.pop_front();
	green_army.push(elem);
      }
      
    }
    
    //final print
    if(green_army.size() == blue_army.size()){//for them to be equal they must = 0
      cout << "green and blue died" << "\n";
    }
    else if(green_army.size() > 0){
      cout << "green wins" << "\n";
      while(green_army.size() > 0){
	cout << green_army.top() << "\n";
	green_army.pop();
      }
    }
    else if(blue_army.size() > 0){
      cout << "blue wins" << "\n";
      while(blue_army.size() > 0){
	cout << blue_army.top() << "\n";
	blue_army.pop();
      }
    }
    if(ntest > 0)
      cout << "\n";
  }

  return 0;
}
