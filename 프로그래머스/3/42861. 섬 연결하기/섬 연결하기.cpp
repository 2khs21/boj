#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<bool> vis(n);
    vector<vector<pair<int,int>>> edges(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;    
    for (auto & c : costs){
        int w,v,u;
        v = c[0];
        u = c[1];
        w = c[2];
        edges[v].push_back({w,u});
        edges[u].push_back({w,v});
    }
    int edgeCnt = -1;
    int weights = 0;
    pq.push({0, 0});
    while (!pq.empty() && edgeCnt != n - 1){
        auto[w, u] = pq.top(); pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        weights += w;
        edgeCnt++;
        
        for (auto [nw, v] : edges[u]) {
            if (vis[v]) continue;
            pq.push({nw, v});
        }
    }
    
    answer = weights;
    return answer;
}