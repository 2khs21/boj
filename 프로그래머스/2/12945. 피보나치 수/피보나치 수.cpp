#include <string>
#include <vector>

using namespace std;
#include <iostream>

int solution(int n) {
    int answer = 0;
    
    int bb = 0;
    int b = 1;
    int cur;
    
    for (int i = 2; i <= n; i++){
        cur = bb + b;
        cur = cur % 1234567;
        bb = b;
        b = cur;
        // cout << "i : "<< i << " , " << cur << "\n";
        // if (bb > 1234567) {
            // bb = bb % 1234567;
            // b = b % 1234567;
            
        // }
        
    }
    answer = cur % 1234567;
    
    return answer;
}