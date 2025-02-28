#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

int main(){
	
	int N, L, R;
	cin >> N >> L >> R;
	int answer = 0;
	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0 ; i < N; i++){
		for (int j = 0 ; j < N;j++){
			cin >> arr[i][j];
		}
	}

	while (1){
		queue<pair<int,int>> Q;
		vector<vector<pair<int, int>>> unions;
		vector<int> people;
		vector<vector<bool>> vis(N, vector<bool>(N));

		int ui = -1;
		for (int y = 0; y < N; y++){
			for (int x = 0; x < N; x++){
				if (vis[y][x]) continue;
				vis[y][x] = 1;
				ui++;
				unions.push_back({{x, y}});
				Q.push({x, y});
				int total = 0;
				int cnt = 0;
				while (!Q.empty()){
					int cx, cy;
					tie(cx, cy) = Q.front(); Q.pop();
					// cout << "cxcy : " << cx << ", " << cy << "\n";
					cnt++;
					total += arr[cy][cx];
					for (int dir = 0; dir < 4; dir++){
						int nx, ny;
						nx = cx + dx[dir];
						ny = cy + dy[dir];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if (vis[ny][nx]) continue;
						int dif = abs(arr[ny][nx] - arr[cy][cx]);
						// cout << "dif : " << dif << "\n";
						if (dif >= L && dif <= R) {
							// cout << "ui : " << ui << "  " << nx << ", " << ny << "\n";
							unions[ui].push_back({nx, ny});
							vis[ny][nx] = 1;
							Q.push({nx, ny});
						}
					}
				}
				if(cnt == 1) {
					unions.pop_back();
					ui--;
				}
				else {
					people.push_back(total / cnt);
				}
			}
		}
		if (unions.empty()){
			break;
		}
		answer++;
		for (int ui = 0; ui < unions.size(); ui++){
			for (auto p : unions[ui]){
				int x, y;
				tie(x, y) = p;
				arr[y][x] = people[ui];
			}
		}

	}

	// for (int y = 0; y < N; y++){
	// 		for (int x = 0; x < N; x++){
	// 			cout << arr[y][x] << " ";
	// 		}
	// 		cout << "\n";
	// }


	cout << answer;

}