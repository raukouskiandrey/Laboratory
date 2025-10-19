#pragma once

template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};