#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> p(100001, -1);
int cycleEdge;

int find(int x){
	if (p[x] < 0) {
		return x;
	}

	return p[x] = find(p[x]);
}

bool uni(int u, int v){
	u = find(u);
	v = find(v);

	if (u == v) return false ;

	if (u > v) swap(u, v);

	p[v] = u;
	return true;
}
int n, m;
int main(){
	cin >> n >> m;

	for (int i = 0 ; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (uni(u, v) == false){
			cycleEdge++;
		}
	}

	int com = 0;
	for (int i = 1; i <= n; i++){
		if (p[i] == -1) {
			com++;
		}
	}

	cout << cycleEdge + (com - 1);
	return 0;
	long long sub = cycleEdge;
	long long curE = m - sub;
	long long add = (n-1) - curE;

	
	cout << curE + add << "\n";

}