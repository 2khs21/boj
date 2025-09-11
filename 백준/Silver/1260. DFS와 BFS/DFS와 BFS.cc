#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;


typedef pair<int, int> edge;
static vector <vector<int>> A;
static vector <bool> visited;
int n_node, n_route, s;

void BFS(int node);
void DFS(int node);

int main(){
	cin >> n_node >> n_route >> s;

	A.resize(n_node + 1);

	for (int i=0; i < n_route; i++){
		int s,e;
		cin >> s >> e;
		
		A[s].push_back(e);
		A[e].push_back(s);
	}
	for (int i=1; i <= n_node; i++){
		sort(A[i].begin(), A[i].end());
	}
	visited = vector <bool> (n_node+1, false);
	DFS(s);
	cout << "\n";
	fill(visited.begin(), visited.end(), false);
	BFS(s);
}

void BFS(int node){
	queue<int> myqueue;
	myqueue.push(node);
	visited[node] = true;
	
	while (!myqueue.empty()){
		int now_node = myqueue.front();
		cout << myqueue.front() << " ";
		myqueue.pop();
		for (int i : A[now_node]){
			if (!visited[i]){
				visited[i] = true;
				myqueue.push(i);
			}
		}
	}
	cout << "\n";
}

void DFS(int node){
	visited[node] = true;
	cout << node << " ";
	for (int i : A[node]){
		if (!visited[i]){
			DFS(i);
		}
	}
}