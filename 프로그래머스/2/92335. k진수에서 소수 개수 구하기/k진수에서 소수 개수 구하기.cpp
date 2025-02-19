#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long

bool isPrime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    vector<int> num;
    
    while (n) { // order 
        num.push_back(n % k);
        n /= k;
    }
    vector<ll> S;
    
    ll tmpNum = 0;
    for (auto it = num.rbegin(); it != num.rend(); it++){
        ll cur = *it;
        
        if (cur == 0) {
            if (tmpNum) {
                S.push_back(tmpNum);
                tmpNum = 0;
            }
            continue;
        }
        
        tmpNum = tmpNum * 10 + cur;   
    }
    if (tmpNum) {
        S.push_back(tmpNum);
        tmpNum = 0;
    }
    
    if (S.empty()) return 0;
    ll maxVal = *max_element(S.begin(), S.end());;
    // int maxVal = 10000;
    
    
    
  
    
    for (auto s : S) {
        // cout << "s : " << s << "\n";
        if (isPrime(s)) answer++;
    }
    
    return answer;
}