#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;

void func(int st, int dest, int tmp, int k){
    if (k == 1) {
        answer.push_back({st,dest});
        return ;
    } 
    func(st, tmp, dest, k-1);
    answer.push_back({st,dest});
    func(tmp,dest,st,k-1);
}

vector<vector<int>> solution(int n) {
    // vector<vector<int>> answer;
    
    func(1, 3, 2, n);
    
    
    return answer;
}