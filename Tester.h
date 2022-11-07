#pragma once

#include "CondVar.h"
#include <iostream>

class Tester
{
	class Node {
	public:
		Node(int value_, Node* next_) : value(value_), next(next_) {}
		int value{ 0 };
		Node* next = nullptr;
	};
public:
	Tester() = default;
	~Tester() = default; // TO LAZY TO MAKE IT 
	void Push(int value);
	void Pop();

private:
	Node* head = nullptr;
	CondVar cv;
	std::mutex mutex_;
};

