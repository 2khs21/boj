#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int H, W;
queue<pair<int,int>> Q;

// #include <iostream>
// void p(vector<vector<int>> vis, vector<string> & board){
//     for (int i = 0 ; i < H; i++){
//         for (int j = 0; j < W; j++){
//             if (board[i][j] == 'R'){
//                 cout << 'R';
//             } else if (board[i][j] == 'G'){
//                 cout << 'G';
//             } else {
//                 cout << vis[i][j];
//             }
//             cout << " ";
//         }
//         cout << "\n";
//     }
//     cout << "\n";
    
// }

int BFS(vector<string> & board){
    
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};    
    
    
    
    vector<vector<int>> vis(H, vector<int>(W, 0));
    
    while (!Q.empty()){
        int cx, cy;
        tie(cx, cy) = Q.front();
        Q.pop();
        // p(vis, board);
        for (int dir = 0; dir < 4; dir++){
            int nx, ny;
            ny = cy;
            nx = cx;
            while (1){
                ny += dy[dir];
                nx += dx[dir];

                if (ny < 0 || ny >= H || nx < 0 || nx >= W || board[ny][nx] == 'D') {
                    ny -= dy[dir];
                    nx -= dx[dir];
                    break;
                }
            }
            if (vis[ny][nx] || board[ny][nx] == 'R') continue; // 이미 방문
            if (board[ny][nx] == 'G') {// 도착
                return (vis[cy][cx] + 1);
            }
            else { // 새로 방문
                vis[ny][nx] = vis[cy][cx] + 1;
                Q.push({nx, ny});
            }
        }
        
    }
    return -1;
}

int solution(vector<string> board) {
    int answer = 0;

    H = board.size();
    W = board[0].size();

    int rx, ry, gx, gy;
    for (int i = 0 ; i < H; i++){
        for (int j = 0; j < W; j++){
            if (board[i][j] == 'R'){
                ry = i;
                rx = j;
                Q.push({rx, ry});
            if (board[i][j] == 'G'){
                gy = i;
                gx = j;
            }
            }
        }
    }

    answer = BFS(board);
    
    return answer;
}