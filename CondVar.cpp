#include "CondVar.h"

void CondVar::Wait(std::unique_lock<std::mutex>& locker) {
	locker.unlock();
	WaintinQueue.TryPut();
	locker.lock();
	return;
}

void CondVar::NotifyOne() {
	WaintinQueue.GetOne();
}

