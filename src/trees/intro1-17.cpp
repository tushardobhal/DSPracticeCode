#include "bits/stdc++.h"

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void preOrder(Node* node)
{
    if (node == NULL) return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void inorder(Node* temp) {
	if(!temp) 
		return;
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}

void levelInsert(Node* root, int data) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if(!temp->left) {
			temp->left = newNode(data);
			break;
		} 
		else
			q.push(temp->left);
		if(!temp->right) {
			temp->right = newNode(data);
			break;
		} 
		else
			q.push(temp->right);
	}
}

void levelOrderInsert() {
    	Node* root = newNode(10);
    	root->left = newNode(11);
    	root->left->left = newNode(7);
    	root->right = newNode(9);
    	root->right->left = newNode(15);
    	root->right->right = newNode(8);
 
    	inorder(root);
 
    	int key = 12;
    	levelInsert(root, key);
 
    	inorder(root);
}

void deleteDeepestNode(Node* root, Node* deep) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if(temp->left) {
			if(temp->left == deep) {
				temp->left = NULL;
				delete(deep);
				return;
			}
			else
				q.push(temp->left);		
		}	
		if(temp->right) {
			if(temp->right == deep) {
				temp->right = NULL;
				delete(deep);
				return;
			}
			else
				q.push(temp->right);		
		}
	}
}

void delNode(Node* root, int data) {
	queue<Node*> q;
	q.push(root);
	Node* temp;
	Node* key;
	while(!q.empty()) {
		temp = q.front();
		q.pop();
		if(temp->data == data)
			key = temp;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	int x = temp->data;
	deleteDeepestNode(root, temp);
	key->data = x;
}

void deleteNode() {
	Node* root = newNode(10);
    	root->left = newNode(11);
    	root->left->left = newNode(7);
    	root->left->right = newNode(12);
    	root->right = newNode(9);
    	root->right->left = newNode(15);
    	root->right->right = newNode(8);
	
	inorder(root);
	cout<<endl;
	delNode(root, 11);
	inorder(root);
	cout<<endl;
}

bool isFoldableUtil(Node* a, Node* b) {
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;
	return (isFoldableUtil(a->left, b->right) && isFoldableUtil(a->right, b->left));
}

void isFoldableTree() {
	Node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->right  = newNode(4);
  	root->right->left = newNode(5);
	
	if(root == NULL) {
		cout<<"TRUE"<<endl;
		return;	
	}
	cout<<isFoldableUtil(root->left, root->right)<<endl;
}

bool isMirror(Node* a, Node* b) {
	if(a == NULL && b == NULL)
		return true;
	if(a == NULL || b == NULL)
		return false;
	if(a->data == b->data) {
		return (isMirror(a->left, b->right) && isMirror(a->right, b->left));
	}
	else
		return false;
}

void isSymmetric() {
	Node* root = newNode(1);
	root->left = newNode(2);
    	root->right = newNode(2);
    	root->left->left  = newNode(3);
    	root->left->right = newNode(4);
    	root->right->left = newNode(4);
    	root->right->right = newNode(3);
	
	cout<<isMirror(root, root)<<endl;
}

void mirror(Node* a, Node* b) {
	if(a == NULL || b==NULL) 
		return;
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
	mirror(a->left, b->right);
	mirror(a->right, b->left);
}

void mirrorTree() {
	Node* root = newNode(10);
    	root->left = newNode(11);
    	root->left->left = newNode(7);
    	root->left->right = newNode(12);
    	root->right = newNode(9);
    	root->right->left = newNode(15);
    	root->right->right = newNode(8);
	
	inorder(root);
	cout<<endl;
	mirror(root->left, root->right);	
	inorder(root);
	cout<<endl;
}

/*int main() {
	//levelOrderInsert();
	//deleteNode();
	//isFoldableTree();
	//isSymmetric();
	mirrorTree();	

	return 0;
}*/
