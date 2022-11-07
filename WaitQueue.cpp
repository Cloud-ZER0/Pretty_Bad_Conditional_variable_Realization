#include "WaitQueue.h"
#include <iostream>

void WaitQueue::TryPut() {
	while (true) {
		if (!is_busy_.exchange(1)) {
			buffer_.push(Task());
			is_busy_.store(0);
			buffer_.top().StartWork();
			buffer_.pop();
			return;
		}
		else continue;
	}
}

void WaitQueue::GetOne() {
	std::cout << "Thread is notified\n";
	while (buffer_.empty()) {};
	buffer_.top().Awake();
}
