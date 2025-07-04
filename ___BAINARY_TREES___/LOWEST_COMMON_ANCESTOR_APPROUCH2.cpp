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

// bool rootToNodePath(Node* root, int n1, vector<int>& path1) {

//     if (root == NULL) {
//         return false;
//     }

//     path1.push_back(root->data);
//     if (root->data == n1) {
//         return true;
//     }

//     bool isLeft = rootToNodePath(root->left, n1, path1);
//     bool isRight = rootToNodePath(root->right, n1, path1);

//     if (isLeft || isRight) {
//         return true;
//     }

//     path1.pop_back();
//     return false;

// }

// int LCA(Node* root, int n1, int n2) {

//     vector<int> path1;
//     vector<int> path2;

//     rootToNodePath(root, n1, path1);
//     rootToNodePath(root, n2, path2);

//     int lca = -1;
//     for (int i = 0, j = 0; i < path1.size() && j < path2.size(); i++, j++) {
//         if (path1[i] != path2[j]) {
//             return lca;
//         }
//         lca = path1[i];
//     }

//     return lca;

// }

Node* LCA2(Node* root, int n1, int n2){

    if(root == NULL) {
        return NULL;
    }

    if(root->data == n1 || root->data == n2) {
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;

}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node* root = buildTree(nodes);

    cout << "root = " << root->data << endl;

    int n1 = 4, n2 = 5;
    //cout << "lca = " << LCA(root, n1, n2) << endl;

    cout << "lca2 = " << LCA2(root, n1, n2)->data << endl;

    return 0;
}
