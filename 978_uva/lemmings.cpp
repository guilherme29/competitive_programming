
#include<iostream> //std::cout
#include<queue>    //std::priority_queue
#include<list>     //std::list
using namespace std;


int main(){
  int ntest; cin >> ntest;
  while(ntest-- > 0){
    int nbf, sg, sb;//number of battlefields and of green and blue lemmings respectively
    cin >> nbf;
    cin >> sg;
    cin >> sb;
    priority_queue<int> green_army;
    priority_queue<int> blue_army;
    //to prevent soldiers from fighting again, we store them on a list temporarly
    list<int> green_done;
    list<int> blue_done;

    //reading each soldier stats
    int k;
    for(int i=0;i<sg;i++){
      cin >> k;
      green_army.push(k);
    }
    for(int i=0;i<sb;i++){
      cin >> k;
      blue_army.push(k);
    }
    

    while(!green_army.empty() && !blue_army.empty()){
      while(green_army.size()>0 && blue_army.size()>0){
	int green = green_army.top();
	green_army.pop();
	int blue = blue_army.top();
	blue_army.pop();
	
	if(blue > green){
	  int victor = blue - green;
	  if(victor != 0){
	    blue_done.push_back(victor);
	  }
	}
        else if(blue < green){
	  int victor = green - blue;
	  if(victor != 0){
	    green_done.push_back(victor);
	  }
	}
      }
      //putting the soldiers who fought back in the priority queue
      while(green_done.size() > 0){
	int elem = green_done.front();
	green_done.pop_front();
	green_army.push(elem);
      }
      while(blue_done.size() > 0){
	int elem = blue_done.front();
	blue_done.pop_front();
	blue_army.push(elem);
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
    cout << "\n";
  }
  
}

