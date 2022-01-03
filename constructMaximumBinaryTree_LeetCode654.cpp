//
// Created by 李思 on 2022/1/3.
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

class Solution{
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {

        return constructMaximumBinaryTree(nums, 0, nums.size()-1);

    }

    TreeNode* constructMaximumBinaryTree(vector<int> &nums, int left, int right){
        if(left > right) return nullptr;

        // find the index that corresponding the max value
        int index,max=-1;
        for(int i = left; i <= right; i++){
            if(nums[i] >= max) {
                index = i; max = nums[i];
            }
        }

        TreeNode *root = new TreeNode(nums[index]);
        root->left = constructMaximumBinaryTree(nums, left, index - 1);
        root->right = constructMaximumBinaryTree(nums, index + 1, right);

        return root;

    }
};

int main(){
    vector<int> test{1, 3, 2, 4, 6, 5};
    auto maxValueIndex = max_element(test.begin(), test.end()) - test.begin();

    return 1;
}