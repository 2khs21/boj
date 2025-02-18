#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string numbers) {
    int answer = 0;    
    set<int, greater<int>> s;

    for (int i = 1; i <= numbers.size(); i++){
        vector<bool> comb(numbers.size());
        for (int j = 0; j < i; j++){
            comb[numbers.size() - 1 - j] = 1;
        }
        
        do {
            string n = "";
            for (int i = 0 ; i < numbers.size(); i++){
                if (comb[i]) {
                    n.push_back(numbers[i]);
                }
            }
            if (n.size() == 0) continue;
            sort(n.begin(), n.end());
            do {
                s.insert(stoi(n));
            } while(next_permutation(n.begin(), n.end()));
            
        } while (next_permutation(comb.begin(), comb.end()));
        
    }

    int maxVal = *s.begin();
    
    vector<bool> isPrime(maxVal + 1, true);
    isPrime[0] = false;
    if (isPrime.size() > 1) {
        isPrime[1] = false;
    }
    
    for (int i = 2; i * i <= maxVal; i++){
        int k = i;
        for (int j = 2; j * k <= maxVal; j++){
            isPrime[j * k] = false;
        }
    }
        
    for (auto a : s) {
        if (isPrime[a]) {
            
            answer++;
        }
    }

    return answer;
}






