#include <iostream>
#include <queue>
using namespace std;
/*
input
N(1~100,000) K(1~100,000)

*/
int arr[100001];
#define max 100000

queue<pair<int, int>> Q;
#include <unistd.h>
void teleport(){
  int pos = Q.front().first;
  int depth = Q.front().second;
  
  Q.pop();
  if (arr[pos] != -1) return ;
  if (pos == 0) {
    arr[0] = depth;
    if (arr[1] == -1)
    Q.push({1, depth + 1});
    return ;
  }
  while (pos <= max) {
    if (arr[pos] != -1) return ;
    arr[pos] = depth;
    if (pos - 1 >= 0 && arr[pos - 1] == -1 ){
      Q.push({pos - 1, depth + 1});
    }
    if (pos + 1 <= max && arr[pos + 1] == -1){
      Q.push({pos + 1, depth + 1});
    }
    pos *= 2;
  }
}


int main(){
  int N, K;
  cin >> N >> K;
  for (int i = 0 ; i <= max; i++){
    arr[i] = -1;
  }

  Q.push({N, 0});
  while (!Q.empty()){
    teleport();
  }
  // for (int i = 0 ; i <= 10 ; i++){
  //   cout << i << " ; " << arr[i] << "\n";
  // }
  cout << arr[K];
}