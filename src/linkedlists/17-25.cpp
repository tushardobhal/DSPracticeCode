#include <iostream>
#include <stdio.h>
#include "8-16.cpp"

using namespace std;

bool checkEqual(Node* a, Node* b) {
	while(a && b) {
		if(a -> data != b -> data) {
			return false;
		}
		a = a -> next;
		b = b -> next;
	}
	return true;
}

void checkPalindrome(Node* head) {
	Node* ptr = head;	
	int len = size(ptr);
	int i = 0;
	while(ptr) {
		if(len/2 == i) {
			if(len % 2 == 1) {
				ptr = ptr -> next;
				reverseList(&ptr);
			}
			else {
				reverseList(&ptr);
			}
			break;
		}
		ptr = ptr -> next;
		++i;
	}
	cout<<checkEqual(head, ptr)<<endl;
	reverseList(&ptr);
	printList(head);
}

Node* checkInPoint(Node* h1, Node* h2) {
	Node* p1, *p2;	
	int c1 = size(h1);
	int c2 = size(h2);
	int diff;
	if(c1 >= c2) {
		diff = c1 - c2;
		p1 = h1;
		p2 = h2;
	}
	else {
		diff = c2 - c1;
		p1 = h2;
		p2 = h1;
	}
	for(int i=0; i<diff; i++, p1 = p1 -> next);
	while(p1 && p2) {
		if(&(*p1) == &(*p2)) {
			return p1;
		}
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	return NULL;
}

void intersectionPoint() {
	struct Node* newNode;
  	struct Node* head1 = (struct Node*) malloc(sizeof(struct Node));
  	head1->data  = 10;
 
  	struct Node* head2 = (struct Node*) malloc(sizeof(struct Node));
  	head2->data  = 3;
 
  	newNode = (struct Node*) malloc (sizeof(struct Node));
  	newNode->data = 6;
  	head2->next = newNode;
 
  	newNode = (struct Node*) malloc (sizeof(struct Node));
  	newNode->data = 9;
  	head2->next->next = newNode;
 
  	newNode = (struct Node*) malloc (sizeof(struct Node));
  	newNode->data = 15;
  	head1->next = newNode;
  	head2->next->next->next  = newNode;
 
  	newNode = (struct Node*) malloc (sizeof(struct Node));
  	newNode->data = 30;
  	head1->next->next= newNode;
 
  	head1->next->next->next = NULL;
	
	printList(head1);
	printList(head2);
	cout<<checkInPoint(head1, head2) -> data<<endl;
}

void removeDuplicatesSorted(Node** head) {
	Node* ptr = *head;
	while(ptr && ptr -> next) {
		if(ptr -> data == ptr -> next -> data) {
			Node* temp = ptr -> next;
			free(ptr -> next);
			ptr -> next = temp -> next;
		}
		ptr = ptr -> next;
	}
	printList(*head);
}

void removeDuplicatesUnsorted(Node** head) {
	Node* p1 = *head, *p2 = p1 -> next;
	Node* prev;
	while(p1) {
		p2 = p1;
		while(p2 -> next) {
			if(p1 -> data == p2 -> next -> data) {
				Node* temp = p2 -> next;
				p2 -> next = p2 -> next -> next;
				free(temp);
			}
			else {
				p2 = p2 -> next;
			}
		}
		p1 = p1 -> next;
	}
	printList(*head);
}

void swap(Node* prev1, Node* ptr1, Node* prev2, Node* ptr2, Node** head) {
	if(prev1 == NULL) {
			*head = ptr2;
			prev2 -> next = ptr1;
	}
	else {
		prev1 -> next = ptr2;
		prev2 -> next = ptr1;
	}
	Node* temp = ptr1 -> next;
	ptr1 -> next = ptr2 -> next;
	ptr2 -> next = temp;
}

void pairWiseSwap(Node** head) {
	Node* ptr1 = *head;
	Node* ptr2 = ptr1 -> next;
	Node* prev1 = NULL;
	Node* prev2 = *head;
	while(1) {
		swap(prev1, ptr1, prev2, ptr2, head);
		prev1 = ptr1 -> next;
		prev2 = ptr2 -> next;
		if(ptr2 -> next && ptr2 -> next -> next) {
			ptr1 = ptr1 -> next -> next;
			ptr2 = ptr2 -> next -> next;
		}
		else {
			break;
		}
	}
	printList(*head);
}

void moveLastToFirst(Node** head) {
	/*Node* ptr = *head;
	Node* prev;
	while(ptr -> next) {
		prev = ptr;		
		ptr = ptr -> next;
	}
	prev -> next = NULL;
	ptr -> next = *head;
	*head = ptr; */
	reverseList(head);
	reverseList(&((*head) -> next));
	printList(*head);
}

Node* inSL(Node* h1, Node* h2) {
	Node dummy;
	Node* tail = &dummy;
	dummy.next = NULL;
	while(h1 != NULL && h2 != NULL) {
		if(h1 -> data == h2 -> data) {
			moveNode(&(tail -> next), &h1);
			tail = tail -> next;			
			h2 = h2 -> next;
		}
		else if(h1 -> data < h2 -> data) {
			h1 = h1 -> next;
		}
		else {
			h2 = h2 -> next;
		}
		
	}
	return (dummy.next);
}
void intersectionSortedList() {
	Node *head1 = NULL;
	push(&head1, 6);
	push(&head1, 4);
	push(&head1, 3);
	push(&head1, 1);
	printList(head1);	

	Node *head2 = NULL;
	push(&head2, 6);
	push(&head2, 5);
	push(&head2, 3);
	push(&head2, 0);
	printList(head2);

	printList(inSL(head1, head2));
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
	//checkPalindrome(head);

	//intersectionPoint();

	//removeDuplicatesSorted(&head);
	
	//removeDuplicatesUnsorted(&head);

	//pairWiseSwap(&head);

	//moveLastToFirst(&head);
	
	intersectionSortedList();
}*/
