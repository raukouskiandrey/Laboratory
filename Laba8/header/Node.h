#pragma once

template<typename t>
class Node {
public:
	t data;
	Node* next = nullptr;
	Node* prev = nullptr;

	explicit Node(t value): data(value){}
};
