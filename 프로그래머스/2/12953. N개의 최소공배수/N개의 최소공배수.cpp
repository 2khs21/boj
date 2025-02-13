#include <string>
#include <vector>

using namespace std;
#include <iostream>
int LCD(int a, int b){
    // cout << "a : b  " << a << ", " << b << "\n";
    if (a < b) swap(a, b);
    if (b == 0) {
        return a;
    }
    return LCD (a % b, b);
}

int GCD(int a, int b){

    return a * b / LCD(a, b);

}

int solution(vector<int> arr) {
    int answer = 0;
    int gcd=1;
    for (auto a : arr){
        gcd = GCD(gcd, a);
    }
    
    answer = gcd;
    
    
    return answer;
}
