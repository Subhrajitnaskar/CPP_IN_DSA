#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

int idx = -1;

Node* buildTree(vector<int>& nodes) {
    idx++;
    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);  // call for left subtree
    currNode->right = buildTree(nodes); // call for right subtree

    return currNode;
}

int sum (Node* root) {

    if(root == NULL) {
        return 0;
    }
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    int currSum =  leftSum + rightSum + root->data;
   // cout<<"Sum : "<<currSum <<endl;
    return currSum;

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl;
    cout<<"Sum of node in : "<<sum(root)<<endl;

    return 0;
}
