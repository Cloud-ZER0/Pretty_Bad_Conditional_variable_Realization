#pragma once
#include <mutex>
#include <thread>
#include <utility>
#include "WaitQueue.h"


class CondVar
{
public:
	CondVar() = default;
	~CondVar() = default;
	CondVar(const CondVar& another) = delete;
	void Wait(std::unique_lock<std::mutex>& locker);
	void NotifyOne();
	void NotifyAll();
private:
	WaitQueue WaintinQueue;
};

