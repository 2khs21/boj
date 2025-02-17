#include <string>
#include <vector>
#include <cmath>

using namespace std;
#include <iostream>
long long solution(int k, int d) {
    long long answer = 0;
    
    double a = (double)d / (double)k;
    double limitsDis = a * a;
    
    long long r = ceil(a);
    
    for (long long cur = 0; cur <= a; cur++){
        
        while ((cur * cur) + (r * r) > limitsDis) {
            r--;
        }
        answer += (r + 1);
        // cout << "cur : " << cur << " : " << r << "\n";
        
    }
    
    return answer;
}