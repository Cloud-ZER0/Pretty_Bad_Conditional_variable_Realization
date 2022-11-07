#include "Task.h"
#include <iostream>

Task::Task() {
	tasker = [this]() {
		Routine();
	};
}

void Task::Routine() {
	std::cout << "Thread is in QUEUE\n";
	while (!sleep_.load()) {
		sleep_.wait(true);
	}
	std::cout << "Out Of Routine\n";
}

void Task::StartWork() {
	std::invoke(tasker);
}

void Task::Awake() {
	sleep_.store(true);
	sleep_.notify_one();
	std::cout << "Thread is awaked\n";
}

Task::Task(const Task& another) {
	tasker = another.tasker;
	sleep_.store(another.sleep_.load());
}
