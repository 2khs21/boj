#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define NEW_ZERO 2

int N, newN, cur;
int arr[505][505];
enum {
	L, D, R, U
};

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
/*
void printArr(){
	return ;
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0 ; j < N; j++){
			cout << arr[NEW_ZERO + i][NEW_ZERO + j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void printFArr(){
	cout << "\n";
	for (int i = 0; i < N + 4; i++){
		for (int j = 0 ; j < N + 4; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
*/
void tornado(int y, int x, int dir){
	// cout << " tornaod : x, y " << x << ", " << y << "\n";
	int sideDir1 = (dir + 1) % 4;
	int sideDir2 = (dir + 3) % 4;
	int backDir = (dir + 2) % 4;
	int prevSend = arr[y][x];
	int send1 = (prevSend * 1) / 100;
	int send2 = (prevSend * 2) / 100;
	int send5 = (prevSend * 5) / 100;
	int send7 = (prevSend * 7) / 100;
	int send10 = (prevSend * 10) / 100;
	int remainA = prevSend - (send1 + send2 + send7 + send10) * 2 - send5;
	
	// 기존에 있던거 다 밀려남
	arr[y][x] = 0;
	// a 같은 방향
	arr[y + dy[dir]][x + dx[dir]] += remainA;
	int nx, ny;
	// 1%
	nx = x + dx[backDir] + dx[sideDir1];
	ny = y + dy[backDir] + dy[sideDir1];
	arr[ny][nx] += send1;
	nx = x + dx[backDir] + dx[sideDir2];
	ny = y + dy[backDir] + dy[sideDir2];
	arr[ny][nx] += send1;

	// 7
	nx = x + dx[sideDir1];
	ny = y + dy[sideDir1];
	arr[ny][nx] += send7;
	nx = x + dx[sideDir2];
	ny = y + dy[sideDir2];
	arr[ny][nx] += send7;

	// 2
	nx = x + dx[sideDir1] * 2;
	ny = y + dy[sideDir1] * 2;
	arr[ny][nx] += send2;
	nx = x + dx[sideDir2] * 2;
	ny = y + dy[sideDir2] * 2;
	arr[ny][nx] += send2;

	// 10
	nx = x + dx[dir] + dx[sideDir1];
	ny = y + dy[dir] + dy[sideDir1];
	arr[ny][nx] += send10;
	nx = x + dx[dir] + dx[sideDir2];
	ny = y + dy[dir] + dy[sideDir2];
	arr[ny][nx] += send10;

	// 5
	nx = x + dx[dir] * 2;
	ny = y + dy[dir] * 2;
	arr[ny][nx] += send5;
}

int main(){
	cin >> N;
	newN = N + 4;
	cur =  newN / 2;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> arr[NEW_ZERO + i][NEW_ZERO + j];
		}
	}

	int x =cur;
	int y = cur;
	int count = 0;
	for (int t = 0; t < (N / 2); t++)	{
	// 	t + 1 칸 왼쪽
	//	t + 1 칸 아래쪽
	//	t + 2 칸 오른쪽
	//	t + 2 칸 위쪽
		count++;
		for (int i = 0; i < count; i++){
			x += dx[L];
			y += dy[L];
			tornado(y, x, L);
			
		}
		for (int i = 0; i < count; i++){
			x += dx[D];
			y += dy[D];
			tornado(y, x, D);
		}
		count++;
		for (int i = 0; i < count; i++){
			x += dx[R];
			y += dy[R];
			tornado(y, x, R);
		}
		for (int i = 0; i < count; i++){
			x += dx[U];
			y += dy[U];
			tornado(y, x, U);
		}
	}
	// N / 2 칸 왼쪽

	for (int i = 0; i < count; i++){
		x += dx[L];
		y += dy[L];
		tornado(y, x, L);
	}
	// cout << "\n";
	int ans = 0;
	// int block = 0;
	// int remain = 0;
	for (int i = 0; i < N + 4; i++){
		for (int j = 0; j < N + 4; j++){
				if ((i >= NEW_ZERO && i < NEW_ZERO + N) && (j >= NEW_ZERO && j < NEW_ZERO + N)) {
					// block++;
					// remain += arr[i][j];
					continue;
				} else {
					ans += arr[i][j];

				}
		}
	}
	// printFArr();
	// cout << "block : " << block << "\n";
	// cout << "remain : "<< remain << "\n";
	cout << ans;
	
}
