#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 인오더 : 중위순회
// 포스트 오더 : 후위순회

// 프리오더 : 전위순회

vector<int> in;
vector<int> post;
int N;

void recursive(int is, int ie, int ps, int pe){
	if (is > ie || ps > pe) return ;
	
	int rootVal = post[pe];
	cout << rootVal << " ";
	int inRootIndex = find(in.begin() + is, in.begin() + ie + 1, rootVal) - in.begin();

	int lSize = inRootIndex - is;
	int rSize = ie - inRootIndex;

	if (lSize < 0 || rSize < 0) return ;

	if (lSize > 0){
		recursive(is, inRootIndex - 1, ps, ps + lSize - 1);
	}
	if (rSize > 0){
		recursive(inRootIndex + 1, ie, ps + lSize, pe - 1);
	}

}

int main(){
	cin >> N;
	in.resize(N + 1);
	post.resize(N + 1);
	for (int i = 0 ; i < N; i++) cin >> in[i];
	for (int i = 0 ; i < N; i++) cin >> post[i];
	recursive(0, N - 1, 0, N - 1);

}
/*

8
8 4 2 5 1 6 3 7
8 4 5 2 6 7 3 1

*/