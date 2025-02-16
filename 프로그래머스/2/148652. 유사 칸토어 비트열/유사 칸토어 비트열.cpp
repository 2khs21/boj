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
        
        if (n / part == 2) return 0;    // 

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
    
    // if (l > r) { swap(l, r); }
    
    for (long long i = l - 1 ; i <= r - 1; i++){
        answer += isTrue(i);
    }
    
    return answer;
}

/*
    k 값을 구할때 , k 보다 큰 5 의 제곱값을 구한다.
    
    100 -> 125 
    ( ) ( ) ( ) ( ) ( )


*/



	