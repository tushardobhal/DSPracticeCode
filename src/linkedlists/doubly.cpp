#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node {
	int data;
	Node *next;
	Node *prev;
};

void printList(Node *head) {
	Node *ptr = head;
	while(ptr != NULL) {
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	cout<<endl;
}

void push(Node **head, int data) {
	Node *ptr = (Node*)malloc(sizeof(Node*));
	ptr->data = data;
	if(*head == NULL) {
		ptr->next = NULL;
		ptr->prev = NULL;
		*head = ptr;
	}
	else {
		ptr->next = *head;
		ptr->prev = NULL;
		ptr->next->prev = ptr;
		*head = ptr;
	}
}

void deleteNode(Node **head, Node *del) {
	if(del == *head) {
		*head = del->next;
		(*head)->prev = NULL;
	}
	else if(del->next == NULL) {
		del->prev->next = NULL;
	}
	else {
		del->prev->next = del->next;
		del->next->prev = del->prev;
	}
	free(del);
	printList(*head);
}

void reverseList(Node **head) {
	Node *ptr = *head;
	Node *next, *prev = NULL;
	while(ptr) {
		next = ptr->next;
		ptr->next = prev;
		ptr->prev = next;
		prev = ptr;
		ptr = next;
	}
	*head = prev;
	printList(*head);
}

void swapNode(Node **head, Node *prev1, Node *ptr1, Node *prev2, Node *ptr2) {
	if(prev1 == NULL) {
		*head = ptr2;
	}
	else {
		prev1->next = ptr2;
	}
	if(prev2 == NULL) {
		*head = ptr1;
	}
	else {
		prev2->next = ptr1;
	}
	Node *temp = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = temp;
	
	Node *temp1 = ptr1->prev;
	ptr1->prev = ptr2->prev;
	ptr2->prev = temp1;
}

void swapK(Node **head, int k) {
	Node *ptr = *head;	
	Node *ptr1, *ptr2;
	Node *prev1 = NULL, *prev2 = NULL;
	int i=1;	
	while(i<k) {
		prev1 = ptr;
		ptr = ptr->next;
		++i;
	}
	ptr1 = ptr;
	ptr2 = *head;
	while(ptr->next != NULL) {
		prev2 = ptr2;
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}
	swapNode(head, prev1, ptr1, prev2, ptr2);
	printList(*head);
}

Node* getCopy(Node *head) {
	Node *ptr = head;
	Node *sec = NULL, *ptr2;
	while(ptr) {
		Node *temp = (Node*)malloc(sizeof(Node*));
		temp->data = ptr->data;
		temp->next = temp->prev = NULL;
		if(sec == NULL) {
			sec = temp;
			ptr2 = sec;
			ptr = ptr->next;
			continue;
		}
		ptr2->next = temp;
		ptr2->next->prev = ptr2;
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}
	return sec;
}

void findTriplet(Node *head, int sum) {
	Node *ptr = head, *tail, *ptrTail;
	Node *sec = getCopy(head);
	while(ptr->next) {
		ptr = ptr->next;
	}
	tail = ptr;
	while(sec) {
		ptr = head;
		ptrTail = tail;
		while(ptr != ptrTail) {
			if(sec->data == ptr->data || sec->data == ptrTail->data)
				break;
			if(sec->data+ptr->data+ptrTail->data == sum) {
				cout<<sec->data<< " "<<ptr->data<<" "<<ptrTail->data<<endl;
				ptr = ptr->next;
				ptrTail = ptrTail->prev;
			}
			else if(sec->data+ptr->data+ptrTail->data < sum) {
				ptr = ptr->next;
			}
			else {
				ptrTail = ptrTail->prev;
			}
		}
		sec = sec->next;
	}
}

void moveNode(Node *prev, Node **dest, Node **ptr, bool isPrev) {
	Node *temp = *ptr;
	if(isPrev)
		*ptr = temp->prev;
	else
		*ptr = temp->next;
	if(prev) {
		temp->prev = prev;
	}
	else
		temp->prev = NULL;
	temp->next = *dest;
	*dest = temp;
}

void sortBiotonic(Node **head) {
	Node *ptr = *head, *tail;
	while(ptr->next) 
		ptr = ptr->next;
	tail = ptr;
	ptr = *head;
	Node dummy;
	Node *t = &dummy;
	dummy.next = NULL;
	while(ptr != tail) {
		if(ptr->data < tail->data) {
			moveNode(t, &(t->next), &ptr, false);
		}
		else {
			moveNode(t, &(t->next), &tail, true);
		}
		t = t->next;
	}
	printList(dummy.next);
}

int main() {
	Node *head = NULL;
	push(&head, 1);
	push(&head, 4);	
	push(&head, 6);	
	push(&head, 10);
    	push(&head, 12);
    	push(&head, 7);
    	push(&head, 5);
    	push(&head, 2);
	printList(head);
	
	/*deleteNode(&head, head);
	deleteNode(&head, head->next);
	deleteNode(&head, head->next);	*/

	//reverseList(&head);

	//swapK(&head, 4);

	//findTriplet(head, 15);

	sortBiotonic(&head);
} 
