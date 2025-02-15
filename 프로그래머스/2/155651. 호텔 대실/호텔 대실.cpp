#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#include <iostream>
int timeToInt(string time){

    return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));    
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    
    sort(book_time.begin(), book_time.end()); // 시작시간으로 정렬해서 하나씩 넣자.
    
    int waiting = 0;
    int maxWaiting = 0;
    for (auto t : book_time){
        cout << t[0] << ", " << t[1] << "\n";
        int sTime = timeToInt(t[0]);
        int eTime = timeToInt(t[1]);
        
        while (!pq.empty() && pq.top() + 10 <= sTime) {
            pq.pop();
            waiting--;
        }        
        waiting++;
        maxWaiting = max(maxWaiting, waiting);
        pq.push(eTime);
    }
    answer = maxWaiting;
    
    return answer;
}