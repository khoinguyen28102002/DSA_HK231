#include<iostream>
#include<vector>
using namespace std;

class LLNode {
public:
    int val;
    LLNode* next;
    LLNode();
    LLNode(int val, LLNode* next);
    template <typename InputIterator>
    static LLNode* createWithIterators(InputIterator first, InputIterator last);
    static void printList(LLNode* head);
    void clear();
    LLNode* foldLinkedlist(LLNode *head);
    LLNode* addLinkedList(LLNode* l0, LLNode* l1);
};

LLNode::LLNode() : val(0), next(nullptr) {}

LLNode::LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}

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
long long int findNum(LLNode* list){
    if(list == NULL) return 0;
    return list->val + 10*findNum(list->next);
}
LLNode* addLinkedList(LLNode* l0, LLNode* l1){
    vector<int> List;
    LLNode* lt0 = l0;
    LLNode* lt1 = l1;
    int sum = 0, remain = 0;
    for(lt0 = l0, lt1 = l1; lt0 != NULL || lt1 != NULL || remain;){
            if(lt0 != NULL && lt1 != NULL){
                sum = lt0->val + lt1->val + remain;
                lt0 = lt0->next;
                lt1 = lt1->next;
            }else if (lt0 == NULL && lt1 != NULL){
                sum = lt1->val + remain;
                lt1 = lt1->next;
            }else if (lt1 == NULL && lt0 != NULL){
                sum = lt0->val + remain;
                lt0 = lt0->next;
            }
            else{
                sum = remain;
            }
            List.push_back(sum%10);
            remain = (sum >= 10)? 1 : 0;
    }
    int N = List.size();
    int* arrNum = new int[N];
    for(int i = 0; i < N; i++) arrNum[i] = List[i];
    return LLNode::createWithIterators(arrNum, arrNum + N); 
};
LLNode* LLNode::foldLinkedlist(LLNode *head){
        int size = 0;
        for( LLNode* p0 = head; p0 != NULL; p0 = p0->next){
            size++;
        }
        int arr2[size], i = 0, s = (size+1)/2, arr3[s];
        for( LLNode* p0 = head; p0 != NULL; p0 = p0->next, i++){
            arr2[i] = p0->val;
        }
        for(i = 0; i < size/2; i++){
            arr3[i] = arr2[i] + arr2[size-i-1];
        }   
        if(size%2 == 1){
            arr3[s -1] = arr2[size/2];        
        }
        for(i = 0; i < s/2; i++){
            int temp = arr3[i];
            arr3[i] = arr3[s-i-1];
            arr3[s-i-1] = temp;
        } 
        LLNode* result = LLNode::createWithIterators(arr3, arr3 + sizeof(arr3) / sizeof(int));  
        return result;
};

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
    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    return 1;
}
