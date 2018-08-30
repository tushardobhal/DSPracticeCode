#include "bits/stdc++.h"

using namespace std;

#define MAX 100

class Dequeue {
	int a[MAX];
	int front;
	int rear;
	int size;
	public:
	Dequeue() {
		front = -1;
		rear = -1;
		size = 0;
	}
	void insertFront(int x);
	void insertRear(int x);
	void deleteFront();
	void deleteRear();	
	bool isEmpty();
	bool isFull();
};

bool Dequeue::isEmpty() {
	if(front == rear == -1)
		return true;
	return false;
}

bool Dequeue::isFull() {
	if((front == 0 && rear == MAX-1) || front == rear+1)
		return true;
	return false;
}

void Dequeue::insertFront(int x) {
	if(isFull()) {
		cout<<"Dequqeue is Full"<<endl;
		return;
	}
	if(front == -1)
		rear = front = 0;
	if(front == 0)
 		front = MAX-1;
	 else
		front = front-1;
	a[front] = x;	
	size += 1;
}

void Dequeue::insertRear(int x) {
	if(isFull()) {
		cout<<"Dequeue is Full"<<endl;
		return;
	}
	if(front == -1)
		rear = front = 0;
	if(rear == MAX-1) 
		rear = 0;
	else
		rear = rear+1;
	a[rear] = x;
	size += 1;
}

void Dequeue::deleteFront() {
	if(isEmpty()) {
		cout<<"Dequeue is Empty"<<endl;
		return;
	}
	if(front == MAX-1)
		front = 0;
	else
		front = front+1;
	if(front == rear+1)
		front = rear = -1;
	size -= 1;
}

void Dequeue::deleteRear() {
	if(isEmpty()) {
		cout<<"Dequeue is Empty"<<endl;
		return;
	}
	if(rear == 0)
		rear = MAX-1;
	else
		rear = rear - 1;
	if(front == rear+1)
		front = rear = -1;
	size -= 1;
}

int main() {
	

	return 0;
}

