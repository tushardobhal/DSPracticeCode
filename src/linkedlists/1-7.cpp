#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	Node *next;
};

int size(Node *head) {
	int i;
	Node *ptr = head;
	for(i = 0; ptr != NULL; i++, ptr = ptr -> next);
	return i;
}

int sizeRec(Node *head) {
	if(head == NULL) {
		return 0;
	}
	else {
		return 1 + sizeRec(head -> next);
	}
}

void printList(Node *head) {
	cout<<"Size = " <<size(head)<<endl;
	Node *ptr = head;	
	while(ptr != NULL) {
		cout<<ptr -> data<< " ";
		ptr = ptr -> next;
	}
	cout<<"\n";
}

Node* basicList() {
	Node *head, *second, *third;	
	head = (Node*) malloc(sizeof(Node*));
	second = (Node*) malloc(sizeof(Node*));
	third = (Node*) malloc(sizeof(Node*));
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = NULL;	
	return head;
}

void push(Node** head, int data) {
	Node *ptr = (Node*) malloc(sizeof(Node*));
	ptr -> data = data;
	ptr -> next = *head;
	*head = ptr;
}

void append(Node* head, int data) {
	Node *ptr = head;
	while(ptr -> next != NULL) {
		ptr = ptr -> next;
	}
	Node *nptr = (Node*) malloc(sizeof(Node*));
	nptr -> data = data;
	nptr -> next = NULL;
	ptr -> next = nptr;
}

void insertAfter(Node* prev, int data) {
	Node *ptr = (Node*) malloc(sizeof(Node*));
	ptr -> data = data;
	ptr -> next = prev -> next;
	prev -> next = ptr;
}

void deleteKey(Node** head, int key) {
	Node *ptr = *head;
	if(ptr -> data == key) {
		*head = ptr -> next;
		free(ptr);
		return;
	}
	Node* prev;
	while(ptr -> data != key && ptr != NULL) {
		prev = ptr;
		ptr = ptr -> next;
	}
	prev -> next = ptr -> next;
	free(ptr);
}

void deleteAtPos(Node** head, int pos) {
	Node *ptr = *head;
	if(pos == 0) {
		*head = ptr -> next;
		free(ptr);
		return;
	}
	Node* prev;
	int i = 0;
	while(pos != i && ptr != NULL) {
		prev = ptr;		
		ptr = ptr -> next;
		++i;
	}
	prev -> next = ptr -> next;
	free(ptr);
}

/*int main() {
	Node *head = NULL;
	push(&head, 7);
    	push(&head, 1);
    	push(&head, 3);
    	push(&head, 2);
    	push(&head, 8);
    	printList(head);
    	deleteAtPos(&head, 4);
	deleteKey(&head, 2);
    	printList(head);	
} */
