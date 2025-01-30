#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
map<int, bool> vis;
queue<pair<int, int>> Q;
#define STEP second
#define POSITION first
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int ans = 1e9;


int arrToInt(int arr[3][3]){
	int res = 0;
	for (int i = 0; i < 9; i++){
		res = res * 10 + arr[i / 3][i % 3];
	}
	return res;
}

void pushNext(int val, int step){
	int arr[3][3];
	int x, y;
	for (int i = 8; i >= 0; i--) {
			if (val % 10 == 0) {
				y = i / 3;
				x = i % 3;
			}
			arr[i / 3][i % 3] = val % 10;
			val /= 10;
	}
	for (int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3){
			continue;
		}
		int tmp[3][3];
		memcpy(tmp, arr, sizeof(arr));
		tmp[y][x] = tmp[ny][nx];
		tmp[ny][nx] = 0;
		Q.push({arrToInt(tmp), step + 1});
	}
}

int isSolved(int val) {
	if (val == 123456780)
		return 1;
	else
		return 0;
}

void BFS(){
	while(!Q.empty()){
		int val = Q.front().POSITION;
		int step = Q.front().STEP;
		Q.pop();
		if (isSolved(val)){
			ans = step;
			return ;
		}
		if (vis[val]) continue;
		vis[val] = 1;
		pushNext(val, step);
	}
	ans = -1;
	return ;
}

int main(){
	int arr[3][3];
	for (int i = 0; i < 9; i++){
		cin>> arr[i / 3][i % 3];
	}
	Q.push({arrToInt(arr), 0});
	BFS();
	cout << ans;
}