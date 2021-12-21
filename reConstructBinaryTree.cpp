//
// Created by Orange on 2021/12/20.
//

#include "vector"
#include "unordered_map"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class solution{
public:
    unordered_map<int, int> map;

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin){
        for(vector<int>::size_type i = 0; i < vin.size(); i++){
            map[vin[i]] = i;
        }

        return reConstructBinaryTree(pre, 0, pre.size() -1, 0);
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, int preL, int preR, int inL){
        if(preL > preR) return nullptr;

        TreeNode *root = new TreeNode(pre[preL]);
        auto inIndex = map[root->val];

        auto leftTreesize = inIndex - inL;
        root->left = reConstructBinaryTree(pre, preL + 1, preL + leftTreesize, inL);
        root->right = reConstructBinaryTree(pre, preL + leftTreesize + 1, preR, inL + leftTreesize + 1);

        return root;
    }

};