//
// Created by 李思 on 2022/1/4.
//

/*
 * 利用中序和后序构建二叉树
 * 我觉得本质上 这和 前序中序构建二叉树是一样的
 */


#include "vector"
#include "unordered_map"
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
    unordered_map<int, int> map;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;
        }

        return reConstructBinaryTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode *reConstructBinaryTree(vector<int>& inorder, int inStart, int inEnd,
                                    vector<int>& postorder, int postStart, int postEnd){
        if(postStart > postEnd) return nullptr;

        int locationInInorder = map[postorder[postEnd]];

        TreeNode *root = new TreeNode(postorder[postEnd]);

        root->left = reConstructBinaryTree(inorder, inStart, locationInInorder - inStart - 1, postorder, postStart, postStart + locationInInorder - inStart - 1);
        root->right = reConstructBinaryTree(inorder,locationInInorder + 1, inEnd, postorder, postStart + locationInInorder - inStart, postEnd - 1);

        return root;

    }
};