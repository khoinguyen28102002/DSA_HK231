#include<iostream>

using namespace std;

template <class T>
class ArrayList {
protected:
    T* data;        // dynamic array to store the list's items
    int capacity;   // size of the dynamic array
    int count;      // number of items stored in the array
public:
    ArrayList(){capacity = 5; count = 0; data = new T[5];}
    ~ArrayList(){ delete[] data; }
    void    add(T e);
    void    add(int index, T e);
    int     size();
    void    ensureCapacity(int index);
    string  toString();
    void    clear();
    T       get(int index);
    void    set(int index, T e);
    int     indexOf(T item);
    bool    contains(T item);
    T       removeAt(int index);
    bool    removeItem(T item);
};

template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    /* 
        if cap == capacity: 
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if(cap == capacity){
        capacity = capacity*1.5;
        T* newArr = new T[capacity];
        for(int i = 0; i < cap; i++)
            newArr[i] = data[i];
        data = newArr;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    ensureCapacity(count);
    data[count] = e;
    count += 1;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    /* 
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */ 
    ensureCapacity(count);
    if(index < 0 || index > capacity) throw std::out_of_range("the input index is out of range!");
    for(int i = count; i > index; i--){
        data[i] = data[i-1]; 
    }
    data[index] = e;
    count++;
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return count;
}

template<class T>
string ArrayList<T>::toString() {
    /* 
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */
    string result = "[";
    for(int i = 0; i < count - 1; i++){
        result += to_string(data[i]) + ", ";
    }
    result += to_string(data[count-1]) + "]";
    return result;
}

template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    if(index < 0 || index > capacity) throw std::out_of_range("the input index is out of range!");
    int ret_val = data[index];
    for(int i = index; i < count; i++)
        data[i] = data[i+1];
    count--;
    return ret_val;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
    if(!count) return false;
    for(int i = 0; i < count; i++)
        if(data[i] == item){
            removeAt(i);
            return true;
        }   
    return false;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    if(data) delete[] data;
    data = new T[5];
    count = 0;
    capacity = 5;
}

int main(){
    ArrayList<int> arr;

    for (int i = 0; i < 10; ++i) {
        arr.add(i);
    }
    arr.clear();

    cout << arr.toString() << '\n';
    cout << arr.size();
    return 0;
}