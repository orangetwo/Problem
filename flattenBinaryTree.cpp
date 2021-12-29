//
// Created by Orange on 2021/12/29.
//

#include "iostream"
using namespace std;

struct Node{
    Node *left;
    Node *right;
    int val;
    Node(Node *l, Node *r, int i) : left(l), right(r), val(i){}
};

void preorderTravel(Node *root){
    if(root == nullptr) return;
    cout << root->val << endl;

    preorderTravel(root->left);
    preorderTravel(root->right);

}

Node *flattenBinaryTree(Node *root){
    if(root == nullptr) return nullptr;

    Node *left = flattenBinaryTree(root->left);
    Node *right = flattenBinaryTree(root->right);

    if (left != nullptr && right != nullptr){
        root->left = left;
        root->right = nullptr;
        left->left = right;
    } else if(left != nullptr && right == nullptr){
        root->left = left;
        root->right = nullptr;
        left->left = nullptr;
    } else if(left == nullptr && right != nullptr){
        root->left = right;
        root->right = nullptr;
    }

    return root;

}

void print(Node *root){
    while(root){
        cout << root->val << endl;
        root = root->left;
    }

}
int main(){
    Node *A = new Node(nullptr, nullptr, 1);
    Node *B = new Node(nullptr, nullptr, 2);
    Node *C = new Node(nullptr, nullptr, 3);
    Node *D = new Node(nullptr, nullptr, 4);
    Node *E = new Node(nullptr, nullptr, 5);
    Node *F = new Node(nullptr, nullptr, 6);

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->left = F;

    // preorderTravel(A);

    flattenBinaryTree(A);

    print(A);

    return 1;
}

/*
 *          1
 *         / \
 *        2   3
 *       / \ / \
 *      4  5 6
 */