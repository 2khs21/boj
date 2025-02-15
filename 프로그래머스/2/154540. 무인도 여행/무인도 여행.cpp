#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int, int>> Q;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int H, W;
vector<vector<bool>> vis;

int BFS(vector<string> & maps){
    int cnt = 0;
    
    while (!Q.empty()) {
        int x, y;
        tie(x,y) = Q.front();
        Q.pop();
        
        cnt += maps[y][x] - '0'; // pop -> cnt++
        
        for (int dir = 0 ; dir < 4; dir++){
            int nx,ny;
            nx = x + dx[dir];
            ny = y + dy[dir];
            
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if (maps[ny][nx] == 'X' || vis[ny][nx]) continue;
            
            Q.push({nx,ny});
            vis[ny][nx] = 1;
        } 
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    H = maps.size();
    W = maps[0].size();
    vis.resize(H, vector<bool>(W));
    for (int y = 0 ; y < H; y++){
        for (int x=0; x < W; x++){
            
            if (vis[y][x] || maps[y][x] == 'X') continue;
            
            else {
                Q.push({x, y});
                vis[y][x] = 1;
                answer.push_back(BFS(maps));
            }
            
        }
    }
    
    if (answer.empty()) return {-1};
    
    sort(answer.begin(), answer.end());
    return answer;
}