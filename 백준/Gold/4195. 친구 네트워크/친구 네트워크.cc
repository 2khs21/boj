#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int T, F;
unordered_map<int,int> parents;
unordered_map<int, int> relationshipCount;

int findParent(int child){
	int parent = parents[child] == child ? child : parents[child] = findParent(parents[child]);
	return parent;
}

void unionGraph(int a, int b){
	a = findParent(a);
	b = findParent(b);

	if (a == b)
		cout << relationshipCount[a] << "\n";
	else {
		a < b ? parents[a] = b : parents[b] = a; // bigger to parents
		relationshipCount[max(a, b)] += relationshipCount[min(a, b)];
		relationshipCount.erase(min(a, b));
		cout << relationshipCount[max(a, b)] << "\n";
	}
	return ;
}

void func(){
	cin >> F;
	vector<vector<int>> v;
	v.resize(F);
	unordered_map<string, int> m;
	int nameIndex = 1;
	
	for (int i = 0 ; i < F; i++){
		string u, v;
		cin >> u >> v;
		int ui, vi;
		ui = m[u] ? m[u] : m[u] = nameIndex++;
		vi = m[v] ? m[v] : m[v] = nameIndex++;
		parents[ui] ? : parents[ui] = ui;
		parents[vi] ? : parents[vi] = vi;
		if (relationshipCount.find(ui) == relationshipCount.end() && parents[ui] == ui){
			relationshipCount[ui] = 1;
		}
		if (relationshipCount.find(vi) == relationshipCount.end() && parents[vi] == vi){
			relationshipCount[vi] = 1;
		}
		unionGraph(ui, vi);
	}
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> T;

	while (T--){
		func();
		parents.clear();
		relationshipCount.clear();
	}
}
