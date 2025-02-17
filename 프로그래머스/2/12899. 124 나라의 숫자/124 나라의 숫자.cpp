#include <string>
#include <vector>
#include <algorithm>

using namespace std;
#include <iostream>
string solution(int n) {
    string answer = "";
    int k = n;
    
    while (k) {
        k--;
        int m = k % 3;
        char c;
        cout << k << ", " << m << "\n";
        if (m == 0) c = '1';
        else if (m == 1) c = '2';
        else if (m == 2) c = '4';
        answer += c;
        k /= 3;
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}

