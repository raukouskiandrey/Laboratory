#include"Algorithm.h"

template <typename t>
bool Algorithm<t>::find(const DoublyLinkedList<t>& list, const t& value) const{
    auto end = list.end();
    for (auto it = list.begin(); it != end; ++it) {
        if (*it == value) return true;
    }
    return false;
}

template <typename t>
Node<t>* Algorithm<t>::findMiddle(Node<t>* head) {
    if (!head) {
        return nullptr;
    }

    Node<t>* midFinder = head;
    Node<t>* endFinder = head;

    while (endFinder->next && endFinder->next->next) {
        midFinder = midFinder->next;
        endFinder = endFinder->next->next;
    }

    return midFinder;
}

template <typename t>
Node<t>* Algorithm<t>::mergeSort(Node<t>* head) {
    if (!head || !head->next) {
        return head;
    }

    Node<t>* middle = findMiddle(head);
    Node<t>* rightHead = middle->next;

    middle->next = nullptr;
    if (rightHead) {
        rightHead->prev = nullptr;
    }

    Node<t>* left = mergeSort(head);
    Node<t>* right = mergeSort(rightHead);

    return merge(left, right);
}

template <typename t>
Node<t>* Algorithm<t>::merge(Node<t>* left, Node<t>* right) {
    if (!left) return right;
    if (!right) return left;

    Node<t>* result = nullptr;
    if (left->data <= right->data) {
        result = left;
        left = left->next;
    }
    else {
        result = right;
        right = right->next;
    }

    Node<t>* tail = result;
    tail->prev = nullptr;

    while (left && right) {
        if (left->data <= right->data) {
            tail->next = left;
            left->prev = tail;
            tail = left;
            left = left->next;
        }
        else {
            tail->next = right;
            right->prev = tail;
            tail = right;
            right = right->next;
        }
    }

    if (left) {
        tail->next = left;
        left->prev = tail;
    }
    else if (right) {
        tail->next = right;
        right->prev = tail;
    }

    return result;
}

template <typename t>
void Algorithm<t>::sort(DoublyLinkedList<t>& list) {
    if (list.empty() || list.getHead()->next == nullptr) {
        return;
    }

    Node<t>* head = list.getHead();

    head = mergeSort(head);

    list.setHead(head);

    Node<t>* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    list.setTail(tail);
}