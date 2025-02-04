#include <iostream>

using namespace std;

#include <map>
#include <algorithm>
#include <queue>
/*

answer : 헛간 번호 / 거리 / 같은 거리 헛간개수
*/
/*
1번에서 가장 먼것들 찾기 (다익스트라)
*/

int N, M;
vector<int> dis;	
vector<vector<int>> graph;
queue<pair<int, int>> Q;

#define W first
#define NODE second
#define INF 1e9
int maxDis;
int dest;
int cnt;

void solution(){
	Q.push({0,1});
	dis[1] = 0;
	while(!Q.empty()){
		int w, node;
		tie(w, node) = Q.front();
		if (maxDis < w) {
			maxDis = w;
			dest = node;
			cnt = 1;
		} else if (maxDis == w) {
			dest = min(dest, node);
			cnt++;
		}
		Q.pop();
		int nw = w + 1;
		for (int i = 0; i < graph[node].size(); i++){
			int next = graph[node][i];
			if (nw < dis[next]){
				dis[next] = nw;
				Q.push({nw, next});
			}
		}
	}
}

int main(){
	cin >> N >> M;
	graph.resize(N + 1);
	dis.resize(N + 1);
	for (int i = 1 ; i <= N; i++){
		dis[i] = INF;
	}
	for (int i = 0 ; i < M; i++){
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	solution();
	
	cout << dest << " " << maxDis << " " << cnt;
	
}
