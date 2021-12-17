//
// Created by 李思 on 2021/12/17.
//

/**
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
 * 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
 * 如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "iostream"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while(fast != nullptr && slow != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr) return nullptr;
            fast = fast->next;

            if(fast == slow) break;
        }

        if(fast == nullptr) return nullptr; // if not, it indicate linked list is circular.

        ListNode *root = head;

        int count = 0;
        while(root != slow){
            root = root->next;
            slow = slow->next;
            count += 1;
        }

        return slow;

    }
};

int main(){
    auto *one = new ListNode(1);
    auto *two = new ListNode(2);
    one->next = two;
    two->next = one;

    ListNode *root = one;

    Solution s;
    std::cout << s.detectCycle(root);
}