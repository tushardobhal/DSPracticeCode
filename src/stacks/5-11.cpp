#include "stack.cpp"

using namespace std;

struct DLL {
	DLL* next;
	DLL* prev;
	int data;
};

struct DLLStack {
	DLL* head;
	DLL* mid;
	int count;
};

DLLStack* createDLLStack() {
	DLLStack* ds = (DLLStack*)malloc(sizeof(DLLStack));
	ds->head = NULL;
	ds->mid = NULL;
	ds->count = 0;
	return ds;
}

void push(DLLStack* ds, int x) {
	DLL* node = (DLL*)malloc(sizeof(DLL));
	node->data = x;
	node->prev = NULL;
	if(ds->head == NULL) {
		node->next = NULL;
	} else {
		ds->head->prev = node;
		node->next = ds->head;
	}
	ds->head = node;
	++ds->count;
	if(ds->count % 2 == 1) {
		if(ds->count == 1) {
			ds->mid = ds->head;
		} else {
			ds->mid = ds->mid->prev;
		}
	}
}

int pop(DLLStack* ds) {
	int a = ds->head->data;	
	ds->head = ds->head->next;
	--ds->count;
	if(ds->count % 2 == 0) {
		ds->mid = ds->mid->next;
	}
	return a;
}

int findMiddle(DLLStack* ds) {
	return ds->mid->data;
}

void printDLLStack(DLLStack* ds) {
	DLL* d = ds->head;
	while(d) {
		cout<<d->data<<" ";
		d = d->next;
	}
	cout<<endl;
}

void impStackWithMiddleNode() {
	DLLStack* ms = createDLLStack();
	push(ms, 11);
    	push(ms, 22);
    	push(ms, 33);
    	push(ms, 44);
    	push(ms, 55);
    	push(ms, 66);
    	push(ms, 77);
 	printDLLStack(ms);
    	printf("Item popped is %d\n", pop(ms));
   	printf("Item popped is %d\n", pop(ms));
	printDLLStack(ms);
    	printf("Middle Element is %d\n", findMiddle(ms));
}

struct MinMaxStack {
	int* a;
	int top;
	int capacity;
	int min;
	int max;
};

MinMaxStack* create(int capacity) {
	MinMaxStack* s = (MinMaxStack*)malloc(sizeof(MinMaxStack));
	s->a = (int*)malloc(sizeof(int));
	s->capacity = capacity;
	s->top = -1;
	s->min = INT_MAX;
	s->max = INT_MIN;
	return s;
}

void push(MinMaxStack* s, int x) {
	if(s->top == -1) {
		s->a[++s->top] = x;
		s->min = x;
		s->max = x;
	} else {
		if(x < s->min) {
			s->a[++s->top] = 2*x-s->min;
			s->min = x;
		}
		else if(x > s->max) {
			s->a[++s->top] = 2*x-s->max;
			s->max = x;
		} else {
			s->a[++s->top] = x;
		}
	}
}

void pop(MinMaxStack* s) {
	int x = s->a[s->top--];
	int t = x;
	if(x < s->min) {
		t = s->min;
		s->min = 2*s->min-x;
	} 
	if(x > s->max) {
		t = s->max;
		s->max = 2*s->max-x;
	}
	cout<<"Element popped is "<<t<<endl;
}

void getMin(MinMaxStack* s) {
	cout<<"Min element is "<<s->min<<endl;
}

void getMax(MinMaxStack* s) {
	cout<<"Max element is "<<s->max<<endl;
}

void implementMinMaxStack() {
	MinMaxStack* s = create(100);
	push(s, 3);
    	push(s, 5);
    	getMin(s);
	getMax(s);
   	push(s, 2);
    	push(s, 1);
    	getMin(s);
	getMax(s);
    	pop(s);
    	getMin(s);
	getMax(s);
    	pop(s);
	getMin(s);
	getMax(s);
	push(s, 6);
	getMin(s);
	getMax(s);
}

int main() {
	//impStackWithMiddleNode();
	implementMinMaxStack();
 	return 0;
} 
