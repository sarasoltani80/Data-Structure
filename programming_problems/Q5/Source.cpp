#include <iostream>
#include<vector>
#include <assert.h>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T>* next;


    Node(Node<T>* ptr = NULL) { next = ptr; }

    Node(const T& item, Node<T>* ptr = NULL)
    {
        next = ptr;
        data = item;
    }
};

template<class T>
class Linkedlist {
private:
    Node<T>* head;
    int capacity;

public:

    Linkedlist(int capacity = 100) { head = new Node<T>; }

    ~Linkedlist()
    {
        Node<T>* current = head;
        Node<T>* next = NULL;

        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }

        head = NULL;
    }

    void push(const T& x);
    void empty();
    T index(const T& item);
    int size();
};

template<class T>
void Linkedlist<T>::empty()
{
    Node<T>* current = head;
    Node<T>* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->data = NULL;
        current = next;
    }

}

template<class T>
T Linkedlist<T>::index(const T& key)
{

    Node<T>* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == key)
            return (current->data);
        count++;
        current = current->next;
    }

    //assert(0);
}

template<class T>
int Linkedlist<T>::size()
{
    int count = 0;
    Node<T>* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

template<class T>
void Linkedlist<T>::push(const T& x)
{
    //Node<T>* p = NULL;
    Node<T>* new_node = new Node<T>;
    new_node->data = x;
    new_node->next = (head);
    (head) = new_node;
}


int main()
{

    Linkedlist<int> L(10);
    L.push(15);
    L.push(16);
    L.push(17);
    L.push(18);
    //L.empty();
    int n = L.size();
    cout << "array has " << n << " elements." << endl;
    cout << "the first element is " << L.index(0) << "" << endl;
    L.empty();
    cout << "array has " << n << " elements." << endl;
    cout << "the first element is " << L.index(0) << "" << endl;
    return 0;

}



