#include <vector>
#include <string>
using namespace std;
int maxDP[102][102];
int minDP[102][102];
int N;
char ops[102];
#include <iostream>

void DP(){
    for (int len = 1; len < N; len++){
        
        for (int i = 0; i <= N - len; i++){
            
            int j = i + len;
            
            for (int k = i; k < j; k++){

                if (ops[k] == '+') {
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] + maxDP[k + 1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] + minDP[k + 1][j]);
                } else if (ops[k] == '-') {
                    maxDP[i][j] = max(maxDP[i][j], maxDP[i][k] - minDP[k + 1][j]);
                    minDP[i][j] = min(minDP[i][j], minDP[i][k] - maxDP[k + 1][j]);
                }
             }

            
            
        }
        
        
        
        
    }
}


int solution(vector<string> arr)
{
    int answer = -1;
    N = arr.size() / 2 + 1;
    
    for (int i = 0 ; i < N; i++){
        for (int j = 0; j<N; j++){
            maxDP[i][j] = -1e9;
            minDP[i][j] = 1e9;
        }
    }
    
    maxDP[0][0] = stoi(arr[0]);
    minDP[0][0] = stoi(arr[0]);
    for (int i = 1 ; i < arr.size(); i += 2){
        int val = stoi(arr[i + 1]);
        maxDP[i/2 + 1][i/2 + 1] = val;
        minDP[i/2 + 1][i/2 + 1] = val;
        ops[i/2] = arr[i][0];
    }
    
    
    
    DP();
    
    answer = maxDP[0][N - 1];
    
    return answer;
}