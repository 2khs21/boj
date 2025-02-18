#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;

    set<int> S;
    int initVal = 0;
    int eSize = elements.size();
    for (int sz = 1; sz < eSize; sz++){
        
        int en = sz - 1;
        initVal += elements[en];
        
        int val = initVal;
        S.insert(val);
        // cout << "\nval : " << val << "\n";
        for (int st = 0 ; st < eSize; st++){
            en = (en + 1) % eSize; // 1 2 3  0
            val -= elements[st];
            val += elements[en];
            S.insert(val);
            // cout << "val : " << val << "\n";
        }
    }
    initVal += elements[eSize - 1];
    S.insert(initVal);
     // cout << "val : " << initVal << "\n";
    answer = S.size();
    return answer;
}