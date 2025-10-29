#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <typename T>
class LinkedList {
    private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr){}
    };
    Node* head;
    public:
    LinkedList() : head(nullptr) {}

    void insert(const T& val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    Node* getHead() const { return head; }
    bool isEmpty() const{ return head == nullptr; }
    };
#endif