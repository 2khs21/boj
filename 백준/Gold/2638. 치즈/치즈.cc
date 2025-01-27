#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int N, M;
int arr[101][101];
int vis[101][101];
#define Y first
#define X second
#define MELT 3
queue<pair<int, int>> airQ;
queue<pair<int, int>> meltingQ;
int ans = -1;

void airing(){
	
	while(!airQ.empty()){
		
		int cy = airQ.front().Y;
		int cx = airQ.front().X;
		airQ.pop();
		if (vis[cy][cx]) continue; // visited already
		vis[cy][cx] = 1;
		for (int dir = 0; dir < 4; dir++){
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue; // out of range
			if (vis[ny][nx]) {
				continue; // visted already
			}
			if (arr[ny][nx]) {
				arr[ny][nx] += 1; // exposed side (1,2,3,4,5)
				if (arr[ny][nx] >= MELT){
				 meltingQ.push({ny,nx});
				}
			} else if (arr[ny][nx] == 0){
				airQ.push({ny, nx});
			}
		}
	}
}

void melting(){
	while(!meltingQ.empty()){
		int cy = meltingQ.front().Y;
		int cx = meltingQ.front().X;
		meltingQ.pop();
		airQ.push({cy,cx}); // air push at cheese melted pos
		arr[cy][cx] = 0;
		vis[cy][cx] = 0;
	}
}

int main(){
	cin >> N >> M;
	for (int i = 0 ; i < N; i++){
		for (int j = 0 ; j< M; j++){
			cin >> arr[i][j];
		}
	}
	airQ.push({0,0});	
	while(!airQ.empty()){
		airing();
		melting();
		ans++;
	}
	cout << ans;
}