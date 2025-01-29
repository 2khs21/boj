#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define ll long long
enum{
	red = -1, blue = 1
};

int K, V, E, u, v;

void solution(){
	cin >> V >> E;
	vector<vector<int>> graph;
	vector<int> colors;
	vector<bool> vis;
	queue<int> Q;
	
	graph.resize(V + 1);
	colors.resize(V + 1);
	vis.resize(V + 1);
	for (int i = 0; i < E; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < V; i++){
		if(vis[i]) continue;
		Q.push(i);
		if (!colors[i]) colors[i] = red;
		while (!Q.empty()){
			int node = Q.front();
			// cout << "while : " << node << "\n";
			Q.pop();
			if (vis[node]) continue ;
			// cout << "!\n";
			vis[node] = 1;
			for (int j = 0; j < graph[node].size(); j++){
				int destNode = graph[node][j];
				// cout << "dest : " <<  destNode  << "c : " << colors[destNode] << "\n";
				if (colors[destNode] == colors[node]) {
					cout << "NO\n";
					return ; // duplicaion exists;
				}
				colors[destNode] = -1 * colors[node];
				// cout << "color " << destNode << " : " << colors[destNode] << "\n";
				Q.push(destNode);
			}
		}
	}
	cout << "YES\n";
	return ;
}
int main(){

	cin >> K;

	while (K--){
		// cout << "\nK : " << K << "\n";
		solution();
	}
}
/*
1
4 4
1 2
2 3
3 4
4 2
*/