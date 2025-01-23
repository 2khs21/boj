#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int N, P;

vector<stack<int>> v(7);

int main(){
    cin >> N >> P;

    int ans = 0;    
    while(N--){
        int lineNum;
        int platNum;

        cin >> lineNum >> platNum;
        if (v[lineNum].empty() || v[lineNum].top() < platNum) {
            v[lineNum].push(platNum);
            ans++;
        }
        else {
            while (!v[lineNum].empty() && v[lineNum].top() > platNum){
                v[lineNum].pop();
                ans++;
            }
            if (!v[lineNum].empty() && v[lineNum].top() == platNum){
                ;
            } else {
                v[lineNum].push(platNum);
                ans++;
            }
        }
    }
    cout << ans;
}