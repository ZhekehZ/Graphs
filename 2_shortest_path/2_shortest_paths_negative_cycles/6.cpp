#include <iostream>
#include <vector>
#include <set>
#include <ios>

using namespace std;

const int INF = 600000000;

vector<pair<int, int>> e[100000];
vector<int> d(100000, INF);
int n, m;

void dijkstra(int v){
    set<pair<int, int>> q;
    q.insert({0, v});
    d[v] = 0;
    while(!q.empty()){
        int k = q.begin()->second;
        q.erase(q.begin());

        for(auto u : e[k]){
            if(d[u.first] > d[k] + u.second){
                q.erase({d[u.first], u.first});
                d[u.first] = d[k] + u.second;
                q.insert({d[u.first], u.first});
            } 
        }        
    } 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s, t;

    cin >> n >> m;
    cin >> s >> t;
    s--; t--;

    int a, b, w;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        e[a - 1].push_back({b - 1, w});
        e[b - 1].push_back({a - 1, w});
    }

    dijkstra(s);

    if(d[t] < INF){
        cout << d[t] << '\n';
    }
    else
        cout << "-1\n";

    return 0;
}