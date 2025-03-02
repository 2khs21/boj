#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int arr[100001];

vector<int> getNPos(int pos){
	return {pos-1, pos+1, pos*2};
}


int sPos, yPos;

int solution(){
	int answer = 0;
	if (sPos == yPos){
		return 0;
	}


	queue<pair<int,int>> Q;
	Q.push({0, sPos});
	while (!Q.empty()){
		auto[w, pos] = Q.front(); Q.pop();
		
		vector<int> dests = getNPos(pos);

		for (auto & dest : dests){
			if (dest == yPos) {
				answer = w + 1;
				return answer;
			}

			if (dest < 0) continue;
			else if (dest > 100001) continue;
			else if (arr[dest]) continue;

			arr[dest] = w + 1;
			Q.push({w + 1, dest});
			// cout << "w+1 , dest : " << w+1 << ", " << dest << "\n";

		}
	}

	return answer;
}
int main(){	

	cin >> sPos >> yPos;

	int answer = solution();
	cout << answer;	
}