#include "intro1-17.cpp"

using namespace std;

void levelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left) 
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	cout<<endl;	 
}

void preorder(Node* temp) {
	if(temp == NULL)
		return;
	cout<<temp->data<<" ";
	preorder(temp->left);
	preorder(temp->right);
}

void postorder(Node* temp) {
	if(temp == NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
	cout<<temp->data<<" ";
}

void traversal() {
	Node *root = newNode(1);
     	root->left = newNode(2);
     	root->right = newNode(3);
     	root->left->left = newNode(4);
     	root->left->right = newNode(5);
	inorder(root);
	cout<<endl;	
	preorder(root);
	cout<<endl;
	postorder(root); 
	cout<<endl;
}

void inorderWoRecursion() {
	Node *root = newNode(1);
     	root->left = newNode(2);
     	root->right = newNode(3);
     	root->left->left = newNode(4);
     	root->left->right = newNode(5);

	stack<Node*> s;
	Node* cur = root;
	do {
		while(cur != NULL) {
			s.push(cur);
			cur = cur->left;
		}
		Node* ele = s.top();
		s.pop();
		cout<<ele->data<<" ";
		cur = ele->right;
	} while(!s.empty() || cur != NULL);	
	cout<<endl;			
}

int search(int x, int a[], int n) {
	for(int i=0; i<n; i++) {
		if(a[i] == x)
			return i;
	}
	return -1;
}

void printPostOrder(int in[], int pre[], int n) {
	int root = search(pre[0], in, n);
	if(root != 0)
		printPostOrder(in, pre+1, root);
	if(root != n-1)	
		printPostOrder(in+root+1, pre+root+1, n-root-1);
	cout<<pre[0]<<" ";
}

void postFromInAndPreOrder() {
	int in[] = {4, 2, 5, 1, 3, 6};
   	int pre[] = {1, 2, 4, 5, 3, 6};
	int n = sizeof(in)/sizeof(in[0]);
	printPostOrder(in, pre, n);
	cout<<endl;
}

void storeInOrder(Node* root, vector<int> &a) {
	if(root == NULL)
		return;
	storeInOrder(root->left, a);
	a.push_back(root->data);
	storeInOrder(root->right, a);
}

void replaceInOrderNodeWithPreSuc(Node* root, vector<int> a) {
	static int i = 1;
	if(root == NULL)
		return;
	replaceInOrderNodeWithPreSuc(root->left, a);
	root->data = a[i-1] + a[i+1];
	++i;
	replaceInOrderNodeWithPreSuc(root->right, a);
}

void replaceWithInOrderPreSuc() {
	Node* root = newNode(1); 
    	root->left = newNode(2);        
    	root->right = newNode(3);       
    	root->left->left = newNode(4);  
    	root->left->right = newNode(5);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
	
	preorder(root);
	cout<<endl;
	vector<int> a;
	a.push_back(0);
	storeInOrder(root, a);
	a.push_back(0);	
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	cout<<endl;	
	replaceInOrderNodeWithPreSuc(root, a);
	preorder(root);
	cout<<endl;
}

vector<Node*> getTrees(int in[], int start, int end) {
	vector<Node*> trees;
	if(start > end) {
		trees.push_back(NULL);
		return trees;
	}
	for(int i=start; i<=end; i++) {
		vector<Node*> lTrees = getTrees(in, start, i-1);
		vector<Node*> rTrees = getTrees(in, i+1, end);
		for(int j=0; j<lTrees.size(); j++) {
			for(int k=0; k<rTrees.size(); k++) {
				Node* node = newNode(in[i]);
				node->left = lTrees[j];
				node->right = rTrees[k];
				trees.push_back(node);
			}
		}
	}
	return trees;
}

void allSubTreesFromInorder() {
	int in[] = {4, 5, 7};
    	int n = sizeof(in) / sizeof(in[0]);
  
    	vector<Node *> trees = getTrees(in, 0, n-1);
	for(int i=0; i<trees.size(); i++) {
		preorder(trees[i]);
		cout<<endl;	
	}
}

void spiralLevelOrder(Node* root) {
	stack<Node*> s1;
	stack<Node*> s2;
	s1.push(root);
	while(!s1.empty() || !s2.empty()) {
		while(!s1.empty()) {
			Node* temp = s1.top();
			cout<<temp->data<<" ";
			s1.pop();
			if(temp->right)
				s2.push(temp->right);
			if(temp->left)
				s2.push(temp->left);
		}
		while(!s2.empty()) {
			Node* temp = s2.top();
			cout<<temp->data<<" ";
			s2.pop();
			if(temp->left)
				s1.push(temp->left);
			if(temp->right)
				s1.push(temp->right); 
		}
	}
	cout<<endl;
}

void spiralLevelOrderTraversal() {
	Node *root = newNode(1);
    	root->left        = newNode(2);
    	root->right       = newNode(3);
    	root->left->left  = newNode(7);
    	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	root->right->right = newNode(4);
	levelOrder(root);
	spiralLevelOrder(root);
	cout<<endl;
}

void reverseLevelOrder(Node* root) {
	stack<Node*> s;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* temp = q.front();
		s.push(temp);
		q.pop();
		if(temp->left) 
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	while(!s.empty()) {
		cout<<s.top()->data<<" ";
		s.pop();
	} 
	cout<<endl;
}

void reverseLevelOrderTraversal() {
	Node *root = newNode(1);
    	root->left        = newNode(2);
    	root->right       = newNode(3);
    	root->left->left  = newNode(7);
    	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	root->right->right = newNode(4);
	levelOrder(root);
	reverseLevelOrder(root);
}

void lineLevelOrder(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int nodeCount = q.size();
		if(nodeCount == 0)
			break;
		while(nodeCount > 0) {
			Node* temp = q.front();
			q.pop();
			if(temp->left) 
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			cout<<temp->data<<" ";
			--nodeCount;
		}
		cout<<endl;
	}
}

