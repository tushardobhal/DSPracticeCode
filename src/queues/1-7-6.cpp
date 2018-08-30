#include "bits/stdc++.h"

using namespace std;

struct Queue {
	int* a;
	int capacity;
	int front;
	int rear;
};

Queue* createQueue(int capacity) {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->a = (int*)malloc(sizeof(int));
	q->capacity = capacity;
	q->front = 0;
	q->rear = -1;
	return q;
}
	
bool isEmpty(Queue* q) {
	if(q->front > q->rear) {
		cout<<"Underflow Condition"<<endl;
		return true;
	}
	return false;
}

bool isFull(Queue* q) {
	if(q->rear-q->front+1 == q->capacity) {
		cout<<"Overflow condition"<<endl;
		return true;
	}
	return false;
}

void enqueue(Queue* q, int x) {
	if(isFull(q)) 
		return;
	q->a[++q->rear] = x;
}

int dequeue(Queue* q) {
	if(isEmpty(q)) 
		return INT_MIN;
	return q->a[q->front++];
}

int size(Queue* q) {
	return(q->rear-q->front+1);
}

void print(Queue* q) {
	for(int i=q->front; i<=q->rear; i++) {
		cout<<q->a[i]<<" ";
	}
	cout<<endl;
}

class Stack {
	queue<int> q1;
	queue<int> q2;
	int curr_size;
	
	public:
	Stack() {
		curr_size = 0;
	}

	void push(int x) {
		q1.push(x); 
		++curr_size;
	}

	int pop() {
		if(q1.empty()) {
			cout<<"Underflow"<<endl;
			return INT_MIN;
		}
		while(q1.size() != 1) {
			int ele = q1.front();
			q1.pop();
			q2.push(ele);
		}
		int x = q1.front();
		q1.pop();
		queue<int> q = q1;
		q1 = q2;
		q2 = q;
		--curr_size;
		return x;
	}

	int size() {
		return curr_size;
	}

	void print() {
		for(int i
	}
};

void implementStackUsingQueue() {
	Stack s;
	s.push(1);
	cout<<s.size()<<endl;
	s.push(2);
	cout<<s.size()<<endl;
	s.push(3);
	cout<<s.size()<<endl;
	s.push(4);
	cout<<s.size()<<endl;
	s.pop();
	cout<<s.size()<<endl;
	
}

int main() {
	/*Queue* q = createQueue(1000);
 	enqueue(q, 10);
    	enqueue(q, 20);
    	enqueue(q, 30);
    	enqueue(q, 40);
	print(q);	
	dequeue(q);
	print(q);*/

	implementStackUsingQueue();	
	return 0;
}
