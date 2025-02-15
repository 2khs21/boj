#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    
    stack<pair<int, int>> S;
    for(int i = 0 ; i < numbers.size();i++){

        while (!S.empty() && S.top().first < numbers[i]) {
            int index = S.top().second;
            S.pop();
            answer[index] = numbers[i];
        }
        
        S.push({numbers[i], i});
    }
    
    return answer;
}