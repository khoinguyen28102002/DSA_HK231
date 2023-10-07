#include<iostream>

using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode(); // Constructor: val = 0, next = nullptr
    LLNode(int val, LLNode* next); // Constructor with customized data
    LLNode* reverseLinkedList(LLNode* head);
    template <typename InputIterator>
    static LLNode* createWithIterators(InputIterator first, InputIterator last);
    static void printList(LLNode* head);
    void clear();
};

LLNode::LLNode() : val(0), next(nullptr) {}

LLNode::LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}

LLNode* reverseLinkedList(LLNode* head) {
    // STUDENT ANSWER
    LLNode *p = head, *res = nullptr;
    while(p){
        res = new LLNode(p->val, res);
        p = p->next;
    }
    return res;
}
LLNode* rotateLinkedList(LLNode* head, int k) {
    // STUDENT ANSWER
    if(!head || k == 0){
        return head;
    }    
    int size = 0;
    LLNode* p = head;
    while(p){
        size++;
        p = p->next;
    }
    int idx = k % size;
    if(idx == 0){
        return head;
    }
    LLNode *partII = head;
    for(int i = 0; i < size - idx - 1; i++){
        partII = partII->next;
    }
    LLNode *partI = partII->next;
    partII->next = nullptr;
    p = partI;
    while(p->next){
        p = p->next;
    }
    p->next = head;
    return partI;
}

template <typename InputIterator>
LLNode* LLNode::createWithIterators(InputIterator first, InputIterator last) {
    LLNode* trav = nullptr;
    LLNode* head = nullptr;
    while (first != last) {
        if (trav == nullptr) {
            head = new LLNode(*first);
            trav = head;
        }
        else {
            trav->next = new LLNode(*first);
            trav = trav->next;
        }
        first = first + 1;
    }
    return head;
}

void LLNode::printList(LLNode* head) {
    cout << "[";
    LLNode* trav = head;
    while (trav != nullptr) {
        cout << trav->val;
        trav = trav->next;
        if (trav != nullptr) cout << ", ";
    }
    cout << "]";
}

void LLNode::clear() {
    LLNode* pre = this;
    LLNode* trav = this;
    while (trav != nullptr) {
        trav = trav->next;
        delete pre;
        pre = trav;
    }
}
int main(){
    int arr[] = {2, 4, 6, 6, 3};
int k = 3;
LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
LLNode::printList(head);
cout << "\n";
LLNode* newhead = rotateLinkedList(head, k);
LLNode::printList(newhead);
    return 0;
}