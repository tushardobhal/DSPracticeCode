#include "bits/stdc++.h"

using namespace std;

void slidingWindowMax() {
	deque<int> d;
	int a[] = {12, 1, 78, 90, 57, 89, 56};
    	int n = sizeof(a)/sizeof(a[0]);
    	int k = 3;
	int i;
	for(i=0; i<k; i++) {
		while(!d.empty() && a[d.back()] <= a[i])
			d.pop_back();
		d.push_back(i);
	}
	for(; i<n; i++) {
		cout<<a[d.front()]<<" ";
		if(d.front() <= i-k)
			d.pop_front();
		 while(!d.empty() && a[d.back()] <= a[i])
			d.pop_back();
		d.push_back(i);
	}
	if(!d.empty()) 
		cout<<a[d.front()]<<" ";
	cout<<endl;
}

struct pp {
	int pet;
	int dis;
};

void circularTrackPetrolPump() {
	pp p[] = {{6, 4}, {3, 6}, {7, 3}};
	int n = sizeof(p)/sizeof(p[0]);
	queue<int> q;
	q.push(p[0].pet-p[0].dis);
	int start = 0;
	int end = 1;
	int c = q.front();
	while(start != end || c < 0) {
		while(c < 0 && !q.empty()) {
			c = c-q.front();
			q.pop();
			start = (start+1)%n;
			if(start == 0)
				start = -1;
		}
		int x = p[end].pet-p[end].dis;
		q.push(p[end].pet-p[end].dis);
		end = (end+1)%n;
		c = c+x;
	}
	cout<<start<<endl;
}

void minSumAfterKCharRemove() {
	string str = "abbccc";  
	int k = 2;
	priority_queue<int> q;
	int freq[26] = {0};
	for(int i=0; i<str.length(); i++)
		freq[str[i]-'a']++;
	for(int i=0; i<26; i++)
		q.push(freq[i]);
	while(k > 0) {
		int c = q.top();
		q.pop();
		--c;
		q.push(c);
		--k;
	}
	int res = 0;
	while(!q.empty()) {
		res += q.top()*q.top();
		q.pop();
	}
	cout<<res<<endl;
}

void firstNonRepeatingChar() {
	queue<char> q;
	string s = "aabc";
	int freq[26] = {0};
	for(int i=0; i<s.length(); i++) {
		q.push(s[i]);
		freq[s[i]-'a']++;
		while(!q.empty()) {
			if(freq[q.front()-'a'] > 1)
				q.pop();
			else {
				cout<<q.front()<<" ";
				break;
			}
		}
		if(q.empty())
			cout<<"-1 ";
	}
	cout<<endl;
}

int main() {
	//slidingWindowMax();
	//circularTrackPetrolPump();
	//minSumAfterKCharRemove();
	firstNonRepeatingChar();
	return 0;
}
