#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Edge {
  int to;
  int isDown;
};
int primBest(vector<vector<Edge>>& graph, int N) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>>
      pq;
  vector<bool> visited(N, false);
  int count = 0;
  visited[0] = true;
  for (auto& next : graph[0]) pq.push({next.isDown, next.to});
  while (!pq.empty()) {
    int curr = pq.top().second;
    int isDown = pq.top().first; // 추가
    pq.pop();
    if (visited[curr]) continue;
		if(isDown == 0 && curr != 0) count++; // 추가
    visited[curr] = true;
    for (Edge& edge : graph[curr]) {
      if (!visited[edge.to]) {
        pq.push({edge.isDown, edge.to});
        // if (curr.isDown == 0) count++;   삭제
      }
    }
  }
  return count;
}
int primWorst(vector<vector<Edge>>& graph, int N) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<bool> visited(N, false);
  int count = 0;
  visited[0] = true;
  for (auto& next : graph[0]) pq.push({next.isDown, next.to});
  while (!pq.empty()) {
    int curr = pq.top().second;
		int isDown = pq.top().first; // 추가
    pq.pop();
    if (visited[curr]) continue;
    if(isDown == 0 && curr != 0) count++; // 추가
    visited[curr] = true;
    for (Edge& edge : graph[curr]) {
      if (!visited[edge.to]) {
        pq.push({edge.isDown, edge.to});
        // if (curr.isDown == 0) count++;  제거
      }
    }
  }
  return count;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> graph(n + 1);
  int from, to, isDown;
  for (int i = 0; i < m + 1; i++) {
    cin >> from >> to >> isDown;
    graph[from].push_back({to, isDown});
    graph[to].push_back({from, isDown});
  }
  int worst = primWorst(graph, n + 1);
  int best = primBest(graph, n + 1);
  // cout << worst << ' ' << best << '\n';
    cout << worst * worst - best * best << '\n';
  return 0;
}
