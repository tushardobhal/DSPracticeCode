#include "intro1-17.cpp"

using namespace std;

bool checkChildrenSum(Node* root) {
	if(root == NULL)
		return true;
	if(root->left == NULL && root->right == NULL)
		return true;
	int ldata = root->left == NULL? 0:root->left->data;
	int rdata = root->right == NULL? 0:root->right->data;
	if(root->data != ldata + rdata) {
		return false;
	}	
	else {
		return checkChildrenSum(root->left) && checkChildrenSum(root->right);
	}
}

void checkChildrenSumProp() {
	Node *root  = newNode(10);
  	root->left         = newNode(8);
  	root->right        = newNode(2);
  	root->left->left   = newNode(3);
  	root->left->right  = newNode(5);
  	root->right->right = newNode(2);
	cout<<checkChildrenSum(root)<<endl;
}

int sum(Node*root) {
	if(root == NULL)
		return 0;
	return root->data+sum(root->left)+sum(root->right);
}

bool checkSumTree(Node* root) {
	if(root == NULL)
		return true;
	if(root->left == NULL && root->right == NULL)
		return true;
	int lsum = sum(root->left);
	int rsum = sum(root->right);
	if(lsum+rsum == root->data)
		return checkSumTree(root->left)&&checkSumTree(root->right);
	else
		return false;
}

void checkSumTreeProp() {
	Node *root  = newNode(26);
    	root->left         = newNode(10);
    	root->right        = newNode(3);
    	root->left->left   = newNode(4);
    	root->left->right  = newNode(6);
    	root->right->right = newNode(3);
	cout<<checkSumTree(root)<<endl;
}

int getSumTree(Node* root) {
	if(root == NULL)
		return 0;
	return root->data + getSumTree(root->left) + getSumTree(root->right);
}

int getUncovLeftSumTree(Node* root) {
	if(root->left == NULL && root->right == NULL)
		return root->data;
	if(root->left)
		return root->data + getUncovLeftSumTree(root->left);
	else if(root->right)
		return root->data + getUncovLeftSumTree(root->right);
}

int getUncovRightSumTree(Node* root) {
	if(root->left == NULL && root->right == NULL)
		return root->data;
	if(root->right)
		return root->data + getUncovRightSumTree(root->right);
	else if(root->left)
		return root->data + getUncovRightSumTree(root->left);
}

void checkUncoveredCoveredSum() {
	Node* root = newNode(8);
   	root->left = newNode(3);
    	root->left->left = newNode(1);
    	root->left->right = newNode(6);
    	root->left->right->left = newNode(4);
    	root->left->right->right = newNode(7);
    	root->right = newNode(10);
    	root->right->right = newNode(14);
    	root->right->right->left = newNode(13);
	int sum = getSumTree(root);
	int uncovSum = getUncovLeftSumTree(root->left)+getUncovLeftSumTree(root->right)+root->data;
	int covSum = sum - uncovSum;
	cout<<sum<<" "<<uncovSum<<" "<<(covSum==uncovSum)<<endl;
}

bool checkIfSameLevel(Node* root, Node* node1, Node* node2) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		int nodeCount = q.size();
		if(nodeCount == 0)
			break;
		bool flag1 = false, flag2 = false;		
		while(nodeCount > 0) {
			Node* temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			if(temp == node1)
				flag1 = true;
			if(temp == node2)
				flag2 = true;
			if(flag1 && flag2)
				return true;
			--nodeCount;	
		}
	}
	return false;
}

bool checkIfDiffParent(Node* root, Node* node1, Node* node2) {
	if(root == NULL)
		return true;
	if(root->left && root->right)
		if(root->left == node1 && root->right == node2)
			return false;
	return checkIfDiffParent(root->left, node1, node2) && checkIfDiffParent(root->right, node1, node2);		
}

void checkIfCousin() {
	Node *root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->left->right->right = newNode(15);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
    	root->right->left->right = newNode(8);
    	Node *node1,*node2;
    	node1 = root->left->left;
    	node2 = root->right->right;
	bool cond1 = checkIfSameLevel(root, node1, node2);
	bool cond2 = checkIfDiffParent(root, node1, node2);
	cout<<cond1<<" "<<cond2<<" "<<(cond1&&cond2)<<endl;
}

