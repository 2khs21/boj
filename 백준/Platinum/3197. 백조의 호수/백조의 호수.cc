#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int R, C;
vector<string> lake;
queue<pair<int, int>> water_q, next_water_q;
queue<pair<int, int>> swan_q, next_swan_q;
bool visited[1500][1500];
pair<int, int> swans[2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 얼음이 녹는 시뮬레이션
void melt() {
    while (!water_q.empty()) {
        auto [x, y] = water_q.front();
        water_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (lake[nx][ny] == 'X') {
                lake[nx][ny] = '.';
                next_water_q.push({nx, ny});
            }
        }
    }
}

// 백조가 이동 가능한 범위 탐색
bool move_swan() {
    while (!swan_q.empty()) {
        auto [x, y] = swan_q.front();
        swan_q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = true;

            if (lake[nx][ny] == '.') {
                swan_q.push({nx, ny});
            } else if (lake[nx][ny] == 'X') {
                next_swan_q.push({nx, ny});
            } else if (lake[nx][ny] == 'L') {
                return true; // 다른 백조 발견
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    lake.resize(R);

    int swan_count = 0;
    for (int i = 0; i < R; i++) {
        cin >> lake[i];
        for (int j = 0; j < C; j++) {
            if (lake[i][j] != 'X') {
                water_q.push({i, j});
            }
            if (lake[i][j] == 'L') {
                swans[swan_count++] = {i, j};
            }
        }
    }

    swan_q.push(swans[0]);
    visited[swans[0].first][swans[0].second] = true;

    int days = 0;
    while (true) {
        if (move_swan()) {
            cout << days << "\n";
            break;
        }

        melt();

        // 다음 날로 업데이트
        swap(water_q, next_water_q);
        swap(swan_q, next_swan_q);

        while (!next_water_q.empty()) next_water_q.pop();
        while (!next_swan_q.empty()) next_swan_q.pop();

        days++;
    }

    return 0;
}