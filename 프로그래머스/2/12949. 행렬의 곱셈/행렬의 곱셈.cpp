#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    
    int n1, m1, n2, m2;
    n1 = arr1.size();
    m1 = arr1[0].size();
    n2 = arr2.size();
    m2 = arr2[0].size();
    
    vector<vector<int>> answer(n1, vector<int>(m2));
    
    
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < m2; j++){
            int val = 0;
            for (int k = 0; k < m1; k++){
                // cout << arr1[i][k] << " * " << arr2[k][j] << "\n";
                val += arr1[i][k] * arr2[k][j];
            }
            // cout << val << "\n\n";
            answer[i][j] = val;
        }
    }
    
    return answer;
}
/*
[[2, 3, 2],
[4, 2, 4],
[3, 1, 4]],

[[5, 4, 3],
[2, 4, 1],
[3, 1, 1]]
기댓값 〉	[[22, 22, 11], [36, 28, 18], [29, 20, 14]]
*/