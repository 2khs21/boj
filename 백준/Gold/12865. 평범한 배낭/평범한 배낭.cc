#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, K;
int wArr[101];
int vArr[101];
int dp[101][100001];

int main(){
	cin >> N >> K;

	for (int i = 1 ; i <= N; i++){
		cin >> wArr[i] >> vArr[i];
	}

	for (int i = 1 ; i <= N; i++){
		for (int j = 0 ; j <= K; j++) {
			int w = wArr[i];
			int v = vArr[i];

			if (w > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j - w] + v);
			}

			// cout << dp[i][j] << "\n";

		}
	}
	cout << dp[N][K];
}

