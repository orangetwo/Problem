//
// Created by 李思 on 2022/1/17.
//

#include "vector"

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
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        kthSmallest(root);
        return ret;
    }

    void kthSmallest(TreeNode *root){
        if (root == nullptr) return;

        kthSmallest(root->left);

        count ++;
        if (count == target) ret = root->val;
        kthSmallest(root->right);
    }

private:
    int count = 0;
    int target;
    int ret;
};