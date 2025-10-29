#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

template<class T>
class SinglyLinkedList {
private:
    Node<T>* head;
    int size;
public:
    SinglyLinkedList() : head(nullptr), size(0) {}
    ~SinglyLinkedList();

    void pushFront(const T& val);
    void pushBack(const T& val);

    void print();

    void deleteByIndex(int index);
    void popFront();
    void popBack();
    void clear();

    bool isEmpty() const;
    int getSize() const;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
};

template<class T>
void SinglyLinkedList<T>::pushFront(const T& val) {
    Node<T>* newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
    size++;
}

template<class T>
void SinglyLinkedList<T>::pushBack(const T& val) {
    if (head == nullptr) {
        head = new Node<T>(val);
    }
    else {
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node<T>(val);
    }
    size++;
}

template<class T>
void SinglyLinkedList<T>::print() {
    Node<T>* current = head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

template<class T>
void SinglyLinkedList<T>::deleteByIndex(int index) {
    index += 1;
    if (!head) {
        cout << "List is empty!" << endl;
        return;
    }

    if (index == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
        cout << "Element with index " << index << " removed." << endl;
        return;
    }

    Node<T>* current = head;
    for (int i = 0; current != nullptr && i < index - 1; i++) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid index!" << endl;
        return;
    }

    Node<T>* temp = current->next;
    current->next = temp->next;
    delete temp;
    size--;
    cout << "Element with index " << index << " removed." << endl;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    size = 0;
}

template <typename T>
int SinglyLinkedList<T>::getSize() const {
    return size;
}

template <typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void SinglyLinkedList<T>::popFront() {
    if (isEmpty()) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template <typename T>
void SinglyLinkedList<T>::popBack() {
    if (isEmpty()) return;

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node<T>* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    --size;
}

template <typename T>
T& SinglyLinkedList<T>::front() {
    if (isEmpty()) throw runtime_error("List is empty.");
    return head->data;
}

template <typename T>
const T& SinglyLinkedList<T>::front() const {
    if (isEmpty()) throw runtime_error("List is empty.");
    return head->data;
}

template <typename T>
T& SinglyLinkedList<T>::back() {
    if (isEmpty()) throw runtime_error("List is empty.");
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    return current->data;
}

template <typename T>
const T& SinglyLinkedList<T>::back() const {
    if (isEmpty()) throw runtime_error("List is empty.");
    Node<T>* current = head;
    while (current->next)
        current = current->next;
    return current->data;
}