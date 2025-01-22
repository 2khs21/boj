#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 1e9
enum{
	R, U, L, D
};

int N;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int arr[101][101];

void printArr(){
	cout << "\n\n";
	for (int i = 0 ; i< 100; i++){
		for (int j = 0 ; j < 100; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){

	cin >> N;

	int x,y,d,g;
	for(int i = 0; i < N; i++){
		cin >> x >> y >> d >> g;
		
		arr[y][x] = 1;
		vector<int> dirV;
		dirV.push_back(d);
		while(g--){
			int dirVSize = dirV.size();
			for (int j = dirVSize - 1; j >= 0; j--){
				dirV.push_back((dirV[j] + 1) % 4);
			}
		}
		int cx = x, cy = y;
		for (int j = 0; j < dirV.size(); j++){
			int direction = dirV[j];
			int ny = cy + dy[direction];
			int nx = cx + dx[direction];
			arr[ny][nx] = 1;
			cy = ny;
			cx = nx;
		}
		// break ; // 한번만
	}
	// printArr();
	int ans = 0;
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (arr[i][j] && arr[i + 1][j] && arr[i][j+1] && arr[i + 1][j + 1]) {
				ans++;
				// cout << "[ " << i << ", " << j << " ]  ans : " << ans << "\n"; 
			}
		}
	}
	cout << ans;
}