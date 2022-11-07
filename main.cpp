#include "Tester.h"


int main() {

	Tester test = Tester();

	std::thread t1([&]() {
		test.Pop();
	});

	std::thread t2([&]() {
		test.Pop();
	});

	std::thread t3([&]() {
		test.Push(1);
		});

	std::thread t4([&]() {
		test.Push(2);
	});

	t1.join();
	t2.join();
	t3.join();
	t4.join();

	return 0;
}