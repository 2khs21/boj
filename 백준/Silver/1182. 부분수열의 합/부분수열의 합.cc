#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, S;
int ans;
vector<int> v;
vector<int> comb;

void isAns(const vector<int> & comb) {
  int total = 0;
  if (comb.empty()){
    return ;
  } 
  for (auto c : comb){
    total += c;
  }
  if (total == S){
    ans++;
  }
}

void getComb(int st, vector<int> comb){
  isAns(comb);
  if (comb.size() == N){
    return ;
  }
  for (int i = st + 1; i < v.size(); i++){
    comb.push_back(v[i]);
    getComb(i, comb);
    comb.pop_back();
  }
}

int main(){
  cin >> N >> S;
  v.resize(N);
  for (int i = 0; i < N; i++){
    cin >> v[i];
  }
  getComb(-1, comb);
  cout << ans;
}

