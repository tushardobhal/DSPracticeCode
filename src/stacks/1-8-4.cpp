#include "stack.cpp"

using namespace std;

int prec(char ch) {
	switch(ch) {
		case '^': {
			return 3;
			break;
		}
		case '*': { }
		case '/': {
			return 2;
			break;
		}
		case '+': { }
		case '-': {
			return 1;
			break;
		}
		default: {
			return -1;
		}
	}
}

bool isOperator(char ch) {
	return(ch == '^' || ch == '*' || ch == '/' || ch == '+' || ch == '-');
}

bool isOperand(char ch) {
	return((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

void infixToPostfix() {
	Stack* s = createStack(100);
	char e[] = "a+b*(c^d-e)^(f+g*h)-i";
	int k = -1;
	for(int i=0; e[i] != '\0'; i++) {
		if(isOperand(e[i]))
			e[++k] = e[i];
		else if(e[i] == '(') {
			push(s, e[i]);
		}
		else if(e[i] == ')') {			
			while(peek(s) != '(' && !isEmpty(s)) {
				e[++k] = pop(s);
			}
			if(!isEmpty(s) && peek(s) != '(')
				return;
			else
				pop(s);
		}
		else {
			while(!isEmpty(s) && prec(e[i]) <= prec(peek(s))) {
				e[++k] = pop(s);
			}
			push(s, e[i]);
		}
	}
	while(!isEmpty(s)) {
		e[++k] = pop(s);
	}
	e[++k] = '\0';
	cout<<e<<endl;
}

void stockSpan() {
	int price[] = {10, 4, 5, 90, 120, 80};
	int n = sizeof(price)/sizeof(price[0]);
	Stack* s = createStack(n);
	int* a = (int*)malloc(sizeof(int));
	a[0] = 1;
	push(s, price[0]);
	for(int i=1; i<n; i++) {
		int p = s->top;
		int m = 1;
		while(p!=-1 && s->a[p--] < price[i]) {
			++m;
		} 
		a[i] = m;
		push(s, price[i]);
	}
	for(int i=0; i<n; i++) 
		cout<<a[i]<<" ";
	cout<<endl;	
}

void nextGreaterEle() {
	int a[] = {4, 5, 2, 25};
	int n = sizeof(a)/sizeof(a[0]);
	Stack* s = createStack(n);
	for(int i=n-1; i>=0; i--)
		push(s, a[i]);
	int*as = (int*)malloc(sizeof(int));
	for(int i=0; i<n-1; i++) {
		int p = s->top;
		while(p!=-1 && s->a[--p] < s->a[s->top]);
		if(p == -1) 
			as[i] = -1;
		else
			as[i] = s->a[p];
		pop(s);	
	}
	as[n-1] = -1;
	for(int i=0; i<n; i++) 
		cout<<as[i]<<" ";
	cout<<endl;	
}

bool  MATRIX[8][8] = {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};
 
bool knows(int a, int b)
{
    return MATRIX[a][b];
}

void nCelebrityProb() {
	int n = 4;
	int a = 0;
	int b = n-1;
	while(a<b) {
		if(knows(a,b)) 
			++a;
		else
			--b;
	}
	for(int i=0; i<n; i++) {
		if(i!=a && (knows(a,i) || !knows(i,a)))
			a = -1;
	}
	cout<<a<<endl;
}

bool isDigit(char ch) {
	return(ch >= '0' && ch <= '9');
}

void evaluatePostfix() {
	char e[] = "231*+9-";
	Stack* s = createStack(100);
	for(int i=0; e[i]!='\0';++i) {
		if(isDigit(e[i]))
			push(s, e[i]-'0');
		else {
			int a = pop(s);
			int b = pop(s);
			switch(e[i]) {
			case '+': 
				push(s, b+a); break;
			case '-': 
				push(s, b-a); break;
			case '*': 
				push(s, b*a); break;
			case '/': 
				push(s, b/a); break;	
			}
		}
	}
	cout<<pop(s)<<endl;
}

void reverseStack() {
	Stack* s = createStack(100);
	push(s, 34);
    	push(s, 3);
    	push(s, 31);
    	push(s, 98);
    	push(s, 92);
    	push(s, 23);
	Stack* ts = createStack(s->capacity);
	while(!isEmpty(s)) {
		int temp = pop(s);
		while(!isEmpty(ts) && ts->a[ts->top] > temp) {
			push(s, pop(ts));
		}
		push(ts, temp);
	}
	printStack(ts);	
}

int main() {
	//infixToPostfix();
	//stockSpan();
	//nextGreaterEle();
	//nCelebrityProb();
	//evaluatePostfix();
	reverseStack();
 	return 0;
} 