void lineLevelOrderTraversal() {
	Node *root = newNode(1);
    	root->left        = newNode(2);
    	root->right       = newNode(3);
    	root->left->left  = newNode(7);
    	root->left->right = newNode(6);
    	root->right->left  = newNode(5);
    	root->right->right = newNode(4);
	levelOrder(root);
	lineLevelOrder(root);
}

void twoLevelDirectionChange(Node* root) {
	queue<Node*> q;
	q.push(root);
	stack<Node*> s;
	int ct = 0;
	bool leftToRight = true;
	while(!q.empty()) {
		++ct;
		int nodeCount = q.size();
		if(nodeCount == 0)
			break;
		while(nodeCount > 0) {
			Node* temp = q.front();
			q.pop();
			if(temp->left) 
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			if(leftToRight)
				cout<<temp->data<<" ";
			else
				s.push(temp);
			--nodeCount;
		}
		if(!leftToRight) {
			while(!s.empty()) {
				cout<<s.top()->data<<" ";
				s.pop();
			}
		}
		if(ct == 2) {
			ct = 0;
			leftToRight = !leftToRight;
		}
		cout<<endl;
	}
}

void twoLevelDirectionChangeTraversal() {
	Node* root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(9);
    	root->left->right->left = newNode(3);
    	root->left->right->right = newNode(1);
    	root->right->left->left = newNode(4);
    	root->right->left->right = newNode(2);
    	root->right->right->left = newNode(7);
    	root->right->right->right = newNode(2);
    	root->left->right->left->left = newNode(16);
    	root->left->right->left->right = newNode(17);
    	root->right->left->right->left = newNode(18);
    	root->right->right->left->right = newNode(19);
	lineLevelOrder(root);
	twoLevelDirectionChange(root);
}

void binaryTreeSpecificOrder(Node* root) {
	cout<<root->data<<" "<<root->left->data<<" "<<root->right->data<<" ";
	queue<Node*> q;
	q.push(root->left);
	q.push(root->right);
	while(!q.empty()) {
		Node* fir = q.front();
		q.pop();
		Node* sec = q.front();
		q.pop();
		cout<<fir->left->data<<" "<<sec->right->data<<" "<<fir->right->data<<" "<<sec->left->data<<" ";
		if(fir->left->left != NULL) {
			q.push(fir->left);
			q.push(sec->right);
			q.push(fir->right);
			q.push(sec->left);
		}
	}
	cout<<endl;
}

