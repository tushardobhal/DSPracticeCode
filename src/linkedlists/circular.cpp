#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	Node *next;
};

void printList(Node *head) {
	Node *ptr = head;
	while(true) {
		cout<<ptr->data<<" ";
		ptr = ptr->next;
		if(ptr == head) {
			break;
		}
	}
	cout<<endl;	
}

void push(Node **head, int data) {
	Node *ptr = (Node*)malloc(sizeof(Node*));
	ptr->data = data;
	if(*head == NULL) {
		*head = ptr;
		ptr->next = *head;
	}
	else {
		Node* ptr1 = *head;
		while(true) {
			if(ptr1->next == *head) {
				ptr1->next = ptr;
				ptr->next = *head;
				*head = ptr;
				break;
			}
			ptr1 = ptr1->next;
		}
	}
}

void splitList(Node *head) {
	Node *sptr = head, *fptr = head;
	Node *sprev, *fprev;
	while(1) {
		sprev = sptr;
		sptr = sptr->next;
		fprev = fptr->next;
		fptr = fptr->next->next;
		if(fptr == head) {
			sprev->next = head;
			fprev->next = sptr;
			printList(head);
			printList(fprev);
			break;
		}
		if(fptr->next == head) {
			fptr->next = sptr->next;
			sptr->next = head;
			printList(head);
			printList(fptr);
			break;		
		}
	}
}
	
void checkIfCircular(Node *head) {
	Node *fptr = head, *sptr = head;
	while(1) {
		if(head->next && head->next->next) {
			fptr = fptr->next->next;
			sptr = sptr->next;
		}
		else {
			cout<<"FALSE"<<endl;
			break;
		}
		if(!fptr || !sptr)
			break;
		if(fptr == sptr) {
			if(fptr == head) 
				cout<<"TRUE"<<endl;
			else
				cout<<"FALSE"<<endl;
		break;
		} 
	}	
}

void josephusCircle(int n, int m) {
	Node *head = NULL;	
	for(int i=n; i>=1; i--) {
		push(&head, i);
	}
	printList(head);
	Node *ptr = head, *prev;
	while(1) {
		int i=1;
		while(i < m) {
			prev = ptr;
			ptr = ptr->next;
			++i;
		}
		prev->next = ptr->next;
		ptr = prev->next;
		if(ptr->next == ptr) {
			cout<<ptr->data<<endl;
			break;	
		}
	}
}

int main() {
	Node *head = NULL;
	push(&head, 6);	
	push(&head, 5);
    	push(&head, 4);
    	push(&head, 3);
    	push(&head, 2);
    	push(&head, 1);
	//printList(head);

	//splitList(head);
	
	//checkIfCircular(head);

	josephusCircle(14, 2);
} 
