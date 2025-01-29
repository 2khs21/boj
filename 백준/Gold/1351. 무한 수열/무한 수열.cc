#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
#define ll long long

vector<ll> v;
map<ll, ll> m;

ll N, P, Q;
ll p, q;

void func(){
	m.insert({0, 1});
	m.insert({N, 0});
	for(auto it = m.begin(); it != m.end(); it++){
		ll key = it->first;
		if (!it->first) continue;
		it->second = m[key/P] + m[key/Q];
		cout << "A" << key << " = A" << key/p << " + A" <<  key/Q << "\n";
		cout << it->second << " = " << m[key/P] << " + " << m[key/Q] << "\n\n";
	}
}

ll recursive(ll i){
	if (i == 0) return 1;
	if (m[i]) return m[i];

	m[i] = recursive(i / P) + recursive(i / Q);
	return m[i];
}

int main(){
	cin >> N >> P >> Q;

	p = N;
	q = N;
	recursive(N);
	m[0] = 1;
	cout << m[N];
}