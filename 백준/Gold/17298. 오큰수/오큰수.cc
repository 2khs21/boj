#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <stack>
using namespace std;
#define INF 1e9

int N;
int arr[1000001];
int nge[1000001];

stack<int> s;

void checkNge(int value){
	while(!s.empty()){
		int si = s.top();
		if (arr[si] < value) {
			nge[si] = value;
			s.pop();
		}
		else break;
	}
}

int main(){
	cin >> N;
	for (int i =0 ;i < N; i++){
		cin >>arr[i];
	}
	s.push(0);
	for (int i = 1; i < N; i++){
		checkNge(arr[i]);
		s.push(i);
	}
	while(!s.empty()){
		int si = s.top();
		nge[si] = -1;
		s.pop();
	}

	for (int i = 0 ; i < N; i++){
		cout << nge[i] << " ";
	}
}