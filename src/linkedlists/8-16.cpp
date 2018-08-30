#include <iostream>
#include <stdio.h>
#include "1-7.cpp"

using namespace std;

Node* getNode(Node* head, int key) {
	Node* ptr = head;
	while(ptr -> data != key && ptr != NULL) {
		ptr = ptr -> next;
	}
	return ptr;
}

Node* getPrevNode(Node *head, int key) {
	Node* ptr = head;
	if(ptr -> data == key) {
		return NULL;
	}
	Node *prev;
	while(ptr -> data != key && ptr != NULL) {
		prev = ptr;
		ptr = ptr -> next;
	}
	return prev;
}

void swapNodes(Node** head, int key1, int key2) {
	Node *pos1 = *head;
	Node *pos2 = *head;	
	Node *prev1,*prev2;
	while(pos1 != NULL && pos1 -> data != key1) {
		prev1 = pos1;
		pos1 = pos1 -> next;
	}
	while(pos2 != NULL && pos2 -> data != key2) {
		prev2 = pos2;
		pos2 = pos2 -> next;
	}

	Node* temp;
	if(prev1 == NULL) {
		*head = pos2;
	}
	else {
		prev1 -> next = pos2;
	}
	if(prev2 == NULL) {
		*head = pos1;
	}
	else {
		prev2 -> next = pos1;
	}
	temp = pos1 -> next;
	pos1 -> next = pos2 -> next;
	pos2 -> next = temp;
	printList(*head);
}

void getNthNode(Node *head, int n) {
	Node* ptr = head;
	for(int i=0; ptr != NULL; ++i, ptr = ptr -> next) {
		if(i == n) {
			break;
		}
	}
	cout<<ptr -> data<<endl;
}

void getMiddleNode(Node *head) {
	Node* p1 = head, *p2 = head;
	while(p1 -> next != NULL && p1 != NULL) {
		p2 = p2 -> next;
		p1 = p1 -> next -> next;
	}
	cout<<p2 -> data<<endl;
}

void getNthNodeFromLast(Node *head, int n) {
	Node* ptr1 = head, *ptr2 = head;
	for(int i=0; i<n; i++, ptr1 = ptr1 -> next);
	for(; ptr1 != NULL; ptr1 = ptr1 -> next, ptr2 = ptr2 -> next);
	cout<<ptr2 -> data<<endl;
}

int countKeyRec(Node* head, int key) {	
	if(head == NULL) {
		return 0;
	}
	if(head -> data == key) {
		return 1 + countKeyRec(head -> next, key);
	}
	else {
		return countKeyRec(head -> next, key);
	}
}

void reverseList(Node** head) {
	Node *prev = NULL;
	Node *current = *head;
	Node* next;
	while(current != NULL) {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void detectLoop(Node* head) {
	Node* p1 = head, *p2 = head;
	while(p1 && p1 -> next && p2) {
		if(p1 == p2) {
			cout<<"Loop Detected" <<endl;
			return;
		}
		p1 = p1 -> next -> next;
		p2 = p2 -> next;
	}
}

void moveNode(Node** dest, Node** insert) {
	Node* node = *insert;
	*insert = node -> next;
	node -> next = *dest;
	*dest = node;
}

Node* ms(Node* a, Node* b) {
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;
	while(1) {
		if(a == NULL) {
			tail -> next = b;
			break;
		}
		else if(b == NULL) { 
			tail -> next = a;
			break;
		}
		if(a -> data <= b -> data) 
			moveNode(&(tail -> next), &a);
		else
			moveNode(&(tail -> next), &b);
		tail = tail -> next;
	}
	return dummy.next;
}	

void sortedMerge() {
	Node *a = NULL;
	push(&a, 5);
	push(&a, 3);
	push(&a, 1);
	Node *b = NULL;
	push(&b, 6);
	push(&b, 4);
	push(&b, 2);
	Node* r = ms(a,b);
	printList(r);
}	

/*int main() {
	Node *head = NULL;
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	push(&head, 0);
	printList(head);

	//swapNodes(&head, 0, 3);

	//getNthNode(head, 1);

	//getMiddleNode(head);

	//getNthNodeFromLast(head, 3);

	//cout<<countKeyRec(head, 2)<<endl;

	//reverseList(&head);

	push(&head, 20);
    	push(&head, 4);
    	push(&head, 15);
    	push(&head, 10);
	head->next->next->next->next = head;
	detectLoop(head);

	sortedMerge();
}*/
