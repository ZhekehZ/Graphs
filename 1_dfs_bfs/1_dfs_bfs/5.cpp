#include <iostream>
#include <vector>

std::vector<int> g[100000];
int color[100000];
bool OK;
int cycle;

void dfs(int v){
	if(!OK) return;
	color[v] = 1;
	for(int e : g[v]){
		if(color[e] == 0){
			dfs(e);
		} else {
			if (color[e] == 1){
				OK = false;
				cycle = e;
				return;
			}
		}
	}
	if(OK)
		color[v] = 2;
}

int main(){
	int n, m;
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
		color[i] = 0;
	OK = true;
	int u, v;
	for(int i = 0; i < m; i++){
		std::cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
	} 

	for(int i = 0; i < n; i++){
		if(OK)
		if(color[i] == 0){
			dfs(i);
		}
	}
	if(!OK){
		std::cout << "YES\n" << cycle+1;
		int next;
		for(int e : g[cycle])
			if(color[e] == 1){
				next = e;
				break;
			}
		while(next != cycle){
			std::cout << ' '<< next+1;
			for(int e : g[next])
				if(color[e] == 1){
					next = e;
					break;
				}
		}
		std::cout << '\n';
	} else
		std::cout << "NO\n";
	return 0;
}
