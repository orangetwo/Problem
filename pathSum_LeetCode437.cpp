//
// Created by 李思 on 2021/12/13.
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

// LeetCode 437 https://leetcode-cn.com/problems/path-sum-iii/

#include "iostream"
#include "unordered_map"
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


class solution {
    /**
     * 转换思路, 以当前节点为符合条件的子序列的最低(尾)节点
     * 那如果以当前节点为最低(尾)节点且符合条件的子序列, 则 当前节点的某个祖先节点为符合条件的头节点
     * 假设此最低节点与其所有祖先的节点值只和为 currentValue, 该头节点的所有祖先节点(不包括该节点本身)之和为 ancestorValue
     * 则 存在 currentValue - ancestorValue = targetSum
     * 所以, 剩下的工作为你需要  1. 对二叉树进行回溯, 在此过程中把从root到当前节点的值加起来放在 字典中
     *                       2. 在回溯的过程中检查 是否有或有几个 currentValue - targetSum 在字典中
     */
public:
    int pathSum(TreeNode *root, long long currValue, int targetSum) {

        if (root == nullptr) return 0;

        currValue += root->val;
        int ret;
        ret = myMap[currValue - targetSum];

        ++ myMap[currValue];
        ret += pathSum(root->left, currValue, targetSum);
        ret += pathSum(root->right, currValue, targetSum);
        -- myMap[currValue];

        return ret;


    }


private:
    unordered_map<long long , int> myMap ={{0, 1}};
};

int main() {
    cout << endl;

    unordered_map<int, int> Test = {{0, 9}};

    Test.insert({9, 8});
    auto show = Test.count(4);
    ++ Test[2];


    return 0;
}
