//
// Created by 李思 on 2021/12/10.
//
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 *
 * 之字型打印二叉树
 */

#include "iostream"
#include "vector"
#include "queue"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void leverOrderPrint(TreeNode *root){

    if(root == nullptr) return;

    queue<TreeNode *> Q;
    int currLength;
    Q.push(root);

    while(!Q.empty())

        currLength = Q.size();
        for(int i = 0; i < currLength; i++){
            TreeNode *node = Q.front();
            //TODO: print node->val
            Q.pop();

            if(node->left != nullptr) Q.push(node->left);
            if(node->right != nullptr) Q.push(node->right);
        }

}

int main() {
    return 0;
}
