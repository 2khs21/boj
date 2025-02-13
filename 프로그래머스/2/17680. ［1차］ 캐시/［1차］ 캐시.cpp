#include <string>
#include <vector>

using namespace std;
#include <iostream>
#include <unordered_map>
#include <list>
#include <algorithm>
#include <cctype>

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    list<string> l;
    int size = 0;
    for (auto c : cities) {
        for (int i =  0 ; i < c.size(); i++) {
            c[i] = toupper(c[i]);
        }
        // transform(c.begin(), c.end(), c.begin(), toupper);
        
        auto it = find(l.begin(), l.end(), c); // 캐시 되어 있다.
        if (it != l.end()){
            answer++;
            l.erase(it);
            l.push_back(c);
        } else { // 캐쉬에 없다. (사이즈 보기)
            if (cacheSize == 0) {
                answer += 5;
                continue;
            }
            if (cacheSize == l.size()) l.pop_front();
                
            l.push_back(c);
            answer += 5;

        }
    }    
    
    return answer;
}