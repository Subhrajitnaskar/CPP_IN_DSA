#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// class Student {

// public:
//     string name;
//     int marks;

//     Student(string name, int marks) {
//         this->name = name;
//         this->marks = marks;
//     }

//     bool operator < (const Student &obj) const {
//         return this->marks < obj.marks;
//     }

// };

struct ComparePair {
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string, int>, vector<pair<string,int>>, ComparePair> pq;
    pq.push(make_pair("aman", 85));
    pq.push(make_pair("subhrajit", 95));
    pq.push(make_pair("jitu", 65));

    while(!pq.empty()){
        cout << "top = " << pq.top().first << "," << pq.top().second <<endl;
        pq.pop();
    }
    return 0;

}