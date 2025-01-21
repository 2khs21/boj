#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <list>
using namespace std;
#define INF 1e9
enum{
	UP = 1, DOWN, RIGHT, LEFT
};

class Shark{
	public:
	Shark(int r, int c, int speed, int direction, int size, int alive) : 
	r(r), c(c), speed(speed), direction(direction), size(size), alive(alive){}
		Shark() : r(INF), c(0), alive(0) {}
		int r,c;
		int speed;
		int direction;
		int size;
		int alive;
};

int R, C, M;

int r, c, s, d, z;
// (y, x) 속력, 방향(1 2 3 4 위아래오왼), 크기
int fisher;
int ans;
vector<Shark> v;

void fish(){
	int hunt = -1;
	int proDis = INF;
	for (int i = 0 ; i < v.size(); i++){
		if (v[i].c == fisher && v[i].alive){
			if (v[i].r < proDis){
				hunt = i;
				proDis = v[i].r;
			}
		}
	}
	if (hunt != -1) {
		v[hunt].alive = 0;
		ans += v[hunt].size;
		// cout << "Hunt : " << hunt << " , ans : " << ans << "\n";
	}
}
/*
-3 
*/
void oneMove(int i){
	int r = v[i].r;
	int c = v[i].c;

	int dir = v[i].direction;
	int s = v[i].speed;
	
	if (dir == UP) {
		r -= s;
	}  else if (dir == DOWN){
		r += s;
	}
	while (!(1 <= r && r <= R)){
		// cout << "sped : " << s << "\n";
		// cout << "r : " << r << "\n";
		if (r < 1) {
			r = -1 * r + 2;
			v[i].direction = DOWN;
		} else if (r > R) {
			r = R - (r - R);
			v[i].direction = UP;
		}
	}

	if (dir == LEFT) {
		c -= s;
	} else if (dir == RIGHT){
		c += s;
	}
	while (!(1 <= c && c <= C)){
		// cout << "c : " << c << "\n";
		if (c < 1){
			c = -1 * c + 2;
			v[i].direction = RIGHT;
		} else if (c > C){
			c = C - (c - C);
			v[i].direction = LEFT;
		}
	}
	v[i].r = r;
	v[i].c = c;

}

void move(){
	int arr[101][101];
	for (int i = 0; i < 101; i++){
		for (int j = 0; j < 101; j++){
			arr[i][j] = -1;
		}
	}

	for (int i = 0; i < v.size(); i++){
		if (v[i].alive == 0) continue;
		oneMove(i);
		int alreadyIndex = arr[v[i].r][v[i].c];
		if (alreadyIndex == -1 || v[alreadyIndex].alive == 0){
			arr[v[i].r][v[i].c] = i;
		} else if (v[alreadyIndex].size > v[i].size){
				v[i].alive = 0;
		} else if (v[alreadyIndex].size < v[i].size){
			v[alreadyIndex].alive = 0;
			arr[v[i].r][v[i].c] = i;
		}
	}
	// for (int i = 1; i <= R; i++){
	// 	for (int j = 1; j <= C; j++){
	// 		if (arr[i][j] == -1 ) cout << ". ";
	// 		else if (v[arr[i][j]].alive == 0) cout << "x ";
	// 		else cout << char('A' + arr[i][j]) << " ";
	// 	}
	// 	cout << "\n";
	// }
}

int main(){
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++){
		cin >> r >> c >> s >> d >> z;
		v.push_back(Shark(r,c,s,d,z, 1));
	}
	

	for (fisher = 1; fisher < C + 1; fisher++){
		// cout << "fisher : " << fisher << "\n";
		fish();
		// cout << "--------\n";
		move();
		// cout << "---------\n";
	}
	cout << ans;
}