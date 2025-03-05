#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
int a,b;
vector<vector<pair<int,int>>> m;
#define W first
#define V second
int answer;
int d[1001];
#define ll long long

priority_queue<pair<ll, int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
void dijkstra(){
	d[a] = 0;
	pq.push({0, a});

	while (!pq.empty()){
		ll w; int x;
		tie(w, x) = pq.top(); pq.pop();
		if (x == b) {
			answer = d[b];
			return ;
		}
		for (int i = 0 ; i < m[x].size(); i++){
			ll nw; int nxt;
			tie(nw, nxt) = m[x][i];
			nw += d[x];
			if (d[nxt] > nw) {
				d[nxt] =nw;
				pq.push({nw, nxt});
			}
		}		
	}
}

int main(){
	cin >> N >> M;

	m.resize(N + 1);

	for (int i = 1; i <= N; i++){
		d[i] = 1e9;
	}

	for (int i = 0 ; i < M; i++){
		int u, v, w;
		cin >> u >> v >> w;
		m[u].push_back({w, v});
	}

	cin >> a >> b;

	dijkstra();
	cout << d[b] << "\n";
	

}