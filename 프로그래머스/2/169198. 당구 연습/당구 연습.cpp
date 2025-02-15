#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// 가로,세로, 공위치x,y , 타겟들

int getDisSquare(int sx, int sy, int tx, int ty){
    return ((sx - tx) * (sx - tx) + (sy - ty) * (sy - ty));
}


vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;

    
    vector<pair<int, int>> pos;
    vector<int> dis;
    
    int x = startX;
    int y = startY;
    
    int lx = -1 * x;
    int uy = -1 * y;
    int rx = m + (m - x);
    int dy = n + (n - y);
    
    
    pos.push_back({lx, uy});
    pos.push_back({x, uy});
    pos.push_back({rx, uy});
    
    pos.push_back({lx, y});
    
    pos.push_back({rx, y});
    
    pos.push_back({lx, dy});
    pos.push_back({x, dy});
    pos.push_back({rx, dy});
    
    for (auto b : balls){

        dis.clear();
        
        for (auto p : pos) {
            int nx, ny, bx,by;
            nx = p.first;
            ny = p.second;
            bx = b[0];
            by = b[1];
            if (nx == bx && ( by < max(y, ny) && by > min(y, ny))) {
                continue;
            }
            if (ny == by && ( bx < max(x, nx) && bx > min(x, nx))) {
                continue;
            }            
            
            dis.push_back(getDisSquare(p.first, p.second, b[0], b[1]));
        }   
        
        answer.push_back(*min_element(dis.begin(), dis.end()));
    }
    
    return answer;
}