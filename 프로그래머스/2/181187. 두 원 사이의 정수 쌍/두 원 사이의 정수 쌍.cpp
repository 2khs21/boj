#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long getPointCntOut(long long r) {
    long long y = r;
    long long cnt = 0;
    for (long long x = 0 ; x <= r; x++){
        
        while (y>= 0){
            if ((x * x) + (y * y) <= r * r) {
                cnt += y;
                break;
            } else {
                y--;    
            }            
        }
        // cout << x  << " - " << y << "\n";
    }
    long long res = cnt * 4 + 1;
    // cout << "res : " << res << "\n";
    return res;
}

long long getPointCntIn(long long r) {
    long long y = r;
    long long cnt = 0;
    for (long long x = 0 ; x < r; x++){
        
        while (y>= 0){
            if ((x * x) + (y * y) < r * r) {
                cnt += y;
                break;
            } else {
                y--;    
            }            
        }
        // cout << x  << " - " << y << "\n";
    }
    long long res = cnt * 4 + 1;
    // cout << "res : " << res << "\n";
    return res;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    answer = getPointCntOut(r2) - getPointCntIn(r1);
    // cout << "O - I : " << getPointCntOut(r2) << ", " << getPointCntIn(r1) << "\n";
    return answer;
}