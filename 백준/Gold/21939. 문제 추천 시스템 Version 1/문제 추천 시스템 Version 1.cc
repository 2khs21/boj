#include <iostream>
using namespace std;
#include <map>
#include <set>
/*
recommend x
1 가장 어려운문제 (문제번호가 큰 순)
-1 가장 쉬운 문제 (문제 번호가 낮은 순)

add P L
난이도 L 인 문제 추가

solved P
문제번호 P 제거
*/

// p[문제번호] == 난이도.
map<int, int> levelOfProblem; // 문제 번호로 난이도 접근
// 난이도, 문제번호들	
map<int, set<int>> pList;

void exeAdd(){
	int P, L;
	cin >> P >> L;
	levelOfProblem[P] = L;
	pList[L].insert(P);
}

void exeRecommend(){
	int order;
	cin >> order;
	int P, L;
	if (order == 1) {
		P = *(pList.rbegin()->second.rbegin());
	} else if (order == -1) {
		P = *(pList.begin()->second.begin());
	}
	cout << P << "\n";
}

void exeSolved(){
	int P;
	cin >> P;
	int L = levelOfProblem[P];
	levelOfProblem[P] = 0; // 문제난이도 삭제
	pList[L].erase(P);
	if (pList[L].empty()) pList.erase(L);
}

int main(){
	int N, P, M, L;
	cin >> N;
	for (int i = 0 ; i < N; i++){
		cin >> P >> L;
		levelOfProblem[P] = L;
		pList[L].insert(P);
	}
	
	cin >> M;
	while (M--){
		string cmd;
		cin >> cmd;
		if (cmd == "add") exeAdd();
		else if (cmd == "recommend") exeRecommend();
		else if (cmd == "solved") exeSolved();
	}
}