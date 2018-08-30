#include "bits/stdc++.h"
#include "math.h"

using namespace std;

struct Interval {
	int s;
	int e;
};

bool compareStart(Interval i1, Interval i2) {
	return (i1.s < i2.s);
}

void mergeIntervals() {
	stack<Interval> stack;
	Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} };
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr, arr+n, compareStart);
	stack.push(arr[0]);
	for(int i=1; i<n; i++) {
		Interval a = arr[i];
		if(stack.top().e < a.s)
			stack.push(a);
		else if(stack.top().e > a.s) {
			Interval i1 = stack.top();
			if(i1.e < a.e)
				i1.e = a.e;
			stack.pop();
			stack.push(i1);
		}
	}
	while(!stack.empty()) {
		cout<<"{"<<stack.top().s<<", "<<stack.top().e<<"}";
		stack.pop();
	}
	cout<<endl;
}

void largestHistArea() {
	int hist[] = {6, 2, 5, 4, 5, 1, 6};
    	int n = sizeof(hist)/sizeof(hist[0]);
	stack<int> s;
	int max = 0;
	int i=0;	
	while(i<n) {
		if(s.empty() || hist[i] > hist[s.top()])
			s.push(i++);
		else {
			int h = s.top();
			s.pop();
			int area = hist[h]*(s.empty() ? i : (i-s.top()-1));
			if(area > max)
				max = area;
		}
	}
	while(!s.empty()) {
		int h = s.top();
		s.pop();
		int area = hist[h]*(s.empty() ? i : (i-s.top()-1));
		if(area > max)
			max = area;
	}
	cout<<max<<endl;
}

void largestDepthParanthesis() {
	char ch[] = "b)(c)()";
	int n = 0;
	int len = 0;
	for(int i=0; ch[i]!='\0'; i++) {
		if(ch[i] == '(' || ch[i] == ')') {
			if(ch[i] == '(')
				++n;
			else
				--n;	
		}
		else {
			if(n > len)
				len = n;
		}
	}
	if(n == 0)
		cout<<len<<endl;
	else
		cout<<"-1"<<endl;
}

void maxOfMinArrayWindow() {
	int arr[]  = {10, 20, 30, 50, 10, 70, 30};
	int n = sizeof(arr)/sizeof(arr[0]);	
	stack<int> s;
	int left[n+1], right[n+1];
	for(int i=0; i<n; i++) {
		left[i] = -1;
		right[i] = n;
	}
	for(int i=0; i<n; i++) {
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			left[i] = s.top();
		s.push(i);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1; i>=0; i--) {
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			right[i] = s.top();
		s.push(i);
	}
	int ans[n+1];
	for (int i=0; i<=n; i++)
        	ans[i] = 0;
	for(int i=0; i<n; i++) {
		int len = right[i] - left[i] - 1;
		ans[len] = max(ans[len], arr[i]);
	}
	for (int i=n-1; i>=1; i--)
        	ans[i] = max(ans[i], ans[i+1]);

	for(int i=1; i<=n; i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

void bracketReversals() {
	string e = "}{{}}{{{";
	int len = e.length();
	stack<char> s;
	for(int i=0; i<len; i++) {
		if(!s.empty() && e[i] == '}' && s.top() == '{')
			s.pop();
		else
			s.push(e[i]);
	}
	int n = 0;
	int m = s.size();
	while(!s.empty()) {
		if(s.top() == '}') {		
			++n;
		}
		s.pop();
	}
	cout<<(ceil((n/2.0)) + ceil((m - n)/2.0))<<endl; 
}

void maxOfLeftRightMin() {
	int arr[] = {2, 4, 8, 7, 7, 9, 3};
	int n = sizeof(arr)/sizeof(arr[0]);
	stack<int> s;
	int left[n], right[n];
	for(int i=0; i<n; i++) {
		left[i] = right[i] = 0;	
	}
	for(int i=0; i<n; i++) {
		while(!s.empty() && arr[i] >= s.top())
			s.pop();
		if(!s.empty())
			left[i] = s.top();
		s.push(arr[i]);
	}
	while(!s.empty())
		s.pop();
	for(int i=n-1; i>=0; i--) {
		while(!s.empty() && arr[i] >= s.top())
			s.pop();
		if(!s.empty())
			right[i] = s.top();
		s.push(arr[i]);
	}
	for(int i=0; i<n; i++)
		cout<<left[i]<<" ";
	cout<<endl;
	for(int i=0; i<n; i++)
		cout<<right[i]<<" ";
	cout<<endl;
	int r = 0;
	for(int i=0; i<n; i++) {
		r = max(r, abs(left[i] - right[i]));
	}
	cout<<r<<endl;
}
	
void decodeStringCount() {
	char ch[] = "3[b2[ca]]";
	string ans = "";
	stack<char> s;
	int j = 0;
	for(int i=0; ch[i] != '\0'; i++) {
		if(ch[i] >= '0' && ch[i] <= '9')
			s.push(ch[i]);
		else if(ch[i] >= 'a' && ch[i] <= 'z')
			s.push(ch[i]);
		else if(ch[i] == '[')
			s.push(ch[i]);
		else {
			while(!s.empty() && s.top() != '[') {
				ans = ans + s.top();
				s.pop();
			}
			s.pop();
			for(int k=0; k<s.top() -'0'-1; k++)
				ans = ans + ans;
		}
	} 
	for(int i=ans.length()-1; i>=0; i++)
		cout<<ans[i];
	cout<<endl;
}

void matchTextPattern() {
	string p = "ABC";
	string t = "ABABCABCC";
	stack<char> s;
	for(int i=0; i<t.length(); i++)
		s.push(t[i]);
	cout<<s.size()<<endl;
	int res = 0;
	while(!s.empty()) {
		int m = 0;
		for(int i=p.length()-1; i>=0; i--) {
			if(!s.empty() && s.top() == p[i]) {
				s.pop();
				++m;
			} else {
				break;
			}
		}
		if(m == p.length())
			++res;
	}
	cout<<res<<endl;
}

int main() {	
	//mergeIntervals();
	//largestHistArea();
	//largestDepthParantheis();
	//maxOfMinArrayWindow();
	//bracketReversals(); 	
	//maxOfLeftRightMin();
	//decodeStringCount();
	//matchTextPattern();
	
	return 0;
} 
