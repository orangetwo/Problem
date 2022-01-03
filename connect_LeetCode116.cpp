//
// Created by 李思 on 2022/1/3.
//

/*
 *  我觉得我这道题 用队列做 BFS更好一点
 */
struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution{
public:
    Node *connect(Node *root){
        if(root == nullptr) return nullptr;

        connect(root->left, root->right);
        return root;
    }

    void connect(Node *root1, Node *root2){
        if (root1 == nullptr || root2 == nullptr) return;
        connect(root1->left, root1->right);
        connect(root2->left, root2->right);
        connect(root1->right, root2->left);
        root1->next = root2;

    }
};