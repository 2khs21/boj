#include <string>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;
#include <iostream>
int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<>());
    
    int st = 0;
    int en = people.size() - 1;
    
    while (st <= en) {

        if (st == en) {
            answer++;
            break;
        }
        
        if (people[st] + people[en] <= limit) {
            answer++;
            st++;
            en--;
            
        } else {
            answer++;
            st++;
        }
    }
    
    
    return answer;
}