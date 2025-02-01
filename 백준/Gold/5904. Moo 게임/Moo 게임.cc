#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

ll N;
int main(){
	cin >> N;
	int target = N;
	while (1){
		int i = 0;
		ll prev = 0;
		ll curr = i + 3;
		while(curr < target){
			i++;
			prev = curr;
			curr = curr * 2 + (i + 3);
		}
		target -= prev;
		if (target <= i + 3){
			if (target == 1) cout << "m";
			else cout << "o";
			return 0;
		} else {
			target -= i + 3;
		}
	}
}