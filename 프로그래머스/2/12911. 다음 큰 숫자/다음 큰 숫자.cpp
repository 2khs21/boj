#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <iostream>
int solution(int n) {
    int answer = 0;
    
    
    vector<bool> v;
    while (n) {
        v.push_back(n % 2);
        n /= 2;
    }
    reverse(v.begin(), v.end());

    if (next_permutation(v.begin(), v.end())){
     ;     
    }   else {
        reverse(v.begin(), v.end());
        v.push_back(0);

        v.push_back(1);
                
        reverse(v.begin(), v.end());
        
        v.pop_back();
    
    }

    for (int i = 0 ; i < v.size(); i++){
        answer = answer * 2 + v[i];
    }
    
    return answer;
}