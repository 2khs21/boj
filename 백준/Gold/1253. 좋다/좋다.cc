#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define INF 1e9


int N;
vector<int> v;
set<int> goods;
int ans;
int main(){
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++){
    int st = 0, en = N-1;

    int target = v[i];
    while (st < en){
      if (st == i) {
          st++;
          continue;
      }
      if (en == i) {
        en--;
        continue;
      }
      int sum = v[st] + v[en];
        // cout << "find ?  " << v[st] << " + " << v[en] << " = " << target << "  ans : " << ans << "\n";
      if (target == sum){
        ans++;
        // cout << v[st] << " + " << v[en] << " = " << target << "  ans : " << ans << "\n";
        break;
      }
      if (target > sum) st++;
      if (target < sum) en--;

    }
  }
  cout << ans;
}