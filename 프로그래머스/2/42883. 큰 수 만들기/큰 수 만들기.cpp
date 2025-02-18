#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size() - k;

    auto stIt = number.begin();
    while (len--){
        char maxVal = *max_element(stIt, number.end() - len);
        stIt = find(stIt, number.end(), maxVal);
        stIt++;
        answer += maxVal;
    }

    return answer;
}