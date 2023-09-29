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
    // Iterator begin()
    // {
    //     return Iterator(this, true);
    // }
    // Iterator end()
    // {
    //     return Iterator(this, false);
    // }
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
    // class Iterator
    // {
    // private:
    //     SLinkedList<T> *pList;
    //     Node *current;
    //     int index; // corresponding with current node
    // public:
    //     Iterator(): pList(nullptr), current(nullptr), index(0){};
    //     // Iterator(const Iterator& i): pList(i.pList->c), current(i.current->clone()), index(i.index){};
    //     Iterator(SLinkedList<T> *pList, bool begin);
    //     // Iterator &operator=(const Iterator &iterator);
    //     // void set(const T &e);
    //     T &operator*(){
    //         if(pList) return *(*pList);
    //     };
    //     bool operator!=(const Iterator &iterator);
    //     // // Prefix ++ overload
    //     // Iterator &operator++();
    //     // // Postfix ++ overload
    //     // Iterator operator++(int);
    // };
};
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
        // TODO
    }
    void insertTerm(double coeff, int exp){
        // TODO
    }
    void print() {
        SLinkedList<Term>* Tcp = this->terms;
        cout <<"[";
        for(int i = 0; i < this->terms->size() - 1; i++){
            cout << "{" << this->terms->get(i).coeff << ", " << this->terms->get(i).exp << "}, ";
        }
        cout << "{" << this->terms->get(this->terms->size()-1).coeff << ", " << this->terms->get(this->terms->size()-1).exp << "}]";
    }
};
int main(){
    Polynomial *poly = new Polynomial();
    poly->insertTerm(6.0, 2);
    // poly->insertTerm(4.0, 5);
    // poly->insertTerm(4.0, 3);
    // poly->insertTerm(6.0, 5);
    // poly->insertTerm(-1.0, 0);
    // poly->insertTerm(-6.0, 6);
    // poly->insertTerm(6.0, 6);
    poly->print();
    return 0;
}