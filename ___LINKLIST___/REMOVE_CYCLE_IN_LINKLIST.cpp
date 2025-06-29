#include<iostream>
using namespace std;

class Node {
public:    
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    } 
};

class List {
public: 
    Node* head;                             
    Node* tail;
    
    List() {
        head = NULL;
        tail = NULL;
    } 
    
    void push_front(int val) {
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    
    void push_back(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<< temp->data << "->" ;
        temp = temp->next;
    }  
    cout<< "NULL\n";
}

bool removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    // Detect Cycle
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout <<"Cycle exists\n";
            isCycle = true;
            break;
        }
    }
   
    if(!isCycle) {
        cout << "Cycle does not exist\n";
        return false;
    }

    // Special case: cycle at head
    slow = head;
    if(slow == fast) {
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    }
    else{
        Node* prev = NULL;
        while(slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
    }

    return true;
}

int main(){
    List ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // Creating cycle for testing
    ll.tail->next = ll.head;

    removeCycle(ll.head);
    printList(ll.head);
   
    return 0;
}
