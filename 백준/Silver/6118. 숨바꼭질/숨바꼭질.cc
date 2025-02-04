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
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
#define W first
#define NODE second
#define INF 1e9

int maxDis;
int dest;
int cnt;

void dijkstra(){
	pq.push(make_pair(0, 1));
	dis[1] = 0;
	while(!pq.empty()){
		int w, node;
		tie(w, node) = pq.top();
		pq.pop();
		if (w > maxDis) {
			maxDis = w;
			dest = node;
			cnt = 1;
		} else if (w == maxDis){
			dest = min(dest, node);
			cnt++;
		}
		for (int i = 0 ; i < graph[node].size(); i++){
			int nw, next;
			nw = dis[node] + 1;
			next = graph[node][i];
			if (dis[next] > nw) {
				dis[next] = nw;
				pq.push(make_pair(nw, next));
			}
		}
	}
}

int main(){
	cin >> N >> M;
	graph.resize(N + 1);
	dis.resize(N + 1);
	for (int i = 1; i <= N; i++){
		dis[i] = INF;
	}
	for (int i = 0 ; i < M; i++){
		int v, u;
		cin >> v >> u;
		graph[v].push_back(u);
		graph[u].push_back(v);
	}

	dijkstra();
	
	cout << dest << " " << maxDis << " " << cnt;
	
}
