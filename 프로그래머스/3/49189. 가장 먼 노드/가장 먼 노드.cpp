#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n);
    
    for (auto & e : edge){
        graph[e[0] - 1].push_back(e[1] - 1);
        graph[e[1] - 1].push_back(e[0] - 1);
    }
    
    priority_queue<pair<int, int>> pq;
    
    vector<int> dis(n, 1e9); // 0-base
    pq.push({0, 0});
    dis[0] = 0;
    while (!pq.empty()){
        int w, node;
        tie(w, node) = pq.top();
        pq.pop();
        
        for (auto & g : graph[node]){
            int destNode = g;
            int nw = w + 1;
            if (dis[destNode] > nw) {
                dis[destNode] = nw;
                pq.push({nw, destNode});
            }
        }
    }
    
    sort(dis.begin(), dis.end(), greater<>());
    int max = dis[0];
    for (auto & d : dis) {
        if (d == max) answer++;
        else break;
    }
    
    
    
    
    
    return answer;
}