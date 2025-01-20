#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define INF 1e9

int distA[101], distB[101];
vector<vector<pair<int, int>>> v;

int V,M;

void dijkstra(int startX, int dist[101]){
  
  fill(dist, dist + 101, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
  dist[startX] = 0;
  pq.push({0, startX});
  while (!pq.empty()){
    int totalDistance = pq.top().first;
    int x = pq.top().second;
    pq.pop();
    for (int i = 0; i < v[x].size(); i++){
      int distance = v[x][i].first;
      int nx = v[x][i].second;

      if (dist[nx] > totalDistance + distance){
        dist[nx] = totalDistance + distance;
        pq.push({dist[nx], nx});
      }
    }
  }

}

int main(){
  cin >> V >> M;
  v.resize(V + 1);
  for (int i = 0 ; i < M; i++){
    int from, to, weight;
    cin >> from >> to >> weight;
    v[from].push_back({weight, to});
    v[to].push_back({weight, from});
  }
  int a, b;
  cin >> a >> b;
  
  dijkstra(a, distA);
  dijkstra(b, distB);

  priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int, int,int>>> indexPq;
  int minDistance = INF;
  for (int i = 1; i <= V; i++){
    // cout << "i : [" << i << "]   a, b : " << distA[i] << ", " << distB[i] << "\n";
    // cout << "i : " << i << " | A : " << distA[i] << ", " << distB[i] << "\n";
    if (i == a || i == b) continue;
    if (distA[i] == INF || distB[i] == INF) continue;
    // if (distA[i] > distB[i]) continue;
    indexPq.push({distA[i] + distB[i], distA[i], i});
    minDistance = min(minDistance, distA[i] + distB[i]);
    // cout << "index push : " << i << "\n";
  }
  if (indexPq.empty()) cout << -1;
  else {
      int distanceA, distanceB;
      distanceA = get<1>(indexPq.top());
      distanceB = get<0>(indexPq.top()) - distanceA;
      if (distanceA > distanceB) cout << -1;
      else cout << get<2>(indexPq.top());
  }
} 

