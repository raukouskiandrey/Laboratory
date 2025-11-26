#pragma once
#include"DoublyLinkedList.h"

template <typename t>
class Algorithm {
private:
    Node<t>* mergeSort(Node<t>* head);
    Node<t>* merge(Node<t>* left, Node<t>* right);
    Node<t>* findMiddle(Node<t>* head);
public:
    bool find(const DoublyLinkedList<t>& list, const t& value);
    void sort(DoublyLinkedList<t>& list);

};

template class Algorithm<int>;
template class Algorithm<char>;
template class Algorithm<float>;
template class Algorithm<std::string>;