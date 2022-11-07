#include "Tester.h"

void Tester::Push(int value) {
	std::lock_guard lock(mutex_);
	if (head != nullptr) {
		Node* newHead = new Node(value, head);
		head = newHead;
		std::cout << "Value Pushed\n";
		cv.NotifyOne();
	}
	else {
		Node* newHead = new Node(value, nullptr);
		head = newHead;
		std::cout << "Value Pushed\n";
		cv.NotifyOne();
	}
}

void Tester::Pop() {
	std::unique_lock locked(mutex_);
	while (head == nullptr)
	{
		cv.Wait(locked);
	}
	Node* buffer = head->next;
	delete head;
	head = buffer;
	std::cout << "Poped\n";
	
}
