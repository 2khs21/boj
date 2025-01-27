#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

int N, M;
int arr[9][9];
int tmp[9][9];
int blank;
int tmpBlank;
int ans;

enum {
	L, U, R, D
};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
vector<pair<int, int>> cctvs;

void copyArr(const int src[9][9], int dest[9][9]){
	for (int i = 0; i < N; i++){
		for (int j = 0; j< M; j++){
			dest[i][j] = src[i][j];
		}
	}
}

void monitor(int cctvY, int cctvX, int dir){
	int nx = cctvX + dx[dir];;
	int ny = cctvY + dy[dir];
	while (1){
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) return ;
		if (tmp[ny][nx] == 6) return ;
		if (tmp[ny][nx] == 0){
			tmp[ny][nx] = '#';
			tmpBlank--;
		}
		nx += dx[dir];
		ny += dy[dir];
	}
}
void printTmp(){
	return ;
		cout << "--  PRINT TMP -- \n";
		for (int y = 0; y < N; y++){
			for (int x = 0; x < M; x++){
				if (tmp[y][x] == '#') cout << '#';
				else cout << tmp[y][x];
			}
			cout << "\n";
		}
		cout << "\n";
}

void checkCctv(){

	// int totalCount = pow(4, cctvs.size());
	int totalCount = 1 << 2 * cctvs.size();

	for (int i = 0; i < totalCount; i++){
		tmpBlank = blank;	
		copyArr(arr, tmp);
		for (int cctv = 0; cctv < cctvs.size(); cctv++){
			int dir = (i >> (cctv * 2)) & 0b11;
			
			int posX = cctvs[cctv].second;
			int posY = cctvs[cctv].first;
			if (arr[posY][posX] == 1){
				monitor(posY, posX, dir);
			} else if (arr[posY][posX] == 2 ) {
				if (dir > 1) continue;
				monitor(posY, posX, dir);
				monitor(posY, posX, (dir + 2) % 4);
			} else if (arr[posY][posX] == 3){
				monitor(posY, posX, dir);
				monitor(posY, posX, (dir + 1) % 4);
			} else if (arr[posY][posX] == 4){
				monitor(posY, posX, dir);
				monitor(posY, posX, (dir + 1) % 4);
				monitor(posY, posX, (dir + 2) % 4);
			} else if (arr[posY][posX] == 5){
				if (dir > 0) continue;
				monitor(posY, posX, dir);
				monitor(posY, posX, (dir + 1) % 4);
				monitor(posY, posX, (dir + 2) % 4);
				monitor(posY, posX, (dir + 3) % 4);
			}
		}
		printTmp();
		ans = min(tmpBlank, ans);
	}
}


int main(){
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> arr[i][j];
			if (arr[i][j] == 0) blank++;
			else if (arr[i][j] != 6) cctvs.push_back({i, j});
		}
	}
	ans = blank;
	checkCctv();
	cout << ans;
}
