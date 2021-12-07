//
// Created by 李思 on 2021/12/5.
//

/**
*  Definition for singly-linked list.
*  struct ListNode {
*      int val;
*      ListNode* next;
*      ListNode() : val(0), next(nullptr) {}
*      ListNode(int x) : val(x), next(nullptr) {}
*      ListNode(int x, ListNode* next) : val(x), next(next) {}
*  };
**/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string"

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* merge(ListNode* head, ListNode* tail){
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy, *temp1 = head, *temp2 = head;

    while (temp1 != nullptr && temp2 != nullptr){
        if(temp1->val<= temp2->val){
            temp->next = temp1;
            temp1 = temp1->next;
        }
        else{
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
    }

    if (temp1 != nullptr){
        temp->next = temp1;
    }
    else{
        temp->next = temp2;
    }

    return dummy->next;
}

ListNode* sortList(ListNode* head, string orange){

    // 如果head为空
    if(head == nullptr){
        return head;
    }

    // 统计链表长度
    int length = 0;
    ListNode* node = head;
    while(node != nullptr){
        length ++;
        node = node->next;
    }

    // 设置哑节点
    ListNode* dummy = new ListNode(-1, head);

    //for()

    return head;

}

ListNode* sortList(ListNode* head, ListNode* tail){
    if (head == nullptr) { return head; }

    if (head->next == tail){ head->next = nullptr; return head; }

    ListNode* slow = head, *fast = head;

    while (fast != tail){
        slow = slow->next;
        fast = fast->next;
        if(fast != nullptr){
            fast = fast->next;
        }
    }

    ListNode* mid = slow;
    return merge(sortList(head, mid), sortList(mid, tail));
}

int main() {

    srand((int)time(0));
    int loop = 0;
    ListNode* dummy;
    ListNode* Node;
    auto* pre = new ListNode(-1);

    while(loop < 10){

        auto* p = new ListNode(rand()%100);
        pre->next = p;
        pre = p;

        if(loop == 0 ) {dummy = p;}

        loop++;
    }

    Node = dummy;
    while(Node != nullptr){
        cout <<Node->val <<endl;
        Node = Node->next;
    }

    int subLength =1;
    cout << "北海道"<<endl;
    cout << (subLength <<= 1) << endl;
    cout << (subLength <<= 1) << endl;
    cout << (subLength <<= 1) << endl;
    return 1;
}
