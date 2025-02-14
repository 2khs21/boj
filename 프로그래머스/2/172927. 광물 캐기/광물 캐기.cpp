#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// picks[dia, iron, st];


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    cout << "m size : " << minerals.size() << "\n";
    int chunkCnt = (minerals.size() + 4) / 5;
    chunkCnt = min(chunkCnt, picks[0] + picks[1] + picks[2]);
    
    cout << "chunk Cnt : " << chunkCnt << "\n";
    vector<vector<int>> v(chunkCnt, vector<int>(3));
    cout << "v size : " << v.size() << "\n";
    // cout << "v[0] s : " << v[0].size() << "\n";
    // cout << "v[1] s : " << v[1].size() << "\n";
    /*
    	chunk Cnt : 2
        v size : 2
        v[0] s : 3
        v[1] s : 3
        v[2] s : 8

    */

    int index = 0;
    for (int i = 0 ; i < minerals.size(); i = i + 5){    
        for (int j = 0 ; j < 5; j++){
    
            if (i + j >= minerals.size()) break;
            
            
            cout <<"index  " << index << "\n";
            if (minerals[i + j] == "diamond") {
                // cout << v[index][0] << "\n";
            
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
    // return 1 ;

    for (auto a : v) {
        cout << a[0] << ", " << a[1] << ", " << a[2] << "\n";
    }
    
    
    vector<int> per(chunkCnt);
    cout << "Ccnt : " << chunkCnt << "\n";
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
            cout << "i : " << i << ", "<< "tmp : " << tmp << "\n";
            if (answer < tmp) break;
        }
        answer = min (answer, tmp);
        cout << "\nans : " << answer << "\n";
    } while (next_permutation(per.begin(), per.end()));
    
    
    return answer;
}