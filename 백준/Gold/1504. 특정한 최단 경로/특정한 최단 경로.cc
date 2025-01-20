#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
using namespace std;
#define INF 1e9


int N, E, a, b;
int stToA, stToB;
int enToA, enToB;
int aToB;
vector<vector<pair<int, int>>> v;

int dist[801];
void dijstra(int startX, vector<vector<pair<int, int>>> v){
  
  fill(dist, dist + 801, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
  pq.push({0, startX});

  while(!pq.empty()){    
    int totalDistance = pq.top().first; //x까지 거리
    int x = pq.top().second;
    pq.pop();
    
    for(int i = 0; i < v[x].size(); i++){
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
  cin >> N >> E;

  v.resize(N + 1); // 이거 필요한가?
  for (int i = 0 ; i < E; i++){
    int from, to, weight;
    cin >> from >> to >> weight;
    v[from].push_back({weight, to});
    v[to].push_back({weight, from});
  }
  cin >> a >> b;

  dijstra(1, v);
  stToA = dist[a];
  stToB = dist[b];

  dijstra(N, v);
  enToA = dist[a];
  enToB = dist[b];
  
  dijstra(a, v);
  aToB = dist[b];

  // cout << "s->a : " << stToA << "\n";
  // cout << "s->b : " << stToB << "\n";
  // cout << "en->a : " << enToA << "\n";
  // cout << "en->b : " << enToB << "\n";
  // cout << "a->b : " << aToB << "\n";
  int route1, route2;
  if (a > b) swap(a, b);

  if (a == 1 && b == N){
    route1 = (aToB == INF ? -1 : aToB);
    
    cout << route1;
  } else {
    route1 = (stToA == INF || aToB == INF || enToB == INF ? -1 : stToA + aToB + enToB);
    route2 = (stToB == INF || aToB == INF || enToA == INF ? -1 : stToB + aToB + enToA);
    cout << min(route1, route2);
  }



}

