#include <bits/stdc++.h>

using namespace std;

const int N = 1000;

int g[N][N];
int used[N];
int w[N*N];

int n, maxw, z;
int curr;

#define DFS1 z=0;curr++;re=false;dfs(0)
#define DFS2 z=0;curr++;re=true;dfs(0)

bool re;
inline int gt(int v, int u){
    return re ? g[u][v] : g[v][u];
}

void dfs(int v){
    used[v] = curr;
    z++; 
    for(int u = 0; u < n; ++u)
        if((used[u] < curr)&&(gt(v, u) <= maxw))
            dfs(u);
}

int main(){ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    curr = 0;
    int k = 0;

    cin >> n;

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j){
            cin >> g[i][j]; 
            w[k++] = g[i][j];
        }
    sort(w, w+k-1);

    int l = 0, r = k - 1;
    while(l != r){
        int m = (l + r) / 2; 
        maxw = w[m]; 
        bool ok;
        
        DFS1;
        if(z < n){ 
            ok = false;
        } else {
            DFS2;
            ok = (z == n);
        }
        
        ok ? r = m : l = m + 1;
    }

    cout << w[l] << '\n';
    return 0;
}

/*
4
0 10 12 16
11 0 8 9
10 13 0 22
13 10 17 0

*/

/*
real    0m15.884s
user    0m15.872s
sys     0m0.012s
*/