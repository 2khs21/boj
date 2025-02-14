#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int st = 0;
    int en = 0;
    int total = sequence[0];
    int minLen = 1e9;
    while(1){
        if (total == k) {
            int len = en - st;
            if (len < minLen) {
                answer = {st, en};
                minLen = len;
            }            
        }
        
        if (total < k){
            en++;
            if (en >= sequence.size()) break;
            total += sequence[en];
        } else if (total >= k) {
            if (st >= en) break;
            total -= sequence[st];
            st++;

        }
    }
    
    
    return answer;
}