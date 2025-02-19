#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> dun;
int maxStep = 0;
void DFS(int k, int cnt, vector<bool> vis){
    maxStep = max(maxStep, cnt);
    for (int i = 0; i< dun.size(); i++){
        if (vis[i] || dun[i][0] > k) continue; //visited || tired
    
        vis[i] = true;
        DFS(k - dun[i][1], cnt + 1, vis);
        vis[i] = false;
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    dun = dungeons;
    sort(dun.begin(), dun.end(), greater<>());
    
    vector<bool> vis(dun.size(), false);
    DFS(k, 0, vis);
    answer = maxStep;
    
    return answer;
}