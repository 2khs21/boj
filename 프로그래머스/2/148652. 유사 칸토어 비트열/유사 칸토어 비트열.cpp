#include <string>
#include <vector>
#include <iostream>
using namespace std;

int isTrue(long long n) {
    
    long long FiveS = 5;
    while (n >= FiveS) {
        FiveS *= 5;
    }
    
    while (n >= 5) {
        long long part = FiveS / 5;
        
        if (n / part == 2) return 0;

        n = n % part;
        FiveS /= 5;
        
    }
    if (n < 5) {
        if (n == 2) return 0;
        else return 1;
    }
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    
    if (l > r) { swap(l, r); }
    
    for (long long i = l - 1 ; i <= r - 1; i++){
        answer += isTrue(i);
    }
//     for (long long i = 0; i <= 630 * 5; i++){
//         // if (i % 5 == 0) cout << " ";
//         if (i % 25 == 0 ) cout << " ";
//         if (i % 125 == 0 ) cout << "\n";
//         if (i % (125 * 5) == 0 ) cout << "\n\n\n";
//         if (isTrue(i)) cout << "1"; else cout << "0";
        
//     }
    
    return answer;
}


	