#include <iostream>
#include <queue>
#include <vector>
#include <ios>

using namespace std;

int used[1001][1001];
int H, W, x1, y1, x2, y2;

inline bool check(int x, int y){
	return x > -1 && x < W && y > -1 && y < H;
}

bool do_u_know_da_wae(){
	queue<int> q;
	q.push(x2);
	q.push(y2);

	int x, y;

	while(!q.empty()){
		x = q.front();	
		q.pop();
		y = q.front();	
		q.pop();
		
		if(check(x + 1, y) && used[x + 1][y] == 0){
			used[x + 1][y] = (x << 10) + y + 1; 
			q.push(x + 1);
			q.push(y);
		}
		if(check(x - 1, y) && used[x - 1][y] == 0){
			used[x - 1][y] = (x << 10) + y + 1;
			q.push(x - 1);
			q.push(y);
		}
		if(check(x, y + 1) && used[x][y + 1] == 0){
			used[x][y + 1] = (x << 10) + y + 1;
			q.push(x);
			q.push(y + 1);
		}
		if(check(x, y - 1) && used[x][y - 1] == 0){
			used[x][y - 1] = (x << 10) + y + 1;
			q.push(x);
			q.push(y - 1);
		}

		if (abs(x - x1) + abs(y - y1) == 1)
			return true;
	}
	return false;
}

void show_me_da_wae(){
	int x = x1, y = y1, tmp;
	while(x!=x2 || y!=y2){
		cout << x + 1 << ' ' << y + 1 << '\n';
		tmp = used[x][y];
		y = (tmp - 1) % (1 << 10);
		x = (tmp - y) >> 10;
	}
	cout << x2 + 1 << ' ' << y2 + 1<< '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> W >> H >> x1 >>y1 >> x2 >> y2;
	x1--; y1--; x2--; y2--;

	char c;
	for(int i = 0; i < H; i++)
		for(int j = 0; j < W; j++){
			cin >> c;
			used[j][i] = (c == '.') - 1;
		}
	used[x2][y2] = 1;

	if(do_u_know_da_wae() == true){
		cout << "YES\n";
		show_me_da_wae();
	}
	else{
		cout << "NO\n";
	}
	return 0;
}