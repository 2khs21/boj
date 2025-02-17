#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



int tmp = 0;
int isPossible(vector<char> & seq, string & d) {
    char l = d[0];
    char r = d[2];
    
    char cmp =d[3];
    int dis = d[4] - '0';
    
    int li, ri;
    
    for (int i = 0 ; i < seq.size(); i++){
        if (seq[i] == l) {
            li = i;
        } else if (seq[i] == r) {
            ri = i;
        }
    }
    
    
    if (cmp == '=') {
        if (abs(li - ri) - 1 == dis) return 1;
        else return 0;
    }
    
    else if (cmp == '<') {
        if (abs(li - ri) - 1 < dis) return 1;
        else return 0;
    }
    else if (cmp == '>'){
        if (abs(li - ri) - 1 > dis) return 1;
        else return 0;
    }    
    return -1;
}


int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char> seq = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    
    do {
        int possible = 1;
        for (auto & d : data){
            if ((possible = isPossible(seq, d)) == 0) break;
        }
        answer += possible;
        
    } while(next_permutation(seq.begin(), seq.end()));
    
    
    return answer;
}