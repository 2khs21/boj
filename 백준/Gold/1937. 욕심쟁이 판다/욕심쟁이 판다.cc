#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int N;
int arr[500][500];
int dp[500][500];
int ans;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
priority_queue<
		pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>
> pq;
    
void DP(){
	while(!pq.empty()){
		int val = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();
		int maxAround = 0;
		for (int dir = 0; dir < 4; dir++){
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (arr[y][x] > arr[ny][nx]) maxAround = max(maxAround, dp[ny][nx]);
		}
		dp[y][x] = maxAround + 1;
		ans = max(ans, dp[y][x]);
	}
}

int main(){
	cin >> N;

	for (int y = 0; y < N; y++){
		for (int x = 0; x < N; x++){
			cin >> arr[y][x];
			pq.push({arr[y][x],{y,x}});
		}
	}
	DP();
	cout << ans;
}