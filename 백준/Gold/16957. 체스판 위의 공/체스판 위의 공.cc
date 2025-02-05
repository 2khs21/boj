#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define VAL first
#define POS second

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int R, C;


int board[501][501];
int vis[501][501];
pair<int, int> dest[501][501];
int cnt[501][501];

priority_queue<
pair<int, pair<int, int>>,
vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>>
> pq;

void DP(){
	
	while (!pq.empty()){
		int val, cx, cy;
		val = pq.top().VAL;
		tie(cx, cy) = pq.top().POS;
		pq.pop();
		int minAroundVal = 1e9;
		int nextDir = -1;
		for (int dir = 0 ; dir < 8; dir++){
			int nx,ny;
			nx = cx + dx[dir];
			ny = cy + dy[dir];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R) continue;
			if (board[cy][cx] < board[ny][nx]) continue;
			if (minAroundVal > board[ny][nx]) {
				minAroundVal = board[ny][nx];
				nextDir = dir;
			}
		}
		if (nextDir == -1) {dest[cy][cx] = {cx, cy};} //
		else {
			int nx = cx + dx[nextDir];
			int ny = cy + dy[nextDir];
			dest[cy][cx] = dest[ny][nx];
		}
		int destX, destY;
		tie(destX, destY) = dest[cy][cx];
		
		cnt[destY][destX]++;
	}

}

int main(){
	cin >> R >> C;
	for (int y = 0 ; y < R; y++){
		for (int x = 0; x < C; x++){
			int n;
			cin >> n;
			pq.push({n,{x,y}});
			board[y][x] = n;
		}
	}
	DP();

	for (int y = 0 ; y < R; y++){
		for (int x = 0; x < C; x++){
			cout << cnt[y][x] << " ";
		}
		cout << "\n";
	}
}
