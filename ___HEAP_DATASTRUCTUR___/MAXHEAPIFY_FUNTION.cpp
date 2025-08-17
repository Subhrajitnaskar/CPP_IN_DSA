#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Heap
{
    vector<int> vec;

public:
    void push(int val)
    {

        vec.push_back(val);

        int x = vec.size() - 1;
        int parI = (x - 1) / 2;

        while (parI >= 0 && vec[x] > vec[parI])
        { // ✅ changed < to >
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x - 1) / 2;
        }
    }

    void heapify(int i)
    {

        if (i >= vec.size())
        {
            return;
        }

        int l = 2 * i + 1;
        int r = 2 * i + 2;

        int maxIdx = i; // ✅ renamed to match max heap
        if (l < vec.size() && vec[l] > vec[maxIdx])
        {
            maxIdx = l;
        }
        if (r < vec.size() && vec[r] > vec[maxIdx])
        {
            maxIdx = r;
        }

        if (maxIdx != i)
        {
            swap(vec[i], vec[maxIdx]);
            heapify(maxIdx);
        }
    }

    void pop()
    {

        swap(vec[0], vec[vec.size() - 1]);

        vec.pop_back();

        heapify(0);
    }

    int top()
    {
        return vec[0];
    }

    bool empty()
    {
        return vec.size() == 0;
    }
};

int main()
{
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    // cout << "top = " <<heap.top() << endl;
    // heap.pop();
    // cout << "top = " <<heap.top() << endl;

    while (!heap.empty()){
    
        cout << "top = " << heap.top() << endl;
        heap.pop();
    }

    return 0;
}
