#include <iostream>
#include <vector>

std::vector<int> g[10000];
bool used[100];
int nums[100];
int n, sum;

void dfs(int v){
	used[v] = true;
	int h = 1;
	for(int e : g[v]){
		if(!used[e]){
			dfs(e);
			h += nums[e];
			sum += nums[e]*(n - nums[e]);
		}
	}
	nums[v] = h;
}

int main(){
	int m;
	std::cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0);
	std::cout << sum << '\n';
	return 0;
}