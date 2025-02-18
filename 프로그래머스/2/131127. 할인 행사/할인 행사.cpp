#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
#include <iostream>
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
     
    unordered_map<string, int> m;
    int needs = 0;
    for (int i = 0 ; i < want.size(); i++){
        m[want[i]] = number[i];
        needs += number[i];
    }
    // cout << "ori needs : "<< needs << "\n";
    // needs
    
    for (int i = 0 ; i < 10 ; i++){
        if (m.find(discount[i]) == m.end()) { // can't find
            continue;
        }
        if (m[discount[i]] > 0) {
            needs--;
        }
        m[discount[i]]--;
    }
    if (needs == 0) answer++;
    for (int front = 0, back = 10; back < discount.size(); front++, back++){
        // cout << "need : " << needs << "\n";
        if (m.find(discount[back]) == m.end()) { // can't find
            ;
        } else { // find
            if (m[discount[back]] > 0) {
            needs--;
            }
            m[discount[back]]--;
        }
        
        if (m.find(discount[front]) == m.end()) { // can't find
            ;
        } else { // find
            if (m[discount[front]] >= 0) {
            needs++;
            }
            m[discount[front]]++;
        }
        
        if (needs == 0) answer++;
    }
    
    
    
    return answer;
}