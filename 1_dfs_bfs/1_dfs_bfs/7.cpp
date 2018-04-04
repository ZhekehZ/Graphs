#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int matrix[1000][1000];
vector<int> g[1000];
int used[1000];
queue<int> q;
int d[1000];
int n, m;
int val;

void bfs(int v){
	used[v] = val;
	q.push(v);
	d[v] = 0;
	while(!q.empty()){
		int fr = q.front();
		for(int u : g[fr]){
			if(used[u] != val){
				used[u] = val;
				q.push(u);
				d[u] = d[fr] + 1;
				if(matrix[u][v] > d[u] || matrix[u][v] == 0)
					matrix[u][v] = matrix[v][u] = d[u];
			}
		}
		q.pop();
	}
	val++;
}

int main(){
	val = 0;
	cin >> n >> m;
	
	int a, b;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
			
	for(int i = 0; i < n; i++){
		bfs(i);
	}

	int sum = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			sum += matrix[i][j];

	cout << sum << '\n';	

	return 0;
}