#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// picks[dia, iron, st];


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int chunkCnt = (minerals.size() + 4) / 5;
    chunkCnt = min(chunkCnt, picks[0] + picks[1] + picks[2]);
    vector<vector<int>> v(chunkCnt, vector<int>(3));
    int index = 0;
    for (int i = 0 ; i < minerals.size(); i = i + 5){    
        for (int j = 0 ; j < 5; j++){
            if (i + j >= minerals.size()) break;
            
            if (minerals[i + j] == "diamond") {
                v[index][0] += 1;
                v[index][1] += 5;
                v[index][2] += 25;
            } else if (minerals[i + j] == "iron") {
                v[index][0] += 1;
                v[index][1] += 1;
                v[index][2] += 5;
            } else if (minerals[i + j] == "stone") {
                v[index][0] += 1;
                v[index][1] += 1;
                v[index][2] += 1;
            }
        }
        index++;
        if (index >= chunkCnt) break;
    }

    for (auto a : v) {
        cout << a[0] << ", " << a[1] << ", " << a[2] << "\n";
    }
    
    
    vector<int> per(chunkCnt);

    for (int i = 0; i < chunkCnt; i++){
        if (i < picks[0]) {
            per[i] = 0;
        } else if (i < picks[0] + picks[1]){
            per[i] = 1;
        } else {
            per[i] = 2;
        }
    }

    answer = 1e9;
    do {
        int tmp = 0;
        for (int i = 0; i < chunkCnt; i++){
            tmp += v[i][per[i]];
            if (answer < tmp) break;
        }
        answer = min (answer, tmp);
    } while (next_permutation(per.begin(), per.end()));
    
    return answer;
}