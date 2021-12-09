//
// Created by 李思 on 2021/12/6.
//

/* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
 * 这里的 "/" 表示整除
 * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
 * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
 * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
 * 这样 pivot 本身最大也只能是第 k-1 小的元素
 * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
 * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
 * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
 */



#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

__attribute__((unused)) unsigned long getKthLargestNum(vector<int> arr1, vector<int> arr2, unsigned long k){


    auto rightOne = arr1.size();
    auto rightTwo = arr2.size();

    unsigned long leftOne = 0;
    unsigned long leftTwo = 0;

    while (true){

        if (leftOne == rightOne) return arr2[leftTwo + k - 1];
        if (leftTwo == rightTwo) return arr1[leftOne + k - 1];
        if (k == 1) return min(arr1[leftOne], arr2[leftTwo]);

        unsigned long newleftOne = min(leftOne + k / 2 - 1, rightOne - 1);
        unsigned long newleftTwo = min(leftTwo + k / 2 - 1, rightTwo - 1);

        if (arr1[newleftOne] <= arr2[newleftTwo]){
            k -= newleftOne - leftOne + 1;
            leftOne = newleftOne + 1;
        }
        else{
            k -= newleftTwo - leftTwo + 1;
            leftTwo = newleftTwo + 1;
        }

    }

}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    auto totalLength = nums1.size() + nums2.size();
    if (totalLength % 2 == 1) {
        return (double) getKthLargestNum(nums1, nums2, (totalLength + 1) / 2);
    }
    else {
        return (double) (getKthLargestNum(nums1, nums2, totalLength / 2) +getKthLargestNum(nums1, nums2, totalLength / 2 + 1)) / 2.0;
    }
}


int main(){

    cout <<"祭祀宫殿征战" << endl;

    vector<int> arr1 { 2, 3, 4, 0};//{10, 12, 15, 4, 5, 9};
    vector<int> arr2 { 6, 5, 7, 2};
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    cout << "arr1" << endl;
    for(vector<int>::iterator it = arr1.begin(); it != arr1.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    cout << "arr2" << endl;
    for(vector<int>::iterator it = arr2.begin(); it != arr2.end(); it++){
        cout << *it << " ";
    }
    cout << endl;


    vector<int> show {0, 2 ,6, 4, 2, 3, 5, 7, };
    sort(show.begin(), show.end());
    for(vector<int>::iterator it = show.begin(); it != show.end(); it++){
        cout << *it << " ";
    }
    cout << "\n"<<show[show.size() / 2] << endl;
    return 1;
}