//
// Created by Orange on 2021/12/29.
//

/*
 *  用stack可以解决问题
 *  但是 如果 要求 space complexity O(1), 似乎不太ok
 */
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

/*
 *  1. 将 root 的左子树和右子树拉平
 *  2. 将 root 的右子树接到左子树下方，然后将整个左子树作为右子树。
 */

void flattenBinaryTree(Node *root){
    if(root == nullptr) return;

    flattenBinaryTree(root->left);
    flattenBinaryTree(root->right);

    Node *left = root->left;
    Node *right = root->right;

    root->left = nullptr;
    root->right = left;

    Node *p = root;
    while (p->right){
        p = p->right;
    }
    p->right = right;

//
//    if(root->left != nullptr){
//        Node *pre = root->left;
//        while (pre->right != nullptr) pre = pre->right;
//        pre->right = root->right;
//        root->right = root->left;
//        root->left = nullptr;
//    }

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

    return 0;
}

/*
 *          1
 *         / \
 *        2   3
 *       / \ / \
 *      4  5 6
 */