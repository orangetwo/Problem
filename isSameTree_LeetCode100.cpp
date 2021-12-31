//
// Created by 李思 on 2021/12/31.
//

#include "vector"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q){

        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);

        if(p->val == q->val) return left && right;
        else return false;

     }
};