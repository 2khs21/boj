#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    sort(weights.begin(), weights.end());

    for (int i = 0 ; i < weights.size() - 1; i++){   // n^2
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



// long long solution(vector<int> weights) {
//     long long answer = 0;
    
//     sort(weights.begin(), weights.end());
    
    
//     for (int i = 0 ; i < weights.size() - 1; i++){
//         int l = weights[i];
        
//         cout << l  << "\n";
//         vector<int> targets;
        
//         targets.push_back(l);
//         if (l * 3 % 2 == 0) targets.push_back(l*3/2);
//         targets.push_back(2*l);
//         if (l * 4 % 3 == 0) targets.push_back(l*4/3);
    
//         cout << "L : " << l <<"\n";
//         for (auto t : targets){
            
//             cout << "t: " << t << " \ncandi : ";
            
//             for (auto it = weights.begin() + i + 1; it != weights.end(); it++){
//                 cout << *it <<" ";
//             }
//             cout << "\n";
//             if (find(weights.begin() + i + 1, weights.end(), t) != weights.end()) {
//                 answer++;
//                 cout << "find! ";
//                 break;
//             }
//         }
//         cout << "\n";
//     }
    
//     return answer;
// }


