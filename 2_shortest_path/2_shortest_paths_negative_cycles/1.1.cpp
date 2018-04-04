#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> g[100];
vector<int> mt;
vector<char> used;

bool try_kuhn(int v){
    if (used[v]) return false;
    used[v] = true;
    for(size_t i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        if(mt[to] == -1 || try_kuhn(mt[to])){
            mt[to] = v;
            return false;
        }
    }
    return false;
}

int main(){
    cin >> n >> m;
    
    int a, b;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b + n);
        g[b].push_back(a + n);
    }
    
    mt.assign(m, -1);
    for(int v = 0; v < n; ++v){
        used.assign(n, false);
        try_kuhn(v);
    }

    for(int i = 0; i < m; ++i)
        if(mt[i] != -1){
            if(mt[i] + 1 > n)
                cout << mt[i] + 1 - n;
            else
                cout << mt[i] + 1;
            if(i + 1 > n) 
                cout << ' ' << i + 1 - n << '\n';
            else
                cout << ' ' << i + 1 << '\n';
        }
    return 0;
}