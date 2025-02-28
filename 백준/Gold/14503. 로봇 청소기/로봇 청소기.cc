#include <iostream>
#include <algorithm>
#include <vector>
#include <vector>
#include <queue>

using namespace std;

enum {
	U, L, D, R
};

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

vector<vector<int>> map;
vector<vector<int>> vis;
queue<pair<int, int>> Q;

int main(){
	int N, M;
	cin >> N >> M;

	int rx, ry, cd;
	cin >> ry >> rx >> cd;
	if (cd == 1 || cd == 3) {
		cd = (cd + 2) % 4;
	}
	map.resize(N, vector<int>(M));
	vis.resize(N, vector<int>(M));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	
	Q.push({rx, ry});
	int answer = 0;
	while(!Q.empty()){
		int cx, cy;
		tie(cx, cy) = Q.front();
		Q.pop();
		if (vis[cy][cx] == 0) {
			answer++;
			vis[cy][cx] = answer;
		} 
		for (int di = 1 ; di < 5; di++){
			int nx, ny;
			int nd = (cd + di) % 4;
			nx = cx + dx[nd];
			ny = cy + dy[nd];
			if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
				continue;
			}
			if (map[ny][nx] == 0 && vis[ny][nx] == 0) {
				cd = nd;
				Q.push({nx, ny});
				break;
			}
		}
		if (!Q.empty()) {
			continue;
		}

		int nx, ny, nd;
		nd = (cd + 2) % 4;
		nx = cx + dx[nd];
		ny = cy + dy[nd];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N || map[ny][nx] == 1) {
			break;
		} else {
			Q.push({nx, ny});
		}
	}
	cout << answer;
}
