#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#include <iostream>


int stotime(string timeStr) {
    int h = stoi(timeStr);
    int m = stoi(&timeStr[3]);
    return  h * 60 + m;
}

int tCmp( vector<string> a, vector<string> b) {
    return stotime(a[1]) < stotime(b[1]);
    
}

vector<string> solution(vector<vector<string>> plans) {
    sort(plans.begin(), plans.end(), tCmp);
    
    vector<string> answer;
    
    stack<pair<string, int>> S;
    
    int curTime = 0;
    for (auto p : plans) {
        cout << "\n\n P : " << p[0] << "\n";
        if (S.empty()) {
            curTime = stotime(p[1]);
            int remain = stoi(p[2]);
            S.push({p[0], remain});
            continue;
        }
        
        int nextTime = stotime(p[1]);
        int dif = nextTime - curTime;
        cout << "dif : " << dif << "\n";
        while (!S.empty() && dif > 0) {
            string s;
            int remain;
            tie(s, remain) = S.top();
            S.pop();
            cout << "s : " << s << " remian : " << remain << "\n";
            
            if (remain > dif) {
                
                S.push({s, remain - dif}); // 조금만 하고 다시 스택에
                dif = 0;
            } else {
                dif -= remain;
                answer.push_back(s);
                cout << "dif : " << dif << "  answer += " << s << "\n";
            }
        }
        S.push({p[0], stoi(p[2])});
        curTime = nextTime;
    }
    while (!S.empty()){
        answer.push_back(S.top().first);
        S.pop();
    }

    return answer;
}