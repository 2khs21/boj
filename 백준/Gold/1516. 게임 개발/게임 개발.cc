#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int endTime[501], startTime[501], duration[501];

int inDeg[501];
vector<int> childs[501];
queue<int> Q;
int N;

int findStartNodes(){
  for (int i = 0; i <= N; i++){
    if (inDeg[i] != 0) continue;
    Q.push(i);
    inDeg[i]--;
    endTime[i] += startTime[i] + duration[i];
  }
  if (Q.empty()) return 0;
  return 1;
}

void popStartNodes(){
  while (!Q.empty()){
    auto parent = Q.front();
    Q.pop();
    
    for (auto child : childs[parent]){
      startTime[child] = max(startTime[child], endTime[parent]);
      inDeg[child]--;
    }
  }
}

int main(){
  cin >> N;

  for(int i = 1; i <= N; i++){
    cin >> duration[i];
    while (1){      
      int tmp;
      cin >> tmp;
      if (tmp == -1) break;
      childs[tmp].push_back(i);
      inDeg[i]++;
    }
  }
  
  while (1){
    if (!findStartNodes()) break;
    // cout << "Q size : " << Q.size() << "\n";
    popStartNodes();
  }

  for (int i = 1; i <= N; i++){
    cout << endTime[i] << "\n";
  }
}