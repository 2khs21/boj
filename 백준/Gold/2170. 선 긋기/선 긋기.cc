#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
/*
input
N (1 ~ 1,000,000)
x, y (-1,000,000,000 ~ 1,000,000,000)
*/
int N;
pair<int, int> arr [1000001];
int st, en;

int len;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  int p1, p2;
  for (int i = 0; i < N; i++){
    cin >> p1 >> p2;
    
    if (p1 < p2) {
      arr[i].first = p1;
      arr[i].second = p2;
    } else {
      arr[i].first = p2;
      arr[i].second = p1;
    }
  }
  sort(arr, arr + N);

  st = arr[0].first;
  en = arr[0].second;
  for (int i = 0 ; i < N; i++){
    int x = arr[i].first;
    int y = arr[i].second;
    if (x <= en) {
      if (y > en) {
        en = y;
      }
    } else if (x > en) {
      len += en - st;
      // cout << en << " - " << st << " : " << en - st << "\n";
      st = x;
      en = y;
    }
  }
  len += en - st;
  cout << len;
}