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

pair<int,int> diam2(Node* root) {

    if(root == NULL) {
        return make_pair(0,0);
    }
    
    pair<int,int> leftInfo = diam2(root->left);
    pair<int,int> rightInfo = diam2(root->right);

    int currDiam = leftInfo.second + rightInfo.second + 1;
    int finalDiam = max(currDiam,max(leftInfo.first,rightInfo.first));
    int finalHt = max(leftInfo.second,rightInfo.second) + 1;

    return make_pair(finalDiam,finalHt);

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl;
    cout<<"diameter = " << diam2(root).first << endl;                                                            
    return 0;
}
