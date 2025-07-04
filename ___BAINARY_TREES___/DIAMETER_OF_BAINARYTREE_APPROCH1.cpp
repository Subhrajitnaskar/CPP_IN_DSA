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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHt = max(leftHt,rightHt) + 1;
    return currHt;

}

int diam1(Node* root) {

    if(root == NULL){
        return 0;
    }

    int currDiam = height(root->left) + height(root->right) + 1; //o(n)
    int leftDiam = diam1(root->left);//o(n)
    int rightDiam = diam1(root->right);

    return max(currDiam,max(leftDiam,rightDiam));

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout<< "diameter = " << diam1(root)<<endl;

    cout << "root = " << root->data << endl;

    cout<<"Height = " << height(root);
    return 0;
}
