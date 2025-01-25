#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;
long long total;
bool state[4000001];
// vector<int> v;
vector<long long>addV;

int ans;
int main(){
    int N;
    cin >> N;
    addV.push_back(total);
    for (int i = 2; i < N + 1; i++){
        if (state[i]) continue;
        // cout << i << ", ";
        total += i;
        addV.push_back(total);
        // v.push_back(i);
        for (int j = 1; i * j < N + 1; j++) {
            state[i*j] = 1;
        }
    }
    // for (int i = 0; i < 10; i++){
    //     cout << addV[i] << ", ";
    // }
    int st = 0;
    auto enit = lower_bound(addV.begin(), addV.end(), N);
    if (enit == addV.end()){
        cout << ans; return 0;
    }
    int en = lower_bound(addV.begin(), addV.end(), N) - addV.begin();
    // int en = 0;
    while(st < en && en < addV.size()){
        long long cur = addV[en] - addV[st];
        if (cur == N){
            // cout << "\n" << addV[en] << " - " << addV[st] << "\n";
            ans++;
            st++;
            en++;
        }else if (cur < N) {
            en++;
        } else if (cur > N) {
            st++;
            if (st == en) en++;
        }
    }
    cout << ans;
}
