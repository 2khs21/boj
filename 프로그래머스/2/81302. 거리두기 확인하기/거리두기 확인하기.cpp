#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int n, m;
    n = 5;
    m = 5;
    
    
    
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    
    for (auto p : places){
        vector<vector<int>> vis(n, vector<int>(m, -1)) ;
        queue<pair<int,int>> Q;
        queue<pair<int,int>> bQ;
        int error = 0;    
        for (int y = 0 ; y < n; y++){
            for (int x = 0; x < m; x++){
                if (p[y][x] == 'P' && vis[y][x] == -1){

                    vis[y][x] = 0;
                    Q.push({x, y});

                    while (!Q.empty() && error == 0) {
                        int cx, cy;
                        tie(cx, cy) = Q.front();
                        Q.pop();
        
                        for (int dir = 0 ; dir < 4; dir++){
                            int nx, ny;

                            nx = cx + dx[dir];
                            ny = cy + dy[dir];

                            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if (vis[ny][nx] != -1) continue;
                            
                            if (p[ny][nx] == 'X') continue;
                            if (p[ny][nx] == 'P') {
                                error = 1;
                                break;
                             }
                            if (vis[cy][cx] == 1) continue;
                            
                            if (p[ny][nx] == 'O') {
                                vis[ny][nx] = vis[cy][cx] + 1;
                                Q.push({nx,ny});
                                bQ.push({nx,ny});
                            }
                        }
                        if (error) break;
                    }
                    if (error) break;
                    while (!bQ.empty()){
                        int bx, by;
                        tie(bx, by) = bQ.front();
                        bQ.pop();
                        vis[by][bx] = -1;
                    }
                 
                }
                if (error) break;
            }
            if (error) break;
        }
        answer.push_back(!error);
    }
  return answer;
}
 