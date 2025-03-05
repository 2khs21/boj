#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
int N;
vector<vector<int>> bricks;

int dpH[101];

enum{
	INDEX, S, W, H, PI
};

bool cmp (vector<int> a, vector<int> b){
	if (a[1] < b[1]) return true;
	else if (a[1] > b[1]) return false;
	
	if (a[2] < b[1]) return true;
	else return false;
}

int main(){

	cin >> N;
	for (int i = 0 ; i<N; i++){
		int S,W,H;
		cin >> S >> H >> W;
		bricks.push_back({i, S, W, H, -1});
	}

	sort(bricks.begin(), bricks.end(), cmp);

	int maxH = 0;
	int topI = 0;
	int topPrev = -1;
	for (int i = 0 ; i < N; i++){
		
		dpH[i] = bricks[i][H];
		for (int j = 0; j < i ;j++){
			if (bricks[i][W] > bricks[j][W]) {
				if (dpH[i] < dpH[j] + bricks[i][H]) {

					// cout << "dpH[ " << i << " ] " << dpH[i] << " -> " << dpH[j] + bricks[i][H] << "\n";
					dpH[i] = dpH[j] + bricks[i][H];
					bricks[i][PI] = bricks[j][INDEX];
				}
			}

		}

		if (maxH < dpH[i]) {
			maxH = dpH[i];
			topI = bricks[i][INDEX];
		}
	}

	// cout << topI << ", " << maxH << "\n";

	sort(bricks.begin(), bricks.end());

	vector<int> a;
	while (topI != -1) {
		a.push_back(topI);
		topI = bricks[topI][PI];
	}
	cout << a.size() << "\n";
	for (auto rit = a.rbegin(); rit != a.rend(); rit++){
		cout << *rit + 1<< "\n";
	}

}
