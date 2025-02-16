#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue<int> pq;
#include <iostream>
int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    int totalE = 0;
    
    int i = 0;
    
    while (i < enemy.size() && n >= totalE) {

        // cout << "i : " << i << " : " << enemy[i] << "\n";
        totalE += enemy[i];
        pq.push(enemy[i]);
        i++;

        if (totalE > n && k--) {
            totalE -= pq.top();
            // cout << "pass : " << pq.top() << "\n";
            pq.pop();
        }
    }
    if (totalE > n) i--;
    return i;
}