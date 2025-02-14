#include <iostream>
#include <vector>
using namespace std;
#define INF 1e9
#include <algorithm>
#include <queue>
vector<int> dis;
vector<vector<pair<int, int>>> v;
priority_queue<pair<int, int>> pq;

void dijsktra() {
    pq.push({0, 1}); // 자기한테 0
    dis[1] = 0;
    
    while (!pq.empty()){
        int w, node;
        tie(w, node) = pq.top(); // node = 1
        pq.pop();
        
        for (auto e : v[node]) {
            int nw, next;
            nw = dis[node] + e.first;
            next = e.second;
            if (dis[next] > nw) {
                dis[next] = nw;
                pq.push({nw, next});
            }
        }
    }
    
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dis.resize(N + 1, INF);
    v.resize(N+1);
    for (auto r : road) {
        int a, b, c;
        a = r[0]; b = r[1];c = r[2];
        
        v[a].push_back({c, b});
        v[b].push_back({c, a});
    }
    
    dijsktra();
    for (int i = 1; i <= N; i++){
        if (dis[i] <= K) answer++;
    }
    

    return answer;
}