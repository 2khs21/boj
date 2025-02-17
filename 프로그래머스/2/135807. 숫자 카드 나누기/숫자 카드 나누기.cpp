#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    
    if (a < b) swap(a, b);
    
    if (b == 0) return a;

    return gcd(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    
    int n = arrayA.size();
    int gcdA = arrayA[0];
    for (int i = 1; i < n;i++){
        gcdA = gcd(gcdA, arrayA[i]);
        if (gcdA == 1) break;
    }
    int gcdB = arrayB[0];
    for (int i = 1; i < n;i++){
        gcdB = gcd(gcdB, arrayB[i]);
        if (gcdB == 1) break;
    }
    
    int answerA = gcdB;
    for (auto a : arrayA) {
        if (a % gcdB == 0) {
            answerA = 0;
            break;
        }
    }
    int answerB = gcdA;
    for (auto b: arrayB) {
        if (b % gcdA == 0){
            answerB = 0;
            break ;
        }
    }
    return max(answerA, answerB);
}