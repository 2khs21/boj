#include <iostream>
#include <stack>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string str;
	getline(cin, str);

	stack<char> st;
	int stick = 0;;
	int ans = 0;
	for (int i = 0 ; i < str.size(); i++){
		if (str[i] == '(')  {
			st.push('(');
			stick++;
		}
		if (str[i] == ')') {
			if (str[i - 1] == '('){
				st.pop();
				stick--;
				ans += stick;
			} else {
				ans++;
				stick--;
			}
		}
	}
	cout << ans;
}