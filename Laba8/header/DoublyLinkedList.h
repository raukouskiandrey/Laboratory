#pragma once
#include"Node.h"

#include<string>
template<typename t>
class DoublyLinkedList {
private:
    Node<t>* head = nullptr;
    Node<t>* tail = nullptr;
    size_t size = 0;
public:
    DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList<t>& other);
    ~DoublyLinkedList();

    DoublyLinkedList& operator=(const DoublyLinkedList<t>& other);

    class Iterator {
    private:
        Node<t>* current = nullptr;
    public:
        Iterator(Node<t>* node = nullptr) : current(node) {}
        Iterator& operator++();
        Iterator& operator--();
        t& operator*();
        bool operator!=(const Iterator& other) const;
    };

    Iterator begin() const;
    Iterator end() const;

    void push_back(const t value);
    void pop_back();
    void push_front(const t value);
    void pop_front();
    t front() const;
    t back() const;
    void clear();
    bool empty() const;

    size_t getSize() const;
    Node<t>* getHead() const;
    Node<t>* getTail() const;

    void setHead(Node<t>* newHead);
    void setTail(Node<t>* newTail);
};

template class DoublyLinkedList<int>;
template class DoublyLinkedList<float>;
template class DoublyLinkedList<char>;
template class DoublyLinkedList<std::string>;