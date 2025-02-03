#include <iostream>
#include <stack>

using namespace std;

/*


   6    
5  6           5
5  6  4        5
5  6  4     3  5
5  6  4  2  3  5
5  6  4  2  3  5

스택은 내림차순으로 쌓인다.

새로운 요소 보다 작은건 모두 pop
새로운 요소 보다 큰 값 출력.
새로운 요소 스택에 push

*/
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	// height, index
	stack<pair<int, int>> st;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++){
		int h;
		cin >> h;

		int ans = 0;
		while (!st.empty()){
			int curHeight = st.top().first;
			if (curHeight > h) {
				ans = st.top().second;
				break;
			}
			else {
				st.pop();
			}
		}
		st.push({h, i});
		cout << ans << " ";
	}

}
