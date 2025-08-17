#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Student {

public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->name < obj.name;
    }

};

int main(){
    priority_queue<Student> pq;
    pq.push(Student("aman", 85));
    pq.push(Student("subhrajit", 95));
    pq.push(Student("jitu", 65));

    while(!pq.empty()){
        cout << "top = " << pq.top().name << "," << pq.top().marks <<endl;
        pq.pop();
    }
    return 0;

}