//
// Created by 李思 on 2022/1/19.
//

/*
 * 输入: nums = [1,1,2,3,3,4,4,8,8]
 * 输出: 2
 */

/*
 *  Solution:
 *          如果不考虑“特殊”的单一元素的话，我们有结论：
 *          成对元素中的第一个所对应的下标必然是偶数，成对元素中的第二个所对应的下标必然是奇数。
 *          再考虑存在单一元素的情况，假如单一元素所在的下标为 x，那么下标 x 之前（左边）的位置仍满足上述结论，
 *          而下标 x 之后（右边）的位置由于 xx 的插入，导致结论翻转。
 *
 *          若mid 为偶数下标：根据上述结论，正常情况下偶数下标的值会与下一值相同，因此如果满足该条件，
 *          可以确保 mid 之前并没有插入单一元素。正常情况下，此时应该更新 l = mid，否则应当让 r = mid−1，
 *          但需要注意这样的更新逻辑，会因为更新 r 时否决 mid 而错过答案，我们可以将否决 mid 的动作放到更新 l 的一侧，
 *          即需要将更新逻辑修改为 l = mid+1 和 r = mid；
 */

#include "vector"

using namespace std;

int singleNonDuplicate(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mid % 2 == 0) {
            // 偶数情况
            if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            }
            else right = mid; // 特殊值必处于 偶数 索引
        } else {
            // 奇数情况
            if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                left = mid + 1;
            }
            else right = mid - 1;
        }
    }

    return nums[left];
}

int main() {
    vector<int> nums = {1, 2, 2, 3, 3};
    singleNonDuplicate(nums);
}