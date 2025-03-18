#include <iostream>
#include <vector>
#include <string>

using namespace std;

string str, boom, ans;

int main(){
	cin >> str >> boom;

	int boomLen = boom.length();
	
	for (auto c : str){
		ans.push_back(c);
		if (ans.length() >= boomLen && ans.compare(ans.length() - boomLen, boomLen, boom) == 0)  {
			ans.resize(ans.length() - boomLen);
		}
	}
	if (ans.length() == 0) cout << "FRULA";
	else cout << ans;
}