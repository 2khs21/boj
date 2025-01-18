#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;




int N, M;
int arr[51][51];
vector<pair<int,int>> stores;
vector<pair<int,int>> homes;
int ans = 1e9;
void getChickenDistance(vector<bool> comb){
  // cout << "getCicken\n";
  int dis = 0;
  
  for (int i = 0; i < homes.size(); i++){
    int homeDis = 1e9;
    auto posHome = homes[i];
    for (int j = 0 ; j < stores.size(); j++){
      if (comb[j] == false) continue;
      auto posStore = stores[j];
      int tmp = abs(posHome.first - posStore.first) + abs(posHome.second - posStore.second);
      homeDis = min(homeDis, tmp);
    }
    dis += homeDis;
    // cout << "a dis : " << dis << "\n";
  }
  ans = min(ans, dis);
}

int main(){


  cin >> N >> M;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> arr[i][j];
      if (arr[i][j] == 1) homes.push_back({i,j});
      if (arr[i][j] == 2) stores.push_back({i,j});
    }
  }
  
  vector<bool> boolForComb(stores.size());
  fill(boolForComb.end() - M, boolForComb.end(), true);
  
  do{
    getChickenDistance(boolForComb);
  } while(next_permutation(boolForComb.begin(), boolForComb.end()));
  
  cout << ans;
}