void binaryTreeSpecificOrderTraversal() {
	Node *root = newNode(1);
    	root->left        = newNode(2);
    	root->right       = newNode(3);
    	root->left->left  = newNode(4);
    	root->left->right = newNode(5);
    	root->right->left  = newNode(6);
    	root->right->right = newNode(7);
     	root->left->left->left  = newNode(8);
    	root->left->left->right  = newNode(9);
    	root->left->right->left  = newNode(10);
    	root->left->right->right  = newNode(11);
    	root->right->left->left  = newNode(12);
    	root->right->left->right  = newNode(13);
    	root->right->right->left  = newNode(14);
    	root->right->right->right  = newNode(15);
     	root->left->left->left->left  = newNode(16);
    	root->left->left->left->right  = newNode(17);
    	root->left->left->right->left  = newNode(18);
    	root->left->left->right->right  = newNode(19);
    	root->left->right->left->left  = newNode(20);
    	root->left->right->left->right  = newNode(21);
    	root->left->right->right->left  = newNode(22);
    	root->left->right->right->right  = newNode(23);
    	root->right->left->left->left  = newNode(24);
    	root->right->left->left->right  = newNode(25);
    	root->right->left->right->left  = newNode(26);
    	root->right->left->right->right  = newNode(27);
    	root->right->right->left->left  = newNode(28);
    	root->right->right->left->right  = newNode(29);
    	root->right->right->right->left  = newNode(30);
    	root->right->right->right->right  = newNode(31);

	binaryTreeSpecificOrder(root);
}	

void binaryTreeSpecificOrder2(Node* root) {
	stack<Node*> s;	
	s.push(root);
	s.push(root->right);
	s.push(root->left);
	queue<Node*> q;
	q.push(root->left);
	q.push(root->right);
	while(!q.empty()) {
		Node* fir = q.front();
		q.pop();
		Node* sec = q.front();
		q.pop();
		s.push(sec->left);
		s.push(fir->right);
		s.push(sec->right);
		s.push(fir->left);		
		if(fir->left->left != NULL) {
			q.push(fir->right);
			q.push(sec->left);
			q.push(fir->left);
			q.push(sec->right);	
		}
	}
	while(!s.empty()) {
		cout<<s.top()->data<<" ";
		s.pop();
	}
	cout<<endl;
}

void binaryTreeSpecificOrderTraversal2() {
	Node *root = newNode(1);
    	root->left        = newNode(2);
    	root->right       = newNode(3);
    	root->left->left  = newNode(4);
    	root->left->right = newNode(5);
    	root->right->left  = newNode(6);
    	root->right->right = newNode(7);
     	root->left->left->left  = newNode(8);
    	root->left->left->right  = newNode(9);
    	root->left->right->left  = newNode(10);
    	root->left->right->right  = newNode(11);
    	root->right->left->left  = newNode(12);
    	root->right->left->right  = newNode(13);
    	root->right->right->left  = newNode(14);
    	root->right->right->right  = newNode(15);
     	root->left->left->left->left  = newNode(16);
    	root->left->left->left->right  = newNode(17);
    	root->left->left->right->left  = newNode(18);
    	root->left->left->right->right  = newNode(19);
    	root->left->right->left->left  = newNode(20);
    	root->left->right->left->right  = newNode(21);
    	root->left->right->right->left  = newNode(22);
    	root->left->right->right->right  = newNode(23);
    	root->right->left->left->left  = newNode(24);
    	root->right->left->left->right  = newNode(25);
    	root->right->left->right->left  = newNode(26);
    	root->right->left->right->right  = newNode(27);
    	root->right->right->left->left  = newNode(28);
    	root->right->right->left->right  = newNode(29);
    	root->right->right->right->left  = newNode(30);
    	root->right->right->right->right  = newNode(31);

	binaryTreeSpecificOrder2(root);
}

void revAltNodes(Node* r1, Node* r2, bool rev) {
	if(r1 == NULL || r2 == NULL)
		return;
	if(rev) {
		int temp = r1->data;
		r1->data = r2->data;
		r2->data = temp;
	}
	revAltNodes(r1->left, r2->right, !rev);
	revAltNodes(r1->right, r2->left, !rev);
}

