//
// Created by Orange on 2021/12/31.
//

/*
 *  思路是 判断两个树是不是一样的
 *  根节点的两个节点 看作两个新的树来做
 *
 */
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

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;

        return isSymmetric(root->left, root->right);

    }

    bool isSymmetric(TreeNode *p, TreeNode *q){
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        bool left = isSymmetric(p->left, q->right);
        bool right = isSymmetric(p->right, q->left);

        return left && right && (p->val == q->val);


    }
};