bool checkIfLeafAtSameLevel(Node* root) {
	queue<Node*> q;
	q.push(root);
	int nodeCount = 0, prevNodeCount = 0;
	while(!q.empty()) {
		nodeCount = q.size();
		if(nodeCount < prevNodeCount)
			return false;
		if(nodeCount == 0)
			break;	
		prevNodeCount = nodeCount;	
		while(nodeCount > 0) {
			Node* temp = q.front();
			q.pop();
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
			--nodeCount;	
		}
	}
	return true;
}

void checkIfLeavesAtSameLevel() {
	Node* root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->right = newNode(4);
    	root->right->left = newNode(5);
    	root->right->right = newNode(6);
	cout<<checkIfLeafAtSameLevel(root)<<endl;
}

int count(Node* root) {
	if(root == NULL)
		return 0;
	return count(root->left)+count(root->right)+1;
}

int countSplitTree(Node* root, int n, bool &res) {
	if(root == NULL)
		return 0;
	int c = countSplitTree(root->left, n, res)+1+countSplitTree(root->right, n, res);
	if(c == n-c)
		res = true;
	return c;
}

void checkIfTwoEqualTreesSplit() {
	Node* root = newNode(5);
    	root->left = newNode(1);
    	root->right = newNode(6);
   	root->left->left = newNode(3);
    	root->right->left = newNode(7);
    	root->right->right = newNode(4);
	int n = count(root);
	bool res = false;
	countSplitTree(root, n, res);
	cout<<res<<endl;
}

bool leafTraversalSame(Node* root1, Node* root2) {
	queue<Node*> q1;
	queue<Node*> q2;
	q1.push(root1);
	q2.push(root2);
	bool res = false;
	while(!q1.empty() || !q2.empty()) {
		int n1 = q1.size();
		int n2 = q2.size();
		if(n1 == 0 || n2 == 0)
			break;
		res = true;
		while(n1>0 && n2>0) {
			Node* temp1 = q1.front();
			Node* temp2 = q2.front();
			q1.pop();
			q2.pop();
			if(temp1->left)
				q1.push(temp1->left);
			if(temp1->right)
				q1.push(temp1->right);
			if(temp2->left)
				q2.push(temp2->left);
			if(temp2->right)
				q2.push(temp2->right);
			res = res&&(temp1->data == temp2->data);
			--n1;
			--n2;
		}
	}
	return res;
}

void checkIfLeafTraversalSame() {
	Node* root1 = newNode(1);
      	root1->left = newNode(2);
      	root1->right = newNode(3);
      	root1->left->left = newNode(4);
      	root1->right->left = newNode(6);
      	root1->right->right = newNode(7);
 
      	Node* root2 = newNode(0);
      	root2->left = newNode(1);
      	root2->right = newNode(5);
      	root2->left->right = newNode(4);
      	root2->right->left = newNode(6);
      	root2->right->right = newNode(7);

	cout<<leafTraversalSame(root1, root2)<<endl;
}

bool fullBinaryTree(Node* root) {
	if(root==NULL)
		return true;
	if(root->left==NULL && root->right == NULL)
		return true;
	if(root->left==NULL || root->right == NULL)
		return false;
	return fullBinaryTree(root->left)&&fullBinaryTree(root->right);
}

void checkFullBinaryTree() {
	Node* root = NULL;
    	root = newNode(10);
    	root->left = newNode(20);
    	root->right = newNode(30);
    	root->left->right = newNode(40);
    	root->left->left = newNode(50);
    	root->right->left = newNode(60);
    	root->right->right = newNode(70);
    	root->left->left->left = newNode(80);
    	root->left->left->right = newNode(90);
    	root->left->right->left = newNode(80);
    	root->left->right->right = newNode(90);
    	root->right->left->left = newNode(80);
    	root->right->left->right = newNode(90);
    	root->right->right->left = newNode(80);
    	root->right->right->right = newNode(90);
	cout<<fullBinaryTree(root)<<endl;
}

/*const char ch = '$';
unordered_set<string> trees;
string dupSubTree(Node* root) {
	string s = "";
	if(root == NULL)
		return s+ch;
	string lstr = dupSubTree(root->left);
	string rstr = dupSubTree(root->right);
	s = s+lstr+rstr;
	if(trees.find(s) != trees.end() && s.size() > 3)
		return "";
	trees.insert(s);
	return s;
}*/

