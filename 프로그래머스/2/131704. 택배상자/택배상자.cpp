#include <string>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    stack<int> S;
    int n = 1;
    for (auto & o : order) {
        // yet
        while (n < o) {
            S.push(n);
            n++;
        }
        // possible
        if (!S.empty() && S.top() == o) {
            answer++;
            S.pop();
            continue; // next order;
        }
        else if (o == n) {
            answer++;
            n++;
            continue;            
        }
        // impossible
        if (o < n) {
            break;
        }
\
    
    }
    
    
    return answer;
}