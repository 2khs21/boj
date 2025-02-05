#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<int> src;
vector<int> dp;

int solution(const string & str){

	src.resize(str.size());
	dp.resize(str.size());
	for (int i = 0; i < str.size(); i++){
		if (!(str[0] >= '0' && str[0] <= '9')) 
		{
			//  cout << "\nreturn 0 : str[0]==" << str[0] << "\n";
			return 0;
		} else {
			src[i] = str[i] - '0'; // 1-base
		}
	}
	if (src[0] == 0) {
		return 0;
	}
	dp[0] = 1;
	int twoDigits = src[0] * 10 + src[1];
	if (src[1] > 0) dp[1] += 1;
	if (twoDigits >= 10 && twoDigits <= 26) dp[1] +=  1;

	for (int i = 2; i < src.size(); i++){
		if (src[i] > 0){
			dp[i] = dp[i - 1];
			// cout << " - 1 : " << dp[i] << "\n";
		}
		int twoDigits = src[i - 1] * 10 + src[i]; // 앞에 글자랑 두자리수
		if (twoDigits >= 10 && twoDigits <= 26) {
			dp[i] += dp[i - 2];
			// cout << "  - 2 : " << dp[i] << "\n";
		}
		if (dp[i] == 0) return 0;
		if (dp[i - 1] >= 1000000 && dp[i] >= 100000){
			dp[i - 1] = dp[i - 1] % 1000000;
			dp[i] = dp[i] % 1000000;
		}
		if (src[i] == 0 && twoDigits == 0) {
			// cout << "one ,two both zero\n";
			return 0;
		}
	}	
	return dp.back();
}

int main(){
	string str;
	getline(cin, str);
	int ans = solution(str);

	// for (int i = 0; i < dp.size(); i++){
	// 	cout << dp[i] << " ";
	// }
	// cout << "\n";
	cout << ans;
}