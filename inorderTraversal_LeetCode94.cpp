//
// Created by Orange on 2021/12/31.
//

#include "vector"
#include "stack"
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
     vector<int> inorderTraversal(TreeNode* root) {

        stack<TreeNode *> stack;
        vector<int> ret;
        TreeNode *curr = root;

        while (curr || !stack.empty()){
            while (curr){
                stack.push(curr);
                curr = curr->left;
            }

            TreeNode *topp = stack.top();
            ret.push_back(topp->val);
            stack.pop();

            curr = topp->right;
        }


        return ret;

    }
};