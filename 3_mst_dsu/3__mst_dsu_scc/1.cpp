#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll double
vector<pair<int,int>> g;
const ll INF = 1e15; 

inline ll get(int u, int v){
    auto t1 = g[u];
    auto t2 = g[v];
    return sqrt( (ll) ((t1.first - t2.first)*(t1.first - t2.first) +
                        (t1.second - t2.second)*(t1.second - t2.second) ) );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(6);
    cout.setf(cout.fixed);
    int n;
    cin >> n;
    int a, b;

    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        g.push_back({a, b});
    }

    vector<char> used(n, false);
    vector<ll> me(n, INF);

    ll sum = 0;

    me[0] = 0.0;
    for(int i = 0; i < n; ++i){
        int v = -1;
        for(int j = 0; j < n; ++j)
            if(!used[j] && (v ==-1 || me[j] < me[v]))
                v = j;
            
        used[v] = true;
        sum += me[v];

        ll w;
        for(int j = 0; j < n; ++j)
            if((w = get(j, v)) < me[j])
                me[j] = w;
    }

    cout << sum << '\n';
    return 0;
}