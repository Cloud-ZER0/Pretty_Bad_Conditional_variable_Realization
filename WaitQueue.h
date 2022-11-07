#pragma once
#include <stack>
#include <functional>
#include <atomic>
#include"Task.h"

class WaitQueue
{
public:
	WaitQueue() = default;
	~WaitQueue() = default;
	WaitQueue(const WaitQueue& another) = delete;
	void TryPut();
	void GetOne();
	void GetAll();
private:
	std::stack<Task> buffer_;
	std::atomic<int> waker_{ 1 };
	std::atomic_bool is_busy_{ false };
};

