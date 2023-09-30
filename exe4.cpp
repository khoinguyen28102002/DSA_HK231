#include<iostream>

using namespace std;

class LinkedList {
public:
    class Node; // Forward declaration
private:
    Node* head;
    Node* tail;
    int size;
public:
    LinkedList() : head(NULL), tail(NULL), size(0){};
public:
    class Node {
    private:
        int value;
        Node* next;
        friend class LinkedList;
    public:
        Node() {
            this->next = NULL;
        }
        Node(Node* node) {
            this->value = node->value;
            this->next = node->next;
        }
        Node(int value, Node* next = NULL) {
            this->value = value;
            this->next = next;
        }
    };
    void partition(int k);
    void print(){
    if (this->head == NULL){
        cout<<"List is empty";
    }
    else{
        Node* ptr = this->head;
        while(ptr != NULL){
            cout<<ptr->value<<" ";
            ptr = ptr->next;
        }
    }
    return;
    }
    void add(const int& e) {
    /* Insert an element into the end of the list. */
        Node* temp = new Node(e, NULL);
        if(this->head == NULL && this->tail == NULL){
            this->head = temp;
            this->tail = temp;
            this->size++;
        }
        else {
            this->tail->next = temp;
            this->tail = temp;
            this->size++;
        }    
    }
};
void LinkedList::partition(int k) {
    Node *start[3] = {nullptr, nullptr, nullptr};
    Node *end[3] = {nullptr, nullptr, nullptr};
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = nullptr;
        int i = (current->value < k) ? 0 : ((current->value == k) ? 1 : 2);
        if (end[i] == nullptr) {
            start[i] = end[i] = current;
        } else {
            end[i]->next = current;
            end[i] = current;
        }
        current = next;
    }
    if (start[0] != nullptr) {
        head = start[0];
        tail = end[0];
        if (start[1] != nullptr) {
            tail->next = start[1];
            tail = end[1];
            if (start[2] != nullptr) {
                tail->next = start[2];
                tail = end[2];
            }
        } else if (start[2] != nullptr) {
            tail->next = start[2];
            tail = end[2];
        }
    } else if (start[1] != nullptr) {
        head = start[1];
        tail = end[1];
        if (start[2] != nullptr) {
            tail->next = start[2];
            tail = end[2];
        }
    } else if (start[2] != nullptr) {
        head = start[2];
        tail = end[2];
    }
}
int main(){
    LinkedList* l = new LinkedList();
    l->add(20); l->add(30); l->add(10); l->add(60); l->add(40); l->add(45); l->add(55);
    l->print();
    cout<<endl;
    l->partition(50);
    l->print();

}