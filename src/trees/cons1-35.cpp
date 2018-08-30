#include "intro1-17.cpp"

#define MAX 100

using namespace std;


int search(int in[], int x, int n) {
	for(int i=0; i<=n; i++) {
		if(in[i] == x)
			return i;
	}
	return -1;
}

Node* treeFromInPre(int in[], int pre[], int n) {
	Node* node = newNode(pre[0]);
	if(n < 0)
		return NULL;
	int root = search(in, node->data, n);
	node->left = treeFromInPre(in, pre+1, root-1);
	node->right = treeFromInPre(in+root+1, pre+root+1, n-root-1);
	return node;
}

void buildTreeFromInPre() {
	int in[] = {68, 66, 69, 65, 70, 67};
  	int pre[] = {65, 66, 68, 69, 67, 70};
	int n = sizeof(pre)/sizeof(pre[0]);
	Node* root = treeFromInPre(in, pre, n-1);
	inorder(root);
	cout<<endl;
}

Node* buildTree(int a[], int i, int n) {
	if(i > n)
		return NULL;
	Node* node = newNode(a[i]);
	node->left = buildTree(a, 2*i+1, n);
	node->right = buildTree(a, 2*i+2, n);
	return node;
}

void buildTreeFromArray() {
	int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    	int n = sizeof(arr)/sizeof(arr[0]);
	inorder(buildTree(arr, 0, n-1));
	cout<<endl;
}

Node* buildTreeFromPrePreM(int pre[], int preM[], int l, int h, int size) {
	static int preIndex = 0;	
	if(l>h || preIndex >= size)
		return NULL;
	Node* node = newNode(pre[preIndex++]);	
	if(l == h)
		return node;
	int i;
	for(i=l; i<=h; i++) {
		if(pre[preIndex] == preM[i])
			break;
	}
	if(i <= h) {
		node->left = buildTreeFromPrePreM(pre, preM, i, h, size);
		node->right = buildTreeFromPrePreM(pre, preM, l+1, i-1, size);
	}
	return node;
}

void consTreeFromPrePreM() {
	int pre[] = {1,2,4,5,3,6,7};
    	int preM[] = {1,3,7,6,2,5,4};
    	int size = sizeof(pre)/sizeof(pre[0]);
	int l = 0; int h = size-1;
	inorder(buildTreeFromPrePreM(pre, preM, l, h, size));
	cout<<endl;
}

Node* treeFromSpecPre(int pre[], char preLN[], int n) {
	static int preIndex = 0;
	if(preIndex >= n)
		return NULL;
	Node* node = newNode(pre[preIndex]);
	if(preLN[preIndex] == 'N') {
		++preIndex;
		node->left = treeFromSpecPre(pre, preLN, n);
		++preIndex;
		node->right = treeFromSpecPre(pre, preLN, n);
	}
	return node;
}

void buildTreeFromSpecPre() {
	int pre[] = {10, 30, 20, 5, 15};
    	char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    	int n = sizeof(pre)/sizeof(pre[0]);
	inorder(treeFromSpecPre(pre, preLN, n));
	cout<<endl;
}

bool a[MAX][MAX];

int ancestorMatrix(vector<int> anc, Node* root) {
	if(!root)
		return 0;	
	int data = root->data;
	for(int i=0; i<anc.size(); i++)
		a[anc[i]][data] = true;
	anc.push_back(root->data);
	int l = ancestorMatrix(anc, root->left);
	int r = ancestorMatrix(anc, root->right);	
	anc.pop_back();
	return l+r+1;
}

void consAncestorMatrix() {
	Node *root        = newNode(5);
    	root->left        = newNode(1);
    	root->right       = newNode(2);
    	root->left->left  = newNode(0);
    	root->left->right = newNode(4);
    	root->right->left = newNode(3);
	vector<int> anc;
	int n = ancestorMatrix(anc, root);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}

int max(int in[], int st, int en) {
	int max = 0;
	for(int i = st; i<en; i++) {
		if(a[i] > a[max])
			max = i;
	}
	return max;
}

