#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

int N, K;
unordered_map<int, int> vis;
queue<pair<int, int>> Q;
int ans;

int reverseOnIndex(vector<int> src, int st){
	vector<int> dest = src;
	
	for (int i = 0; i < K; i++){
		// cout << " <-> " << dest[st - i] << ", " << src[st-K+1+i]<<"\n";
		// cout << "<-> i : " << st-i << ", " << st-K+1+i << "\n";
		dest[st - i] = src[st - K + 1 + i];
	}

	int res = 0;;
	for (int i = N - 1 ; i >= 0 ; i--){
		res = res * 10 + dest[i];
	}
	// cout << "1newVal : " << res	 << "\n";
	return res;
	
}

int isSorted(vector<int> curV){
	for (int i = 0 ; i < curV.size() - 1; i++){
		if (curV[i] < curV[i + 1]) {
			return 0;
		}
	}
	return 1;
}
void BFS(){
	while (!Q.empty()){
		int curVal = Q.front().first;
		int step = Q.front().second;
		Q.pop();
		if (vis[curVal]) continue;
		vis[curVal] = 1;
		vector<int> curV(N);
		int tmp = curVal;
		for (int i = 0; i < N; i++){
			curV[i] = tmp % 10;
			tmp /= 10;
		}
		// cout << "curVal : " << curVal << "\n";
		if (isSorted(curV)) {
			ans = step;
			return ;
		}
		// cout << "curVal : " << curVal << "\n";
		for (int i = N - 1; i >= K -1; i--){
			int newVal = reverseOnIndex(curV, i);
			// cout << "newVal : " << newVal << "\n";
			if (vis[newVal]) continue ;
			Q.push({newVal, step + 1});
		}
		// return ;
	}
	ans = -1;
	return ;
}

int main(){
	cin >> N >> K;
	
	int val = 0;
	for (int i = 0 ; i < N; i++){
		int tmp;
		cin >> tmp;
		val = tmp + val * 10;
	}
	Q.push({val, 0});
	BFS();
	cout << ans;
}