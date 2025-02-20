#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;


long long func (long long num) {
    
    int i = 0;
    long long n = num;
    while(1){
        if (n % 2 == 0){
            if (i == 0){
                return (num + 1);
            } else {
                // cout << "num : " << num << " + " << pow(2, i) << "\n";
                return (num + pow(2, i) - pow(2, i-1));
            }
        }
        n /= 2;
        i++;
    }
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (auto n : numbers){
        long long ans = func(n);
        answer.push_back(ans);
    }

    
    
    return answer;
}