#include <string>
#include <vector>
#include <queue>

using namespace std;

int func(int n, vector<vector<int>> & edges, vector<int> & w){
    int a = w[0];
    int b = w[1];
    vector<bool> vis(n + 1);
    vis[b] = true;
    
    int aLen = 0;
    queue<int> Q;
    Q.push(a);
    vis[a] = true;
    while (!Q.empty()){
        int st = Q.front();
        Q.pop();
        aLen++;
        for (auto dest : edges[st]) {
            if (vis[dest]) continue;
            vis[dest] = true;
            Q.push(dest);
        }
        
    }
    return aLen;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>> edges(n + 1);
    
    for (auto w : wires) {
        int u, v;
        u = w[0];
        v = w[1];
        
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    answer = n;
    for (auto & w : wires){
        int aLen = func(n, edges, w);
        int bLen = n - aLen;
        int dif = abs(aLen - bLen);
        
        answer = min(answer, dif);
    }
    
    
    
    return answer;
}