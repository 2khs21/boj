#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
/*
  1
3 0 2
  4
	5
*/

int dx[]= {1, -1,0,0};
int dy[] = {0,0,-1,1};

vector<int> dice(6);

void rollN(){dice = {dice[4], dice[0], dice[2], dice[3], dice[5], dice[1]};}
void rollS(){dice = {dice[1], dice[5], dice[2], dice[3], dice[0], dice[4]};}
void rollE(){dice = {dice[3], dice[1], dice[0], dice[5], dice[4], dice[2]};}
void rollW(){dice = {dice[2], dice[1], dice[5], dice[0], dice[4], dice[3]};}

void roll(int order)
{
    switch (order)
    {
    case 1:
        rollE();
        break;
    case 2:
        rollW();
        break;
    case 3:
        rollN();
        break;
    case 4:
        rollS();
        break;
    default:
        break;
    }
}

int main(){
	int N, M, cx,cy, t;

	cin >> N >> M >> cy >> cx >> t;

	int arr[N][M];

	for (int i = 0 ; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> arr[i][j];
		}
	}
	
	while (t--){
		int cmd;
		cin >> cmd;
		int nx = cx + dx[cmd - 1];
		int ny = cy + dy[cmd - 1];
		
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		
		roll(cmd);

		if (arr[ny][nx] == 0) {
			arr[ny][nx] = dice[5];
		} else {
			dice[5] = arr[ny][nx];
			arr[ny][nx] = 0;
		}
		cout << dice[0] << "\n";
		cx = nx;
		cy = ny;
	}

	
}