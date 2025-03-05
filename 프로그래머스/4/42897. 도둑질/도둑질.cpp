#include <string>
#include <vector>

using namespace std;
int dp[1000001];
int dpNoZ[1000001];
int solution(vector<int> money) {
    int answer = 0;
    int N = money.size();
    dp[0] = money[0];
    dp[1] = money[1];
    dp[2] = money[2] + dp[0];
    dpNoZ[1] = money[1];
    dpNoZ[2] = money[2];
    
    
    for (int i = 3; i < money.size(); i++){
        dp[i] = money[i] + max(dp[i - 2], dp[i - 3]);
        dpNoZ[i] = money[i] + max(dpNoZ[i - 2], dpNoZ[i - 3]);
    }
    
    answer = max(dpNoZ[N - 1], max(dp[N - 2], dp[N-3]));
    
    return answer;
}