#include <iostream>
#include <vector>

std::vector<int> g[10000];
bool used[100];

void dfs(int v){
	used[v] = true;
	for(int e : g[v]){
		if(!used[e]){
			dfs(e);
		}
	}
}

int main(){
	int n, m;
	std::cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	for(int i = 0; i < n; i++){
		if(!used[i]){
			std::cout << "NO\n";		
			return 0;
		}
	}
	std::cout << "YES\n";
	return 0;
}
