#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N;
int pop1, pop2;
int answer = -1;
int minDif = 1e9;
vector<int> sect;
vector<vector<int>> m;
vector<int> pop;
bool vis[11];

int isIn(vector<int> & s, int x) {

	if (find(s.begin(), s.end(), x) != end(s)){
	// cout <<  x << " is IN\n";
		return 1;
	} else 
	// cout << x << " not in\n";
		return 0;
}

int getPop(vector<int> & s){
	int answer = 0;
	for (auto e : s){
		answer += pop[e];
	}
	return answer;
}

int isLinked(vector<int> & v){
	
	vector<bool> tmpVis(N + 1);
	queue<int> Q;
	int cnt = 0;
	
	Q.push(v[0]);
	while (!Q.empty()){
		int x = Q.front(); Q.pop();
		if (tmpVis[x]) continue;
		tmpVis[x] = true;
		
		cnt++;
		for (int i = 0 ; i < m[x].size(); i++){
			int y = m[x][i];
			if (isIn(v, y) == 0) continue;
			if (tmpVis[y]) continue;
			Q.push(y);
		}
	}
	
	if (v.size() == cnt) {
		// cout << "is Link!!\n";
		return 1;
	}
	else {
		// cout << "not linek\n";
		return 0;
	}
}

void getDif(){
	
	vector<int> sect2;
	for (int i = 1 ; i <= N; i++){
		vis[i] = false;
	}
	for (int i = 0 ; i < sect.size(); i++){
		vis[sect[i]] = true;
	}
	
	for (int i = 1; i <= N; i++) {
		if (vis[i] == false) {
			sect2.push_back(i);
			// cout << "push : " << i << " -> "<<sect2.size()<<"\n";
		}
	}
	// cout << "\n";
	// for (auto e : sect){
	// 	cout << e << " ";
	// }
	// cout << " / ";
	// for (auto e : sect2){
	// 	cout << e << " ";
	// }
	// cout << "\n";

	if (isLinked(sect) && isLinked(sect2)) {
		int pop1, pop2, dif;
		pop1 = getPop(sect);
		pop2 = getPop(sect2);

		dif = abs(pop1 - pop2);

		// cout << pop1 << " , " << pop2 << " = " << dif << "\n";
		minDif = min(minDif, dif);
	} else {
	}

	return ;
}

void DFS(int cnt) {
	if (cnt == N) {
		if (sect.size() == 0 || sect.size() == N) return ;
		getDif();
		return ;
	}
	
	sect.push_back(cnt + 1); // 1 push
	DFS(cnt + 1);
	sect.pop_back();
	DFS(cnt + 1);
}

int main(){
	cin >> N;

	m.resize(N + 1);
	pop.resize(N +1);
	for (int i = 1; i <= N; i++){
		cin >> pop[i];
	}

	for (int i = 1; i <= N; i++){
		int t;
		cin >> t;
		for (int j = 0; j < t; j++){
			int x;
			cin >> x;
			m[i].push_back(x);
		}
	}

	DFS(0);

	if (minDif == 1e9) cout << -1;
	else cout << minDif;
	
	return 0;
}