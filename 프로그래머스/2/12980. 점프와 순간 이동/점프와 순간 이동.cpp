#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while (n){
        if (n % 2 == 0) {
            n /= 2;
            continue;
        } else {
            n--;
            ans++;
        }
    }

    return ans;
}