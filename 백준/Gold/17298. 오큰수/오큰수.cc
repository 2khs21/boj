#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; // 수열의 크기
    cin >> n;

    vector<int> ret(n, -1); // 결과 배열, 오큰수를 저장. 초기값은 -1.
    vector<int> table(n, -1); // 입력받은 수열
    stack<int> s; // 스택, 아직 오큰수를 찾지 못한 원소들의 인덱스 저장

    // 수열의 원소를 입력받으면서 오큰수 찾기
    for (int i = 0; i < n; i++) {
        cin >> table[i]; // 수열의 원소 입력
        // 스택이 비어있지 않고, 현재 원소가 스택 top의 원소보다 큰 경우
        while (s.size() && table[s.top()] < table[i]) {
            ret[s.top()] = table[i]; // 오큰수를 결과 배열에 저장
            s.pop(); // 스택에서 제거
        }
        s.push(i); // 현재 원소의 인덱스를 스택에 저장
    }

    // 결과 출력
    for(int i = 0; i < n; i++) {
        cout << ret[i] << " ";
    }

    return 0;
}