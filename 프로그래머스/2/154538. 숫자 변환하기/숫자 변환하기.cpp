#include <string>
#include <vector>

using namespace std;
#include <iostream>
int solution(int x, int y, int n) {
    int answer = 0;
    
    vector<int> v(y - x + 1, -1);
    
    int xIndex = 0;
    int yIndex = y - x;
    v[xIndex] = 0;
    for (int i = xIndex; i <= yIndex; i++){
        
        if (v[i] >= 0){
            int next[3];
    
            next[0] = i + n;
            next[1] = 2 * (x + i) - x; 
            next[2] = 3 * (x + i) - x;
            
            // cout << next[0] << ", " << next[1] << ", " << next[2] << "\n";
            
            for (int j = 0; j < 3; j++){
                if (next[j] <= yIndex) {
                    if (v[next[j]] == -1){
                        v[next[j]] = v[i] + 1;
                    } else {
                         v[next[j]] = min(v[i] + 1, v[next[j]]);     
                    }
                   
                    
                }
            }
            
        }
        
    }
    // for (auto a : v){
    // cout << a << " ";
    // }
    answer = v[yIndex];
    return answer;
}