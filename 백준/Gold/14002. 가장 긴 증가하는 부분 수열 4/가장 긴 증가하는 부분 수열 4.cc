#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
#define ll long long

int N;
vector<vector<int>> dp;
vector<int> arr;
enum{
	VAL, CNT, PREV
};

int main(){
	cin >> N;

	arr.resize(N + 1);
	dp.resize(N + 1, {0, 0, -1});


	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}

	int maxIndex = 0;
	int resultCnt = 0;
	for (int i = 0 ; i < N; i++){
		int maxCnt = 0;
		int parent;
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i]) {

				if (dp[i][CNT] < dp[j][CNT] + 1) {
					dp[i][CNT] = dp[j][CNT] + 1;
					dp[i][PREV] = j;
				}

				if (dp[i][CNT] > resultCnt){
					maxIndex = i;
					resultCnt = dp[i][CNT];
				}
			}
		}
	}


	vector<int> answer;
	int index = maxIndex;
	while (index >= 0) {
		answer.push_back(index);
		index = dp[index][PREV];
	}

	cout << answer.size() << "\n";
	for (auto e = answer.rbegin(); e != answer.rend(); e++){
		cout << arr[*e] << " ";
	}

}