#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int vis[100][100];

int solution(vector<string> maps) {
    int toStart = 0;
    int toExit = 0;
    
    int H = maps.size();
    int W = maps[0].size();

    queue<pair<int,int>> Q;
    
    for (int y= 0 ; y < H; y++){
        for (int x = 0 ; x < W; x++){
            if (maps[y][x] == 'L') {
                Q.push({x, y});
            }
        }
    }
    // BFS
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    
    while (!Q.empty()){
        int x, y;
        x = Q.front().first;
        y = Q.front().second;
        Q.pop();
        for (int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            
            if (vis[ny][nx]) continue;
            if (maps[ny][nx] == 'X') continue;
            if (maps[ny][nx] == 'L') continue;
            vis[ny][nx] = vis[y][x] + 1;
            Q.push({nx,ny});
            if (maps[ny][nx] == 'S') toStart = vis[ny][nx];
            else if (maps[ny][nx] == 'E') toExit = vis[ny][nx];
        }
        
    }
    
    if (!(toStart && toExit)) return -1;
    
    return toStart + toExit;
}

/*
"SOOOL"
"XXXXO"
"OOOOO"
"OXXXX"
"OOOOE"
*/