#include<iostream>
#include<vector>
#include<queue>
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

void KthHelper(Node* root,int K, int currLevel) {

    if(root == NULL) {
        return;
    }

    if(currLevel == K) {
        cout << root->data <<" ";
    } 

    KthHelper(root->left,K,currLevel+1);
    KthHelper(root->right,K,currLevel+1);

}

void KthLevel(Node* root, int K) {
    KthHelper(root,K,1);
    cout << endl;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl;

    KthLevel(root,3);

    return 0;
}