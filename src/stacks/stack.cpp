#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

struct Stack {
	int* a;
	int capacity;
	int top;
};

struct Stack* createStack(int capacity) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->a = (int*)malloc(sizeof(int));
	stack->top = -1;
	return stack;
}

bool isFull(Stack* stack) {
	if(stack->top+1 == stack->capacity)
		return true;
	else
		return false;
}

bool isEmpty(Stack* stack) {
	if(stack->top == -1) 
		return true;
	else
		return false;
}

void push(Stack* stack, int x) {
	if(isFull(stack)) 
		return;
	stack->a[++stack->top] = x;
}

int pop(Stack* stack) {
	if(isEmpty(stack))
		return INT_MIN;
	return stack->a[stack->top--];
}

int size(Stack* stack) {
	return stack->top+1;
}

int peek(Stack* stack) {
	return stack->a[stack->top];
}

void printStack(Stack* stack) {
	for(int i=0; i<=stack->top; i++) 
		cout<<stack->a[i]<<" ";
	cout<<endl;
}

/*int main() {
	Stack* stack = createStack(100); 
    	push(stack, 10);
    	push(stack, 20);
    	push(stack, 30);
	printStack(stack);
 	pop(stack);
	printStack(stack);

 	return 0;
} */ 
