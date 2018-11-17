#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
enum Error_code{overflow,underflow,success};
const int maxqueue = 100;
class queue {
public:
	queue();
	Error_code enqueue(const int&item);
	Error_code dequeue();
	Error_code serve();
private:
	int count;
	int front;
	int rear;
	int entry[maxqueue];
};
queue::queue() {
	count = 0;
	front = 0;
	rear =maxqueue-1;
}
Error_code queue::enqueue(const int&item) {
	if (count >= maxqueue)
		return overflow;
	count++;
	rear = ((rear + 1) == maxqueue) ? 0:rear++;
	entry[rear] = item;
	return success;
}
Error_code queue::serve() {
	if (count <= 0) {
		return underflow;
	}
	else {
		count--;
		front = ((front + 1) == maxqueue) ? 0 : front++;
		return success;
	}
}
Error_code queue::dequeue() {
	if (count <= 0) {
		cout << "-1" << endl;
		return underflow;
	}
	else {
		for (int i = 0;i < count;i++)
			cout << entry[i];
		cout << endl;
		while (count != 0) {
			serve();
		}
		return success;
	}
}
int main() {
	queue my;
	int m;
	cin >> m;
	string s1[100];
	int a[100];
	for (int i = 0;i < m;++i) {
		cin >> s1[i];
		if (s1[i] == "enqueue") {
			char str[100];
			cin >> str;
			sscanf_s(str, "%d", &a[i]);
		}
	}
	for (int i = 0;i < m;i++) {
		if (s1[i] == "dequeue")
			my.dequeue();
		else if (s1[i] == "enqueue") {
			my.enqueue(a[i]);
		}
	}
	return 0;
}