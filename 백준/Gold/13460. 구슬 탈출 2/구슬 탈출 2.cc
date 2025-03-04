#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

char arr[11][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
enum {
	U, R, D, L
};

enum{
	rx, ry, bx, by
};

int N, M;
int orx,ory,obx,oby;




queue<vector<int>> Q;
set<vector<int>> S;

int success;
int notPossible;
int answer = 0;

vector<int> moveDir(int dir, vector<int> & pPos){
	int crx = pPos[rx];
	int cry = pPos[ry];
	int cbx = pPos[bx];
	int cby = pPos[by];

	int nrx = crx, nry=cry, nbx=cbx, nby=cby;

		// cout << "nrx ,nry " << nrx << ", " << nry << "\n";
	int redOut = 0;
	int blueOut = 0;

	while (1){
		if (arr[nry + dy[dir]][nrx + dx[dir]] == '#') {
			break;
		} else {
			nrx += dx[dir];
			nry += dy[dir];
		}
		if (arr[nry][nrx] == 'O') {
			// cout << "redOut\n";

			// cout << "crx , cry : " << crx << ", " << cry << "\n";
			// cout << "dir : " << dir << "\n";
			redOut = 1;
			break;
		}
	}

	// cout << " 2 nrx ,nry " << nrx << ", " << nry << "\n";
	while (1){
		
		if (arr[nby + dy[dir]][nbx + dx[dir]] == '#') {
			break;
		} else {
			nbx += dx[dir];
			nby += dy[dir];
		}
		if (arr[nby][nbx] == 'O') {
			blueOut = 1;
			break;
		}
	}

	if (blueOut) {
		notPossible = 1;
		return {0};
	} else if (redOut) {
		success = 1;
		return {0};
	}


	if (nrx == nbx && nry == nby){ // same
		success = 0;

		if (dir == U) {
			if (pPos[ry] > pPos[by]){
					nry += dy[D];
			} else {
				nby += dy[D];
			} 
		} else if (dir == D){
			if (pPos[ry] > pPos[by]) {
				nby += dy[U];
			} else {
				nry += dy[U];
			}
		}

		if (dir == R){
			if (pPos[rx] > pPos[bx]) {
				nbx += dx[L];
			} else { 
				nrx += dx[L];
			}
		} else if (dir == L){
			if (pPos[rx] > pPos[bx]) {
				nrx += dx[R];
			} else {
				nbx += dx[R];
			}
		}
	} 
	if (S.find({nrx, nry, nbx, nby}) != S.end()) {
		notPossible = 1;
		return {0};
	}
	S.insert({nrx, nry, nbx, nby});
	return {nrx, nry, nbx, nby};
}
		

void BFS(){
		Q.push({orx, ory, obx, oby});
		S.insert({orx, ory, obx, oby});


		while(!Q.empty()){
		
			answer++;
			if (answer > 10) {
				answer = -1;
				return;
			}

 	 		int qSiz = Q.size();
			for (int i = 0 ; i < qSiz; i++){
			
				int crx, cry, cbx, cby;
				vector<int> cPos = Q.front(); Q.pop();

				for (int di = 0 ; di < 4; di++){
					// cout << "moveDIr1\n";
					vector<int> nextPos = moveDir(di, cPos);
					// cout << "moveDIr2\n";
					if (notPossible) {
						// cout << "NOt Possible\n" << "\n";
						notPossible = 0;
						continue;
					}
					if (success) {
						// cout << "success\n";
						return;
					}
					
					// cout << "\n answer : " << answer << "\n";
					// for (int y = 0; y < N; y++){
					// 	for (int x = 0; x < M; x++){
					// 		if (x == nextPos[rx] && y == nextPos[ry]) {
					// 			cout << "R";
					// 		} else if (x == nextPos[bx] && y == nextPos[by]){
					// 			cout << "B";
					// 		} else if ( arr[y][x] == '#'){
					// 			cout << "#";
					// 		} else if (arr[y][x] == 'O'){
					// 				cout << "O";
					// 			}
					// 			else {
					// 			cout << ".";

					// 		}
					// 	}
					// 	cout << "\n";
					// }
					// cout << "\n\n";

					Q.push(nextPos);

				}

			}


		}

}



int main(){

	cin >> N >> M;

	for (int y = 0; y < N; y++){
		for (int x = 0; x < M; x++){
			cin >> arr[y][x];
			if (arr[y][x] == 'R') {orx = x; ory = y;}
			else if (arr[y][x] == 'B'){obx = x; oby = y;}
		}
	}

	BFS();

	if (answer == 0 || success == 0) answer = -1;
	cout << answer;

}