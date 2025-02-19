#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

enum {
    U = 0, R, D,L
};
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

using namespace std;
int n, m;
int lazer(int cx, int cy, int cz,  vector<string> & grid, vector<vector<vector<bool>>> & vis){
    int dis = 0;
    
    int nx,ny,nz;
    while (1){
        dis++;
        int cDir = cz;
        nx = (cx + dx[cDir] + m) % m;
        ny = (cy + dy[cDir] + n) % n;

        char c = grid[ny][nx]; 
        if (c == 'S') {
            nz = cz;
        } else if (c =='L'){
            nz = (cz + 4 - 1) % 4;
        } else if (c == 'R') {
            nz = (cz + 1) % 4;
        }
        
        // cout << "C : " << cx << ", " << cy << ", " << cz << "\n";
        // cout << "N : " << nx << ", " << ny << ", " << nz << "\n";
        if (vis[nz][ny][nx]) return dis;
        vis[nz][ny][nx] = 1;
        cx = nx;
        cy = ny;
        cz = nz;
    }
    

    
    return 0;

}


vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    n = grid.size();
    m = grid[0].size();
    
//     int totalLen = n * m
//     total *= 4;
    
    vector<vector<vector<bool>>> vis(4, vector<vector<bool>>(n, vector<bool>(m, false)));
    
    for (int z = 0; z < 4; z++){ // 0:u,r  , 1:r,d
        for (int y = 0; y < n; y++){
            for (int x = 0; x < m; x++){
                if (vis[z][y][x]) continue;
                int dis = 0;
                vis[z][y][x] = 1;
                dis = lazer(x,y,z, grid, vis);
                answer.push_back(dis);
                

            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

/*
["SL", "LR"]
기댓값 〉	[16]
실행 결과 〉	실행한 결괏값 [1]이 기댓값 [16]과 다릅니다.
출력 〉	

C : 0, 0, 0
N : 0, 1, 3

C : 0, 1, 0
N : 0, 0, 0

*/