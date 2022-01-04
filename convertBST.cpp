//
// Created by 李思 on 2022/1/4.
//

/*
  BST 特性：
         1. 对于 BST 的每一个节点 node，左子树节点的值都比 node 的值要小，右子树节点的值都比 node 的值大。
         2. 对于 BST 的每一个节点 node，它的左侧子树和右侧子树都是 BST。
  对于BST 升序遍历 即为 中序遍历, 故 降序遍历 可通过更改中序遍历或得, 更改内容即为 先访问 右子节点 然后访问左子节点
 */

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
    TreeNode *convertBST(TreeNode *root) {

        if(root == nullptr) return nullptr;
        int sum = 0;
        convertBST(root, sum);
        return root;
    }

    void convertBST(TreeNode *root, int &sum){
        if(root == nullptr) return;

        convertBST(root->right, sum);
        sum += root->val;
        root->val = sum;
        convertBST(root->left, sum);

    }

};