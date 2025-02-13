#include <string>

using namespace std;
#include <map>
#include <cctype>

map<string, int> m1, m2;

int solution(string str1, string str2) {
    int answer = 0;
    int cnt1 = 0, cnt2 = 0;
    
    for (int i = 0 ; i + 1< str1.size(); i++){
        
        char c1 = str1[i];
        char c2 = str1[i + 1];
        
        if (!isalpha(c1) || !isalpha(c2)) continue;
        
        c1 = toupper(c1); c2 = toupper(c2);
        
        string s;
        s.push_back(c1);
        s.push_back(c2);
        m1[s]++;
        cnt1++;
    }
        for (int i = 0 ; i + 1< str2.size(); i++){
        
        char c1 = str2[i];
        char c2 = str2[i + 1];
        
        if (!isalpha(c1) || !isalpha(c2)) continue;
        
        c1 = toupper(c1); c2 = toupper(c2);
        
        string s;
        s.push_back(c1);
        s.push_back(c2);
        m2[s]++;
        cnt2++;
    }
    int cntInter = 0; 
    for (auto a : m1){
        const string & key = a.first;
        if (m2.find(key) != m2.end()){
            cntInter += min(m1[key],m2[key]);
        }
    }
    
    if(!cnt1 && !cnt2) return 1 * 65536;
    
    answer = 65536 * cntInter / (cnt1 + cnt2 - cntInter);
    
    
    
    return answer;
}