#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int COL;
bool mycmp(vector<int> a, vector<int> b){
    if (a[COL] == b[COL]) {
        return a[0] > b[0];
    }
    return a[COL] < b[COL];
}


int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    COL = col - 1;
    sort(data.begin(), data.end(), mycmp);
    // for (auto d : data) {
    //     for (auto a : d) { cout << a << " " ; } cout << "\n";    }
    
    vector<int> v;
    
    for (int i = row_begin - 1; i <= row_end -1 ; i++){
        int total = 0;
        for (auto t : data[i]) {
            total += t % (i + 1);
        }
        v.push_back(total);
        // cout << "i : " << i << "for " << i + 1 <<  "\n";
        // cout << "t : " << total << "\n";
    }
    
    int bit = v[0];
    for (int i = 1 ; i < v.size() ; i++){
        bit = bit ^ v[i];
    }
    
    answer = bit;
    
    
    return answer;
}