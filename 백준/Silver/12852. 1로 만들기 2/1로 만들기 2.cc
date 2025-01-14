#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int N; 
int arr[1000001];
int INF = 1e9 ;
int main(){
  cin >> N;
  arr[1] = 0;
  arr[2] = 1;
  arr[3] = 1;

  for (int i = 4; i <= N; i++){
    int divide_2 =  i % 2 ? INF : arr[i / 2]; 
    int divide_3 =  i % 3 ? INF : arr[i / 3];
    // cout << divide_2 << ", " << divide_3 << "\n";
    arr[i] = min({arr[i - 1], divide_2, divide_3}) + 1;  
  }
  // for (int i = 0; i <= 10; i++){
  //   cout << i << " : " <<arr[i] << "\n";
  // }
  cout << arr[N] << "\n";

  int i = N;
  while (i){
    cout << i << " ";
    if (i % 3 == 0 && arr[i / 3] + 1 == arr[i]){
      i /= 3;
    } else if (i % 2 == 0 && arr[i / 2] + 1 == arr[i]){
      i /= 2;
    } else {
      i--;
    }
  }
}