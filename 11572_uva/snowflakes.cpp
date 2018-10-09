#include<iostream>
#include<unordered_set>
#include<list>

using namespace std;


int main(){
  int ntest;
  cin >> ntest;

  while(ntest-- > 0){
    unordered_set<int> data;
    list<int> list1; //we need a list for a sequence like 1 2 3 2 4 5, where we have to back track to get the biggest set possible.

    int n;
    cin >> n;
    int cur_max = 0;
    for(int i=0; i<n; i++){
      int flock;
      cin >> flock;
      list1.push_front(flock);
      
      unordered_set<int>::const_iterator it = data.find(flock);
      
      if(it == data.end()){//if the flock isn't in yet
	data.insert(flock);
	if(data.size() > cur_max){
	  cur_max = data.size();
	}
      }
      else{
	if(data.size() > cur_max){
	  cur_max = data.size();
	}
	data.clear();

	//adding previous elements different from the current one
	//no need to add the current one because we will when adding the previous ones

	
	for(int elem : list1){
	  it = data.find(elem);
	  if(it == data.end()){//not in the set yet
	    data.insert(elem);
	  }
	  else{
	    break;//stop backtracking
	  }
	  
	}
	
      }
      
    }
    cout << cur_max << "\n";
    
  }
  
}
