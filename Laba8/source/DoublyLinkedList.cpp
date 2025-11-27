#include"DoublyLinkedList.h"
#include<iostream>

template<typename t>
DoublyLinkedList<t>::~DoublyLinkedList() {
	clear();
}

template<typename t>
DoublyLinkedList<t>::DoublyLinkedList(const DoublyLinkedList& other) {
	Node<t>* current = other.head;

	while (current) {
		pushBack(current->data);
		current = current->next;
	}
}

template<typename t>
DoublyLinkedList<t>& DoublyLinkedList<t>::operator=(const DoublyLinkedList<t>& other) {
	if (this != &other) {
		clear();
		auto head = other.head;
		while (head) {
			pushBack(head->data);
			head = head->next;
		}
	}
	return *this;
}

template<typename t>
void DoublyLinkedList<t>::clear() {
	Node<t>* current = head;
	while (current != nullptr) {
		Node<t>* next = current->next;
		delete current;
		current = next;
	}
	head = tail = nullptr;
	size = 0;
}

template<typename t>
bool DoublyLinkedList<t>::empty() const {
	return head == nullptr;
}

template<typename t>
void DoublyLinkedList<t>::pushBack(const t value) {
	auto newNode = new Node<t>(value);

	if (empty()) {
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++size;
}

template<typename t>
void DoublyLinkedList<t>::popBack() {
	if (empty()) {
		std::cout << "List is empty!!!!";
		return;
	}
	if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<t>* newTail = tail->prev;
		newTail->next = nullptr;
		delete tail;
		tail = newTail;
	}
	--size;
}

template<typename t>
void DoublyLinkedList<t>::pushFront(const t value) {
	auto newNode = new Node<t>(value);

	if (empty()) {
		head = tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	++size;
}

template<typename t>
void DoublyLinkedList<t>::popFront() {
	if (empty()) {
		std::cout << "List is empty!!!!";
		return;
	}

	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<t>* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
	--size;
}

template<typename t>
t DoublyLinkedList<t>::back() const {
	if (empty()) {
		throw std::runtime_error("List is empty");
	}
	else {
		return tail->data;
	}
}

template<typename t>
t DoublyLinkedList<t>::front() const {
	if (empty()) {
		throw std::runtime_error("List is empty");
	}
	else {
		return head->data;
	}
}

template<typename t>
typename DoublyLinkedList<t>::Iterator& DoublyLinkedList<t>::Iterator::operator++() {
	if (current) {
		current = current->next;
	}
	return *this;
}

template<typename t>
typename DoublyLinkedList<t>::Iterator& DoublyLinkedList<t>::Iterator::operator--() {
	if (current) {
		current = current->prev;
	}
	return *this;
}

template<typename t>
t& DoublyLinkedList<t>::Iterator::operator*() {
	if (!current) {
		throw std::runtime_error("Attempting to dereference an invalid iterator");
	}
	else {
		return current->data;
	}
}

template<typename t>
bool DoublyLinkedList<t>::Iterator::operator!=(const DoublyLinkedList<t>::Iterator& other) const {
	return current != other.current;
}

template<typename t>
typename DoublyLinkedList<t>::Iterator DoublyLinkedList<t>::begin() const {
	return Iterator(head);
}

template<typename t>
typename DoublyLinkedList<t>::Iterator DoublyLinkedList<t>::end() const {
	return Iterator(nullptr);
}

template<typename t>
size_t DoublyLinkedList<t>::getSize() const {
	return size;
}

template<typename t>
Node<t>* DoublyLinkedList<t>::getHead() const {
	return head;
}

template<typename t>
Node<t>* DoublyLinkedList<t>::getTail() const {
	return tail;
}

template<typename t>
void DoublyLinkedList<t>::setHead(Node<t>* newHead) {
	head = newHead;
	if (!head) {
		tail = nullptr;
		size = 0;
		return;
	}
	head->prev = nullptr;
}

template<typename t>
void DoublyLinkedList<t>::setTail(Node<t>* newTail) {
	tail = newTail;
	if (tail) {
		tail->next = nullptr;
	}
}