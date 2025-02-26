#include <iostream>

using namespace std;

int main(){
	long long M, N;
	long long m, n;
	cin >> M >> N;

	m = M;
	n = N;
	long long answer = 0;
	long long x = 1, y =1;
	while (1){
		// cout << "m : " << m << ", n : " << n << "\n";
		if (m <= 1){
			x = N - (x - 1);
			break;
		} else if (n <= 1){
			answer += 1;
			y = M - (y - 1);
			break;
		}
		else if (n <= 2 || m <= 2){
			if (m <= 2) answer += 2;
			else if (n <= 2) answer += 3;
			y++;
			break;
		}
		else {
			answer += 4;
			n -= 2;
			m -= 2;
			x++;
			y++;
		}
	}
	cout << answer << "\n" << y << " " << x << "\n";
}