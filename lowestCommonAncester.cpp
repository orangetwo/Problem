//
// Created by 李思 on 2021/12/10.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include "iostream"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *lowestCommonAncester(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root == nullptr) return nullptr;
    if(root == p || root == q) return root;

    TreeNode *left = lowestCommonAncester(root->left, p ,q);
    TreeNode *right = lowestCommonAncester(root->right, p, q);

    if (left != nullptr && right != nullptr) return root;

    if (left == nullptr && right == nullptr) return nullptr;

    return left == nullptr ? right : left;

}

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}