#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unistd.h>

using namespace std;

#define MAX 100000

int sp, yp;
int arr[100001];
int pArr[100001];
queue<pair<int,int>> Q;

void movePos(){
	auto [w, pos] = Q.front(); Q.pop();
	
	if (pos == 0) {
		arr[pos] = w;
		if (arr[pos+1] == -1) {
			arr[1] = w + 1;
			Q.push({w+1, 1});
		}
		return ;
	}

	int next[] = {pos - 1, pos + 1, pos * 2};
	for (auto & n : next) {
		if (n < 0 || n > MAX || arr[n] != -1) continue;

		arr[n] = w + 1;
		pArr[n] = pos;
		Q.push({w+1, n});
	}


}

int main(){
	cin >> sp >> yp;
	for (int i = 0 ; i <= MAX; i++){
		arr[i] = -1;
	}

	Q.push({0, sp});
	pArr[sp] = -1;
	arr[sp] = 0;
	while(!Q.empty()){
		movePos();
	}
	
	cout << arr[yp] << "\n";

	vector<int> v;
	int dest = yp;
	v.push_back(yp);
	while (1){
		if (pArr[dest] == -1) break;
		v.push_back(pArr[dest]);
		dest = pArr[dest];
	}
	for (auto rit = v.rbegin(); rit != v.rend(); rit++){
		cout << *rit << " ";
	}
}

