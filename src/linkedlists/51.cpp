#include <iostream>
#include <stdio.h>
#include "38-50.cpp"

using namespace std;

void insertionSort(Node **head) {
	Node *ptr = *head;
	Node *headS = NULL, *prev, *sorted;
	Node *nextPtr;
	while(ptr != NULL) {
		nextPtr = ptr->next;
		if(headS == NULL) {
			Node* temp = ptr;
			headS = temp;
			headS->next = NULL;
		}
		else {
			sorted = headS;
			while(sorted != NULL) {
				if(ptr->data <= sorted->data) {
					if(sorted == headS) {
						Node *temp = ptr;
						temp->next = headS;
						headS = temp;
					}
					else {
						Node *temp = ptr;
						temp->next = sorted;
						prev->next = temp;
					}
					break;
				}
				prev = sorted;
				sorted = sorted->next;
			}
			if(sorted == NULL) {
				prev->next = ptr;
				prev->next->next = NULL;
			}
		}
		ptr = nextPtr;
	}
	printList(headS);
}

void arrangeInPlace(Node *head) {
	Node *p = head;
	Node *tail = NULL, *p1 = NULL, *prev = NULL;
	while(1) {
		p1 = p;
		while(p1->next != NULL) {
			prev = p1;
			p1 = p1->next;
		}
		if(p1 == p || p->next == p1)
			break;
		prev->next = NULL;
		tail = p1;
		Node *temp = p->next;
		p->next = tail;
		tail->next = temp;
		p = p->next->next;
	}
	printList(head);
}

void arrangeOddEvenList(Node *head) {
	Node *ptr = head;
	Node od, ed;
	Node *otail = &od;
	Node *etail = &ed;
	od.next = NULL;
	ed.next = NULL;
	int i=1;
	while(ptr != NULL) {
		moveNode(&(otail->next), &ptr);	
		if(ptr)	
			moveNode(&(etail->next), &ptr);	
		otail = otail->next;
		etail = etail->next;
	}
	otail->next = ed.next;
	printList(od.next);
}

void swapPtrNode(Node *prev1, Node *ptr1, Node *prev2, Node *ptr2) {
	if(prev1 == NULL) {
		prev2->next = ptr1;
		
	}
	else {
		prev1->next = ptr2;
		prev2->next = ptr1;
	}
	Node *temp = ptr1->next;
	ptr1->next = ptr2->next;
	ptr2->next = temp;
}

void swapPtr(Node **p1, Node **p2) {
	Node* temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
void arrangeZigZag(Node *head) {
	Node *ptr1 = head;
	Node* ptr2 = ptr1->next;
	Node *prev1 = NULL;
	Node *prev2 = ptr1;
	for(int i=0;ptr2 != NULL; ++i) {
		if(i%2 == 0) {
			if(ptr1->data > ptr2->data) {
				swapPtrNode(prev1, ptr1, prev2, ptr2);
				swapPtr(&ptr1, &ptr2);
			} 
		}
		else {
			if(ptr1->data < ptr2->data) {
				swapPtrNode(prev1, ptr1, prev2, ptr2);
				swapPtr(&ptr1, &ptr2);
			}
		}
		prev1 = ptr1;
		prev2 = ptr2;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	printList(head);
}

void reverse(Node2 **head) {
	Node2 *ptr = *head;
	Node2 *prev = NULL, *next;	
	while(ptr) {
		next = ptr->next;
		ptr->next = prev;
		prev = ptr;
		ptr = next;
	}
	*head = prev;	
}

void pointArbToRightMax() {
	Node2 *head = new Node2(5);
    	head->next = new Node2(10);
    	head->next->next = new Node2(2);
    	head->next->next->next = new Node2(3);
	print(head);

 	reverse(&head);
	Node2 *ptr = head;
	Node2 *max = head;
	ptr = ptr->next;
	while(ptr) {
		ptr->random = max;
		if(ptr->data > max->data) {
			max = ptr;
		}
		ptr = ptr->next;
	} 
	reverse(&head);
	print(head);
}

void sortAbsoluteSortedList() {
	Node *head = NULL;
	push(&head, -5);
	push(&head, 4);
	push(&head, -3);
	push(&head, -2);
	push(&head, 1);
	printList(head);
	
	Node *ptr = head;
	Node *neg = NULL, *pos = NULL, *negT, *posH;
	while(ptr) {
		Node *nxt = ptr->next;
		if(ptr->data < 0) {
			if(neg == NULL) {			
				neg = ptr;
				neg->next = NULL;
				negT = neg;
			}
			else {
				Node *temp = ptr;
				temp->next = neg;
				neg = temp;
			}
		} 
		else {
			if(pos == NULL) {
				pos = ptr;
				pos->next = NULL;
				posH = pos;
			}
			else {
				Node *temp = ptr;
				pos->next = temp;
				temp->next = NULL;
				pos = temp;
			}
		}
		ptr = nxt;
	}
	negT->next = posH;
	printList(neg);
}

int getCommonCount(Node *a, Node *b) {
	int count = 0;
	for(;a && b; a = a->next, b = b->next) {
		if(a->data == b->data)
			++count;
		else
			break;
	}
	return count;
}

void lengthofLongestPalindrome(Node *head) {
	Node *ptr = head;
	Node *prev = NULL, *next;
	int len = 0;
	while(ptr) {
		next = ptr->next;
		ptr->next = prev;
		len = max(len, 2*getCommonCount(prev, next) + 1); //for odd
		len = max(len, 2*getCommonCount(ptr, next)); //for even
		prev = ptr;
		ptr = next;
	}
	cout<<len<<endl;
}

void moveKeyToLast(Node *head, int key) {
	Node *ptr = head;
	Node *tail;
		int size = 1;
	while(ptr->next) {
		ptr=ptr->next;
		++size;
	} 
	tail = ptr;
	ptr = head;
	Node *prev;
	int i = 0;
	while(i < size) {
		if(ptr->data == key) {
			Node *temp = ptr;
			prev->next = ptr->next;
			ptr = ptr->next;
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
		}
		else {
			prev = ptr;
			ptr = ptr->next;
		}
		++i;
	}
	printList(head);
}

void multiplyLists() {
	Node *first = NULL;
	push(&first, 6);
    	push(&first, 4);
    	push(&first, 9);
    	printList(first);
 	Node *second = NULL;
    	push(&second, 4);
    	push(&second, 8);
    	printList(second);

	int n1 = 0, n2 = 0;
	while(first || second) {
		if(first) {
			n1 = n1*10 + first->data;
			first = first->next;	
		}
		if(second) {
			n2 = n2*10 + second->data;
			second = second->next;
		}
	}
	cout<<n1*n2<<endl;
}

int main() {
	Node *head = NULL;
	push(&head, 6);
	push(&head, 2);
	push(&head, 3);
	push(&head, 2);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	
	//insertionSort(&head);

	//arrangeInPlace(head);

	//arrangeOddEvenList(head);

	//arrangeZigZag(head);
	
	//pointArbToRightMax();

	//sortAbsoluteSortedList();

	//lengthofLongestPalindrome(head);

	//moveKeyToLast(head, 2);

	multiplyLists();
}
