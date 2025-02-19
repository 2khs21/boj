#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    vector<pair<int, int>> points;
    
    for (int i = 0 ; i < line.size(); i++){
        for (int j = i + 1; j < line.size(); j++){
            long a,b,c,d,e,f;
            a = line[i][0]; b = line[i][1]; e = line[i][2];
            c = line[j][0]; d = line[j][1]; f = line[j][2];
            
            if (a*d - b*c == 0) continue;
            if (((b*f - e*d) % (a*d - b*c)) || ((e*c - a*f) % (a*d - b*c))) continue;
            int x = (b*f - e*d) / (a*d - b*c);
            int y = ((e*c - a*f) / (a*d - b*c));
            points.push_back({x, y});
        }
    }
    if (points.empty()) return answer;
    
    int maxX, minX, maxY, minY;
    
    maxX = points[0].first;
    minX = points[0].first;
    maxY = points[0].second;
    minY = points[0].second;
    
    for (auto p : points){
        maxX = max(maxX, p.first);
        maxY = max(maxY, p.second);
        
        minX = min(minX, p.first);
        minY = min(minY, p.second);
    }
    
    answer.resize(maxY - minY + 1, string(maxX - minX + 1, '.'));
    for (auto p :points){
        int x = p.first - minX;
        int y= maxY - p.second;
        answer[y][x] = '*';
    }
    
    
    
    
    
    return answer;
}