#include <string>
#include <vector>

using namespace std;
vector<long long> dp;

int solution(int n) {
    int answer = 0;
    if (n % 2 == 1) return 0;
    dp.resize(2501);
    
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 11;
    
    for (int i = 3; i <= n/2; i++){
        dp[i] = dp[i - 1] * 4 - dp[i - 2];
        dp[i] = dp[i] % 1000000007;
        
    }
    answer = dp[n/2];
    
    return answer;
}