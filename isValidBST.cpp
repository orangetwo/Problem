//
// Created by 李思 on 2021/12/7.
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include "iostream"
#include "climits"

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode *buildBST(){
    /*                 5
     *                / \
     *              2    6
     *             / \     \
     *           1    4     7
     *               /
     *              3
     */
    TreeNode *root = new TreeNode(5);

    TreeNode *r_left = new TreeNode(2);
    TreeNode *r_right = new TreeNode(6);
    root->right = r_right;
    root->left  = r_left;

    TreeNode *r_left_left = new TreeNode(1);
    TreeNode *r_left_right = new TreeNode(4);

    r_left->left = r_left_left;
    r_left->right = r_left_right;

    TreeNode *r_left_right_left = new TreeNode(3);
    r_left_right->left = r_left_right_left;

    TreeNode *r_right_right = new TreeNode(7);
    r_right->right = r_right_right;

    return root;
}


class isValidBSTclass {
    public:
        // 中序遍历 如果遍历中出现 当前节点值比后续节点值大则返回false
        bool isValidBST(TreeNode *root) {

            if (root == nullptr) return true;

            if (!isValidBST(root->left) || pre >= root->val) {
                return false;
            }
            // TODO:
            pre = root->val;
            return isValidBST(root->right);
        }

    private:
        int pre = INT_MIN;

};

int main() {
    //std::cout << "Hello, World!" << std::endl;

    char alls[] = "abcdefgh";
    std::string one (alls, 30);
    std::cout << one <<" -> "<<std::endl;
    static int pre = INT_MIN;

    return 0;
}
