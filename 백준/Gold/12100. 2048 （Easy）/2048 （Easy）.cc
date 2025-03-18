#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0 ,1};


int N;
int ans = 0;
void moveL(vector<vector<int>> & v){


	for (int i = 0 ; i < N; i++){
		int k = 0;
		vector<int> line(N);
		for (int j = 0 ; j < N; j++){
			if (v[i][j]) {
				line[k++] = v[i][j];
			}
		}
		v[i] = line;
	}
}

void sumL(vector<vector<int>> & v){
	for (int i = 0 ; i < N; i++){
		for (int j = 0 ; j < N - 1; j++){
			if (v[i][j] == v[i][j + 1]){
				v[i][j] = v[i][j] * 2;
				v[i][j + 1] = 0;
				j++;
			}
		}
	}
}

void moveR(vector<vector<int>> & v){


	for (int i = 0 ; i < N; i++){
		int k = N-1;
		vector<int> line(N);
		for (int j = N-1 ; j >= 0; j--){
			if (v[i][j]) {
				line[k--] = v[i][j];
			}
		}
		v[i] = line;
	}
}

void sumR(vector<vector<int>> & v){
	for (int i = 0 ; i < N; i++){
		for (int j = N - 1 ; j >= 0 ; j--){
			if (v[i][j] == v[i][j - 1]){
				v[i][j] = v[i][j] * 2;
				v[i][j - 1] = 0;
				j--;
			}
		}
	}
}

void moveU(vector<vector<int>> & v){
	for (int j = 0 ; j < N; j++){
		int k = 0;
		for (int i = 0 ; i < N; i++){
			if (v[i][j]) {
				v[k][j] = v[i][j];
				if (k != i){
					v[i][j] = 0;
				}
				k++;
			}
		}
	}
}

void sumU(vector<vector<int>> & v){
	for (int j = 0; j < N; j++){
		for (int i = 0 ; i < N - 1; i++){
			if (v[i][j] == v[i + 1][j]){
				v[i][j] = v[i][j] * 2;
				v[i + 1][j] = 0;
				i++;
			}
		}
	}
}

void moveD(vector<vector<int>> & v){
	for (int j = 0 ; j < N; j++){
		int k = N-1;
		for (int i = N - 1 ; i >= 0; i--){
			if (v[i][j]) {
				v[k][j] = v[i][j];
				if (k != i){
					v[i][j] = 0;
				}
				k--;
			}
		}
	}
}

void sumD(vector<vector<int>> & v){
	for (int j = 0; j < N; j++){
		for (int i = N - 1 ; i > 0; i--){
			if (v[i][j] == v[i - 1][j]){
				v[i][j] = v[i][j] * 2;
				v[i - 1][j] = 0;
				i--;
			}
		}
	}
}


void printV(vector<vector<int>> v){
	cout << "\n";
	for (int i = 0 ; i < N; i++){
		for (int j = 0 ; j < N; j++){
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
}

vector<vector<int>> moveDir(vector<vector<int>> v, int dir){
	if (dir == 0) {
		moveL(v);
		sumL(v);
		moveL(v);
	} else if (dir == 1){
		moveR(v);
		sumR(v);
		moveR(v);
	} else if (dir == 2){
		moveU(v);
		sumU(v);
		moveU(v);
	} else if (dir == 3){
		moveD(v);
		sumD(v);
		moveD(v);
	}
	return v;
}



void dfs(vector<vector<int>> v, int cnt){
	if (cnt >= 5) {
		for (int i = 0 ; i < N; i++){
			for (int j = 0 ; j < N; j++){
				ans = max(ans, v[i][j]);
			}
		}
		return ;
	}

	for (int i = 0 ; i < 4; i++){
		vector<vector<int>> tmpV = moveDir(v, i);
		dfs(tmpV, cnt + 1);
	};
}

int main(){
	cin >> N;
	vector<vector<int>> v(N, vector<int>(N));

	for (int i = 0 ; i < N; i++){
		for (int j= 0; j < N; j++){
			cin >> v[i][j];
		}
	}

	dfs(v, 0);

	cout << ans;

}