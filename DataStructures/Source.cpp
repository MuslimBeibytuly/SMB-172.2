#include <iostream>
using namespace std;
struct queue 
{
	int size = 1024;
	int data[1024];
	int tail = 0, head = 0;
};
void enqueue(int n, queue & q)
{
	if (q.tail + 1 >= q.size) 
	{
		q.tail -= q.size;
		if (q.head == q.tail) 
		{
			cout << "queue is full";
		}
	}
		q.data[q.tail++] = n;
}
int dequeue(queue & q) 
{
	++q.head;
}
int main() 
{
	queue q;
	enqueue(1, q);
	return 0;
}