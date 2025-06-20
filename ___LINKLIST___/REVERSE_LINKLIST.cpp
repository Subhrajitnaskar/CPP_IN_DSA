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
    
    ~Node() {
        //  cout<<"~Node"<<data<<endl;
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;                             
    Node* tail;
    
public: 
    List() {
        head = NULL;
        tail = NULL;
    } 
    
    ~List() {
      // cout<<"~List\n";
        if(head != NULL){
            delete head;
            head = NULL;
        }
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

    void printlist() {
        Node* temp = head;

        while(temp != NULL){
            cout << temp->data <<"->";
            temp = temp->next;
        }

        cout<<"NULL\n";
    }

    void reverse() {
        Node* curr = head;
        Node* prev = NULL;
        tail = head;

        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }
};

int main(){
    List ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.printlist();

    ll.reverse();
    ll.printlist();
   
    return 0;
}