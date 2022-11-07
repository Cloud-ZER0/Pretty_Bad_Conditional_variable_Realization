#pragma once

#include <functional>
#include <atomic>

class Task
{
public:
	using CallableTask = std::function<void()>;
public:
	Task();
	~Task() = default;
	Task(const Task& another);
	void StartWork();
	void Awake();
private:
	void Routine();
private:
	CallableTask tasker;
	std::atomic_bool sleep_{false};
};

