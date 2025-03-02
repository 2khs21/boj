#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution();
int arr[100001];

int main(){
	vector<int> answer;

	answer = solution();

	for (auto & v : answer) {
		cout << v << "\n";
	}
}

vector<int> solution(){
	int sPos, yPos;
	cin >> sPos >> yPos;


	vector<int> answer(2);
	queue<pair<int,int>> Q;

	Q.push({0, sPos});
	int flag = 0;

	while (!Q.empty()){
		auto [w, pos] = Q.front(); Q.pop();

		if (pos == yPos) {
			if (flag == 0){
				flag = 1;
				answer[0] = w;
			}

			if (answer[0] == w){
				answer[1]++;
			}

			// cout << answer[0] << ", " << answer[1]<<"\n";
		}		
		int next;
		for (int i = 0 ; i < 3; i++){
			if (i == 0) next = pos-1;
			else if (i == 1) next = pos + 1;
			else next = pos * 2;
			if (next < 0 || next > 100001) continue;
			if (flag) break;
			
			if (arr[next] && arr[next] < w + 1) continue;

			arr[next] = w + 1;

			Q.push({w + 1, next});
		}
	}
	return answer;

}