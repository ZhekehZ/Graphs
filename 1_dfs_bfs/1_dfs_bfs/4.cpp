#include <iostream>
#include <vector>

std::vector<int> g[100000];
bool used[10000];
int maxL[10000];
int MAXL;

void dfs(int v){
	used[v] = true;
	int len = 0;
	for(int e : g[v]){
		if(!used[e])
			dfs(e);	
		if(maxL[e] + 1 > len)
			len = maxL[e] + 1; 
	}
	maxL[v] = len;
	if(len > MAXL)
		MAXL = len;
}

int main(){
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++){
		used[i] = maxL[i] = 0;
	}	
	MAXL = 0;
	int u, v;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	} 
	for(int i = 0; i < n; i++){
		if(!used[i]){
			dfs(i);
		}
	}
	std::cout << MAXL << '\n';
	
	return 0;
}
