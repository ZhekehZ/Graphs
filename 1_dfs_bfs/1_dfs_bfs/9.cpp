#include <iostream>
#include <vector>
#include <queue>
#include <ios>

using namespace std;

vector<int> g[500000];
char used[500000];
int val = 1;
int matrix[500000];

void bfs(int v){
	queue<int> q;
	q.push(v);
	used[v] = val;
	matrix[v] = 0;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		for(int e : g[t]){
			if(used[e] != val){
				q.push(e);
				matrix[e] = matrix[t] + 1;
				used[e] = val;
			}
		}
	}
	val++;
}

int main(){
	int n, m;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int a, b;
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	bfs(0);
	int Vm = 0, Lm = matrix[0];
	for(int i = 1; i < n; i++){
		if(matrix[i] > Lm){
			Vm = i;
			Lm = matrix[i];
		}
	}
	bfs(Vm);

	int mx = matrix[0];
	for(int i = 1; i < n; i++){
		mx = max(mx, matrix[i]);
	}

	if(m <= mx)
		cout << m + 1;
	else
		if(mx + 1 + ((m - mx)/2) <= n)
			cout << mx + 1 + ((m - mx)/2);
		else
			cout << n;

	return 0;
}