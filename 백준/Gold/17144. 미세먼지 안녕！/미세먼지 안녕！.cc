#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define INF 1e9

int R,C,T;
int arr[52][52];
int head, tail;
#define DIR 4
enum {
	LEFT = 0, UP,	RIGHT, DOWN
};
int dx[] = {-1, 0, 1, 0}; // 좌 상 우 하
int dy[] = {0, 1, 0, -1};


void printArr(int tmp[52][52]){
	return ;
	cout << "\n";
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cout << tmp[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void expansion(){
	int remainArr[52][52];
	int expansionArr[52][52];
	int possibleDir[4] = {0, 0, 0, 0};
	int dirCount;
	
	for (int i = 0 ; i < R + 1 ; i++){
		for (int j = 0; j < C + 1; j++){
			remainArr[i][j] = 0;
			expansionArr[i][j] = 0;
		}
	}

	for (int y = 0; y < R; y++){
		// cout << "\n";
		for (int x = 0; x < C; x++){
			// 방향 체크
			if (arr[y][x] == -1) continue;
			dirCount = 0;
			
			for (int dir = 0; dir < DIR; dir++){
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				// imposible
				if ((nx < 0 || nx >= C || ny < 0 || ny >= R) || (arr[ny][nx] == -1)){

					// cout << "[ " << ny << ", " << nx << " ]  = 0\n";	
					possibleDir[dir] = 0;
				}
				else{
					possibleDir[dir] = 1;
					dirCount++;
				}
			}
			expansionArr[y][x] = arr[y][x] - (arr[y][x]/5 * dirCount);
			// cout << "[ " << y << ", " << x << " ] arr " << arr[y][x] <<  "\texp[y][x]: " << expansionArr[y][x]<< ", dircont : "<< dirCount <<"\n";
			for (int dir = 0; dir < DIR; dir++){
				if (possibleDir[dir] == 1) {
					int nx = x + dx[dir];
					int ny = y + dy[dir];
					remainArr[ny][nx] += arr[y][x] / 5;
				}
			}
		}
	}
	
	// cout << "expan \n";
	// printArr(expansionArr);
	// cout << "----------\n";

	// cout << "remain \n";
	// printArr(remainArr);
	// cout << "-----\n";

	for (int y = 0; y < R; y++){
		for (int x = 0; x < C; x++){
			arr[y][x] = expansionArr[y][x] + remainArr[y][x];
		}
	}
}

void filtering(){
	
	queue<int> upQ;

	int x = 0, y = 0;
	for (; x < C - 1; x++) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push1 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (; y < head; y++) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push2 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;x > 0; x--) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push3 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;y > 0; y--) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push4 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";

	// cout << "size : " << upQ.size() << "\n";
	int tmp = upQ.front(); upQ.pop(); upQ.push(tmp);
	// cout << "front : " << upQ.front() << "\n";


	x = 0, y = 0;
	for (; x < C - 1; x++) {
		arr[y][x] = upQ.front(); upQ.pop();
	}
	for (; y < head; y++) {
		arr[y][x] = upQ.front(); upQ.pop();
	}
	for (;x > 0; x--) {
		arr[y][x] = upQ.front(); upQ.pop();
	}
	for (;y > 0; y--) {
		arr[y][x] = upQ.front(); upQ.pop();
	}
	// cout << "SIZE 2 : " << upQ.size() << "\n";
	//------

	// cout << "head , tail " << head << ", " << tail << "\n";
	x = 0, y = tail;
	upQ.push(arr[tail + 1][0]);
	for (; x < C - 1; x++) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push1 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (; y < R - 1; y++){
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push2 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;x > 0; x--) {
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push3 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;y > head; y--){
		upQ.push(arr[y][x]);
		// cout << "arr[" << y << ", " << x << "] " << "push4 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}

	x = 0, y = tail;
	for (; x < C - 1; x++) {
		arr[y][x] = upQ.front(); upQ.pop();
	}
	// cout << "\n";
	for (; y < R - 1; y++){
		arr[y][x] = upQ.front(); upQ.pop();
		// cout << "arr[" << y << ", " << x << "] " << "push2 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;x > 0; x--) {
		arr[y][x] = upQ.front(); upQ.pop();
		// cout << "arr[" << y << ", " << x << "] " << "push3 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}
	// cout << "\n";
	for (;y > head; y--){
		arr[y][x] = upQ.front(); upQ.pop();
		// cout << "arr[" << y << ", " << x << "] " << "push4 : size" << upQ.size() << " , " << upQ.back() << "\n";
	}

	arr[head][0] = -1;
	arr[head][1] = 0;
	arr[tail][0] = -1;
	arr[tail][1] = 0;
}
	

int main(){
	cin >> R >> C >> T;


	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> arr[i][j];
		}
	}

	for (int i = 0 ; i < R; i++){
		if (arr[i][0] == -1) {
				head = i;
				tail = i + 1;
				break;
		}
	}

	while (T--){
		printArr(arr);
		expansion();
		filtering();
	
		printArr(arr);
	}
	int ans = 0;
	for (int y = 0; y < R; y++){
		for (int x = 0; x < C; x++){
			if (arr[y][x] == -1) continue;
			ans += arr[y][x];
		}
	}
	cout << ans;
}

