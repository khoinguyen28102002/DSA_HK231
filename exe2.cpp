#include<iostream>
#include<assert.h>

using namespace std;

template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList() {
        delete [] head;
        delete [] tail;
        count = 0;
    }
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    SLinkedList(const SLinkedList &list){
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin(){
        return Iterator(this, true);
    }
    Iterator end(){
        return Iterator(this, false);
    }
public:
    class Node{
        private:
            T data;
            Node *next;
            friend class SLinkedList<T>;
        public:
            Node()
            {
                next = 0;
            }
            Node(Node *next)
            {
                this->next = next;
            }
            Node(T data, Node *next = NULL)
            {
                this->data = data;
                this->next = next;
            }
    };
    class Iterator{
        private:
            SLinkedList<T> *pList;
            Node *current;
            int index; // corresponding with current node
        public:
            Iterator(): pList(nullptr), current(nullptr), index(0){};
            Iterator(SLinkedList<T> *pList, bool begin);
            Iterator &operator=(const Iterator &iterator);
            void set(const T &e);
            T &operator*();
            bool operator!=(const Iterator &iterator);
            
            // Prefix ++ overload
            Iterator &operator++();
            
            // Postfix ++ overload
            Iterator operator++(int);

            void remove();
    };
};
/********************************************/
/***IMPLEMENT METHOD OF SINGLY LINKED LIST***/
/********************************************/

template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    add(this->count, e);
}

template<class T>
void SLinkedList<T>::add(int index, const T &e) {
    /* Insert an element into the list at given index. */ 
    if(index < 0 || index > this->count){
        return;
    }
    if(index == 0){
        Node *temp = new Node(e, this->head);
        this->head = temp;
        this->tail = (!this->count) ? temp : tail;
    }else{
        Node *p = this->head;
        for(int i = 0; i < index - 1; i++){
            p = p->next;
        }
        Node *temp = new Node(e, p->next);
        p->next = temp;
        tail = (index == this->count) ? temp : tail;
    }
    this->count++;
}

template<class T>
T SLinkedList<T>::removeAt(int index) {
    /* Give the data of the element at given index in the list. */
    T data;
    if(index == 0 ||  head->next == NULL){
        data = head->data;
        head = head->next;
    }else{
        int k = 1;
        Node *p = this->head;
        while(p->next->next != NULL && k != index){
            p = p->next;
            k++;
        }
        if(p->next != NULL) {
            data = p->data;
        }
        p->next = p->next->next;
    }
    count--;
    return data;  
}

template<class T>
bool SLinkedList<T>::removeItem(const T &removeItem){
    if (indexOf(removeItem) != -1){
        removeAt(indexOf(removeItem));
    }else{
        return false;
    }
    return true;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (count > 0)? true : false;    
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

template<class T>
void SLinkedList<T>::clear(){
    delete [] head;
    delete [] tail;
    count = 0;
}

template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    int i = 0;
    Node* ptr = this->head;
    while(i != index && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    return ptr->data;    
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int i = 0;
    Node* ptr = this->head;
    while(i != index && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    ptr->data = e;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int i = 0;
    Node* ptr = this->head;
    while(item != ptr->data && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    return i;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    bool flag = false;
    Node* ptr = this->head;
    while(ptr != NULL){
        if(item == ptr->data){
            flag = true;
            break;
        }
        ptr = ptr->next;
    }
    return flag;
}

/********************************************/
/********IMPLEMENT METHOD OF ITERATOR********/
/********************************************/

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    this->pList = pList;
    if (begin) {
        if(pList) {
            current = pList->head;
            index = 0;
        }else{
            pList = NULL;
            index = -1;
        }
    } else {
        current = nullptr;
        index = pList->count;
    }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator){
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove(){
    if (current == nullptr) {
        throw std::out_of_range("Segmentation fault!");
    }
    if (index == 0) {
        pList->head = current->next;
    } else {
        Node* prev = pList->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        prev->next = current->next;
    }
    delete current;
    if (index == 0) {
        current = nullptr;
        index = -1;
    } else {
        current = pList->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        index--;
    }
    pList->count--;
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e){
    if (current) {
        current->data = e;
    }
}

template <class T>
T& SLinkedList<T>::Iterator::operator*(){
    if (current != NULL) {
            return current->data;
    }
    else{
        throw std::out_of_range("Segmentation fault!");
    }
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator){
    return this->current != iterator.current;
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++(){
    if (current) {
        current = current->next;
        index++;
    }
    return *this;
}

template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}


class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term){
        if(!term.coeff) return;
        int S = this->terms->size();
        if(S == 0){
            this->terms->add(0, term);
            return;
        }
        int index = 0, indexToInsert = -1, isSameEx = 0;
        while(index < S){
            if(term.exp >= this->terms->get(index).exp){
                indexToInsert = index;
                isSameEx = (term.exp == this->terms->get(index).exp) ? 1 : 0;
                break;
            }
            index++;
        }
        if(indexToInsert == -1){
            this->terms->add(S, term);
        }else{
            if(isSameEx){
                int newCo = term.coeff + this->terms->get(indexToInsert).coeff;
                Term temp(newCo, term.exp);
                if(newCo){
                    this->terms->set(indexToInsert, temp);
                }else{
                    this->terms->removeAt(indexToInsert);
                }
            }else{
                this->terms->add(indexToInsert, term);
            }
        }
    }
    void insertTerm(double coeff, int exp){
        Term term(coeff, exp);
        insertTerm(term);
    }
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};
int main(){
    SLinkedList<int> list;

    int size = 10;
    for(int idx=0; idx < size; idx++){
        list.add(idx);
    }

    SLinkedList<int>::Iterator it;
    int expvalue = 0;
    for(it = list.begin(); it != list.end(); it++){
        assert(*it == expvalue);
        expvalue += 1;
    }
    return 0;
}