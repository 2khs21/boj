#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#include <iostream>
#include <stack>
#define INDEX first
#define CNT second

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    stack<pair<int, int>> d;
    stack<pair<int, int>> p;
    
    for (int i = 0 ; i < n; i++){
        if (deliveries[i]) {
            d.push({i, deliveries[i]});
        }
        if (pickups[i]) {
            p.push({i,pickups[i]});
        }
    }

    while (!d.empty() || ! p.empty()){
        
        int dest = max((d.empty()?0:d.top().INDEX), p.empty()?0:p.top().INDEX);
        
        answer += 2 * (dest + 1); // index + 1 거리 이동
        
        
        int dCap = cap;
        int pCap = cap;
        
        while (!d.empty() && dCap > 0) {
            auto & topBox = d.top().CNT;
            if (topBox > dCap){
                topBox -= dCap;
                dCap = 0;
            
            } else {
                dCap -= topBox;
                d.pop();
            }
            
        }
        while (!p.empty() && pCap > 0) {
            auto & topBox = p.top().CNT;
            
            if (topBox > pCap){
                topBox -= pCap;
                pCap = 0;
                
            } else {
                pCap -= topBox;
                p.pop();
            }
        }   
    
    }
    
        
        
    return answer;
}