Node* specTreeFromIn(int in[], int st, int en) {
	if(st == en)
		return NULL;
	int root = max(in, st, en);
	Node* node = newNode(in[root]);
	node->left = specTreeFromIn(in, st, root);
	node->right = specTreeFromIn(in, root+1, en);
	return node;
}

void buildSpecTreeFromIn() {
	int in[] = {5, 10, 40, 30, 28};
    	int en = sizeof(in)/sizeof(in[0]);
	inorder(specTreeFromIn(in, 0, en));
	cout<<endl;
}

int* search(int root, int p[], int n) {
	int* a = (int*) malloc(sizeof(int)); 
	int j = 0;	
	for(int i=0; i<n; i++) {
		if(p[i] == root)
			a[j++] = i;
	}
	return a;
}

Node* treeFromParentArray(int p[], int root, int n) {
	static int index = 0;
	if(index == n)
		return NULL;	
	Node* node = newNode(root);	
	int* child = search(root, p, n);
	if(child[0]) {
		++index;		
		node->left = treeFromParentArray(p, child[0], n);
	}
	if(child[1]) {
		++index;
		node->right = treeFromParentArray(p, child[1], n);
	}
	return node;
}

void buildTreeFromParentArray() {
	int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    	int n = sizeof parent / sizeof parent[0];
	int root = -1;	
	for(int i=0; i<n; i++) {
		if(parent[i] == -1)
			root = i;
	}
	inorder(treeFromParentArray(parent, root, n));
	cout<<endl;
}

int searchInPost(int in[], int x, int st, int n) {
	int i;	
	for(i=st; i<n; i++)
		if(in[i] == x)
			break;
	return i;
}

Node* treeFromInPost(int in[], int post[], int st, int n) {
	static int postIndex = n-1;
	if (postIndex < 0)
        	return NULL;
 
 	Node* node = newNode(post[postIndex]);
	--postIndex;
	
	int root = searchInPost(in, node->data, st, n);	
	node->right = treeFromInPost(in, post, root+1, n);
	node->left = treeFromInPost(in, post, st, root);
	return node;
}

void buildTreeFromInPost() {
	int in[]   = {4, 8, 2, 5, 1, 6, 3, 7};
    	int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    	int n = sizeof(in)/sizeof(in[0]);
	preOrder(treeFromInPost(in, post, 0, n));
	cout<<endl;
}

struct Knode {
	int data;
	vector<Knode*> child;
};

Knode* newKnode(int data) {
	Knode* node = (Knode*)malloc(sizeof(Knode*));
	node->data = data;
	return node;
}

Knode* buildKaryTree(int pre[], int n, int k, int h) {
	static int i = 0; 	
	if(i >= n)
		return NULL;
	Knode* node = newKnode(pre[i]);
	for(int j=0; j<k; j++) {
		if(h > 1) {
			++i;
			node->child.push_back(buildKaryTree(pre, n, k, h-1));
		}
		else {
			node->child.push_back(NULL);	
		}	
	}
	return node;
} 

void postorder(Knode* node, int k) {
	if(node == NULL)
		return;
	for(int i=0; i<k; i++)
		postorder(node->child[i], k);
	cout<<node->data<<" ";	
}

void buildKaryTreeFromPre() {
	int pre[] = { 1, 2, 5, 6, 7, 3, 8, 9, 10, 4 };
	int k = 3;
	int n = sizeof(pre)/sizeof(pre[0]);
	int h = 0;
	int x = 1;
	while(x<n) {
		++h;
		x = x + pow(k,h);
	}
	cout<<"Height = "<<++h<<endl;
	postorder(buildKaryTree(pre, n, k, h), k);
	cout<<endl;
}

void convertToDLL(Node* root, Node** head) {
	if(root == NULL)
		return;
	static Node* prev = NULL;
	convertToDLL(root->left, head);
	if(prev == NULL)
		*head = root;
	else {
		root->left = prev;
		prev->right = root;
	}	
	prev = root;
	convertToDLL(root->right, head);
}

