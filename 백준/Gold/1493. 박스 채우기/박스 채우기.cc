#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long


/*
정육면체로 분할
*/

int inventory[21];
ll cubes[21];
ll ans;
vector<int> sidebuf(3);
vector<int> cubeSideCandidates;

pair<int, int> getCubeSide(int s1, int s2, int s3){
	auto  it = upper_bound(cubeSideCandidates.begin(), cubeSideCandidates.end(), min({s1, s2, s3}));
	int cubeSide = *(it - 1);
	int sideIndex = it - 1 - cubeSideCandidates.begin();
	// cout << "cubeSide : " << cubeSide << ", sideIndex : " << sideIndex << "\n";
	return {cubeSide, sideIndex};
}

void divideCube(ll s1, ll s2, ll s3){
	sidebuf = {s1, s2, s3};
	sort(sidebuf.begin(), sidebuf.end());
	s1 = sidebuf[0], s2 = sidebuf[1], s3 = sidebuf[2];
	if (s1 == 0) return ;
	int cubeSide, sideIndex;
	tie(cubeSide, sideIndex)  = getCubeSide(s1, s2, s3);
	cubes[sideIndex] += (s1/cubeSide) * (s2/cubeSide) * (s3/cubeSide);

	//
	int s1R = s1 % cubeSide;
	int s1Q = s1 - s1R;
	int s2R = s2 % cubeSide;
	int s2Q = s2 - s2R;
	int s3R = s3 % cubeSide;
	int s3Q = s3 - s3R;

	divideCube(s1, s2, s3R);
	divideCube(s1Q, s2R, s3Q);
	divideCube(s1R, s2R, s3Q);
	divideCube(s1R, s2Q, s3Q);
}

int tryFillCube(int cubeIndex){
	if (cubeIndex < 0) return false;
	if (inventory[cubeIndex]) {
		inventory[cubeIndex]--;
		ans++;
		return true;
	} else {
		for (int i = 0; i < 8; i++)
			if(tryFillCube(cubeIndex - 1) == false) return false;
	}
	return true;
}

int fillCubes(){
	for(int i = 20; i >= 0; i--){
		while (cubes[i]){
			if (tryFillCube(i) == true){
				cubes[i]--;
			} else {
				return -1;
			}
		}
	}
	return 0;
}

int main(){

	int N, A, B;
	int s1, s2, s3;
	vector<int> sides(3);
	cin >> s1 >> s2 >> s3;
	cin >> N;
	for (int i = 0 ; i < N; i++){
		cin >> A >> B;
		inventory[A] = B;
	}
	for (int cubeSideCandidate = 1; cubeSideCandidate <= max({s1, s2, s3}); cubeSideCandidate *= 2){
		// cout << cubeSideCandidate << " ";
		cubeSideCandidates.push_back(cubeSideCandidate);
	}

	divideCube(s1, s2, s3);
	if (fillCubes() == -1) {
		cout << -1;
	} else {
		cout << ans;
	}	
		
}