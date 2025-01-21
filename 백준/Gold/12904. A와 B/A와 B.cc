#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
#include <deque>
using namespace std;
#define INF 1e9

deque<char> a, b;
int direction = 1;

#define SAME 1
#define DIFF 0

int myCmp(){
	
	if (direction == 1){
		for (int i = 0; i < a.size(); i++){
			if (a.at(i) != b.at(i)) return DIFF;
		}
	
	}
	else if (direction == -1){
		for (int i = 0; i < a.size(); i++){
			if (a.at(i) != b.at(a.size() - i - 1)) return DIFF;
		}
	}
	return SAME;
}

int main(){
	int aSize, bSize;
	string tmp;
	getline(cin, tmp);
	aSize = tmp.size();
	for (int i = 0 ; i < tmp.size(); i++){
		a.push_back(tmp[i]);
	}
	getline(cin, tmp);
	bSize = tmp.size();
	for (int i = 0 ; i < tmp.size(); i++){
		b.push_back(tmp[i]);
	}

	while (aSize != bSize){
		if (direction == 1){
			if (*(b.end() - 1) == 'A'){
				b.pop_back();
			}	else if (*(b.end() - 1) == 'B'){
				b.pop_back();
				direction *= -1;
			}
		}
		else if (direction == -1){
			if (*(b.begin()) == 'A'){
				b.pop_front();
			}	else if (*(b.begin()) == 'B'){
				b.pop_front();
				direction *= -1;
			}
		}
		bSize--;
	}

	cout << myCmp();
}
