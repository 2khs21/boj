#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<string> board;
bool visited[10000][500];
int dy[3] = {-1, 0, 1};
int cnt = 0;

bool dfs(int cy, int cx) {

    if (cx == C - 1) {
        cnt++;
        return true;
    }

    for (int i = 0; i < 3; i++) {
        int ny = cy + dy[i];
        int nx = cx + 1;

        if (ny < 0 || ny >= R)
            continue;

        if (board[ny][nx] == 'x' || visited[ny][nx])
            continue;

        visited[ny][nx] = true;
        if (dfs(ny, nx))
            return true;
    }

    return false;
}

int main() {

    cin >> R >> C;
    board.resize(R);

    for (int i = 0; i < R; i++){
			cin >> board[i];
		}

    for (int i = 0; i < R; i++) {
        if (board[i][0] == '.') {
            visited[i][0] = true;
            dfs(i, 0);
        }
    }

    cout << cnt << '\n';
    return 0;
}