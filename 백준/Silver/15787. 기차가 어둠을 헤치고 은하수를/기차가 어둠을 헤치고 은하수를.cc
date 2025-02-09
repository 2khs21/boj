#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*
1 i x 상차, 타있으면 암것도 안함
2 하차 , 없으면 암것도 안함
3 뒤로 전부 한칸, 20번있으면 하차
4 앞으로 한칸 1번 있으면 하차
*/

vector<int> train;
void exeCmd(){
	int cmd, i, x;
	cin >> cmd;

	if (cmd == 1 || cmd == 2){
		cin >> i >> x;
	} else if (cmd == 3 || cmd == 4){
		cin >> i;
	}
		if (cmd == 1) train[i - 1] = train[i - 1] | (1 << (x - 1));
		if (cmd == 2) train[i - 1] = train[i - 1] & (~ (1 << (x - 1)));
		if (cmd == 3) {
			train[i - 1] <<= 1;
			train[i - 1] &= ~(1 << 20);

		}
		if (cmd == 4) train[i - 1] >>= 1;
}

int main(){
	int N, M;
	cin >> N >> M;
	train.resize(N);
	while (M--){
		exeCmd();
	}
	set<int> s;
	for (auto & t : train) {
		s.insert(t);
		
		// for (int i = 0 ; i < 5; i ++) {
		// 	cout << (t & 0b1)  <<  " ";
		// 	t >>= 1;
		// }
		// cout << "\n";
		}

	cout << s.size();
}