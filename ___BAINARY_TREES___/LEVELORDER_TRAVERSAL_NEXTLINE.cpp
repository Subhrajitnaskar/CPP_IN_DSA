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

void levelOrder(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL);  // NULL marker for level separation

    while(!Q.empty()) {
        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL) {
            cout << endl;  // End of current level
            if(!Q.empty()) {
                Q.push(NULL);  // Add marker for next level
            }
        }
        else {
            cout << curr->data << " ";

            if(curr->left != NULL) {
                Q.push(curr->left);
            }
            if(curr->right != NULL) {
                Q.push(curr->right);
            }
        }
    }
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl << endl;

    levelOrder(root);

    return 0;
}
