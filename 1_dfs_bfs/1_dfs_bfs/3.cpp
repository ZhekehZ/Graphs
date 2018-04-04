#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> g[100000];
int color[100000];
std::vector<int> topsort;
bool OK;

void dfs(int v){
	if(!OK) return;
	color[v] = 1;
	for(int e : g[v]){
		if(color[e] == 0){
			dfs(e);
		} else {
			if (color[e] == 1){
				OK = false;
				break;
			}
		}
	}
	color[v] = 2;
	topsort.push_back(v);
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
		std::cout << -1;
	} else {
		std::reverse(topsort.begin(), topsort.end());
		for(int i : topsort){
			std::cout << i + 1 << ' ';
		}
	}
	std::cout << '\n';
	return 0;
}
