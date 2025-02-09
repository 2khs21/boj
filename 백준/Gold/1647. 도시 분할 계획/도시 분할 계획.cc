#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<pair<int, pair<int, int>>,
vector<pair<int, pair<int, int>>>,
greater<pair<int, pair<int, int>>>>pq;

int visCnt;
int N, M;
int ans;

vector<int> p;

int find(int x){
	if (p[x] < 0) return x;
	return p[x] = find(p[x]); // 경로 압축
}
bool uni (int u, int v){
	u = find(u);
	v = find(v);
	// 각각의 루트를 반환
	// 두 루트가 서로 같다면 리턴
	if (u == v) return false;

	// 루트 큰값을 루트 작은값으로 붙이자
	if (u < v) swap(u, v);
	p[u] = v;
	return true;

}

void func(){
	
	while (!pq.empty()) {
		int w, u, v;
		w = pq.top().first;
		tie(u, v) = pq.top().second;
		pq.pop();
		if (uni(u, v)) {
			visCnt++;

			// cout << "link : " << u << "-" << v<< "\n";
			// cout << "ans : " << ans << "\n";
			// cout << "visCnt : " << visCnt << "\n";
			if (visCnt == N  - 1) return; // N-1 (edge)
			ans += w;		
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	p.resize(N + 1, -1);
	for (int i = 0 ; i < M; i++){
		int w, u, v;
		cin >> u >> v >> w;
		pq.push({w, {u, v}});
	}

	func();

	cout << ans;
}