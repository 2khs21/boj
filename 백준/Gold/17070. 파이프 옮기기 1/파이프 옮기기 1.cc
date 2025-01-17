#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define WALL 1

int lengthState[17][17], widthState[17][17], crossState[17][17];
int board[17][17];
int N;

int isPossibleLBCross(int y, int x){
  if (board[y - 1][x - 1] == WALL
  || board[y][x] == WALL 
  || board[y][x - 1] == WALL 
  || board[y - 1][x] == WALL){
    return 0;
  }
  return 1;
}

int isPossibleLWidth(int y, int x){
  if (board[y][x] == WALL || board[y][x - 1] == WALL) return 0;
  return 1;
}
int isPossibleBLength(int y, int x){
  if (board[y][x] == WALL || board[y - 1][x] == WALL) return 0;
  return 1;
}

int getAllState(int y, int x){
  if (board[y][x] == WALL) return 0;
  // 가로 가능 확인
  if (isPossibleLWidth(y, x)){
    widthState[y][x] += widthState[y][x-1]; //가로->가로
    widthState[y][x] += crossState[y][x-1]; //대각->가로
  } 
  // 대각 가능 확인
  if (isPossibleLBCross(y,x)){
    crossState[y][x] += widthState[y-1][x-1]; // 가로->대각
    crossState[y][x] += lengthState[y-1][x-1]; // 세로->대각
    crossState[y][x] += crossState[y-1][x-1]; // 대각->대각
  }
  // 세로 가능 확인
  if (isPossibleBLength(y,x)){
    lengthState[y][x] += lengthState[y-1][x]; // 세로->세로
    lengthState[y][x] += crossState[y-1][x]; // 대각->세로
  }
  return 0;
}

int main(){
  cin >> N;
  for (int j = 1; j <= N; j++){
    for (int i = 1; i <= N; i++){
      cin >> board[j][i];
    }
  }

  for (int i = 2; i <= N; i++){
    if (board[1][i] == WALL) break; 
    widthState[1][i] = 1;
  }

  for (int o = 2; o <= N ; o++){
      getAllState(o, o);
    for (int y = o + 1; y <= N; y++){
      getAllState(y, o);
    }
    for (int x = o + 1; x <= N; x++){
      getAllState(o, x);
    }
  }

/*
  cout << "\n----WIDTH------\n";
  for (int j = 1; j <= N; j++){
    for (int i = 1; i <= N; i++){
      cout << widthState[j][i] << " ";
    }
    cout << "\n";
  }

  cout << "\n----CROSS------\n";
  for (int j = 1; j <= N; j++){
    for (int i = 1; i <= N; i++){
      cout << crossState[j][i] << " ";
    }
    cout << "\n";
  }

  cout << "\n----LENGTH------\n";
  for (int j = 1; j <= N; j++){
    for (int i = 1; i <= N; i++){
      cout << lengthState[j][i] << " ";
    }
    cout << "\n";
  }
*/  
  
 cout << widthState[N][N] + lengthState[N][N] + crossState[N][N];
}