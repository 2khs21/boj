#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#include <iostream>
vector<int> func(vector<int> & fees, vector<string> & records) {
    
    vector<pair<int, int>> pR;
    
    for (auto r : records){
        int time = stoi(r.substr(0,2)) * 60 + stoi(r.substr(3,2));
        int id =  stoi(r.substr(6,4));
        // char flag = r.substr(11,1); 
        pR.push_back({id,time});
    }
    sort(pR.begin(), pR.end());
   
//     for (auto p : pR){
//         cout << p.first << " : " << p.second << "\n";
//     }
    
    int endTime = 23*60 + 59;
    
    map<int, int> m;
    for (int i = 0; i < pR.size();){
        
        int id = pR[i].first;
        int time = pR[i].second;
        
        if (i + 1 >= pR.size() || pR[i + 1].first != id) { // ~23:59
            m[id] += (endTime - time);
            i++; // i++
            continue;
        }
        
        m[id] += (pR[i+1].second - time);
        i += 2;
    }
    
    // for (auto a : m){
    //     cout << a.first << " : " << a.second << "\n";
    // }
    vector<int> res;
    //[180, 5000, 10, 600]
    // 5000 + ⌈(334 - 180) / 10⌉ x 600 = 14600

    for (auto p : m) {
        int fee = 0;
        int dur = max(p.second - fees[0], 0);
        
        int addFee = (dur / fees[2] + (dur % fees[2] != 0)) * fees[3];
        
        // cout << "tmp : [16]  "  << (dur / fees[2] + (dur % fees[2])) << "\n";
        fee = fees[1] +  addFee;
        
        // cout << "dur : " << dur << ", addFee : " << addFee << "fee : " << fee << "\n";
        res.push_back(fee);
    }
    
    return res;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // id , time ,in/out

    answer = func(fees, records);
    
    return answer;
}