void checkDuplicateSubTree() {
	Node *root = newNode('A');
    	root->left = newNode('B');
    	root->right = newNode('C');
    	root->left->left = newNode('D');
    	root->left->right = newNode('E');
    	root->right->right = newNode('B');
    	root->right->right->right = newNode('E');
    	root->right->right->left= newNode('D');
	
	//dupSubTree(root).compare("") == 0 ? cout<<"Yes" : cout<<"No";
	cout<<endl;
}

bool areMirror(Node* a, Node* b) {
	if(a==NULL && b==NULL)
		return true;
	if(a==NULL || b == NULL)
		return false;
	if(a->data != b->data)
		return false;
	return areMirror(a->left, b->right)&&areMirror(a->right, b->left);
}

void checkIfMirrorTree() {
	Node *a = newNode(1);
    	Node *b = newNode(1);
    	a->left = newNode(2);
    	a->right = newNode(3);
    	a->left->left  = newNode(4);
    	a->left->right = newNode(5);
    	b->left = newNode(3);
    	b->right = newNode(2);
    	b->right->left = newNode(5);
    	b->right->right = newNode(4);
	cout<<areMirror(a, b)<<endl;
}

void printMidLevel(Node* a, Node* b) {
	if(b == NULL || a == NULL)
		return;
	if(b->left == NULL && b->right == NULL) {
		cout<<a->data<<" ";
		return;
	}
	printMidLevel(a->left, a->left->left);
	printMidLevel(a->right, a->right->right);
}

void printMidLevelOfPErfectTree() {
	Node* n1 = newNode(1);
    	Node* n2 = newNode(2);
    	Node* n3 = newNode(3);
    	Node* n4 = newNode(4);
    	Node* n5 = newNode(5);
    	Node* n6 = newNode(6);
    	Node* n7 = newNode(7);
    	n2->left = n4;
    	n2->right = n5;
    	n3->left = n6;
    	n3->right = n7;
    	n1->left = n2;
    	n1->right = n3;
	printMidLevel(n1, n1);
	cout<<endl;
}

void printCousin(Node* root, Node* node) {
	queue<Node*> q;
	q.push(root);
	bool flag = false;	
	while(!q.empty() && !flag) {
		int n = q.size();
		if(n==0)
			break;
		while(n>0) {
			Node* temp = q.front();
			if(temp->left == node || temp->right == node) {
				flag = true;	
			}
			else {
				if(temp->left)
					q.push(temp->left);
				if(temp->right)
					q.push(temp->right);
			}	
			q.pop();
			--n;
		}
	}	
	if(flag) {
		if(q.size() == 1)
			cout<<"NONE"<<endl;
		else {
			while(!q.empty()) {
				cout<<q.front()->data<<" ";
				q.pop();
			}
		}
	}
	cout<<endl;
}

void printCousinsInBinaryTree() {
	Node *root = newNode(1);
    	root->left = newNode(2);
    	root->right = newNode(3);
    	root->left->left = newNode(4);
    	root->left->right = newNode(5);
    	root->left->right->right = newNode(15);
    	root->right->left = newNode(6);
    	root->right->right = newNode(7);
    	root->right->left->right = newNode(8);
	printCousin(root, root->left->right);
}

void printArray(int ints[], int len)
{
  	int i;
  	for (i=0; i<len; i++) {
  		printf("%d ", ints[i]);
  	}
  	printf("\n");
} 

void printPaths(Node* root, int path[], int len) {
	if(root == NULL)
		return;
	path[len++] = root->data;
	if(root->left == NULL && root->right == NULL)
		printArray(path, len);
	printPaths(root->left, path, len);
	printPaths(root->right, path, len);
}

void printPathsToNode() {
	Node *root = newNode(1);
  	root->left        = newNode(2);
  	root->right       = newNode(3);
  	root->left->left  = newNode(4);
  	root->left->right = newNode(5); 
	int path[100];
	printPaths(root, path, 0);
}

int main() {
	//checkChildrenSumProp();
	//checkSumTreeProp();
	//checkUncoveredCoveredSum();
	//checkIfCousin();
	//checkIfLeavesAtSameLevel();
	//checkIfTwoEqualTreesSplit();	
	//checkIfLeafTraversalSame();
	//checkFullBinaryTree();
	//checkDuplicateSubTree();
	//checkIfMirrorTree();
	//printMidLevelOfPErfectTree();	
	//printCousinsInBinaryTree();
	printPathsToNode();

	return 0;
}
