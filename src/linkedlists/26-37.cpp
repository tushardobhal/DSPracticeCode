#include <iostream>
#include <stdio.h>
#include "17-25.cpp"

using namespace std;

void deleteAltNode(Node** head) {
	Node* ptr = *head;
	Node* prev = ptr;
	ptr = ptr -> next;
	while(ptr != NULL && prev != NULL) {
		Node* temp = ptr;
		prev -> next = ptr -> next;
		prev = prev -> next;
		if(prev != NULL)
			ptr = prev -> next;
		free(temp);
	}
	printList(*head);
} 

void altSplitList(Node* head) {
	Node* a = head;
	Node* aHead = a;
	head = head -> next;
	Node* b = head;
	Node* bHead = b;
	head = head -> next; 
	for(int i=2; head != NULL; i++, head =  head -> next) {
		if(i%2 == 0) {
			a -> next = head;
			a = head;
		}
		else {
			b -> next = head;
			b = head;
		}
	}
	a -> next = NULL;
	b -> next = NULL;
	printList(aHead);
	printList(bHead);
}

Node* reverseGroupK(Node* head, int k) {
	Node* ptr = head;
	Node* prev = NULL;
	Node *next;
	int i=0;
	while(i<k && ptr != NULL) {
		next = ptr -> next;
		ptr -> next = prev;
		prev = ptr;
		ptr = next;
		++i;
	}
	if(next != NULL)
		head -> next = reverseGroupK(next, k);	
	return prev;
}

void frontBackSplit(Node* head, Node** a, Node** b) {
	Node*f, *s;
	s = head;
	f = head -> next;
	while(f != NULL && f -> next != NULL) {
		s = s -> next;
		if(f -> next != NULL)
			f = f -> next -> next;
	}
	*a = head;
	*b = s -> next;
	s -> next = NULL;
}

void mergeSort(Node** head) {
	Node* ptr = *head;
	Node*a, *b;
	if(ptr == NULL || ptr -> next == NULL) {
		return;
	}
	frontBackSplit(ptr, &a, &b);
	mergeSort(&a);
	mergeSort(&b);
	*head = ms(a, b);
}

Node* reverseAltK(Node* head, int k, bool rev) {
	Node* ptr = head;
	Node* prev = NULL;
	Node *next;
	int i=0;
	while(i<k && ptr != NULL) {
		next = ptr -> next;
		if(rev) {
			ptr -> next = prev;
		}
		prev = ptr;
		ptr = next;
		++i;
	}
	if(next != NULL) {
		if(rev) 
			head -> next = reverseAltK(next, k, !rev);
		else
			prev -> next = reverseAltK(next, k, !rev);
	}
	if(rev)	
		return prev;
	else 
		return head;
}

void delNodeGreatOnRight(Node** head) {
	reverseList(head);
	Node* ptr = *head;
	int max = ptr -> data;
	while(ptr != NULL && ptr -> next != NULL) {
		if(ptr -> next -> data < max) {
			Node* temp = ptr -> next;
			ptr -> next = temp -> next;
			free(temp);
		}
		else {
			max = ptr -> next -> data;
			ptr = ptr -> next;
		}
	}
	reverseList(head);
	printList(*head);
}

void detectAndRemoveLoop(Node** head) {
	Node* fast = *head;
	Node*slow = *head;
	Node* prev;
	int flag = 0;
	while(fast || fast -> next) {
		fast = fast -> next -> next;
		slow = slow -> next;
		if(fast == slow) {
			flag = 1;
			slow = *head;
			while(fast != slow) {
				prev = fast;
				fast = fast -> next;
				slow = slow -> next;
			}
		}
		if(flag)
			break;	
	}
	prev -> next = NULL;
	printList(*head);
}

void unionIntersection(Node* p1) {
	Node *p2 = NULL;
	push(&p2, 7);
	push(&p2, 5);
	push(&p2, 4);
	push(&p2, 2);
	printList(p2);
	mergeSort(&p1);
	mergeSort(&p2);
	printList(ms(p1, p2));
	printList(inSL(p1, p2));
}

/*int main() {
	Node *head = NULL;
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	
	//deleteAltNode(&head);

	//altSplitList(head);
	
	//printList(reverseGroupK(head, 4));
	
	//mergeSort(&head);

	//printList(reverseAltK(head, 2, true));
	
	//delNodeGreatOnRight(&head);

	//head->next->next->next->next->next->next = head->next->next;
	//detectAndRemoveLoop(&head);

	unionIntersection(head);
}*/
