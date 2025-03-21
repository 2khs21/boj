#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> m;
    
    for (auto & c : clothes) {
        m[c[1]]++;
    }
    answer = 1;
    for (auto it = m.begin(); it != m.end(); it++){
        answer *= (it->second + 1);
    }
    answer--;
    return answer;
}