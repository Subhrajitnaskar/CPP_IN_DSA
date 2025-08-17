#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){

    priority_queue<string, vector<string>, greater<string>> pq;
     // priority_queue<string> pq;

    pq.push("Subhrajit");
    pq.push("JOYGURU");
    pq.push("RADHE RADHE");

    while (!pq.empty()) {
      cout<< "top : " << pq.top() << endl;
      pq.pop();
    }
    

    cout << "top: " << pq.top() <<endl;
    
    return 0;
    
}