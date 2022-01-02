//
// Created by 李思 on 2022/1/2.
//

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

class Solution {
public:
    vector<TreeNode*> generateTrees(int begin, int end) {

        if(end < begin) return {nullptr};

        vector<TreeNode *> ret;

        for(int i = begin; i <= end; i++){

            vector<TreeNode *> leftSet = generateTrees(begin, i - 1);
            vector<TreeNode *> rightSet = generateTrees(i + 1, end);

            for(auto left : leftSet){
                for(auto right : rightSet){
                    TreeNode *currNode = new TreeNode(i);

                    currNode->left = left;
                    currNode->right = right;
                    ret.emplace_back(currNode);

                }
            }

        }

        return ret;

    }

    vector<TreeNode*> generateTrees(int n){
        if(n <= 0) return {};
        return generateTrees(1, n);

    }
};