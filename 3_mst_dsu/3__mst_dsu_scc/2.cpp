#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, pair<int, int>>> g;
vector<int> id;

int get (int v) {
	return (v == id[v]) ? v : (id[v] = get(id[v]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        a--; b--;
        g.push_back({c, {a, b}});
    }

    //Kruskal + DSU

    long long sum = 0;
    sort(g.begin(), g.end());
    id.resize(n);
    for(int i = 0; i < n; ++i)
        id[i] = i;

    for(int i = 0; i < m; ++i){
        int w = g[i].first;
        int a = g[i].second.first;
        int b = g[i].second.second;
        if((a = get(a)) != (b = get(b))){
            sum += w;
            id[a] = b;
        }
    }

    cout << sum << '\n';
    return 0;
}