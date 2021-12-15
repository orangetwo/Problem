//
// Created by 李思 on 2021/12/14.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * 输入：
 * [-10,9,20,null,null,15,7]
 *
 *     -10
 *     / \
 *   9  20
 *     /  \
 *    15   7
 * 输出：
 * 42 (15 + 20 + 7)
 */


#include "iostream"
#include "algorithm"
#include "climits"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class solution {

public:
    int maxPathSum(TreeNode *root) {

        if (root == nullptr) return 0;

        int leftValue = max(maxPathSum(root->left), 0);
        int rightValue = max(maxPathSum(root->right), 0);

        maxValue = max(maxValue, root->val + leftValue + rightValue);
        return root->val + max(leftValue, rightValue);

    }

private:
    int maxValue = INT_MIN;
};


int main(){
    cout << endl;
    TreeNode(0);
    return 1;
}