#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, L;

int main(){
	int ans = 0;
	cin >> N >> L;
	vector<pair<int, int>> v;
	for (int i = 0 ; i < N; i++){
		int st, en;
		cin >> st >> en;
		v.push_back({st,en});
	}
	sort(v.begin(), v.end());

	int idx = 0;
	for (auto & e : v){
		auto [st, en] = e;
		st = max(st, idx);
		int cnt = (en - st) / L + ((en - st) % L > 0);
		ans += cnt;
		idx = st + (L * cnt);
	}
	cout << ans;
}

