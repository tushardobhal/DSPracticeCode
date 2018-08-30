#include <iostream>
#include <stdio.h>
#include "26-37.cpp"

#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

struct Node1
{
    int data;
    struct Node1 *next;
    struct Node1 *child;
};

struct Node2
{
	int data;
	Node2 *next;
	Node2 *random;
	Node2(int x) {
		data = x;
		next = random = NULL;
	}
};

void tripletSumCheck(Node* a, Node* b, Node* c, int sum) {
	mergeSort(&b);
	mergeSort(&c);
	reverseList(&c);
	Node* hb = b;
	Node* hc = c;
	while(a != NULL) {
		b = hb;
		c = hc;
		while(b != NULL && c != NULL) {
			int s = a -> data + b -> data + c -> data;
			if(s == sum) {
				cout<<a -> data<<" "<<b -> data<<" "<<c -> data<<endl;
				return;
			}
			else if(s < sum) {
				b = b-> next;
			}
			else {
				c = c -> next;
			}
		}
		a = a -> next; 
	}
	cout<<"NOT FOUND"<<endl;
}

void tripletSum() {
	Node *a = NULL;
	push(&a, 12);
	push(&a, 6);
	push(&a, 29);
	printList(a);
	Node *b = NULL;	
	push(&b, 23);
	push(&b, 5);
	push(&b, 8);
	printList(b);
	Node *c = NULL;	
	push(&c, 90);
	push(&c, 20);
	push(&c, 59);
	printList(c);
	
	int sum = 101;
	tripletSumCheck(a, b, c, sum);
}

void rotateList(Node** head, int k) {
	Node* ptr = *head;
	while(ptr -> next != NULL) {
		ptr = ptr -> next;	
	}
	ptr -> next = *head;
	Node* ptr1 = *head;
	for(int i=0;i<k-1;i++, ptr1 = ptr1 -> next);
	*head = ptr1 -> next;	
	ptr1 -> next = NULL;
	printList(*head);
}

void printList(struct Node1 *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void flatten(Node1** head) {
	Node1* ptr = *head;	
	Node1* tail;
	while(ptr -> next != NULL) {
		ptr = ptr -> next;	
	}
	tail = ptr;
	Node1* cur = *head;
	while(cur != NULL) {
		if(cur -> child != NULL) {
			tail -> next = cur -> child;
			Node1* temp = cur -> child;
			while(temp -> next != NULL) {
				temp = temp -> next;
			}
			tail = temp;
		}
		cur = cur -> next;
	}
	printList(*head);
}

struct Node1 *createList(int *arr, int n)
{
    struct Node1 *head = NULL;
    struct Node1 *p;
 
    int i;
    for (i = 0; i < n; ++i) {
        if (head == NULL)
            head = p = (struct Node1 *)malloc(sizeof(*p));
        else {
            p->next = (struct Node1 *)malloc(sizeof(*p));
            p = p->next;
        }
        p->data = arr[i];
        p->next = p->child = NULL;
    }
    return head;
}

void flattenList() {
    int arr1[] = {10, 5, 12, 7, 11};
    int arr2[] = {4, 20, 13};
    int arr3[] = {17, 6};
    int arr4[] = {9, 8};
    int arr5[] = {19, 15};
    int arr6[] = {2};
    int arr7[] = {16};
    int arr8[] = {3};
 
    /* create 8 linked lists */
    struct Node1 *head1 = createList(arr1, SIZE(arr1));
    struct Node1 *head2 = createList(arr2, SIZE(arr2));
    struct Node1 *head3 = createList(arr3, SIZE(arr3));
    struct Node1 *head4 = createList(arr4, SIZE(arr4));
    struct Node1 *head5 = createList(arr5, SIZE(arr5));
    struct Node1 *head6 = createList(arr6, SIZE(arr6));
    struct Node1 *head7 = createList(arr7, SIZE(arr7));
    struct Node1 *head8 = createList(arr8, SIZE(arr8));
 
 
    /* modify child pointers to create the list shown above */
    head1->child = head2;
    head1->next->next->next->child = head3;
    head3->child = head4;
    head4->child = head5;
    head2->next->child = head6;
    head2->next->next->child = head7;
    head7->child = head8;

    flatten(&head1);
}

void deleteMAfterN(Node **head, int m, int n) {
	Node *ptr = *head;
	while(ptr != NULL) {
		Node *prev;
		int i=0;
		while(ptr && i < m) {
			++i;
			prev = ptr;
			ptr = ptr->next;
		}
		int j=0;
		while(j<n && ptr) {
			++j;
			Node *temp = ptr;
			prev->next = ptr->next;
			ptr = temp->next;
			free(temp);
		}
		
	}
	printList(*head);
}

void mergeAltNode(Node **aa) {
	Node *a = *aa;	
	Node *b = NULL;
	push(&b, 55);
	push(&b, 44);
	push(&b, 33);
	push(&b, 22);
	push(&b, 11);
	Node *bb;
	while(a && b) {
		Node *tempA = a->next;
		Node *tempB = b;
		a->next = tempB;
		b = b->next;
		if(b != NULL) {
			tempB->next = tempA;
		}
		a = tempA;	
	} 
	if(a)
		printList(a);
	else
		printList(b);
	printList(*aa);
}

void print(Node2 *start)
{
    Node2 *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = "
             << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

Node2* copyList(Node2 *start) {
	Node2 *ptr = start;
	while(ptr) {
		Node2 *copy = new Node2(ptr->data);
		copy->next = ptr->next;
		copy->random = ptr->random;
		ptr->next = copy;	
		ptr = ptr->next->next;
	}
	ptr = start;
	Node2 *ptr2 = start->next;
	Node2* copy = ptr2;
	while(ptr && ptr2) {
		if(ptr->next) {
			ptr->next = ptr->next->next;
			ptr = ptr->next;
		}
		else {
			ptr = ptr->next;
		}
		if(ptr2->next) {
			ptr2->next = ptr2->next->next;
			ptr2 = ptr2->next;
		}
		else
			ptr2 = ptr2->next;
	}
	return copy;
}

void copyListWithArb() {
	Node2 *start = new Node2(1);
    	start->next = new Node2(2);
    	start->next->next = new Node2(3);
    	start->next->next->next = new Node2(4);
    	start->next->next->next->next = new Node2(5);
	start->random = start->next->next;
	start->next->random = start;
	start->next->next->random = start->next->next->next->next;
	start->next->next->next->random = start->next->next->next->next;
	start->next->next->next->next->random = start->next;
	print(start);
	cout<<endl;
	print(copyList(start));
	cout<<endl;	
	print(start);
}

/*int main() {
	Node *head = NULL;
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);
	printList(head);
	
	//tripletSum();
	
	//rotateList(&head, 4);

	//flattenList();

	//deleteMAfterN(&head, 3, 2);

	//mergeAltNode(&head);

	copyListWithArb();
} */
