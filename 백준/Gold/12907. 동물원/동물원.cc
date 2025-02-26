#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int t;
	cin >> t;
	int error = 0;

	vector<int> arr(t);

	for (int i = 0; i < t; i++){
		cin >> arr[i];
	}

	int maxVal = *max_element(arr.begin(), arr.end());
	vector<int> cnt(maxVal + 1);
	for (int i = 0; i < t; i++){
		cnt[arr[i]]++; 
	}
	int twoCnt = 0;
	int oneCnt = 0;
	for (int i = 0 ; i < cnt.size(); i++){
		if (cnt[i] == 2) {
			if (oneCnt) {
				error = 1;
				break;
			}
			twoCnt++;
		}
		else if (cnt[i] == 1){
			oneCnt++;
		}
		else {
			error = 1;
			break;
		}
	}
	if (error) {
		cout << 0 << "\n";
	} else {
		cout << static_cast<int>(pow(2, twoCnt + (oneCnt  > 0)));
		// cout << "t : " << twoCnt << "\n";
		// cout << "o : " << (oneCnt > 0 ) << "\n";
	}

}