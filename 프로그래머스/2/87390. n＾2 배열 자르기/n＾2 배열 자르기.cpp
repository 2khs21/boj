#include <string>
#include <vector>
#include <iostream>
using namespace std;


// int getNum(int x, int y){

//     return max(x, y) + 1;
    
// }


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    for (long long i = left; i <= right; i++){
        // int num = getNum(i % n, i / n);
        // answer.push_back(num);
        long long y = (long long)i / n;
        long long x = (long long)i % n;
        answer.push_back(max(x, y) + 1);
    }
    
    return answer;
}


