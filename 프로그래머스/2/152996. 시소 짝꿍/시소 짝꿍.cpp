#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());

    for (int i = 0 ; i < weights.size() - 1; i++){
        for (int j = i + 1; j < weights.size(); j++){
            
            int l = weights[i];
            int r = weights[j];
    
            if (l == r || 3*l == 2*r || 4*l == 2*r || 4*l == 3*r) {
                
                answer++; 
            }
                
        }
    }
    
    return answer;
}