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

    TreeNode *reConstructBinaryTree(vector<int> preorder, vector<int> inorder){
        for(vector<int>::size_type i = 0; i < inorder.size(); i++){
            map[inorder[i]] = i;  // map value to index
        }

        return reConstructBinaryTree(preorder, 0, preorder.size() -1, inorder, 0, inorder.size()-1);
    }


    TreeNode *reConstructBinaryTree(vector<int> preorder, int preStart, int preEnd,
                                    vector<int> inorder, int inStart, int inEnd){
        if (preStart > preEnd) return nullptr;

        int locationInInorder = map[preorder[preStart]];
        TreeNode *root = new TreeNode(preorder[preStart]);

        root->left = reConstructBinaryTree(preorder, preStart + 1, preStart + locationInInorder - inStart,
                                           inorder, inStart, locationInInorder -1);
        root->right = reConstructBinaryTree(preorder, preStart + locationInInorder - inStart + 1, preEnd,
                                            inorder, locationInInorder +1, inEnd);

        return root;
    }

};