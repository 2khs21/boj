#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/*
    개수 n, 다리길이 w, 최대 하중 L 
 - - - - - - - -

n, w, L
a1 a2 a3 ... an
*/
queue<int> Q;
int main(){
    int n,w,L;
    cin >> n >> w >> L;
    for (int i = 0 ; i < w; i++){
        Q.push(0);
    }
    vector<int> v;
    v.resize(n);
    for (int i = 0 ; i < n; i++){
        cin >> v[i];
    }
    int total = 0;
    int ans = 0;
    int i = 0;
    while(n){
        // 나가면 n--
        if (Q.front()) n--;
        total -= Q.front();
        Q.pop();
        if (total < L && total + v[i] <= L) {
            Q.push(v[i]);
            total += v[i];
            i++;
        } else {
            Q.push(0);
        }
        ans++;
    }
    cout << ans;

}