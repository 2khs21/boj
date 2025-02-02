#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int N, K;
int arr[101][101];
#define APPLE 1
#define SNAKE 2
enum{
	L, U, R, D
};
int curDir = R;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
deque<pair<int, int>> dq;
#define X first
#define Y second
int step = 0;
void pb(){
	cout << "\n";
	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}
int t; char rotateDir;

int move(){
	while (step < t || t == 0){
		int nx, ny;
		nx = dq.front().X + dx[curDir];
		ny = dq.front().Y + dy[curDir];
		// cout << "step : " << step << ", t : " << t << "\n";
		// cout << "nx ny : " << nx << ", " << ny << "\n"; 
		step++;
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
		if (arr[ny][nx] == SNAKE) return false;
		dq.push_front({nx, ny});
		if (arr[ny][nx] == APPLE){
			// cout << "eat!\n";
		} else {
			// cout << "no eat!\n";
			int tailX, tailY;
			tie(tailX, tailY) = dq.back();
			arr[tailY][tailX] = 0;
			dq.pop_back();
		}
		arr[ny][nx] = SNAKE;
		// pb();
	}
	if (rotateDir == 'D'){
		curDir = (curDir + 1) % 4;
	} else {
		curDir = (curDir + 3) % 4;
	}
	return true;
}

void solution(){	
	dq.push_front({0,0});
	arr[0][0] = SNAKE;
	cin >> K;

	while (K--){
		cin >> t >> rotateDir;
		if (move() == false) return ;;
	}
	t = 0;
	move();
}

int main(){
	cin >> N >> K;
	for (int i = 0; i < K; i++){
		int x, y;
		cin >> y >> x;
		arr[y - 1][x - 1] = APPLE; // apple
	}
	solution();
	// cout << "\nstep : " << step;
	cout << step;
}

