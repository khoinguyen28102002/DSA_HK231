#include<iostream>

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
    // void add(const T &e);
    void add(int index, const T &e){
        Node *temp = new Node(e);
        if(index == 0 || this->head == NULL){
            if(head == NULL){
                head = temp;
            }else{
                temp->next = head;
                head = temp;
            }
        }else{
            int k = 1;
            Node *p = this->head;
            while(p != NULL && k != index){
                p = p->next;
                k++;
            }
            if(k!= index){
                this->tail->next = temp;
                this->tail = temp;
            }else{
                temp->next = p->next;
                p->next = temp;
            }
        }
        count++;
    }
    T removeAt(int index){
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
    };
    // bool removeItem(const T &removeItem);
    // bool empty();
    int size(){
        return this->count;
    };
    void clear(){
        delete [] head;
        delete [] tail;
        count = 0;
    }
    T get(int index){
        int k = 0;
        Node *p = this->head;
        while(p != NULL && k != index){
            p = p->next;
            k++;
        }
        if(p){
            return p->data;
        }
        return -1;
    }
    void set(int index, const T &e){
        int k = 0;
        Node *p = this->head;
        while(p != NULL && k != index){
            p = p->next;
            k++;
        }
        if(p){
            p->data = e;
        }
    }
    // int indexOf(const T &item);
    // bool contains(const T &item);
    // string toString();
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
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
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(): pList(nullptr), current(nullptr), index(0);
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
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
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
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
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
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current) {
        current->data = e;
    }
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current != NULL) {
            return current->data;
    }else
        throw std::out_of_range("Segmentation fault!");
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
    return this->current != iterator.current;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (current) {
        current = current->next;
        index++;
    }
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
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
        // SLinkedList<Term>* Tcp = this->terms;
        // cout <<"[";
        // for(int i = 0; i < this->terms->size() - 1; i++){
        //     cout << "{" << this->terms->get(i).coeff << ", " << this->terms->get(i).exp << "}, ";
        // }
        // cout << "{" << this->terms->get(this->terms->size()-1).coeff << ", " << this->terms->get(this->terms->size()-1).exp << "}]";
    }
};
int main(){
    Polynomial *poly = new Polynomial();
    poly->insertTerm(0.0, 0);
    // Term term(4.0, 5);
    // poly->insertTerm(term);
    // poly->insertTerm(4.0, 3);
    // poly->insertTerm(6.0, 1);
    // poly->insertTerm(-16.0, 4);
    // poly->insertTerm(-6.0, 6);
    // poly->insertTerm(6.0, 4);
poly->print();
    return 0;
}