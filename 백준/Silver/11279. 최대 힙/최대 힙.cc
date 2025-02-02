#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
#define ui unsigned int

ui heap[100001];
#define MAXSIZE 100001
int sz;

void push(ui n){
	sz++;
	heap[sz] = n;

	int x = sz;
	int parent = x / 2;
	while (x > 1) {
			parent = x / 2;
		if (heap[parent] < heap[x]) {
			swap(heap[parent], heap[x]);
			x = parent;
		} else {
			break;
		}
	}
}

void pop(){
	if (sz == 0) { cout << "0\n"; return; }	
	
	swap(heap[1], heap[sz]);
	cout << heap[sz] << "\n";
	heap[sz] = 0;
	sz--;

	int x = 1;
	while (2* x <= sz) {
		if (heap[x] >= heap[2*x] && heap[x] >= heap[2*x + 1]) break;
		int swapIndex = heap[2*x] > heap[2*x + 1] ? 2 * x : 2 * x + 1;
		swap(heap[x], heap[swapIndex]);
		x = swapIndex;
	}
}

int N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++){
		int cmd;
		cin >> cmd;
		if (cmd == 0) pop();
		else push(cmd);
	}
}