void reverseAltNodes() {
	Node *root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
    	root->left->left->left = newNode(8);
    	root->left->left->right = newNode(9);
    	root->left->right->left = newNode(10);
    	root->left->right->right = newNode(11);
    	root->right->left->left = newNode(12);
    	root->right->left->right = newNode(13);
    	root->right->right->left = newNode(14);
    	root->right->right->right = newNode(15);
	lineLevelOrder(root);
	revAltNodes(root->left, root->right, true);
	lineLevelOrder(root);
}

void preorderWoRecursion() {
	Node *root = newNode(1);
     	root->left = newNode(2);
     	root->right = newNode(3);
     	root->left->left = newNode(4);
     	root->left->right = newNode(5);
	preorder(root);
	cout<<endl;
	stack<Node*> s;
	s.push(root);
	while(!s.empty()) {
		Node* temp = s.top();
		cout<<temp->data<<" ";
		s.pop();
		if(temp->right)
			s.push(temp->right);
		if(temp->left)		
			s.push(temp->left);
	}
	cout<<endl;
}

void postorderWoRecursion() {
	Node *root = newNode(1);
     	root->left = newNode(2);
     	root->right = newNode(3);
     	root->left->left = newNode(4);
     	root->left->right = newNode(5);
	postorder(root);
	cout<<endl;
	stack<Node*> s1, s2;
	s1.push(root);
	while(!s1.empty()) {
		Node* temp = s1.top();
		s2.push(temp);
		s1.pop();
		if(temp->left)
			s1.push(temp->left);
		if(temp->right)
			s1.push(temp->right);
	}
	while(!s2.empty()) {
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
	cout<<endl;
}

void printDiagonalElements() {
	Node* root = newNode(8);
    	root->left = newNode(3);
    	root->right = newNode(10);
    	root->left->left = newNode(1);
    	root->left->right = newNode(6);
    	root->right->right = newNode(14);
    	root->right->right->left = newNode(13);
    	root->left->right->left = newNode(4);
    	root->left->right->right = newNode(7);

	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		Node* temp = q.front();
		q.pop();
		if(temp == NULL) {
			if(q.empty())
				return;
			cout<<endl;
			q.push(NULL);
		}
		else {
				while(temp) {
				cout<<temp->data<<" ";
				if(temp->left)
					q.push(temp->left);
				temp = temp->right;
			}
		}
	
	}
	cout<<endl;
}

void printLeftBoundary(Node* root) {
	if(root) {	
		if(root->left) {
			cout<<root->data<<" ";
			printLeftBoundary(root->left);
		}
		else if(root->right) {
			cout<<root->data<<" ";
			printLeftBoundary(root->right);
		}
	}
}

void printRightBoundary(Node* root) {
	if(root) {	
		if(root->right) {
			printRightBoundary(root->right);
			cout<<root->data<<" ";
		}
		else if(root->left) {
			printRightBoundary(root->left);
			cout<<root->data<<" ";
		}
	}
}
	
void printLeaves(Node* root) {
	if(root) {
		printLeaves(root->left);
		if(!root->left && !root->right)
			cout<<root->data<< " ";
		printLeaves(root->right);
	}
}	

void traverseBoundaryElements() {
	Node *root         = newNode(20);
    	root->left                = newNode(8);
    	root->left->left          = newNode(4);
    	root->left->right         = newNode(12);
    	root->left->right->left   = newNode(10);
    	root->left->right->right  = newNode(14);
    	root->right               = newNode(22);
    	root->right->right        = newNode(25);
	
	printLeftBoundary(root);
	printLeaves(root->left);
	printLeaves(root->right);
	printRightBoundary(root);
	cout<<endl;
}

int main() {
	//traversal();
	//inorderWoRecursion();
	//postFromInAndPreOrder();	
	//replaceWithInOrderPreSuc();
	//allSubTreesFromInorder();	
	//spiralLevelOrderTraversal();
	//reverseLevelOrderTraversal();
	//lineLevelOrderTraversal();	
	//twoLevelDirectionChangeTraversal();
	//binaryTreeSpecificOrderTraversal();
	//binaryTreeSpecificOrderTraversal2();
	//reverseAltNodes();
	//preorderWoRecursion();
	//postorderWoRecursion();
	//printDiagonalElements();
	//traverseBoundaryElements();	

	return 0;
}
