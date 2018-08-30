#include "stack.cpp"

using namespace std;

struct Queue {
	Stack* s1;
	Stack* s2;
	int capacity;
};

bool isFull(Queue* q) {
	if(size(q->s1) + size(q->s2) >= q->capacity) 
		return true;
	else
		return false; 
}

bool isEmpty(Queue* q) {
	if(isEmpty(q->s1) && isEmpty(q->s2))
		return true;
	return false;
}

void enQueue(Queue* q, int a) {
	if(isFull(q))
		return;
	push(q->s1, a);
}

void deQueue(Queue* q) {
	if(isEmpty(q))
		return;
	if(isEmpty(q->s2)) {
		int len = size(q->s1);
		for(int i=0; i<len; i++) {
			int a = pop(q->s1);
			push(q->s2, a);
		}
	}
	cout<<"The element popped is "<<pop(q->s2)<<endl;
}	

void printQueue(Queue* q) {
	printStack(q->s1);
	printStack(q->s2);
}

void implementQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->capacity = 100;
	q->s1 = createStack(q->capacity);
	q->s2 = createStack(q->capacity);
	enQueue(q, 1);
	enQueue(q, 2);
	enQueue(q, 3);
	enQueue(q, 4);
	enQueue(q, 5);
	printQueue(q);
	deQueue(q);
	printQueue(q);
	deQueue(q);
	printQueue(q);
	enQueue(q, 6);
	printQueue(q);
}

struct SpecialStack {
	Stack* s1;
	Stack* s2;
	int capacity;
};

void push(SpecialStack* ss, int x) {
	if(isEmpty(ss->s1)) {
		push(ss->s2, x);
	} else {
		int y = peek(ss->s2);
		if(x < y) 
			push(ss->s2, x);
		else
			push(ss->s2, y);
	}
	push(ss->s1, x);
}

void pop(SpecialStack* ss) {
	cout<<"The element popped is "<<pop(ss->s1)<<endl;
	pop(ss->s2);
}

int getMin(SpecialStack* ss) {
	return peek(ss->s2);
}

void printStack(SpecialStack* ss) {
	printStack(ss->s1);
}

void implementSpecialStack() {
	SpecialStack* ss = (SpecialStack*)malloc(sizeof(SpecialStack));
	ss->capacity = 100;	
	ss->s1 = createStack(100);
	ss->s2 = createStack(100);
	push(ss, 18);
	push(ss, 19);
	push(ss, 29);
	push(ss, 15);
	push(ss, 16);
	cout<<"min = "<<getMin(ss)<<endl;
	pop(ss);
	pop(ss);
	cout<<"min = "<<getMin(ss)<<endl;
	printStack(ss);
}

struct TwoStacks {
	int* a;
	int top1;
	int top2;
	int capacity;
};

TwoStacks* createTwoStacks(int capacity) {
	TwoStacks* ts = (TwoStacks*)malloc(sizeof(TwoStacks));
	ts->a = (int*)malloc(sizeof(int));
	ts->capacity = capacity;
	ts->top1 = -1;
	ts->top2 = capacity;
	return ts;
}

void push1(TwoStacks* ts, int x) {	
	if(ts->top1 >= ts->top2) {
		cout<<"TwoStack full"<<endl;
		return;
	}
	ts->a[++ts->top1] = x;
}

void push2(TwoStacks* ts, int x) {
	if(ts->top1 >= ts->top2) {
		cout<<"TwoStack full"<<endl;
		return;
	}
	ts->a[--ts->top2] = x;
}

int pop1(TwoStacks* ts) {
	cout<<"The element popped is "<<ts->a[ts->top1]<<endl;
	ts->top1--;
}

int pop2(TwoStacks* ts) {
	cout<<"The element popped is "<<ts->a[ts->top2]<<endl;
	ts->top2++;
}

void implementTwoStacks() {
    TwoStacks* ts = createTwoStacks(5);
    push1(ts, 5);
    push2(ts, 10);
    push2(ts, 15);
    push1(ts, 11);
    push2(ts, 7);
    pop1(ts);
    push2(ts, 40);
    pop2(ts);
}

int main() {
	//implementQueue();
	//implementSpecialStack();
	implementTwoStacks();
 	return 0;
} 
