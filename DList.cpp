#include<iostream>

using namespace std;

template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList(){
        delete head;
        delete tail;
        count = 0;
    };
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    // string toString();
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
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};

/******************************************
 **IMPLEMENT METHOD OF DOUBLE LINKED LIST**
******************************************/

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index == count) {
        add(e);
    } else {
        Node* newNode = new Node(e);
        if (index == 0) {
            newNode->next = head;
            head->previous = newNode;
            head = newNode;
        } else {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next->previous = newNode;
            current->next = newNode;
            newNode->previous = current;
        }
        count++;
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return this->count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    int i = 0;
    Node* p = this->head;
    while(p!= NULL && index != i){
        p = p->next;
        i++;
    }
    return p->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    int i = 0;
    Node* p = this->head;
    while(p!= NULL && index != i){
        p = p->next;
        i++;
    }
    p->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return !this->count;
    
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int index = 0;
    Node *p = this->head;
    while(p != NULL){
        if(p->data == item){
            return index;
        }
        p = p->next;
        index++;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node *p = this->head;
    while(p != NULL){
        if(p->data == item){
            return true;
        }
        p = p->next;
    }
    return false;
}
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index < 0 || index >= count || this->head == nullptr) {
        return T();
    }
     Node* current = head;
    for (int i = 0; i < index; i++)
        current = current->next;

    T removedData = current->data;

    // Update previous and next pointers
    if (current->previous)
        current->previous->next = current->next;
    if (current->next)
        current->next->previous = current->previous;

    // Update head and tail pointers if necessary
    if (current == head)
        head = current->next;
    if (current == tail)
        tail = current->previous;

    delete current;
    count--;
    return removedData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if(this->indexOf(item) == -1){
        return false;
    };
    removeAt(this->indexOf(item));
    return true;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* current = head;
    while (current != nullptr)
    {
        Node* next = current->next;
        delete current;
        current = next;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;
}

/******************************************
 *******IMPLEMENT METHOD OF ITERATOR*******
******************************************/

template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
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
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current) {
        current->data = e;
    }
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (current != NULL) {
            return current->data;
    }
    
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    Node* nodeToRemove = current;

    if (nodeToRemove == pList->head) {
        current = nullptr;
        if (pList->head == pList->tail) {
            pList->tail = nullptr;
        }
        pList->head = pList->head->next;
    } else {
        current = nodeToRemove->previous;
        if (nodeToRemove == pList->tail) {
            pList->tail = nodeToRemove->previous;
        }
        nodeToRemove->previous->next = nodeToRemove->next;
    }

    if (nodeToRemove->next) {
        nodeToRemove->next->previous = nodeToRemove->previous;
    }

    delete nodeToRemove;
    pList->count--;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    return this->current != iterator.current;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (current) {
        current = current->next;
        index++;
    }else{
        current = pList->head;
        index = 0;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}


int main(){
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }

    DLinkedList<int>::Iterator it = list.begin();
    while (it != list.end())
    {
        it.remove();
        it++;
    }
}