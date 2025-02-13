#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end());
    
    // for (auto t : targets) {
    //     cout << t[0] << "," << t[1] << " ";
    // }
    // cout << "\n";
    
    stack<vector<int>> S;

    int newHead;
    int minTail;
    int empty = 1;
    for (int i = 0 ; i < targets.size(); i++){
        // cout << "target : " << targets[i][0] << ", " << targets[i][1] << "\n";
        if (empty) {
           empty = 0;
            minTail = targets[i][1];
            // cout << "empty min : " << minTail << "\n";
        }
        // 존재한다면.
        newHead = targets[i][0];
        // cout << "newHead : " << newHead << "\n";
        // cout << "prev minTail : " << minTail << "\n";
        
        if (minTail <= newHead) {
            // cout << "Lazer\n";
            minTail = targets[i][1];
            answer++;
        } else {
            minTail = min(minTail, targets[i][1]);
            // cout <<"new minTail : " << minTail << "\n";
        }
    }
    if (!empty) answer++;
    
    
    return answer;
}