#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Heap {
    vector<int> vec;

public:

    void push(int val){

        vec.push_back(val);

        int x = vec.size()-1;
        int parI = (x-1)/2;

        while(parI >= 0 && vec[x] > vec[parI]){
            swap(vec[x],vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }

    }

    int top(){
        return vec[0];
    }

    bool empty() {
        return vec.size() == 0;
    }

};

int main(){
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout << "top = " <<heap.top() << endl;
    return 0;
}