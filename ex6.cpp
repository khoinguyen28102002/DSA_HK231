#include<iostream>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *left;
    ListNode *right;
    ListNode(int x = 0, ListNode *l = nullptr, ListNode* r = nullptr) : val(x), left(l), right(r) {}
    
};

ListNode* reverse(ListNode* head, int a, int b) {
    ListNode dummy(0);
    dummy.right = head;
    ListNode* pre = &dummy;

    // Move to the node before position 'a'
    for (int i = 1; i < a; i++) {
        pre = pre->right;
    }

    ListNode* current = pre->right;
    ListNode* next = nullptr;
    ListNode* last = current;

    // Reverse the nodes between 'a' and 'b'
    for (int i = a; i <= b; i++) {
        next = current->right;
        current->right = last;
        last->left = current;
        last = current;
        current = next;
    }

    pre->right->right = current;
    if (current) {
        current->left = pre->right;
    }

    pre->right = last;
    last->left = pre;

    return dummy.right;
}
int main(){
    return 0;
}