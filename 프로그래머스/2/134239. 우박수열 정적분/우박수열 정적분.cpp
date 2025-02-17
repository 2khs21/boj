#include <string>
#include <vector>

using namespace std;
#include <iostream>
vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector <int> graph;
    vector <int> x2Sum;
    
    graph.push_back(k);
    while (k > 1) {
        if(k % 2 == 0) {
            k /= 2;
        } else {
            k = k * 3 + 1;
        }
        graph.push_back(k);
    }
    
    // for (auto a : graph) {
    //     cout << a << " ";
    // }
    // cout << "\n";
    int n = graph.size() - 1;
    x2Sum.resize(n + 1);
    
    x2Sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        x2Sum[i] = x2Sum[i - 1] + (graph[i -1] + graph[i]);
    }
    // for (auto a : x2Sum){
    //     cout << a << " ";
    // }
    // cout << "\n";
    
    
    for (auto r : ranges) {
        int st = r[0];
        int en = n + r[1];
        if (st > en) answer.push_back(-1.0);
        
        else if (st == en) answer.push_back(0);
        
        else if (st < en){
            double val = x2Sum[en] - x2Sum[st];
            val /= 2;
            answer.push_back(val);
        }
    }
    
    
    return answer;
}