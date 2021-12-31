//
// Created by 李思 on 2021/12/31.
//

#include "vector"
#include "queue"
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root == nullptr) return ret;

        queue<TreeNode *> q;
        q.push(root);
        unsigned int count = 1;


        while (!q.empty()){
            vector<int> tmp;

            for(auto i = 0; i < count; i ++){
                auto curr = q.front();
                tmp.push_back(curr->val);
                q.pop();

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            count = q.size();
            ret.push_back(tmp);
        }
        return ret;
    }
};