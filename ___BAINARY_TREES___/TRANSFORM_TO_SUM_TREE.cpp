#include<iostream>
#include<vector>
#include<queue>  // Required for queue
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

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);

    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        cout << curr->data << " ";

        if(curr->left != NULL) {
            Q.push(curr->left);
        }
        if(curr->right != NULL) {
            Q.push(curr->right);
        }
    }

    cout << endl;
}

int transform(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;

    root->data = leftOld + rightOld ;
   
    if(root->left != NULL) {
        root->data += root->left->data;
    }

    if(root->right != NULL) {
        root->data += root->right->data;
    }

    return currOld;
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl;

    transform(root);
    levelOrder(root);
     
    return 0;
}
