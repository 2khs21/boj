#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int first = 1;
    
    for (auto c : s){
        if (first == 1 ) {
            if (c >= 'a' && c <= 'z') {
                answer.push_back(c + 'A' - 'a');
            } else {
                answer.push_back(c);
            }
            first = 0;
        } else {
            if (c >= 'A' && c <= 'Z') {
                answer.push_back(c + 'a' - 'A');
            } else {
                answer.push_back(c);
            }
        }
        if (c == ' ') first = 1;
    }
    return answer;
}