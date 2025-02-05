#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define ll long long
unordered_map<ll, ll> um;

ll N, P, Q, X, Y;

ll recursive(ll i){
	if (i <= 0) return 1;
	if (um[i]) return um[i];

    ll val = recursive( i / P - X) + recursive( i / Q - Y);
	um[i] = val;
	return val;
}

int main(){
	cin >> N >> P >> Q >> X >> Y;
	cout << recursive(N);	
}