void printList(Node* node )
{
    	while (node!=NULL)
    	{
        	cout<<node->data<<" ";
        	node = node->right;
    	}
	cout<<endl;
}

void convertTreeToDLL() {
	Node *root        = newNode(10);
    	root->left        = newNode(12);
    	root->right       = newNode(15);
    	root->left->left  = newNode(25);
    	root->left->right = newNode(30);
    	root->right->left = newNode(36);
	Node* head = NULL;
	convertToDLL(root, &head);
	printList(head);
}

void treeWithChildSumProp(Node* root) {
	if(root == NULL || (root->left == NULL && root->right == NULL))	
		return;
	treeWithChildSumProp(root->left);
	treeWithChildSumProp(root->right);
	int ldata=0, rdata=0, diff = 0;	
	if(root->left != NULL)
		ldata = root->left->data;
	if(root->right != NULL)	
		int rdata = root->right->data;
	diff = root->data - (ldata + rdata);
	root->data = root->data - diff;
}

void consTreeWithChildSumProp() {
	Node *root = newNode(50);
  	root->left        = newNode(7);
  	root->right       = newNode(2);
  	root->left->left  = newNode(3);
  	root->left->right = newNode(5);
  	root->right->left  = newNode(1);
  	root->right->right = newNode(30);
	treeWithChildSumProp(root);
	inorder(root);
	cout<<endl;
}

int sumTree(Node* node) {
	if(node == NULL)
		return 0;
	node->data += sumTree(node->left) + sumTree(node->right);
	return node->data;
}

void convertToSumTree() {
	Node* root = newNode(10);
  	root->left = newNode(-2);
  	root->right = newNode(6);
  	root->left->left = newNode(8);
 	root->left->right = newNode(-4);
  	root->right->left = newNode(7);
  	root->right->right = newNode(5);
	sumTree(root);
	inorder(root);
	cout<<endl;
}

int leftSumTree(Node* node) {
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL)
		return node->data;
	int lsum = leftSumTree(node->left);
	int rsum = leftSumTree(node->right);	
	node->data += lsum;	
	return node->data+rsum;
}

void convertToLeftSumTree() {
	Node *root  = newNode(1);
    	root->left         = newNode(2);
    	root->right        = newNode(3);
    	root->left->left   = newNode(4);
    	root->left->right  = newNode(5);
    	root->right->right = newNode(6);
	leftSumTree(root);
	inorder(root);
	cout<<endl;
}

int logicalAndTree(Node* root) {
	if(root == NULL)
		return 0;
	if(root->left == NULL && root->right == NULL)
		return root->data;
	
	root->data = logicalAndTree(root->left) & logicalAndTree(root->right);
	return root->data;
}

void convertToLogicalAndTree() {
	Node *root=newNode(0);
    	root->left=newNode(1);
    	root->right=newNode(0);
    	root->left->left=newNode(0);
    	root->left->right=newNode(1);
    	root->right->left=newNode(1);
	root->right->right=newNode(1);
	logicalAndTree(root);
	inorder(root);
	cout<<endl;
}

Node* flipTree(Node* root) {
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)	
		return root;
	Node* flipped = flipTree(root->left);
	root->left->left = root->right;
    	root->left->right = root;
   	root->left = NULL;
    	root->right = NULL;
	return flipped;
}

void convertToFlipTree() {
	Node* root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->right->left = newNode(4);
    	root->right->right = newNode(5);
	inorder(flipTree(root));
	cout<<endl;
}

int main() {
	//buildTreeFromInPre();
	//buildTreeFromArray();
	//consTreeFromPrePreM();
	//buildTreeFromSpecPre();
	//consAncestorMatrix();	
	//buildSpecTreeFromIn();
	//buildTreeFromParentArray();
	//buildTreeFromInPost();	
	//buildKaryTreeFromPre();
	//convertTreeToDLL();	
	//consTreeWithChildSumProp();	
	//convertToSumTree();
	//convertToLeftSumTree();	
	//convertToLogicalAndTree();	
	convertToFlipTree();	
	
	
	return 0;
}

